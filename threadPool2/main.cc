#include "ThreadPool.h"
#include <iostream>
#include <mutex>
using namespace std;
mutex mutex_cout;
int main()
{
    Task t1 = []() -> void { 
        lock_guard<mutex> lock(mutex_cout);
        cout << "adf" << endl; };
    Task t2 = []() -> void { 
         lock_guard<mutex> lock(mutex_cout);
        cout << "laili" << endl; };
    Task t3 = []() -> void { 
        lock_guard<mutex> lock(mutex_cout);
     cout << "hello" << endl; };

    ThreadPool pool;
    for (int i = 0; i < 10; i++)
    {
        pool.PutTask(t1);
        pool.PutTask(t2);
        pool.PutTask(t3);
    }

    return 0;
}