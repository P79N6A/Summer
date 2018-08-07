#include <iostream>
#include <vector>

using namespace std;

//ц╟ещеепР
vector<int> BubbleSort(vector<int> arr)
{
	for (auto i = 0; i != arr.size()-1; ++i)
	{
		for (auto j = 0; j <= arr.size()-2-i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return arr;
}