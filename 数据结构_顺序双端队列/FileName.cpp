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
			cout << "����ʧ��" << endl;
		}
		else
		{
			size = 0;
			left = 0;
			right = 0;
		}
	}
	//�涨0λ�ô洢�Ҷ���ӵ�һ��Ԫ��
	void En_queue_left(T k)
	{
		//����
		if (size == length)
		{
			cout << "����" << endl;
		}
		else
		{
			//��ֹ��ָ��Ϊ����
			left = (left - 1 + length) % length;
			data[left] = k;
			cout << k << "���" << endl;
			size++;
		}
	}
	void Del_queue_left()
	{
		//�п�
		if (size == 0)
		{
			cout << "�ӿ�" << endl;
			return;
		}
		T x(0);//�洢����Ԫ��
		x = data[left];
		left = (left + 1 + length) % length;
		cout << x << "����" << endl;
		size--;
	}
	void En_queue_right(T k)
	{
		
		//����
		if (size == length)
		{
			cout << "����" << endl;
		}
		else
		{
			//��ָ��ָ�����һ��Ԫ����һ��λ��
			data = k;
			right = (right + 1) % length;
			size++;
		}

	}
	void Del_queue_right()
	{
		//�п�
		if (size == 0)
		{
			cout << "�ӿ�" << endl;
			return;
		}
		T x(0);//�洢����Ԫ��
		right = (right - 1 + length) % length;
		x = data[right];//��Ϊ0λ�ô洢�Ҷ���ӵ�һ��Ԫ�أ�����rightָ���Ҷ�Ԫ����һ��λ��
		cout << x << "����" << endl;
		size--;
	}
	void m_empty()
	{
		if (size == 0)
		{
			cout << "�ӿ�" << endl;
			return;
		}
	}
	void m_full()
	{
		if (size == length)
		{
			cout << "����" << endl;
		}
		return;
	}
public:
	T* data;
	int left;
	int right;
	int size;//����ʵ�ʴ�С
	int length;//���г���
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