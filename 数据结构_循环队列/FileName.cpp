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
			cout << "开辟失败" << endl;
		}
		else
		{
			rear = 0; //指向队尾元素下一个位置
			front = 0;
		}
	}
	void enqueue(T k)
	{
		//判满(牺牲一个空间与判空区分)
		if ((rear + 1) % size == front)
		{
			cout << "队满" << endl;
		}
		else
		{
			data[rear] = k;
			cout << k << "入队" << endl;
			rear = (rear + 1) % size;
		}
	}
	void dequeue()
	{
		int x; //用于保存出队元素
		//判空
		if (front == rear)
		{
			cout << "队空" << endl;
		}
		else
		{
			x = data[front];
			front = (front + 1) % size;
			cout << x << "出队" << endl;
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
		if ((rear + 1) % size == front)
		{
			cout << "队满" << endl;
		}
	}
public:
	T *data;
	int front; //队头指针
	int rear; //队尾指针
	int size; //队列大小
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