#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

//返回一个随机数
int getRandom(int min,int max)
{
	default_random_engine e;
	uniform_int_distribution<int> d(min,max);
	e.seed(time(0));
	return d(e);
}

//快速排序的划分过程
int Partition(vector<int> &arr, int begin, int end)
{
	if (begin >= end)
	{
		return begin;
	}
	int flag = arr[end];
	int less = begin - 1;
	int more = end - 1;
	while (less < more)
	{
		if (arr[less + 1] <= flag)
		{
			less++;
		}
		else if (arr[less + 1] > flag)
		{
			int tmp = arr[less + 1];
			arr[less + 1] = arr[more];
			arr[more] = tmp;
			more--;
		}
	}
	int tmp = arr[less + 1];
	arr[less + 1] = flag;
	arr[end] = tmp;
	return less + 1;
}
//快速排序
void QuickSort(vector<int> &arr,int begin,int end)
{
	if (begin >= end) 
	{
		return;
	}
	int a = Partition(arr,begin,end);
	QuickSort(arr,begin,a-1);
	QuickSort(arr,a+1,end);
}

//快速排序随机化
void QuickSortRandom(vector<int> &arr,int begin,int end)
{
	if (begin >= end)
	{
		return;
	}
	int index = getRandom(begin,end);
	int tmp = arr[index];
	arr[index] = arr[end];
	arr[end] = tmp;
	if (begin >= end)
	{
		return;
	}
	int a = Partition(arr, begin, end);
	QuickSortRandom(arr, begin, a - 1);
	QuickSortRandom(arr, a + 1, end);
}