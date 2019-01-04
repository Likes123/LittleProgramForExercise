#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
uint64_t run_times = 30000;
uint64_t vec_size = 100;
int64_t vec_max = 60;
int64_t vec_min = -60;

class Solution
{
public:
	void MergeSort(vector<int> &vec, int begin, int end)
	{
		if (end - begin < 2)
			return;
		size_t mid = begin + (end - begin) / 2;
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
			temp.insert(temp.end(), vec.begin() + j, vec.end());
		for (int n=begin,m=0;n<end;n++,m++)
		{
			vec[n] = temp[m];
		}
	}
};

int main()
{
	vector<int> vec(vec_size, 0);
	vector<int> vec1(vec.begin(), vec.end());
	vector<int> vec2(vec.begin(), vec.end());
	srand(time(NULL));

	//Solution solution1;
	//vector<int> test_vec{ 34,-10,-56,36,4,5,7,23,46 };
	//solution1.MergeSort(test_vec, 0, test_vec.size());
	//for (auto n : test_vec)
	//	cout << n << ",";

	auto n = vec_max - vec_min;
	for (int t = 0; t < run_times; t++)
	{
		auto size = (rand() % vec_size);
		for (int i = 0; i < size; i++)
			vec[i] = (rand() % n) + vec_min;
		vec1 = vec;
		vec2 = vec;
		sort(vec1.begin(), vec1.begin() + size);
		///////////////////////////////////
		Solution solution;
		//vector<int> test_vec{ 34,-10,-56,36,4,5,7,23,46 };
		//solution.MergeSort(test_vec, 0, test_vec.size());
		//for (auto n : test_vec)
		//	cout << n << ",";
		solution.MergeSort(vec2, 0,size);
		///////////////////////////////////
		for (int i = 0; i < size; i++)
		{
			if (vec1[i] != vec2[i])
			{
				cout << "vector size is " << size << ",error in " << i << "th elem" << endl;
				cout << "source vector " << endl;
				for (int j = 0; j < size; j++)
					cout << vec[j] << ",";
				cout << endl
					<< "right vector" << endl;
				for (int j = 0; j < size; j++)
					cout << vec1[j] << ",";
				cout << endl
					<< "wrong vector" << endl;
				for (int j = 0; j < size; j++)
					cout << vec2[j] << ",";
				cout << endl;
				return 0;
			}
		}
	}
	cout << "success" << endl;

	return 0;
}
