#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>
#include <string>

#include "matrix_exceptions.hpp"

#define ELEMENT_PRINT_SIZE 5

template<class T = std::int32_t, typename = std::enable_if_t<std::is_integral_v<T>>>
class Matrix
{
public:
    using value_type = T;
    using self = Matrix<T>;

public:
    // basic operators
    template<class>
    friend inline Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs);

    template<class>
    friend inline Matrix<T> operator+(const T lhs, const Matrix<T>& rhs);

    template<class>
    friend inline Matrix<T> operator+(const Matrix<T>& lhs, const T rhs);

    template<class>
    friend inline Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs);

    template<class>
    friend inline Matrix<T> operator-(const T lhs, const Matrix<T>& rhs);

    template<class>
    friend inline Matrix<T> operator-(const Matrix<T>& lhs, const T rhs);

    template<class>
    friend inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);
    // fancy operators
    template<class>
    friend Matrix<T> hadamard(const Matrix<T>& lhs, const Matrix<T>& rhs);

    template<class>
    friend Matrix<T> power(const Matrix<T>& matrix, std::uint32_t power);

    template<class>
    Matrix<T> horzcat(const Matrix<T>& lhs, const Matrix<T>& rhs);

    template<class>
    Matrix<T> vertcat(const Matrix<T>& top, const Matrix<T>& bot);

    template<class>
    Matrix<T> blkdiag(const Matrix<T>& lhs, const Matrix<T>& rhs);

    template<class>
    Matrix<T> blkdiag(const T lhs, const Matrix<T>& rhs);

    template<class>
    Matrix<T> blkdiag(const Matrix<T>& lhs, const T rhs);

    template<class>
    Matrix<T> blkdiag(const T lhs, const T rhs);

    template<class>
    Matrix<T> kronecker(const Matrix<T>& lhs, const Matrix<T>& rhs);
    // matrix printer
    template<class>
    friend inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);
    // matrix loader
    template<class>
    friend inline void loadMatrixFile(Matrix<T>& matrix, const std::string& fname);

public:
    inline explicit Matrix(const std::int32_t rowscols = 0) :
        nrows(rowscols), ncols(rowscols)
    {
        if (rowscols < 0)
        {
            throw matrix_negative_size();
        }

        this->data.resize(nrows * ncols, 0);
    }

    inline explicit Matrix(const std::int32_t rows, const std::int32_t cols) :
        nrows(rows), ncols(cols)
    {
        if (rows < 0 || cols < 0)
        {
            throw matrix_negative_size();
        }

        this->data.resize(nrows * ncols, 0);
    }

    inline Matrix(const self& other) :
        nrows(other.nrows), ncols(other.ncols)
    {
        this->data.resize(other.data.size(), 0);
        std::copy(other.data.cbegin(), other.data.cend(), this->data.begin());
    }

    inline Matrix(const std::vector<value_type>& diag) :
        nrows(diag.size()), ncols(diag.size())
    {
        std::size_t diag_size = diag.size();
        this->data.resize(diag_size * diag_size, 0);

        for (std::size_t index = 0; index < diag_size; ++index)
        {
            this->data[index * diag_size + index] = diag[index];
        }
    }

    ~Matrix() noexcept
    {
    }

