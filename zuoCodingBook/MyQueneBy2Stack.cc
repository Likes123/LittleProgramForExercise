#include <iostream>
#include <stack>
using namespace std;
template<typename T>
class MyQueue
{
public:

	void push(T data)
	{
		if (is_2 == true)
		{
			exchange(s1, s2);
			is_2 = false;
		}
		s1.push(data);
	}
	void pop()
	{
		if (is_2 == false)
		{
			exchange(s2,s1);
			is_2 = true;
		}
		s2.pop();
	}
	T get()
	{
		if (is_2 == false)
		{
			exchange(s2,s1);
			is_2 = true;
		}
		return s2.top();
	}
private:
	void exchange(stack<T>& a,stack<T>& b)
	{
		while (b.size() != 0)
		{
			a.push(b.top());
			b.pop();
		}
	}
	bool is_2=false;
	stack<T> s1;
	stack<T> s2;
};
int main()
{
	MyQueue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);


	cout<<q.get()<<",";
	q.pop();
	cout << q.get() << ",";
	q.pop();
	cout << q.get() << ",";
	q.pop();
	cout << q.get() << ","<<endl;
	q.push(9);
	cout << q.get() << ",";
	return 0;
}
