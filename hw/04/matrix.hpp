#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__
/*** PPC - HW03 ***/
/* Tento soubor se odevzdava, muzete ho upravit, pridat funkce. Funkce neumazavejte, nemente jejich rozhrani. */

#include <algorithm>
#include <cstdint>
#include <ios>
#include <iostream>
#include <iomanip>
#include <ratio>
#include <stdexcept>
#include <thread>
#include <type_traits>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "matrix_exceptions.hpp"

#define ELEMENT_PRINT_SIZE 5

template<class T = std::int32_t, typename = std::enable_if_t<std::is_integral_v<T>>>
class Matrix
{
public:
    using value_type = T;
    using self = Matrix<T>;

public:
    friend inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);
    friend inline void loadMatrixFile(Matrix<T>& matrix, const std::string& fname);

public:
    inline explicit Matrix(const std::size_t rowscols = 0) :
        nrows_(rowscols), ncols_(rowscols)
    {
        if (rowscols < 0)
        {
            throw matrix_negative_size();
        }

        this->data_.resize(nrows_ * ncols_, 0);
    }

    inline explicit Matrix(const std::size_t rows, const std::size_t cols) :
        nrows_(rows), ncols_(cols)
    {
        if (rows < 0 || cols < 0)
        {
            throw matrix_negative_size();
        }

        this->data_.resize(nrows_ * ncols_, 0);
    }

    inline Matrix(const Matrix& other) :
        nrows_(other.nrows_), ncols_(other.ncols_)
    {
        this->data_.resize(other.data_.size(), 0);
        std::copy(other.data_.cbegin(), other.data_.cend(), this->data_.begin());
    }

    inline Matrix(const std::vector<value_type>& diag) :
        nrows_(diag.size()), ncols_(diag.size())
    {
        std::size_t diag_size = diag.size();
        this->data_.resize(diag_size * diag_size, 0);

        for (std::size_t index = 0; index < diag_size; ++index)
        {
            this->data_[index * diag_size + index] = diag[index];
        }
    }

    ~Matrix() noexcept
    {
    }

public:
    [[maybe_unused]] inline self& zeros()
    {
        std::fill(this->data_.begin(), this->data_.end(), 0);

        return (*this);
    }

    [[maybe_unused]] inline self& uniform(value_type value)
    {
        std::fill(this->data_.begin(), this->data_.end(), value);

        return (*this);
    }

    [[maybe_unused]] inline self& eye() noexcept
    {
        std::size_t colls_filled = 0;

        for (auto iter = this->data_.begin(); iter < this->data_.end(); ++iter)
        {
            *iter = ((colls_filled < this->ncols_) && ((iter - this->begin()) % (this->ncols_ + 1) == 0)) ? 1 : 0;
            colls_filled += (*iter == 1) ? 1 : 0;
        }

        return (*this);
    }

    [[maybe_unused]] inline self& bias(value_type value)
    {
        /*
        for (auto iter = this->data_.begin(); iter < this->data_.end(); ++iter)
        {
            *iter += value;
        }
        */

        std::transform(this->data_.begin(), this->data_.end(), this->data_.begin(), [value](value_type bias)
        {
            return value + bias;
        });

        return (*this);
    }

    [[maybe_unused]] inline self& scale(value_type value)
    {
        std::transform(this->data_.begin(), this->data_.end(), this->data_.begin(), [value](value_type scale)
        {
            return value * scale;
        });

        return (*this);
    }

    [[maybe_unused]] inline self& transpose()
    {
        self transposed(*this);

        for (std::size_t i = 0; i < this->ncols_; ++i)
        {
            for (std::size_t j = 0; j < this->nrows_; ++j)
            {
                transposed.data_[j * this->nrows_ + i] = this->data_[i * this->ncols_ + j];
            }
        }

        std::swap(this->data_, transposed.data_);
        this->nrows_ = transposed.nrows_;
        this->ncols_ = transposed.ncols_;

        return (*this);
    }

    [[maybe_unused]] inline self& changedim(const std::size_t rows, const std::size_t cols)
    {
        if (rows < 0 || cols < 0)
            throw matrix_negative_size();

        std::vector<value_type> resized(rows * cols, 0);

        for (std::size_t i = 0; i < this->ncols_; ++i)
        {
            for (std::size_t j = 0; j < this->nrows_; ++j)
            {
                resized[i * cols + j] = this->data_[i * this->ncols_ + j];
            }
        }

        std::swap(this->data_, resized);
        this->nrows_ = rows;
        this->ncols_ = cols;

        return (*this);
    }

