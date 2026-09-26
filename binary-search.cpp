#include <iostream>
#include <string>
#include <vector>

int binary_search_index(const std::vector<int>& values, int target)
{
    auto beg = values.begin();
    auto end = values.end();

    while (beg != end)
    {
        auto mid = beg + (end - beg) / 2;

        if (*mid == target)
        {
            return static_cast<int>(mid - values.begin());
        }
        else if (target < *mid)
        {
            end = mid;
        }
        else
        {
            beg = mid + 1;
        }
    }

    return -1;
}

void check(int actual, int expected, const std::string& label)
{
    std::cout << label << ": "
              << (actual == expected ? "PASS" : "FAIL")
              << " (expected " << expected << ", got " << actual << ")\n";
}

int main()
{
    const std::vector<int> values{1, 2, 3, 4, 6};

    check(binary_search_index(values, 5), -1, "missing value");
    check(binary_search_index(values, 3), 2, "middle value");
    check(binary_search_index(values, 1), 0, "first value");
    check(binary_search_index(values, 6), 4, "last value");

// 空向量
const std::vector<int> empty_values{};
check(binary_search_index(empty_values, 10), -1, "empty vector");

// 单元素向量
const std::vector<int> single_value{8};
check(binary_search_index(single_value, 8), 0, "single element found");
check(binary_search_index(single_value, 5), -1, "single element missing");

// 重复元素
const std::vector<int> repeated_values{1, 2, 2, 2, 5};
int duplicate_index = binary_search_index(repeated_values, 2);

bool duplicate_correct =
    duplicate_index >= 1 &&
    duplicate_index <= 3 &&
    repeated_values[duplicate_index] == 2;

std::cout << "duplicate value: "
          << (duplicate_correct ? "PASS" : "FAIL")
          << " (got index " << duplicate_index << ")\n";
    return 0;
}
