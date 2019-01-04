#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
	void MergeSort(vector<int> &vec, int begin, int end)
	{
		if (end - begin <= 2)
			return;
		size_t mid = begin + end - begin / 2;
		MergeSort(vec, begin, mid);
		MergeSort(vec, mid, end);
		vector<int> temp;
		int i = begin, j = mid;
		while (i < mid && j < end)
		{
			if (vec[i] < vec[j])
			{
				temp.push_back(vec[i]);
				i++;
			}
			else if (vec[i] > vec[j])
			{
				temp.push_back(vec[j]);
				j++;
			}
			else
			{
				temp.push_back(vec[i]);
				temp.push_back(vec[j]);
				i++;
				j++;
			}
		}
		if (i < mid)
			temp.insert(temp.end(), vec.begin() + i, vec.begin() + mid);
		else if (j < end)
			temp.insert(temp.end(), vec.begin() + j, vec.begin());
	}
};

#endif /* !MERGESORT_H_ */
