
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int temp = 0;
void QuickSort(vector<int> &arr,int begin,int end)
{
	if (begin == end || begin + 1 == end)
		return;
	temp = arr[begin];
	int i = begin+1, j = end - 1;
	while(i<j)
	{
		if (arr[i] > temp&&arr[j] <= temp)
		{
			swap(arr[i], arr[j]);
			i++; j--;
		}
		else if (arr[i] > temp&&arr[j] > temp)
			j--;
		else if (arr[i] <= temp && arr[j] < temp)
			i++;
		else
		{
			i++;
			j--;
		}
	}
	int start = 0;
	if (temp >= arr[i])
	{
		swap(arr[begin], arr[i]);
		start = i + 1;
	}
	else
	{
		swap(arr[begin], arr[i - 1]);
		start = i;
	}
	QuickSort(arr, begin, start-1);
	QuickSort(arr, start, end);
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
	int test_time = 5000;
	int max_size = 100;
	int max_value = 100;

	for (int i = 0; i < test_time; i++)
	{
		vector<int> arr1;
		GenerateRandomArray(arr1, max_size, max_value);

		vector<int> arr2(arr1.begin(), arr1.end());
		//vector<int> arr2{3,5,2,7};
		vector<int> arr3(arr1.begin(), arr1.end());

		QuickSort(arr2,0,arr2.size());
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
