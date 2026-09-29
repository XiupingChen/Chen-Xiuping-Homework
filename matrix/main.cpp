#include "matrix.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

bool close(double lhs, double rhs, double tolerance = 1e-9)
{
    return std::abs(lhs - rhs) <= tolerance;
}

void check(bool condition, const std::string& label)
{
    std::cout << label << ": " << (condition ? "PASS" : "FAIL") << '\n';
}

int main()
{
    const Matrix a({{1.0, 2.0}, {3.0, 4.0}});
    const Matrix b({{2.0, 0.0}, {1.0, 2.0}});

    const Matrix sum = a + b;
    check(close(sum.at(0, 0), 3.0) && close(sum.at(0, 1), 2.0)
              && close(sum.at(1, 0), 4.0) && close(sum.at(1, 1), 6.0),
          "matrix addition");

    const Matrix product = a * b;
    check(close(product.at(0, 0), 4.0) && close(product.at(0, 1), 4.0)
              && close(product.at(1, 0), 10.0) && close(product.at(1, 1), 8.0),
          "matrix multiplication");

    std::cout << "Matrix a:\n" << a;

    // 自定义矩阵加法测试
    const Matrix c({{1.0, 2.0, 3.0}});
    const Matrix d({{4.0, 5.0, 6.0}});
    const Matrix custom_sum = c + d;

    check(close(custom_sum.at(0, 0), 5.0)
              && close(custom_sum.at(0, 1), 7.0)
              && close(custom_sum.at(0, 2), 9.0),
          "custom matrix addition");

    // 自定义矩阵乘法测试：2 × 3 乘以 3 × 2
    const Matrix e({
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    });

    const Matrix f({
        {7.0, 8.0},
        {9.0, 10.0},
        {11.0, 12.0}
    });

    const Matrix custom_product = e * f;

    check(close(custom_product.at(0, 0), 58.0)
              && close(custom_product.at(0, 1), 64.0)
              && close(custom_product.at(1, 0), 139.0)
              && close(custom_product.at(1, 1), 154.0),
          "custom matrix multiplication");

    // 非法维度测试：1 × 2 矩阵不能与 2 × 2 矩阵相加
    try
    {
        const Matrix invalid_left({{1.0, 2.0}});
        const Matrix invalid_right({
            {1.0, 2.0},
            {3.0, 4.0}
        });

        const Matrix invalid_sum = invalid_left + invalid_right;
        (void)invalid_sum;

        check(false, "invalid dimension test");
    }
    catch (const std::invalid_argument&)
    {
        check(true, "invalid dimension test");
    }

    return 0;
}
