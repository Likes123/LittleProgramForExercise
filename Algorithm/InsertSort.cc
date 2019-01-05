
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
/*插入排序虽然简单，但是在排序数量很少时有工程级的运用，
 *应该熟练掌握。其运行模型有点类似于插扑克牌，最外层的循
 *环角标应该是应该是当前应该插入的扑克牌
*/
void InsertSort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j=i;j>0;j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
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
	int test_time = 50;
	int max_size = 100;
	int max_value = 100;

	for (int i = 0; i < test_time; i++)
	{
		vector<int> arr1;
		GenerateRandomArray(arr1, max_size, max_value);

		vector<int> arr2(arr1.begin(), arr1.end());
		vector<int> arr3(arr1.begin(), arr1.end());

		InsertSort(arr2);
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
