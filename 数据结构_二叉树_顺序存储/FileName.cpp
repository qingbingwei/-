#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
template<class T>
class Binary_Tree
{
public:
	T* data;//�洢���ݣ��±��һ��ʼ�����ö�����������
	int size;
	int length;
public:
	Binary_Tree(int sz,T fx)
	{
		size = 0;
		length = sz;
		data = new T[sz + 5];
		if (data == nullptr)
		{
			cout << "����ʧ��" << endl;
		}
		else
		{
			memset(data, NULL, sizeof(T) * (sz + 5));
				//���ҳ�ʼ��Ϊ0����û�뵽ʲô�õ�İ취
				//�������������������û�����
				//������洢����ʱ�����һ���ֶ����ԣ��ҵ����Ǵ洢0�Ľڵ㻹��δ�洢ʵ�����ݵĽڵ㲻֪����
		        //��֪��nullptr�в���
			    //�ƺ����У���NULL���ԣ���Ϊ��תΪ0���ⲻ��һ����......��
			data[1] = fx;
		}
	}
	void Left_Insert(T x, T fx)
	{
		int fx_i = Find(fx);
		int x_i = 2 * fx_i;
		data[x_i] = x;
		size++;
	}
	void Right_Insert(T x,T fx)
	{
		int fx_i = Find(fx);
		int x_i = 2 * fx_i + 1;
		data[x_i] = x;
		size++;
	}
	int Find(T fx)
	{
		for (int i = 1; i < length; i++)
		{
			if (data[i] == fx)
			{
				return i;
			}
		}
		return -1;
	}
};
int main()
{
	Binary_Tree<int> tree(100, 1000);
	tree.Left_Insert(100, 0);
	tree.Right_Insert(5, 1000);
	cout << tree.Find(0) << endl;
	cout << tree.data[1] << endl;
	cout << tree.data[2] << endl;
	cout << tree.data[3] << endl;
	cout << tree.data[4] << endl;
	cout << tree.data[5] << endl;
	cout << tree.data[6] << endl;
	return 0;
}