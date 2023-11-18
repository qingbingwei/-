#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class m_stack
{
public:
	m_stack(int n)
	{
		size = n;
		data = new T[n];
		if (data == nullptr)
		{
			cerr << "开辟失败" << endl;
		}
		top = -1;//初始化栈顶指针
	}
	void m_push(T k)
	{
		if (this->top == this->size - 1)
		{
			cout << "栈满" << endl;
		}
		else
		{
			this->top++;
			this->data[top] = k;
			//若top初始值为0
			/*
			*if(s.top == s.size)
			{

			}
			else
			{
			s.data[top] = k;
			top++;
			}
			*/
		}
	}
	void m_pop()
	{
		if (this->top == -1)
		{
			cout << "栈空" << endl;
		}
		else
		{
			this->top--;
		}
	}
	void get_top()
	{
		if (this->top == -1)
		{
			cout << "栈空" << endl;
		}
		else
		{
			cout << this->data[top] << endl;
		}
	}
	bool empty()
	{
		if (this->top == -1)
			return true;
		else
			return false;
	}
	bool full()
	{
		if (this->top == size - 1)
			return true;
		else
			return false;
	}
public:
	T* data; //指针模拟数组
	int top; //栈顶指针（该顺序栈中并非严格意义上指针）
	int size;
};

int main()
{
	m_stack<int> s(10);
	s.m_push(1);
	s.m_push(2);
	s.m_push(3);
	s.get_top();
	s.m_pop();
	s.get_top();
	return 0;
}