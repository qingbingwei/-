#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class Tree_Node
{
public:
    T data;
    Tree_Node<T>* first_child; //指向第一个孩子
    Tree_Node<T>* bro; //指向右边第一个亲兄弟
};
template<class T>
class Tree
{
public:
    Tree(T root)
    {
        Tree_Link = new Tree_Node<T>;
        if (Tree_Link == nullptr)
        {
            cout << "开辟失败" << endl;
        }
        else
        {
            Tree_Link->bro = nullptr;
            Tree_Link->data = root;
            Tree_Link->first_child = nullptr;
        }
    }
    //查找，通过递归实现
    Tree_Node<T>* Find(Tree_Node<T>* nd, T fx)
    {
        //递归出口
        if (nd == nullptr || nd->data == fx)
        {
            return nd;
        }
        if (nd->first_child != nullptr)
        {
            Tree_Node<T>* ans = Find(nd->first_child, fx);
            if (ans != nullptr && ans->data == fx)
            {
                return ans;
            }
        }
        if (nd->bro != nullptr)
        {
            Tree_Node<T>* ans = Find(nd->bro, fx);
            if (ans != nullptr && ans->data == fx)
            {
                return ans;
            }
        }
        return nullptr;//fx不存在
    }
    void Insert(T x, T fx)
    {
        Tree_Node<T>* t = Find(Tree_Link, fx);
        if (t == nullptr)
        {
            cout << "父亲节点不存在" << endl;
            return;
        }
        else
        {
            Tree_Node<T>* s = new Tree_Node<T>;
            if (s == nullptr)
            {
                cout << "开辟失败" << endl;
            }
            else
            {
                s->data = x;
                //进行头插（比尾插简单一些）
                //如果插入的为长子
                if (t->first_child == nullptr)
                {
                    t->first_child = s;
                    s->first_child = nullptr;
                    s->bro = nullptr;
                }
                else //插入的不是长子
                {
                    Tree_Node<T>* fir = t->first_child;
                    s->bro = fir->bro;
                    fir->bro = s;
                    s->first_child = nullptr;
                }
            }
        }
    }
public:
    Tree_Node<T>* Tree_Link; //根指针
};
int main()
{
    Tree<int> t(100);
    t.Insert(12, 100);
    t.Insert(16, 100);
    t.Insert(15, 100);
    t.Insert(14, 100);
    t.Insert(13, 100);
    t.Insert(200, 15);
    t.Insert(201, 15);
    t.Insert(202, 15);
    t.Insert(203, 15);
    t.Insert(204, 15);
    t.Insert(205, 15);
    Tree_Node<int>* p = t.Find(t.Tree_Link, 15);
    Tree_Node<int>* fir = p->first_child;
    if (fir != nullptr)
    {
        p = fir;
        while (p != nullptr)
        {
            cout << p->data << ' ' << endl;
            p = p->bro;
        }
    }
    return 0;
}