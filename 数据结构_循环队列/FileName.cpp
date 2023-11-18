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
		data = new T[n];
		if (data == nullptr)
		{
			cout << "����ʧ��" << endl;
		}
		else
		{
			rear = 0; //ָ���βԪ����һ��λ��
			front = 0;
		}
	}
	void enqueue(T k)
	{
		//����(����һ���ռ����п�����)
		if ((rear + 1) % size == front)
		{
			cout << "����" << endl;
		}
		else
		{
			data[rear] = k;
			cout << k << "���" << endl;
			rear = (rear + 1) % size;
		}
	}
	void dequeue()
	{
		int x; //���ڱ������Ԫ��
		//�п�
		if (front == rear)
		{
			cout << "�ӿ�" << endl;
		}
		else
		{
			x = data[front];
			front = (front + 1) % size;
			cout << x << "����" << endl;
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
		if ((rear + 1) % size == front)
		{
			cout << "����" << endl;
		}
	}
public:
	T *data;
	int front; //��ͷָ��
	int rear; //��βָ��
	int size; //���д�С
};
int main()
{
	m_queue<int> q(10);
	q.enqueue(10);
	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14);
	q.enqueue(15);
	q.enqueue(16);
	q.enqueue(17);
	q.enqueue(18);
	q.enqueue(19);
	q.dequeue();
	q.dequeue();
	return 0;
}