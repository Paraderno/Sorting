#pragma once
class Array_Sort
{
private:
	int* array;
	int size;

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
	 * \return 花费时间
	 */
	double Insertion_Sort();

	/**
	 * 冒泡排序.
	 * 
	 * \return 花费时间
	 */
	double Bubble_Sort();

	/**
	 * 选择排序.
	 * 
	 * \return 花费时间
	 */
	double Selection_Sort();

	/**
	 * 希尔排序.
	 * 
	 * \return 花费时间
	 */
	double Shell_Sort();

	/**
	 * 归并排序.
	 * 
	 * \return 花费时间
	 */
	double Merge_Sort();

	/**
	 * 快速排序.
	 * 
	 * \return 花费时间
	 */
	double Quick_Sort();

	/**
	 * 堆排序.
	 * 
	 * \return 花费时间
	 */
	double Heap_Sort();

	/**
	 * 堆排序.
	 * 
	 * \return 花费时间
	 */
	double Bin_Sort();

	/**
	 * 基数排序.
	 * 
	 * \return 花费时间
	 */
	double Radix_Sort();

};