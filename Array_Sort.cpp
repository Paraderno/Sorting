#include "Array_Sort.h"
#include "Get_Time.h"
void Array_Sort::Show()
{
	for (int i = 0; i < size; i++)
		std::cout << temp[i] << ' ';
	std::cout << '\n';
}

void Array_Sort::merge(int l, int r)
{
	if (r - l == 1) return;
	int mid = (l + r) >> 1;
	//����[l,mid)
	merge(l, mid);
	int* A = new int[mid - l];
	for (int i = l; i < mid; i++)
		A[i - l] = temp[i];

	//����[mid,r)
	merge(mid, r);
	int* B = new int[r - mid];
	for (int i = mid; i < r; i++)
		B[i - mid] = temp[i];

	//�ϲ�����
	int posA = 0, posB = 0, posT = l;
	while (posA < mid - l && posB < r - mid)
		A[posA] <= B[posB] ? temp[posT++] = A[posA++] : temp[posT++] = B[posB++];
	while (posA < mid - l) temp[posT++] = A[posA++];
	while (posB < r - mid) temp[posT++] = B[posB++];
	delete A;
	delete B;
}

void Array_Sort::quick(int l, int r)
{
	if (r - l <= 1) return;

	// Ѱ�� Pivot
	int pos = (l + r) >> 1, Pivot = 0;
	for (int i = l; i < r; i++)
	{
		if (temp[i] < temp[pos]) Pivot++;
		if (temp[i] == temp[pos] && i < pos) Pivot++;
	}

	// ����������
	int* A = new int[r - l];
	int Small = 0, Big = Pivot;
	A[Pivot] = temp[pos];
	for (int i = l; i < r; i++)
	{
		if (temp[i] < temp[pos]) A[Small++] = temp[i];
		if (temp[i] > temp[pos]) A[++Big] = temp[i];
		if (temp[i] == temp[pos])
		{
			if (i < pos) A[Small++] = temp[i];
			if (i > pos) A[++Big] = temp[i];
		}
	}
	
	for (int i = l; i < r; i++) temp[i] = A[i - l];
	delete A;
	// ����������
	quick(l, l + Pivot);
	quick(l + Pivot + 1, r);
}

Array_Sort::Array_Sort(int initsize)
{
	size = initsize;
	array = new int[size];
	temp =  new int[size];
	for (int i = 0; i < size; i++)
		std::cin >> array[i];
}

i64 Array_Sort::Insertion_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];	
	Get_Time_Of_Day(&Time_Begin);

	for (int i = 1; i < size; i++)// �ӵ�ǰλ�ÿ�ʼ
	{
		int l = 0, r = i;
		while (l < r)
		{
			int pos = (l + r + 1) >> 1;
			if (temp[pos - 1] <= temp[i]) l = pos;
			else r = pos - 1;//temp[pos-1]>temp[i]
		}// ʹ�ö��ֲ��Ҽ��ٱȽϴ���
		for (int j = i; j > l; j--)
			std::swap(temp[j], temp[j - 1]);
	}
	//�ȶ���
	
	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}

i64 Array_Sort::Bubble_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	for (int i = 0; i < size - 1; i++)//����ô���ð��
	{
		bool flag = false;//��¼��ǰ���ð����û�иı�
		for (int j = size - 1; j > i; j--)//ÿ��ð�ݵ���ֹ�±�
			if (temp[j - 1] > temp[j])
			{
				std::swap(temp[j - 1], temp[j]);
				flag = true;
			}
		if (!flag) break;
		//û������˳�����ı䣬����ð�ݡ�����ʱ�临�Ӷ�
	}
	//ԭ���������������Ÿ��Ӷ�Ϊ O(size)
	//�ȶ���

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}

i64 Array_Sort::Selection_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	for (int i = 0; i < size; i++)//��С����
	{
		int pos = i;
		for (int j = i + 1; j < size; j++)//ѡ��ʣ�������е���Сֵ
			if (temp[j] < temp[pos])
				pos = j;
		if (pos != i) std::swap(temp[i], temp[pos]);//���ٽ�������
	}
	//�ȶ���

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}

i64 Array_Sort::Shell_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	for (int k = size / 2; k; k >>= 1)//ÿ�μ�����һ��
	{
		for (int i = k; i < size; i++)//��������
			for (int j = i; j >= k; j -= k)
				if (temp[j - k] > temp[j])
					std::swap(temp[j - k], temp[j]);
	}
	//���ȶ���

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}

i64 Array_Sort::Merge_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	merge(0, size);
	//�ȶ���

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}


i64 Array_Sort::Quick_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	quick(0, size);
	//�ȶ���

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}

i64 Array_Sort::Heap_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for (int i = 0; i < size; i++) q.push(temp[i]);
	for (int i = 0; i < size; i++) temp[i] = q.top(), q.pop();

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}

i64 Array_Sort::Bin_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	// �ҵ�����Ȩֵ
	int max = 0;
	for (int i = 0; i < size; i++) max = std::max( max, temp[i]);

	std::vector<std::vector<int>> Bin(max + 1);
	for (int i = 0; i < size; i++) Bin[temp[i]].push_back(temp[i]);

	int index = 0;
	for (auto item : Bin)
		for (auto x : item)
			temp[index++] = x;

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}

i64 Array_Sort::Radix_Sort()
{
	for (int i = 0; i < size; i++) temp[i] = array[i];
	Get_Time_Of_Day(&Time_Begin);

	// �ҵ�����Ȩֵ
	int max = 0;
	for (int i = 0; i < size; i++) max = std::max(max, temp[i]);

	int k = 1;
	/*while (k * 10 <= max) k *= 10;*/
	while (k <= max)
	{
		std::vector<std::vector<int>> Bin(10);
		for (int i = 0; i < size; i++) Bin[(temp[i] / k) % 10].push_back(temp[i]);
		int index = 0;
		for (auto item : Bin)
			for (auto x : item)
				temp[index++] = x;
		k *= 10;
	}

	Get_Time_Of_Day(&Time_End);
	//Show();
	i64 time = (Time_End.Second * 1000 + Time_End.Millisecond) - (Time_Begin.Second * 1000 + Time_Begin.Millisecond);
	return time;
}
