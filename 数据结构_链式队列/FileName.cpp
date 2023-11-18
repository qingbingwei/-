#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class q_node
{
public:
	T data;
	q_node<T>* next;
};
template<class T>
class Link_queue
{
public:
	Link_queue()
	{
		head = new q_node<T>;
		rear = head;
		if (head == nullptr)
		{
			cout << "开辟失败" << endl;
		}
		else
		{
			head->next = nullptr;
			rear->next = nullptr;
		}
	}
	void En_queue(T k)
	{
		q_node<T>* s = new q_node<T>;
		if (s == nullptr)
		{
			cout << "开辟失败" << endl;

		}
		else
		{
			s->data = k;
			s->next = nullptr; //新节点插入队尾
			rear->next = s;
			rear = s;
			cout << k << "入队" << endl;
		}
	}
	void Del_queue()
	{
		//出队时需要注意是否时首元节点出队
		T x(0);//保存出队元素
		//判空
		//1.head->next == nullptr
		//2.head == rear
		if (head->next == nullptr)
		{
			cout << "队空" << endl;
		}
		else
		{
			q_node<T>* p = head->next;
			x = p->data;
			head->next = head->next->next;
			if (head->next == nullptr)//删除唯一节点时避免队尾指针成为野指针
			{
				rear = head;
			}
			delete p;
			p = nullptr;
			cout << x << "出队" << endl;
		}
	}
	void m_empty()
	{
		if (head->next == nullptr)
		{
			cout << "队空" << endl;
		}
	}
public:
	q_node<T>* head;//指向头节点的指针
	q_node<T>* rear;//指向队尾元素所在节点的指针
};
int main()
{
	Link_queue<int> q;
	q.En_queue(3);
	q.En_queue(4);
	q.En_queue(5);
	q.En_queue(6);
	q.En_queue(7);
	q.En_queue(8);
	q.En_queue(9);
	q.Del_queue();
	return 0;
}