#include <vector>
#include <algorithm>
#include "declaration.h"
using namespace std;

bool sort_seed(Task a, Task b)
{
	if (a.w > b.w)
	{
		return true;
	}
	return false;
}

void show(vector<Task> task) 
{
	for (auto a : task)
	{
		cout << "id:" << a.index << "  ";
		cout << "d:" << a.d << "  ";
		cout << "w:" << a.w << endl;
	}
}

void taskSchedule(vector<Task> task)
{
	int sum_w = 0;
	int max_d = task[0].d;
	cout<<"当前任务序列："<<endl;
	show(task);
	for (auto a : task)
	{
		sum_w+= a.w;
		if (max_d < a.d) 
		{
			max_d = a.d;
		}
	}
	stable_sort(task.begin(),task.end(),sort_seed);
	
	vector<Task> early;
	vector<Task> late;
	vector<bool> flag(max_d+1,false);
	for (auto a : task)
	{
		for (int i = a.d; i >= 0; --i)
		{
			if ((i>0)&&(flag[i] == false))
			{
				sum_w -= a.w;
				early.push_back(a);
				flag[i] = true;
				break;
			}
			else if(i==0)
			{
				late.push_back(a);
			}
		}
	}
	cout << "提前任务序列：" << endl;
	show(early);
	cout << "推迟任务序列：" << endl;
	show(late);
	cout << "总惩罚：" <<sum_w<< endl;
}