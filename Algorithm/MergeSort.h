#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	void MergeSort(vector<int>::iterator begin,vector<int>::iterator end)
	{
		sort(begin, end);
		*begin = 9;
	}
};
