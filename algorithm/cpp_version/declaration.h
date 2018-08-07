#include<vector>
#include <iostream>

//�����ǻ����������㷨������ʵ��λ��sort.cpp��
std::vector<int> MergeSort(std::vector<int>);//�鲢����

std::vector<int> InsertSort(std::vector<int>);//��������

std::vector<int> BubbleSort(std::vector<int>);//ð������

void QuickSort(std::vector<int>&,int,int);//��������

void QuickSortRandom(std::vector<int>&, int, int);//�����������

std::vector<int> ShellSort(std::vector<int>);//ϣ������

//0-1���������������������
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

//���������ѵķ�װ�������˶������㷨��ʵ��λ��heap.cpp��
class Heap;

//������Huffman��ķ�װ����Ա����������huffman�����㷨
class  Huffman;

//�����ǵ�λ���������������
struct Task
{
	int index;
	int d;
	int w;
	Task(int a,int b,int c):index(a),d(b),w(c){}
};

void taskSchedule(std::vector<Task>);

//�����Ǻ�����Ĳ������
void TestRBTree();

//������AVL���Ĳ������
void TestAVLTree();