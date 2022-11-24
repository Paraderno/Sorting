#pragma once
#include <bits/stdc++.h>
using i64 = long long;
class Array_Sort
{
private:
	int* array; //ԭʼ����
	int* temp; //�������������
	int size; //�����С

	/**
	 * �������������.
	 *
	 */
	void Show();

	/**
	 * �鲢����ĵݹ麯������������[l,r)
	 * 
	 * \param l ���
	 * \param r �ҿ�
	 */
	void merge(int l, int r);

	/**
	 * ��������Ĺ鲢��������������[l,r).
	 * 
	 * \param l ���
	 * \param r �ҿ�
	 */
	void quick(int l, int r);

public:
	/**
	 * ��ʼ������.
	 * 
	 * \param initsize ���鳤��
	 */
	Array_Sort(int initsize);

	/**
	 * ��������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Insertion_Sort();

	/**
	 * ð������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Bubble_Sort();

	/**
	 * ѡ������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Selection_Sort();

	/**
	 * ϣ������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Shell_Sort();

	/**
	 * �鲢����.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Merge_Sort();

	/**
	 * ��������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Quick_Sort();

	/**
	 * ������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Heap_Sort();

	/**
	 * ������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Bin_Sort();

	/**
	 * ��������.
	 * 
	 * \return ����ʱ�䣨��λms��
	 */
	i64 Radix_Sort();

};