#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class dequeue
{
public:
	dequeue(int n)
	{
		length = n;
		data = new T[length];
		if (data == nullptr)
		{
			cout << "分配失败" << endl;
		}
		else
		{
			size = 0;
			left = 0;
			right = 0;
		}
	}
	//规定0位置存储右端入队第一个元素
	void En_queue_left(T k)
	{
		//判满
		if (size == length)
		{
			cout << "队满" << endl;
		}
		else
		{
			//防止左指针为负数
			left = (left - 1 + length) % length;
			data[left] = k;
			cout << k << "入队" << endl;
			size++;
		}
	}
	void Del_queue_left()
	{
		//判空
		if (size == 0)
		{
			cout << "队空" << endl;
			return;
		}
		T x(0);//存储出队元素
		x = data[left];
		left = (left + 1 + length) % length;
		cout << x << "出队" << endl;
		size--;
	}
	void En_queue_right(T k)
	{
		
		//判满
		if (size == length)
		{
			cout << "队满" << endl;
		}
		else
		{
			//右指针指向最后一个元素下一个位置
			data = k;
			right = (right + 1) % length;
			size++;
		}

	}
	void Del_queue_right()
	{
		//判空
		if (size == 0)
		{
			cout << "队空" << endl;
			return;
		}
		T x(0);//存储出队元素
		right = (right - 1 + length) % length;
		x = data[right];//因为0位置存储右端入队第一个元素，所以right指向右端元素下一个位置
		cout << x << "出队" << endl;
		size--;
	}
	void m_empty()
	{
		if (size == 0)
		{
			cout << "队空" << endl;
			return;
		}
	}
	void m_full()
	{
		if (size == length)
		{
			cout << "队满" << endl;
		}
		return;
	}
public:
	T* data;
	int left;
	int right;
	int size;//队列实际大小
	int length;//队列长度
};
int main()
{
	dequeue<int> dq(10);
	dq.En_queue_left(10);
	dq.En_queue_left(11);
	dq.En_queue_left(12);
	dq.Del_queue_right();
	dq.Del_queue_right();
	dq.Del_queue_right();
	return 0;
}