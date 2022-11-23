#pragma once
class Array_Sort
{
private:
	int* array;
	int size;

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
	 * \return ����ʱ��
	 */
	double Insertion_Sort();

	/**
	 * ð������.
	 * 
	 * \return ����ʱ��
	 */
	double Bubble_Sort();

	/**
	 * ѡ������.
	 * 
	 * \return ����ʱ��
	 */
	double Selection_Sort();

	/**
	 * ϣ������.
	 * 
	 * \return ����ʱ��
	 */
	double Shell_Sort();

	/**
	 * �鲢����.
	 * 
	 * \return ����ʱ��
	 */
	double Merge_Sort();

	/**
	 * ��������.
	 * 
	 * \return ����ʱ��
	 */
	double Quick_Sort();

	/**
	 * ������.
	 * 
	 * \return ����ʱ��
	 */
	double Heap_Sort();

	/**
	 * ������.
	 * 
	 * \return ����ʱ��
	 */
	double Bin_Sort();

	/**
	 * ��������.
	 * 
	 * \return ����ʱ��
	 */
	double Radix_Sort();

};