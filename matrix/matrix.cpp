#include "matrix.hpp"

#include <ostream>
#include <stdexcept>

Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : data_(values)
{
    if (data_.empty() || data_.front().empty()) {
        throw std::invalid_argument("a matrix must have at least one row and one column");
    }

    const std::size_t column_count = data_.front().size();
    for (const auto& row : data_) {
        if (row.size() != column_count) {
            throw std::invalid_argument("all matrix rows must have the same length");
        }
    }
}

std::size_t Matrix::rows() const
{
    return data_.size();
}

std::size_t Matrix::cols() const
{
    return data_.front().size();
}

double& Matrix::at(std::size_t row, std::size_t col)
{
    return data_.at(row).at(col);
}

double Matrix::at(std::size_t row, std::size_t col) const
{
    return data_.at(row).at(col);
}

Matrix Matrix::operator+(const Matrix& rhs) const
{
    if (rows() != rhs.rows() || cols() != rhs.cols())
    {
        throw std::invalid_argument(
            "matrix dimensions must match for addition");
    }

    Matrix result(std::vector<std::vector<double>>(
        rows(), std::vector<double>(cols(), 0.0)));

    for (std::size_t i = 0; i < rows(); ++i)
    {
        for (std::size_t j = 0; j < cols(); ++j)
        {
            result.at(i, j) = at(i, j) + rhs.at(i, j);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
    if (cols() != rhs.rows())
    {
        throw std::invalid_argument(
            "left matrix columns must match right matrix rows");
    }

    Matrix result(std::vector<std::vector<double>>(
        rows(), std::vector<double>(rhs.cols(), 0.0)));

    for (std::size_t i = 0; i < rows(); ++i)
    {
        for (std::size_t j = 0; j < rhs.cols(); ++j)
        {
            for (std::size_t k = 0; k < cols(); ++k)
            {
                result.at(i, j) += at(i, k) * rhs.at(k, j);
            }
        }
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (std::size_t i = 0; i < matrix.rows(); ++i)
    {
        for (std::size_t j = 0; j < matrix.cols(); ++j)
        {
            os << matrix.at(i, j);

            if (j + 1 < matrix.cols())
            {
                os << ' ';
            }
        }

        os << '\n';
    }

    return os;
}