public:
    [[maybe_unused]] inline self& zeros()
    {
        std::fill(this->data.begin(), this->data.end(), 0);

        return (*this);
    }

    [[maybe_unused]] inline self& uniform(value_type value)
    {
        std::fill(this->data.begin(), this->data.end(), value);

        return (*this);
    }

    [[maybe_unused]] inline self& eye() noexcept
    {
        std::size_t colls_filled = 0;

        for (auto iter = this->data.begin(); iter < this->data.end(); ++iter)
        {
            *iter = ((colls_filled < this->ncols) && ((iter - this->data.begin()) % (this->ncols + 1) == 0)) ? 1 : 0;
            colls_filled += (*iter == 1) ? 1 : 0;
        }

        return (*this);
    }

    [[maybe_unused]] inline self& bias(value_type value)
    {
        /*
        for (auto iter = this->data.begin(); iter < this->data.end(); ++iter)
        {
            *iter += value;
        }
        */

        std::transform(this->data.begin(), this->data.end(), this->data.begin(), [value](value_type bias)
        {
            return value + bias;
        });

        return (*this);
    }

    [[maybe_unused]] inline self& scale(value_type value)
    {
        std::transform(this->data.begin(), this->data.end(), this->data.begin(), [value](value_type scale)
        {
            return value * scale;
        });

        return (*this);
    }

    [[maybe_unused]] inline self& transpose()
    {
        self transposed(this->ncols, this->nrows);

        for (std::size_t i = 0; i < this->nrows; ++i)
        {
            for (std::size_t j = 0; j < this->ncols; ++j)
            {
                transposed.data[j * this->nrows + i] = this->data[i * this->ncols + j];
            }
        }

        std::swap(this->data, transposed.data);
        this->nrows = transposed.nrows;
        this->ncols = transposed.ncols;

        return (*this);
    }

    [[maybe_unused]] inline self& changedim(const std::int32_t rows, const std::int32_t cols)
    {
        if (rows < 0 || cols < 0)
        {
            throw matrix_negative_size();
        }

        std::vector<value_type> resized(rows * cols, 0);

        std::size_t min_rows = std::min(this->nrows, static_cast<std::size_t>(rows));
        std::size_t min_cols = std::min(this->ncols, static_cast<std::size_t>(cols));

        for (std::size_t i = 0; i < min_rows; ++i)
        {
            for (std::size_t j = 0; j < min_cols; ++j)
            {
                resized[i * cols + j] = this->data[i * this->ncols + j];
            }
        }

        this->data = resized;
        this->nrows = rows;
        this->ncols = cols;

        return (*this);
    }

public:
    inline bool operator==(const Matrix& other) const noexcept
    {
        if (this->ncols != other.ncols || this->nrows != other.nrows)
        {
            return false;
        }

        for (std::size_t index = 0, datasize = this->data.size(); index < datasize; ++index)
        {
            if (this->data[index] != other.data[index])
            {
                return false;
            }
        }

        return true;
    }

    
    inline self& operator=(const self& other)
    {
        if (this == &other)
        {
            return (*this);
        }

        this->ncols = other.ncols;
        this->nrows = other.nrows;
        this->data.resize(other.data.size(), 0);
        std::copy(other.data.cbegin(), other.data.cend(), this->data.begin());

        return (*this);
    }

    inline value_type operator()(const std::size_t row, const std::size_t col) const
    {
        if (row >= this->nrows || col >= this->ncols || row < 0 || col < 0)
        {
            if (row >= this->nrows || row < 0)
            {
                throw std::out_of_range("Row index is out of range");
            }
            else
            {
                throw std::out_of_range("Column index is out of range");
            }
        }

        return this->data[row * this->ncols + col];
    }

    inline value_type& operator()(const std::size_t row, const std::size_t col)
    {
        if (row >= this->nrows || col >= this->ncols || row < 0 || col < 0)
        {
            if (row >= this->nrows || row < 0)
            {
                throw std::out_of_range("Row index is out of range");
            }
            else
            {
                throw std::out_of_range("Column index is out of range");
            }
        }

        return this->data[row * this->ncols + col];
    }

    std::vector<value_type> operator()() const
    {
        std::vector<value_type> diag;
        std::size_t diag_size = (this->nrows > this->ncols) ? this->ncols : this->nrows;

        diag.reserve(diag_size);
        for (std::size_t index = 0; index < diag_size; ++index)
        {
            diag.push_back(this->data[index * this->ncols + index]);
        }

        return diag;
    }

// i dont like this
public:
    std::size_t nrows = 0;

    std::size_t ncols = 0;

    std::vector<T> data = {};

};

#endif
