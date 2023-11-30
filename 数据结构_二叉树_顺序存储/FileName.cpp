#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
template<class T>
class Binary_Tree
{
public:
	T* data;//存储数据，下标从一开始，利用二叉树的性质
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
			cout << "开辟失败" << endl;
		}
		else
		{
			memset(data, NULL, sizeof(T) * (sz + 5));
				//姑且初始化为0，还没想到什么好点的办法
				//在输入正常的情况下是没问题的
				//但如果存储整型时，查找会出现二义性（找到的是存储0的节点还是未存储实际数据的节点不知道）
		        //不知道nullptr行不行
			    //似乎不行，但NULL可以，因为会转为0（这不是一样吗......）
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