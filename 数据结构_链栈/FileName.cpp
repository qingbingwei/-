#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
};
template<class T>
class m_stack
{
public:
	m_stack()
	{
		head = new Node<T>;
		if (head == nullptr)
		{
			cout << "开辟失败" << endl;
		}
		else
		{
			head->next = nullptr;
		}
	}
	void m_push(T k)
	{
		Node<T>* s = new Node<T>;
		s->data = k;
		s->next = head->next;
		head->next = s;
	}
	void m_pop()
	{
		if (head->next == nullptr)
		{
			cout << "栈空" << endl;
		}
		else
		{
			//p指向要删除首元节点
			Node<T>* p = head->next;
			head->next = p->next;
			delete p;
			p = nullptr;
		}
	}
	void get_top()
	{
		if (head->next == nullptr)
		{
			cout << "栈空" << endl;
		}
		else
		{
			cout << head->next->data << endl;
		}
	}
	bool empty()
	{
		if (head->next == nullptr)
			return true;
		else
			return false;
	}
public:
	Node<T>* head;
};
int main()
{
	m_stack<int> s;
	s.m_push(1);
	s.m_push(2);
	s.m_push(3);
	s.get_top();
	s.m_pop();
	s.get_top();
	return 0;
}