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
			cout << "开辟失败" << endl;
		}
		front = 0;
		rear = 0; //指向最后一个元素下一个位置
	}
	void En_queue(T k)
	{
		//判满(牺牲一个位置)
		if (rear == size - 1)
		{
			cout << "队满" << endl;
		}
		else
		{
			data[rear] = k;
			cout << k << "入队" << endl;
			rear++;
		}
	}
	void Del_queue()
	{
		int x(0);//记录出队元素
		//判空
		if (front == rear)
		{
			cout << "队空" << endl;
		}
		else
		{
			x = data[front];
			cout << x << "出队" << endl;
			front++;
		}
	}
	void m_empty()
	{
		if (front == rear)
		{
			cout << "队空" << endl;
		}
	}
	void m_full()
	{
		if (rear == size)
		{
			cout << "队满" << endl;
		}
	}
public:
	int size;//队列大小
	T* data;
	int front; //队头指针
	int rear; //队尾指针
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