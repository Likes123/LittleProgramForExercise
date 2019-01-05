#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

void MergeSort(vector<int> &arr,int begin,int end)
{
	if (begin == end || begin == end - 1)
		return;
	int mid =(begin + end) / 2;
	MergeSort(arr, begin, mid);
	MergeSort(arr, mid, end);
	vector<int> temp_vec;
	int i = begin, j = mid;
	while (i < mid&&j < end)
	{
		if (arr[i] < arr[j])
		{
			temp_vec.push_back(arr[i]);
			i++;
		}
		else if (arr[i] > arr[j])
		{
			temp_vec.push_back(arr[j]);
			j++;
		}
		else
		{
			temp_vec.push_back(arr[i]);
			temp_vec.push_back(arr[j]);
			i++;
			j++;
		}
	}
	if (i < mid)
		temp_vec.insert(temp_vec.end(), arr.begin() + i, arr.begin() + mid);
	else if (j < end)
		temp_vec.insert(temp_vec.end(), arr.begin() + j, arr.end());
	for (int n = 0; n < temp_vec.size(); n++)
		arr[begin + n] = temp_vec[n];

}

void Comparator(vector<int> &arr)
{
	sort(arr.begin(), arr.end());
}
void  GenerateRandomArray(vector<int>&arr, int max_size, int max_value)
{
	srand(time(NULL));
	for (int i = 0; i < max_size; i++)
	{
		arr.push_back(rand() % max_value);
	}
}

bool IsEqual(vector<int> &arr_mine, vector<int> &arr_stl)
{
	if (arr_mine.size() != arr_stl.size())
		return false;
	for (int i = 0; i < arr_stl.size(); i++)
	{
		if (arr_stl[i] != arr_mine[i])
			return false;
	}
	return true;
}

void PrintError(vector<int> &arr_src, vector<int> &arr_mine, vector<int> &arr_stl)
{
	cout << "source array" << endl;
	for (auto& n : arr_src)
		cout << n << ",";
	cout << endl;
	cout << "right array" << endl;
	for (auto& n : arr_stl)
		cout << n << ",";
	cout << endl;
	cout << "wrong array" << endl;
	for (auto& n : arr_mine)
		cout << n << ",";
	cout << endl;
}
int main()
{
	int test_time = 500000	;
	int max_size = 100;
	int max_value = 100;

	for (int i = 0; i < test_time; i++)
	{
		vector<int> arr1;
		GenerateRandomArray(arr1,max_size, max_value);
		
		vector<int> arr2(arr1.begin(), arr1.end());
		vector<int> arr3(arr1.begin(), arr1.end());

		MergeSort(arr2,0,arr2.size());
		Comparator(arr3);

		if (IsEqual(arr2, arr3) == false)
		{
			PrintError(arr1, arr2, arr3);
			return -1;
		}
	}
	cout << "success" << endl;
	return 0;
}
