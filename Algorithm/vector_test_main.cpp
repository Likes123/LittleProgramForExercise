#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "MergeSort.h"
using namespace std;
uint64_t run_times = 300000;
uint64_t vec_size = 100;
int64_t vec_max = 60;
int64_t vec_min = -60;
int main()
{
	vector<int> vec(vec_size, 0);
	vector<int> vec1(vec.begin(), vec.end());
	vector<int> vec2(vec.begin(), vec.end());
	srand(time(NULL));

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
		solution.MergeSort(vec2.begin(), vec2.begin() + size);
		///////////////////////////////////
		for (int i = 0; i < size; i++)
		{
			if (vec1[i] != vec2[i])
			{
				cout << "vector size is "<<size<<",error in " << i << "th elem" << endl;
				cout << "source vector " << endl;
				for (int j=0;j<size;j++)
					cout <<vec[j]<< ",";
				cout << endl << "right vector" << endl;
				for (int j=0; j < size; j++)
					cout << vec1[j] << ",";
				cout << endl << "wrong vector" << endl;
				for (int j=0; j < size; j++)
					cout << vec2[j] << ",";
				cout << endl;
				return 0;
			}
		}
	}
	cout << "success" << endl;


	return 0;
}