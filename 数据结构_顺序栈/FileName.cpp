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
			cerr << "����ʧ��" << endl;
		}
		top = -1;//��ʼ��ջ��ָ��
	}
	void m_push(T k)
	{
		if (this->top == this->size - 1)
		{
			cout << "ջ��" << endl;
		}
		else
		{
			this->top++;
			this->data[top] = k;
			//��top��ʼֵΪ0
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
			cout << "ջ��" << endl;
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
			cout << "ջ��" << endl;
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
	T* data; //ָ��ģ������
	int top; //ջ��ָ�루��˳��ջ�в����ϸ�������ָ�룩
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