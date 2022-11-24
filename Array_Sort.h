#pragma once
#include <bits/stdc++.h>
using i64 = long long;
class Array_Sort
{
private:
	int* array; //原始数组
	int* temp; //用于排序的数组
	int size; //数组大小

	/**
	 * 输出排序后的数组.
	 *
	 */
	void Show();

	/**
	 * 归并排序的递归函数，排序区间[l,r)
	 * 
	 * \param l 左闭
	 * \param r 右开
	 */
	void merge(int l, int r);

	/**
	 * 快速排序的归并函数，排序区间[l,r).
	 * 
	 * \param l 左闭
	 * \param r 右开
	 */
	void quick(int l, int r);

public:
	/**
	 * 初始化数组.
	 * 
	 * \param initsize 数组长度
	 */
	Array_Sort(int initsize);

	/**
	 * 插入排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Insertion_Sort();

	/**
	 * 冒泡排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Bubble_Sort();

	/**
	 * 选择排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Selection_Sort();

	/**
	 * 希尔排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Shell_Sort();

	/**
	 * 归并排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Merge_Sort();

	/**
	 * 快速排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Quick_Sort();

	/**
	 * 堆排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Heap_Sort();

	/**
	 * 堆排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Bin_Sort();

	/**
	 * 基数排序.
	 * 
	 * \return 花费时间（单位ms）
	 */
	i64 Radix_Sort();

};