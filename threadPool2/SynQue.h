#include <mutex>
#include <condition_variable>
#include <list>
namespace std
{
template <typename T>
class SynQue
{
  public:
    SynQue() : task_full_num_(10) {}
    SynQue(size_t n) : task_full_num_(n) {}
    void Put(T &t);
    void Get(T &t);

  private:
    size_t task_full_num_;
    std::list<T> task_list_;
    std::mutex mux_;
    std::condition_variable not_full;
    std::condition_variable not_empty;
};

template <typename T>
void SynQue<T>::Put(T &t)
{
    unique_lock<mutex> lock(mux_);
    while (task_list_.size() == task_full_num_)
    {
        not_full.wait(lock);
    }
    task_list_.push_back(t);
    not_empty.notify_one();
}

template <typename T>
void SynQue<T>::Get(T &t)
{
    unique_lock<mutex> lock(mux_);
    while (task_list_.empty() == true)
    {
        not_empty.wait(lock);
    }
    t = task_list_.front();
    task_list_.pop_front();
    not_full.notify_one();
}

}; // namespace std
