# C++ 课程作业

Repository URL: https://github.com/XiupingChen/homework-01-2026001406.git

这是我完成作业，按照要求，练习了二分查找、归并排序、最大连续子数组和以及矩阵类的实现。

## 文件说明

- `binary-search.cpp`：使用二分查找查找目标元素；
- `merge-sort.cpp`：使用递归和分治实现归并排序；
- `maximum-return.cpp`：使用最大子数组算法计算价格序列中的最大收益；
- `matrix/`：矩阵类的实现，包括矩阵加法、矩阵乘法和矩阵输出。

## 编译和运行

二分查找：

```bash
g++ -std=c++11 binary-search.cpp -o binary-search
./binary-search
```

归并排序：

```bash
g++ -std=c++11 merge-sort.cpp -o merge-sort
./merge-sort
```

最大收益：

```bash
g++ -std=c++11 maximum-return.cpp -o maximum-return
./maximum-return
```

矩阵类：

```bash
g++ -std=c++11 matrix/main.cpp matrix/matrix.cpp -o matrix-demo
./matrix-demo
```

所有程序均使用 C++11 编写，并保留了老师提供的测试，同时增加了自定义测试。运行结果均已通过。

## AI 工具说明

本次作业使用了 ChatGPT作为辅助工具，涉及 binary search、merge sort、maximum return 和 matrix class 四个部分。

AI 工具主要帮助我理解题目要求、梳理算法思路和检查代码。所有代码均由我在本地使用 C++11 编译并运行测试。
