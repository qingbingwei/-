#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class m_queue
{
public:
	m_queue(int n)
	{
		size = n;
		data = new T[size];
		if (data == nullptr)
		{
			cout << "����ʧ��" << endl;
		}
		front = 0;
		rear = 0; //ָ�����һ��Ԫ����һ��λ��
	}
	void En_queue(T k)
	{
		//����(����һ��λ��)
		if (rear == size - 1)
		{
			cout << "����" << endl;
		}
		else
		{
			data[rear] = k;
			cout << k << "���" << endl;
			rear++;
		}
	}
	void Del_queue()
	{
		int x(0);//��¼����Ԫ��
		//�п�
		if (front == rear)
		{
			cout << "�ӿ�" << endl;
		}
		else
		{
			x = data[front];
			cout << x << "����" << endl;
			front++;
		}
	}
	void m_empty()
	{
		if (front == rear)
		{
			cout << "�ӿ�" << endl;
		}
	}
	void m_full()
	{
		if (rear == size)
		{
			cout << "����" << endl;
		}
	}
public:
	int size;//���д�С
	T* data;
	int front; //��ͷָ��
	int rear; //��βָ��
};
int main()
{
	m_queue<int> q(5);
	q.En_queue(10);
	q.En_queue(9);
	q.En_queue(8);
	q.En_queue(7);
	q.En_queue(6);
	q.En_queue(6);
	q.Del_queue();
	q.Del_queue();
	q.Del_queue();
	return 0;
}