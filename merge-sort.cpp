#include <iostream>
#include <string>
#include <vector>

void merge(std::vector<double>& values, int left, int mid, int right)
{
    std::vector<double> temporary;

    int i = left;
    int j = mid + 1;

    // 比较左右两部分的当前元素
    while (i <= mid && j <= right)
    {
        if (values[i] <= values[j])
        {
            temporary.push_back(values[i]);
            ++i;
        }
        else
        {
            temporary.push_back(values[j]);
            ++j;
        }
    }

    // 左半部分可能还有剩余元素
    while (i <= mid)
    {
        temporary.push_back(values[i]);
        ++i;
    }

    // 右半部分可能还有剩余元素
    while (j <= right)
    {
        temporary.push_back(values[j]);
        ++j;
    }

    // 将排好序的结果写回原向量
    for (int k = 0; k < static_cast<int>(temporary.size()); ++k)
    {
        values[left + k] = temporary[k];
    }
}

void merge_sort(std::vector<double>& values, int left, int right)
{
    // 区间为空或只有一个元素时，不需要继续排序
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    // 递归排序左半部分
    merge_sort(values, left, mid);

    // 递归排序右半部分
    merge_sort(values, mid + 1, right);

    // 合并两个已经排好序的部分
    merge(values, left, mid, right);
}

void print_check(const std::vector<double>& actual,
                 const std::vector<double>& expected,
                 const std::string& label)
{
    std::cout << label << ": " << (actual == expected ? "PASS" : "FAIL") << '\n';
}

void run_test(std::vector<double> values,
              const std::vector<double>& expected,
              const std::string& label)
{
    if (!values.empty()) {
        merge_sort(values, 0, static_cast<int>(values.size()) - 1);
    }
    print_check(values, expected, label);
}

int main()
{
    run_test({}, {}, "empty vector");
    run_test({4.0}, {4.0}, "one value");
    run_test({3.0, -1.0, 2.0, 2.0, 0.0},
             {-1.0, 0.0, 2.0, 2.0, 3.0},
             "mixed values");
    run_test({1.0, 2.0, 3.0, 4.0},
             {1.0, 2.0, 3.0, 4.0},
             "already sorted");
    run_test({4.0, 3.0, 2.0, 1.0},
             {1.0, 2.0, 3.0, 4.0},
             "reverse order");

// 自定义测试：小数、负数和重复值
    run_test({-2.5, 10.75, -2.5, 0.0},
             {-2.5, -2.5, 0.0, 10.75},
              "custom decimal values");
    return 0;
}
