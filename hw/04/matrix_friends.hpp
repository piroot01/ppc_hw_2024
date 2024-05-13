#ifndef __MATRIX_FRIENDS_HPP__
#define __MATRIX_FRIENDS_HPP__

#include <fstream>
#include <iomanip>

#include "matrix.hpp"

template<class T>
inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
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
