#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int max_crossing_sum(const std::vector<int>& changes,
                     int low, int mid, int high)
{
    int left_sum = 0;
    int best_left_sum = changes[mid];

    for (int i = mid; i >= low; --i)
    {
        left_sum += changes[i];

        if (left_sum > best_left_sum)
        {
            best_left_sum = left_sum;
        }
    }

    int right_sum = 0;
    int best_right_sum = changes[mid + 1];

    for (int i = mid + 1; i <= high; ++i)
    {
        right_sum += changes[i];

        if (right_sum > best_right_sum)
        {
            best_right_sum = right_sum;
        }
    }

    return best_left_sum + best_right_sum;
}

int max_subarray_sum(const std::vector<int>& changes, int low, int high)
{
    if (low == high)
    {
        return changes[low];
    }

    int mid = low + (high - low) / 2;

    int left_best = max_subarray_sum(changes, low, mid);
    int right_best = max_subarray_sum(changes, mid + 1, high);
    int crossing_best = max_crossing_sum(changes, low, mid, high);

    int best = left_best;

    if (right_best > best)
    {
        best = right_best;
    }

    if (crossing_best > best)
    {
        best = crossing_best;
    }

    return best;
}

int maximum_return(const std::vector<int>& prices)
{
    if (prices.size() < 2) {
        throw std::invalid_argument("at least two prices are required");
    }

    std::vector<int> changes(prices.size() - 1);
    for (std::size_t i = 0; i < changes.size(); ++i) {
        changes[i] = prices[i + 1] - prices[i];
    }

    return max_subarray_sum(changes, 0, static_cast<int>(changes.size()) - 1);
}

void check(int actual, int expected, const std::string& label)
{
    std::cout << label << ": "
              << (actual == expected ? "PASS" : "FAIL")
              << " (expected " << expected << ", got " << actual << ")\n";
}

int main()
{
    check(maximum_return({100, 113, 110, 85, 105, 102, 86, 63, 81,
                          101, 94, 106, 101, 79, 94, 90, 97}),
          43,
          "crossing optimum");
    check(maximum_return({1, 2, 3, 4, 5}), 4, "increasing prices");
    check(maximum_return({9, 7, 4, 1}), -2, "decreasing prices");
        check(maximum_return({5, 8}), 3, "two prices");

    check(maximum_return({10, 8, 6, 4, 12}),
          8,
          "recovery after decline");

    return 0;
}
