
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

void HeapInsert(vector<int>&arr,int index)
{
	for (; index >= 0; )
	{
		int parent_index = (index - 1) / 2;
		if (arr[index] > arr[parent_index])
			swap(arr[index], arr[parent_index]);
		else
			break;
		index = (index - 1) / 2;
	}
}

void Heapify(vector<int>&arr, int index)
{
	for (int i = 0; i < index;)
	{
		int large = -1;
		if (i * 2 + 2 < index)
		{
			large = arr[i * 2 + 2] >= arr[i * 2 + 1] ? i * 2 + 2 : i * 2 + 1;
		}
		else if (i * 2 + 1 < index)
			large = i * 2 + 1;
		else
			break;
		if (arr[i] < arr[large])
		{
			swap(arr[i], arr[large]);
			//HeapInsert(arr, i);
			i = large;
		}
		else
			break;
		//for (auto n : arr)
		//	cout << n << ",";
		//cout << endl;
	}
}

void HeapSort(vector<int> &arr)
{
	if (arr.size() == 0 || arr.size() == 1)
		return ;
	for (int i = 1; i < arr.size(); i++)
		HeapInsert(arr, i);

	for (int i = arr.size() - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i);
	}
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
	int test_time = 50000;
	int max_size = 100;
	int max_value = 100;

	for (int i = 0; i < test_time; i++)
	{
		vector<int> arr1;
		//82,90,98,38,53,99,78,15,7, error
		GenerateRandomArray(arr1, max_size, max_value);

		vector<int> arr2(arr1.begin(), arr1.end());
		vector<int> arr3(arr1.begin(), arr1.end());

		HeapSort(arr2);
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