public:
    inline bool operator==(const Matrix& other) const noexcept
    {
        if (this->ncols_ != other.ncols_ || this->nrows_ != other.nrows_)
        {
            return false;
        }

        for (std::size_t index = 0, data_size = this->data_.size(); index < data_size; ++index)
        {
            if (this->data_[index] != other[index])
                return false;
        }

        return true;
    }

    
    inline self& operator=(const self& other)
    {
        if (this == &other)
        {
            return (*this);
        }

        this->ncols_ = other.ncols_;
        this->nrows_ = other.nrows_;
        this->data_.resize(other.data_.size(), 0);
        std::copy(other.data_.cbegin(), other.data_.cend(), this->data_.begin());

        return (*this);
    }

    inline value_type operator()(const std::size_t row, const std::size_t col) const
    {
        if (row >= this->nrows_ || col >= this->ncols_ || row < 0 || col < 0)
        {
            if (row >= this->nrows_ || row < 0)
            {
                throw std::out_of_range("Row index is out of range");
            }
            else
            {
                throw std::out_of_range("Column index is out of range");
            }
        }

        return this->data_[row * this->ncols_ + col];
    }

    inline value_type& operator()(const std::size_t row, const std::size_t col)
    {
        if (row >= this->nrows_ || col >= this->ncols_ || row < 0 || col < 0)
        {
            if (row >= this->nrows_ || row < 0)
            {
                throw std::out_of_range("Row index is out of range");
            }
            else
            {
                throw std::out_of_range("Column index is out of range");
            }
        }

        return this->data_[row * this->ncols_ + col];
    }

    std::vector<value_type> operator()() const
    {
        std::vector<value_type> diag;
        std::size_t diag_size = (this->nrows_ > this->ncols_) ? this->ncols_ : this->nrows_;

        diag.reserve(diag_size);
        for (std::size_t index = 0; index < diag_size; ++index)
        {
            diag.push_back(this->data_[index * this->ncols_ + index]);
        }

        return diag;
    }

protected:
    std::size_t nrows_ = 0;

    std::size_t ncols_ = 0;

    std::vector<T> data_ = {};

};

template<class T>
inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    os << std::right;

    std::size_t index = 0;
    for (const auto value : matrix.data_)
    {
        os << std::setw(ELEMENT_PRINT_SIZE) << value << ' ';
        if (++index % matrix.ncols_ == 0)
        {
            os << '\n';
        }
    }

    return os;
}

template<class T>
inline void loadMatrixFile(Matrix<T>& matrix, const std::string& fname)
{
    std::ifstream input_file(fname);

    if (input_file.fail())
    {
        throw cannot_open_file();
    }

    std::ostringstream file_content_out;
    file_content_out << input_file.rdbuf();
    std::istringstream file_content_in(file_content_out.str());

    std::string line;
    std::getline(file_content_in, line);
    std::stringstream header_stream(line);

    if (!(header_stream >> matrix.nrows_) || !(header_stream >> matrix.ncols_))
    {
        throw matrix_in_bad_header();
    }

    matrix.data_.resize(matrix.nrows_ * matrix.ncols_);

    std::size_t row = 0;
    std::size_t col = 0;
    std::size_t elements = 0;
    while (std::getline(file_content_in, line))
    {
        std::stringstream line_stream(line);
        T value;
        while (line_stream >> value)
        {
            matrix(row, col) = value;
            ++col;
            if (col == matrix.ncols_)
            {
                col = 0;
                ++row;
            }
            ++elements;
        }
    }

    if (elements != matrix.ncols_ * matrix.nrows_)
    {
        throw matrix_in_bad_body();
    }
}

/*

// L1 Scitani matic.
Matrix operator + (const Matrix & lhs, const Matrix & rhs);
// L1 Pricteni skalaru k cele matici.
Matrix operator + (const value & lhs, const Matrix & rhs);
Matrix operator + (const Matrix & lhs, const value & rhs);

// L1 Odecitani matic.
Matrix operator - (const Matrix & lhs, const Matrix & rhs);
// L1 Odecitani skalaru a matic.
Matrix operator - (const value & lhs, const Matrix & rhs);
Matrix operator - (const Matrix & lhs, const value & rhs);

// L2 Maticovy soucin.
Matrix operator * (const Matrix & lhs, const Matrix & rhs);
Matrix operator * (const value & lhs, const Matrix & rhs);
// L2 nasobeni matice skalarem
Matrix operator * (const Matrix & lhs, const value & rhs);

// L2 Hadamarduv soucin - prvek po prvku (ekvivalent .* z Matlabu).
Matrix hadamard (const Matrix & lhs, const Matrix & rhs);

// L2 Kladna mocnina ctvercove matice: power(A, 3) je ekvivalent A*A*A. Nulta mocnina je jednotkova matice. 
Matrix power (const Matrix & m, unsigned int pow);

// L3 Slouceni matic horizontalne (ekvivalent [lhs, rhs] z Matlabu).
Matrix horzcat (const Matrix & lhs, const Matrix & rhs);

// L3 Slouceni matic vertikalne (ekvivalent [top; bot] z Matlabu). 
Matrix vertcat (const Matrix & top, const Matrix & bot);

// L3 Diagonalni skladani matic. 
// Vstupy musi byt ctvercove matice nebo skalary (chovaji se jako matice 1x1), zbytek doplnen nulami.
Matrix blkdiag (const Matrix & lhs, const Matrix & rhs);
Matrix blkdiag (const value & lhs, const Matrix & rhs);
Matrix blkdiag (const Matrix & lhs, const value & rhs);
Matrix blkdiag (const value & lhs, const value & rhs);

// L3 Kroneckeruv soucin matic dle definice: https://mathworld.wolfram.com/KroneckerProduct.html 
Matrix kronecker (const Matrix & lhs, const Matrix & rhs);
*/
#endif
