// Sorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "Array_Sort.h"

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    int n = 0;
    std::cin >> n;
    assert(n > 0, "n数据范围错误");
    class Array_Sort *test = new Array_Sort(n);
    
    i64 time1 = test->Insertion_Sort();
    std::cout << time1 / 1000 << "s " << time1 % 1000 << "ms\n";
    
    i64 time2 = test->Bubble_Sort();
    std::cout << time2 / 1000 << "s " << time2 % 1000 << "ms\n";
    
    i64 time3 = test->Selection_Sort();
    std::cout << time3 / 1000 << "s " << time3 % 1000 << "ms\n";

    i64 time4 = test->Shell_Sort();
    std::cout << time4 / 1000 << "s " << time4 % 1000 << "ms\n";
    
    i64 time5 = test->Merge_Sort();
    std::cout << time5 / 1000 << "s " << time5 % 1000 << "ms\n";
    
    i64 time6 = test->Quick_Sort();
    std::cout << time6 / 1000 << "s " << time6 % 1000 << "ms\n";

    i64 time7 = test->Heap_Sort();
    std::cout << time7 / 1000 << "s " << time7 % 1000 << "ms\n";

    i64 time8 = test->Bin_Sort();
    std::cout << time8 / 1000 << "s " << time8 % 1000 << "ms\n";

    i64 time9 = test->Radix_Sort();
    std::cout << time9 / 1000 << "s " << time9 % 1000 << "ms\n";
    return 0;
}