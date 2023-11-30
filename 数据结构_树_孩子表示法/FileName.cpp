#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class ch_Node
{
public:
    T data;
    ch_Node<T>* next;
};
template<class T>
class ch_Link //孩子链表
{
public:
    ch_Link()
    {
        head = new ch_Node<T>;
        if (head == nullptr)
        {
            cout << "开辟失败" << endl;
        }
        else
        {
            head->next = nullptr;
        }
    }
public:
    ch_Node<T>* head;
};
template<class T>
class Tree_Node //树的节点
{
public:
    T data;
    ch_Link<T> cl;
};
template<class T>
class Tree //树
{
public:
    Tree(T k, int sz = 1)
    {
        size = 0;
        nd = new Tree_Node<T>[sz];
        nd[0].data = k;
        size++;
    }
    int Find(T x)
    {
        for (int i = 0; i < size; i++)
        {
            if (nd[i].data == x)
            {
                return i;
            }
        }
        return -1;
    }
    void insert(T x, T fx)
    {
        nd[size].data = x; //放入新节点数据
        nd[size].cl.head->next = nullptr;
        int fx_i = Find(fx);//建立fx与x父子关系
        if (fx_i == -1)
        {
            cout << "为根节点，无法建立" << endl;
        }
        else
        {
            ch_Node<T>* s = new ch_Node<T>;
            s->data = x;
            //头插法
            s->next = nd[fx_i].cl.head->next;
            nd[fx_i].cl.head->next = s;
            size++;
        }
    }
    void Find_Ch(T x)
    {
        int x_i = Find(x);
        ch_Node<T>* p = nd[x_i].cl.head->next;
        if (p == nullptr)
        {
            cout << x << "没有孩子" << endl;
            return;
        }
        while (p != nullptr)
        {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }
    void Find_Fa(T x)
    {
        ch_Node<T>* p = nullptr;
        int flag(0); //用于标记根节点
        for (int i = 0; i < size; i++)
        {
            p = nd[i].cl.head->next;
            while (p != nullptr && p->data != x)
            {
                p = p->next;
            }
            if (p != nullptr && p->data == x)
            {
                cout << nd[i].data << ' ' << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << x << "是根节点" << endl;
        }
    }
public:
    Tree_Node<T>* nd;
    int size;
};
int main()
{
    Tree<int> t(100, 1000);
    t.insert(2, 100);
    t.insert(3, 100);
    t.insert(4, 100);
    t.insert(5, 100);
    t.Find_Ch(100);
    t.Find_Fa(100);
    return 0;
}