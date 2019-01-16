#include <stack>
#include <iostream>
using namespace std;
template<typename T>
class MyStack
{
public:
	void pop()
	{
		s.pop();
		s_min.pop();
	}
	void push(T data)
	{
		if (s.size() == 0)
		{
			s.push(data);
			s_min.push(data);
			min = data;
		}
		else
		{
			s.push(data);
			if (data < min)
			{
				min = data;
				s_min.push(data);
			}
			else
				s_min.push(min);
		}
	}
	T getMin()
	{
		return s_min.top();
	}
	T get()
	{
		return s.top();
	}
private:
	T min;
	stack<T> s;
	stack<T> s_min;
};


int main()
{
	MyStack<int> s;
	s.push(6);
	s.push(5);
	s.push(7);
	s.push(4);
	cout << "top " << s.get() << endl;
	cout << "min " << s.getMin() << endl;
	s.pop();
	cout << "top " << s.get() << endl;
	cout << "min " << s.getMin() << endl;
	s.pop();
	cout << "top " << s.get() << endl;
	cout << "min " << s.getMin() << endl;
	return 0;
}
