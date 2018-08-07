#include "declaration.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
void aboutMe()
{
	cout<<"*******************************************************************"<<endl;
	cout<<"������"<<"ʢ����"<<"    ";
	cout << "�༶��" << "����3��" << "    ";
	cout << "ѧ�ţ�" << "SA16225249" << endl;
	cout << "*******************************************************************" << endl;
}

template<typename T>
void print_array(std::vector<T> arr) //��ӡ��������
{ 
	for (auto i = 0; i != arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl; 
}

void TestBubbleSort()
{
	std::vector<int> a = { 1,9,2,8,3,7,4,6,5,11,13,15,17,19,20,18,16,14,12,10 };
	std::cout << "Old Array : ";
	print_array(a);
	a = BubbleSort(a);
	std::cout << "New Array : ";
	print_array(a);
}

void TestInsertSort()
{
	std::vector<int> a = { 1,9,2,8,3,7,4,6,5,11,13,15,17,19,20,18,16,14,12,10 };
	std::cout << "Old Array : ";
	print_array(a);
	a = InsertSort(a);
	std::cout << "New Array : ";
	print_array(a);
}

//�����������ȷ�Բ���
void TestQuickSort()
{
	std::vector<int> a = { 1,9,2,8,3,7,4,6,5,11,13,15,17,19,20,18,16,14,12,10 };
	std::cout << "Old Array : ";
	print_array(a);
	QuickSort(a,0,a.size()-1);
	std::cout << "New Array : ";
	print_array(a);
}
//���������㷨�Ĵ������ݲ���
void TestQuickSortBigdata();

//������汾�Ŀ����������ȷ�Բ���
void TestQuickSortRandom()
{
	std::vector<int> a = { 1,9,2,8,3,7,4,6,5,11,13,15,17,19,20,18,16,14,12,10 };
	std::cout << "Old Array : ";
	print_array(a);
	QuickSortRandom(a, 0, a.size() - 1);
	std::cout << "New Array : ";
	print_array(a);
}

//������汾�Ŀ��������㷨�Ĵ������ݲ���
void TestQuickSortRandomBigdata();

//0-1��������Ķ�̬�滮�ⷨ����
void Test01PackageDP()
{
	std::vector<int> weight = { 2,2,6,5,4 };
	std::vector<int> worth = { 6,3,5,4,6 };
	int total = 10;
	std::cout<<"Select less than "<<total<<std::endl;
	std::cout << "Object Weight: ";
	print_array(weight);
	std::cout << "Object Worth: ";
	print_array(worth);
	_0_1SolutionDP ans = _0_1Package(weight,worth,total);
	std::cout << "Max : "<<ans.total<<std::endl;
	std::cout << "Selected Weight: ";
	print_array(ans.weight);
	std::cout << "Selected Worth: ";
	print_array(ans.worth);
}

//�������������̰�Ľⷨ����
void TestPackageGreedy()
{
	std::vector<int> weight = { 2,2,6,5,4 };
	std::vector<int> worth = { 6,3,5,4,6 };
	int total = 10;
	std::cout << "Select less than " << total << std::endl;
	std::cout << "Object Weight: ";
	print_array(weight);
	std::cout << "Object Worth: ";
	print_array(worth);
	PackageSolutionGreedy ans = PackageGreedy(weight, worth, total);
	std::cout << "Max Weight: " << ans.sum_weight << std::endl;
	std::cout << "Max Worth: " << ans.sum_worth << std::endl;
	std::cout << "Selected Weight_total: ";
	print_array(ans.total_weight);
	std::cout << "Selected Weight_true: ";
	print_array(ans.true_weight);
	std::cout << "Selected Worth: ";
	print_array(ans.worth);
}

/*��λʱ�������������Ĳ���
��������ѡ�ÿα��ϵģ�
��6��10������4��20������1��30������3��40������4��50������2��60������4��70��
Ԥ�ڽ��Ϊ��50
�ӳ����񣺣�4��20������1��30��������������ǰ����
*/

void TestTaskSchedule() 
{
	int n;
	cout << "��������";
	cin >> n;
	vector<Task> task;
	cout<<"��������ÿ�������d,w ��"<<std::endl;
	for (int i=0;i!=n;++i) 
	{
		int d, w;
		cin >> d >> w;
		task.push_back(Task(i+1,d,w));
	}
	taskSchedule(task);
	cout<<"***********************��Ϲ�۵ķָ���*******************"<<std::endl;
	cout << "��wi�޸�Ϊmax-wi ��" << std::endl;
	int max = task[0].w;
	for (int i = 0; i != task.size(); ++i) 
	{
		if (task[i].w > max) 
		{
			max = task[i].w;
		}
	}
	for (int i = 0; i != task.size(); ++i)
	{
		task[i].w = max - task[i].w;
	}
	taskSchedule(task);
}

int main()
{
	aboutMe();
	//TestQuickSort();
	//TestQuickSortRandom();
	//Test01PackageDP();
	//TestPackageGreedy();
	//TestTaskSchedule();
	//TestRBTree();
	TestAVLTree();
}