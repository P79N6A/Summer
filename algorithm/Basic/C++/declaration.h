#include<vector>
#include <iostream>

//以下是基本的排序算法，具体实现位于sort.cpp中
std::vector<int> MergeSort(std::vector<int>);//归并排序

std::vector<int> InsertSort(std::vector<int>);//插入排序

std::vector<int> BubbleSort(std::vector<int>);//冒泡排序

void QuickSort(std::vector<int>&,int,int);//快速排序

void QuickSortRandom(std::vector<int>&, int, int);//快速排序随机

std::vector<int> ShellSort(std::vector<int>);//希尔排序

//0-1背包问题与分数背包问题
struct _0_1SolutionDP
{
	int total;
	std::vector<int> weight;
	std::vector<int> worth;
};

struct PackageSolutionGreedy
{
	float sum_weight;
	float sum_worth;
	std::vector<int> total_weight;
	std::vector<int> worth;
	std::vector<float> true_weight;
};

_0_1SolutionDP _0_1Package(std::vector<int>, std::vector<int>, int);

PackageSolutionGreedy PackageGreedy(std::vector<int>, std::vector<int>, int);

//以下是最大堆的封装，包含了堆排序算法，实现位于heap.cpp中
class Heap;

//以下是Huffman类的封装，成员函数包含了huffman编码算法
class  Huffman;

//以下是单位任务调度问题的求解
struct Task
{
	int index;
	int d;
	int w;
	Task(int a,int b,int c):index(a),d(b),w(c){}
};

void taskSchedule(std::vector<Task>);

//以下是红黑树的测试入口
void TestRBTree();

//以下是AVL树的测试入口
void TestAVLTree();