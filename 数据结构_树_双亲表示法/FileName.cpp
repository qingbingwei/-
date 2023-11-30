#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
    T data;//存储数据
    int fi;//father_i,fi == -1,认为是根节点
};
template<class T>
class Tree
{
public:
    int size;
    Node<T>* pN;//指针开辟数组，存储节点
public:
    Tree(T k, int sz = 1)
    {
        //加入根节点
        pN = new Node<T>[sz];
        pN[0].data = k;
        pN[0].fi = -1;
        size = 1;
    }
    int Find(T fx)
    {
        for (int i = 0; i < size; i++)
        {
            if (pN[i].data == fx)
            {
                return i;
            }
        }
        return -1;
    }
    void insert(T x, T fx)
    {
        pN[size].data = x;
        int fx_i = Find(fx);
        if (fx_i == -1)
        {
            cout << x << "的父亲不存在" << endl;
            return;
        }
        pN[size].fi = fx_i;
        size++;
    }
    void Find_Ch(T x)
    {
        int x_i = Find(x);//查找该数据对应坐标，通过坐标找到该节点孩子节点
        int sum(0);
        for (int i = 0; i < size; i++)
        {
            if (pN[i].fi == x_i)
            {
                sum++;
                cout << pN[i].data << ' ';
            }
        }
        if (sum == 0)
        {
            cout << x << "没有孩子节点" << endl;
        }
    }
    void Find_Fa(T x)
    {
        int x_i = Find(x);
        int fa_i = pN[x_i].fi;
        if (fa_i == -1)
        {
            cout << "该节点是根节点，没有父亲节点" << endl;
        }
        else
        {
            cout << pN[fa_i].data << ' ' << endl;
        }
    }
};
//一般的树不考虑删除
int main()
{
    int n(0);
    cin >> n;
    Tree<int> t(100, n);
    t.insert(12, 100);
    t.insert(13, 100);
    t.Find_Ch(100);
    t.Find_Fa(13);
    cout << t.Find(100) << endl;
    return 0;
}