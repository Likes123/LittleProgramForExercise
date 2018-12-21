/*
** EPITECH PROJECT, 2018
** threadPool2
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include "SynQue.h"
#include <functional>
#include <thread>
#include <vector>
#include <memory>
using Task = std::function<void()>;
namespace std
{
class ThreadPool
{

  public:
    ThreadPool() : threads_num_(10) { Init(); }
    ThreadPool(size_t n) : threads_num_(n) { Init(); }
    void PutTask(Task task);
    ~ThreadPool();

  private:
    void RunTask();
    void Init();
    size_t threads_num_;
    SynQue<Task> que_;
    vector<shared_ptr<thread>> threads_;
};
void ThreadPool::PutTask(Task task)
{
    que_.Put(task);
}
void ThreadPool::RunTask()
{
    while (1)
    {
        Task task;
        que_.Get(task);
        task();
    }
}
void ThreadPool::Init()
{
    for (int i = 0; i < threads_num_; i++)
    {
        auto ptr_t = make_shared<thread>([this]() -> void {
            RunTask();
        });
        threads_.push_back(ptr_t);
    }
}
ThreadPool::~ThreadPool()
{
    for (auto &ptr : threads_)
    {
        ptr->join();
    }
}
}; // namespace std

#endif /* !THREADPOOL_H_ */
