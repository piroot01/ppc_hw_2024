#ifndef __MATRIX_FRIENDS_HPP__
#define __MATRIX_FRIENDS_HPP__

#include <cstdint>
#include <fstream>
#include <iomanip>

#include "matrix.hpp"
#include "matrix_exceptions.hpp"

// matrix overloaded operators

template<class T>
inline Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if (lhs.nrows != rhs.nrows || lhs.ncols != rhs.ncols)
    {
        throw matrix_bad_sizes();
    }

    Matrix<T> result(lhs.nrows, lhs.ncols);

    std::transform(lhs.data.begin(), lhs.data.end(), rhs.data.begin(), result.data.begin(), std::plus<T>());

    return result;
}

template<class T>
inline Matrix<T> operator+(const T lhs, const Matrix<T>& rhs)
{
    Matrix<T> result(rhs);

    result.bias(lhs);

    return result;
}

template<class T>
inline Matrix<T> operator+(const Matrix<T>& lhs, const T rhs)
{
    Matrix<T> result(lhs);

    result.bias(rhs);

    return result;
}

template<class T>
inline Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if (lhs.nrows != rhs.nrows || lhs.ncols != rhs.ncols)
    {
        throw matrix_bad_sizes();
    }

    Matrix<T> result(lhs.nrows, lhs.ncols);

    std::transform(lhs.data.begin(), lhs.data.end(), rhs.data.begin(), result.data.begin(), std::minus<T>());

    return result;
}

template<class T>
inline Matrix<T> operator-(const T lhs, const Matrix<T>& rhs)
{
    Matrix<T> result(rhs);

    result.scale(-1);

    result.bias(lhs);

    return result;
}

template<class T>
inline Matrix<T> operator-(const Matrix<T>& lhs, const T rhs)
{
    Matrix<T> result(lhs);

    result.bias((-1) * rhs);

    return result;
}

template<class T>
inline Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if (lhs.ncols != rhs.nrows)
    {
        throw matrix_bad_sizes();
    }

    Matrix<T> result(lhs.nrows, rhs.ncols);

    for (std::size_t i = 0; i < lhs.nrows; ++i)
    {
        for (std::size_t j = 0; j < rhs.ncols; ++j)
        {
            for (std::size_t k = 0; k < lhs.ncols; ++k)
            {
                result.data[i * rhs.ncols + j] += lhs.data[i * lhs.ncols + k] * rhs.data[k * rhs.ncols + j];
            }
        }
    }

    return result;
}

template<class T>
inline Matrix<T> operator*(const T lhs, const Matrix<T>& rhs)
{
    Matrix<T> result(rhs);

    result.scale(lhs);

    return result;
}

template<class T>
inline Matrix<T> operator*(const Matrix<T>& lhs, const T rhs)
{
    Matrix<T> result(lhs);

    result.scale(rhs);

    return result;
}

// fancy operators
template<class T>
Matrix<T> hadamard(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if (lhs.nrows != rhs.nrows || lhs.ncols != rhs.ncols)
    {
        throw matrix_bad_sizes();
    }

    Matrix<T> result(lhs.nrows, lhs.ncols);

    std::transform(lhs.data.begin(), lhs.data.end(), rhs.data.begin(), result.data.begin(), std::multiplies<T>());

    return result;
}

template<class T>
Matrix<T> power(const Matrix<T>& matrix, std::uint32_t power)
{
    if (matrix.nrows != matrix.ncols)
    {
        throw matrix_bad_sizes();
    }

    Matrix<T> result(matrix.nrows, matrix.ncols);

    result.eye();

    Matrix<T> base(matrix);
    while (power > 0)
    {
        if (power & 1)
        {
            result = result * base;
        }
        base = base * base;
        power >>= 1;
    }

    return result;
}

template<class T>
Matrix<T> horzcat(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if (lhs.nrows != rhs.nrows)
    {
        throw matrix_bad_sizes();
    }

    Matrix<T> result(lhs.nrows, lhs.ncols + rhs.ncols);

    for (std::size_t i = 0; i < lhs.nrows; ++i)
    {
        for (std::size_t j = 0; j < lhs.ncols; ++j)
        {
            result.data[i * result.ncols + j] = lhs.data[i * lhs.ncols + j];
        }
        for (std::size_t j = 0; j < rhs.ncols; ++j)
        {
            result.data[i * result.ncols + lhs.ncols + j] = rhs.data[i * rhs.ncols + j];
        }
    }

    return result;
}

