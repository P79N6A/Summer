#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "declaration.h"

using namespace std;

//动态规划方法求解0-1背包问题
_0_1SolutionDP _0_1Package(std::vector<int>weight, std::vector<int> worth, int total)
{
	vector<vector<_0_1SolutionDP>> cache(weight.size());
	for (auto &a : cache)
	{
		for (int i = 0; i <= total; ++i) 
		{
			_0_1SolutionDP tmp;
			tmp.total = -1;
			a.push_back(tmp);
		}
	}

	for (int i = 0; i != weight.size(); ++i)
	{
		for (int j = 1; j <= total; ++j)
		{
			if (i == 0) 
			{
				if (weight[0]<=j)
				{
					cache[i][j].weight.push_back(weight[i]);
					cache[i][j].worth.push_back(worth[i]);
					cache[i][j].total = worth[0];
				}
				else {
					cache[i][j].total = 0;
				}
			}
			else 
			{
				int tmp1;
				if (j - weight[i] < 0) {
					tmp1 = 0;
				}
				else {
					tmp1 = cache[i - 1][j - weight[i]].total + worth[i];
				}
				
				int tmp2 = cache[i - 1][j].total;
				if (tmp1 > tmp2)
				{
					cache[i][j] = cache[i - 1][j - weight[i]];
					cache[i][j].weight.push_back(weight[i]);
					cache[i][j].worth.push_back(worth[i]);
					cache[i][j].total = tmp1;
				}
				else {
					cache[i][j] = cache[i - 1][j];
				}
			}

		}
	}
	return cache[worth.size()-1][total];
}

//贪心算法的中间结构（三元组）
struct greedyTuple
{
	float average;
	int weight;
	int worth;
};

//使用排序泛型算法时的比较函数函数
bool Less(const greedyTuple &a , const greedyTuple &b) 
{
	if (a.average > b.average) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//贪心算法求解分数背包问题
PackageSolutionGreedy PackageGreedy(std::vector<int>weight, std::vector<int> worth, int total)
{
	PackageSolutionGreedy solution;
	solution.sum_weight = 0;
	solution.sum_worth = 0;
	list<greedyTuple> mylist;
	for (int i = 0; i != weight.size(); ++i) 
	{
		greedyTuple tmp;
		tmp.weight = weight[i];
		tmp.worth = worth[i];
		tmp.average = ((float)worth[i]) / (float)(weight[i]);
		mylist.push_back(tmp);
	}
	stable_sort(mylist.begin(),mylist.end(),Less);
	while ((solution.sum_weight < total) && (mylist.empty() == false))
	{
		if ((solution.sum_weight + mylist.begin()->weight) <= total)
		{
			//当加上一整个物品还未超过
			solution.sum_weight += mylist.begin()->weight;
			solution.sum_worth += mylist.begin()->worth;
			solution.total_weight.push_back(mylist.begin()->weight);
			solution.true_weight.push_back(mylist.begin()->weight);
			solution.worth.push_back(mylist.begin()->worth);
			mylist.pop_front();
		}
		else if ((solution.sum_weight + mylist.begin()->weight) > total)
		{
			//此时只能加上一个分数背包
			float delta = ((float)total - solution.sum_weight) / mylist.begin()->weight;
			solution.sum_weight += mylist.begin()->weight*delta;
			solution.sum_worth += mylist.begin()->worth*delta;
			solution.total_weight.push_back(mylist.begin()->weight);
			solution.true_weight.push_back(mylist.begin()->weight*delta);
			solution.worth.push_back(mylist.begin()->worth);
			mylist.begin()->weight = mylist.begin()->weight*(1-delta);
			mylist.begin()->worth = mylist.begin()->worth*(1 - delta);
		}
	}
	return solution;
}