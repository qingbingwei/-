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
			cout << "����ʧ��" << endl;
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
			cout << "����ʧ��" << endl;

		}
		else
		{
			s->data = k;
			s->next = nullptr; //�½ڵ�����β
			rear->next = s;
			rear = s;
			cout << k << "���" << endl;
		}
	}
	void Del_queue()
	{
		//����ʱ��Ҫע���Ƿ�ʱ��Ԫ�ڵ����
		T x(0);//�������Ԫ��
		//�п�
		//1.head->next == nullptr
		//2.head == rear
		if (head->next == nullptr)
		{
			cout << "�ӿ�" << endl;
		}
		else
		{
			q_node<T>* p = head->next;
			x = p->data;
			head->next = head->next->next;
			if (head->next == nullptr)//ɾ��Ψһ�ڵ�ʱ�����βָ���ΪҰָ��
			{
				rear = head;
			}
			delete p;
			p = nullptr;
			cout << x << "����" << endl;
		}
	}
	void m_empty()
	{
		if (head->next == nullptr)
		{
			cout << "�ӿ�" << endl;
		}
	}
public:
	q_node<T>* head;//ָ��ͷ�ڵ��ָ��
	q_node<T>* rear;//ָ���βԪ�����ڽڵ��ָ��
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