#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
    T data;//�洢����
    int fi;//father_i,fi == -1,��Ϊ�Ǹ��ڵ�
};
template<class T>
class Tree
{
public:
    int size;
    Node<T>* pN;//ָ�뿪�����飬�洢�ڵ�
public:
    Tree(T k, int sz = 1)
    {
        //������ڵ�
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
            cout << x << "�ĸ��ײ�����" << endl;
            return;
        }
        pN[size].fi = fx_i;
        size++;
    }
    void Find_Ch(T x)
    {
        int x_i = Find(x);//���Ҹ����ݶ�Ӧ���꣬ͨ�������ҵ��ýڵ㺢�ӽڵ�
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
            cout << x << "û�к��ӽڵ�" << endl;
        }
    }
    void Find_Fa(T x)
    {
        int x_i = Find(x);
        int fa_i = pN[x_i].fi;
        if (fa_i == -1)
        {
            cout << "�ýڵ��Ǹ��ڵ㣬û�и��׽ڵ�" << endl;
        }
        else
        {
            cout << pN[fa_i].data << ' ' << endl;
        }
    }
};
//һ�����������ɾ��
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