template<class T>
Matrix<T> vertcat(const Matrix<T>& top, const Matrix<T>& bot)
{
    if (top.ncols != bot.ncols)
    {
        throw matrix_bad_sizes();
    }

/*
    Matrix<T> result(top.nrows + bot.nrows, top.ncols);

    for (int i = 0; i < top.nrows; ++i)
    {
        for (int j = 0; j < top.ncols; ++j)
        {
            result.data[i * top.ncols + j] = top.data[i * top.ncols + j];
        }
    }
    
    for (int i = 0; i < bot.nrows; ++i)
    {
        for (int j = 0; j < bot.ncols; ++j)
        {
            result.data[(top.nrows + i) * top.ncols + j] = bot.data[i * bot.ncols + j];
        }
    }
*/
    Matrix<T> result(top);

    // update the dimensions
    result.nrows += bot.nrows;

    result.data.insert(result.data.end(), bot.data.begin(), bot.data.end());

    return result;
}

template<class T>
Matrix<T> blkdiag(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if (lhs.nrows != lhs.ncols or rhs.nrows != rhs.ncols)
    {
        throw matrix_bad_sizes();
    }

    std::size_t result_rows = lhs.nrows + rhs.nrows;
    std::size_t result_cols = lhs.ncols + rhs.ncols;

    Matrix result(result_rows, result_cols);

    for (std::size_t i = 0; i < lhs.nrows; ++i)
    {
        for (std::size_t j = 0; j < lhs.ncols; ++j)
        {
            result.data[i * result_cols + j] = lhs.data[i * lhs.ncols + j];
        }
    }

    for (std::size_t i = 0; i < rhs.nrows; ++i)
    {
        for (std::size_t j = 0; j < rhs.ncols; ++j)
        {
            result.data[(i + lhs.nrows) * result_cols + (j + lhs.ncols)] = rhs.data[i * rhs.ncols + j];
        }
    }

    return result;
}

template<class T>
Matrix<T> blkdiag(const T lhs, const Matrix<T>& rhs)
{
    Matrix<T> lhs_matrix(1, 1);

    lhs_matrix.data[0] = lhs;

    return blkdiag(lhs_matrix, rhs);
}

template<class T>
Matrix<T> blkdiag(const Matrix<T>& lhs, const T rhs)
{
    Matrix rhs_matrix(1, 1);

    rhs_matrix.data[0] = rhs;

    return blkdiag(lhs, rhs_matrix);
}

template<class T>
Matrix<T> blkdiag(const T lhs, const T rhs)
{
    Matrix lhs_matrix(1, 1);

    lhs_matrix.data[0] = lhs;

    Matrix rhs_matrix(1, 1);

    rhs_matrix.data[0] = rhs;

    return blkdiag(lhs_matrix, rhs_matrix);
}

template<class T>
Matrix<T> kronecker(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    std::size_t result_rows = lhs.nrows * rhs.nrows;

    std::size_t result_cols = lhs.ncols * rhs.ncols;

    Matrix result(result_rows, result_cols);

    for (std::size_t i = 0; i < lhs.nrows; ++i)
    {
        for (std::size_t j = 0; j < lhs.ncols; ++j)
        {
            for (std::size_t k = 0; k < rhs.nrows; ++k)
            {
                for (std::size_t l = 0; l < rhs.ncols; ++l)
                {
                    result.data[(i * rhs.nrows + k) * result_cols + (j * rhs.ncols + l)] = lhs.data[i * lhs.ncols + j] * rhs.data[k * rhs.ncols + l];
                }
            }
        }
    }

    return result;
}

// matrix printer
template<class T>
inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    if (matrix.data.empty())
    {
        os << '\n';
    }

    os << std::right;

    std::size_t index = 0;
    for (const auto value : matrix.data)
    {
        os << std::setw(ELEMENT_PRINT_SIZE) << value << ' ';
        if (++index % matrix.ncols == 0)
        {
            os << '\n';
        }
    }

    return os;
}

// matrix loader
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

    if (!(header_stream >> matrix.nrows) || !(header_stream >> matrix.ncols))
    {
        throw matrix_in_bad_header();
    }

    matrix.data.resize(matrix.nrows * matrix.ncols);

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
            if (col == matrix.ncols)
            {
                col = 0;
                ++row;
            }
            ++elements;
        }
    }

    if (elements != matrix.ncols * matrix.nrows)
    {
        throw matrix_in_bad_body();
    }
}

#endif
