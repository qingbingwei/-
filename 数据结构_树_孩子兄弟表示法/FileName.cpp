#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class Tree_Node
{
public:
    T data;
    Tree_Node<T>* first_child; //ָ���һ������
    Tree_Node<T>* bro; //ָ���ұߵ�һ�����ֵ�
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
            cout << "����ʧ��" << endl;
        }
        else
        {
            Tree_Link->bro = nullptr;
            Tree_Link->data = root;
            Tree_Link->first_child = nullptr;
        }
    }
    //���ң�ͨ���ݹ�ʵ��
    Tree_Node<T>* Find(Tree_Node<T>* nd, T fx)
    {
        //�ݹ����
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
        return nullptr;//fx������
    }
    void Insert(T x, T fx)
    {
        Tree_Node<T>* t = Find(Tree_Link, fx);
        if (t == nullptr)
        {
            cout << "���׽ڵ㲻����" << endl;
            return;
        }
        else
        {
            Tree_Node<T>* s = new Tree_Node<T>;
            if (s == nullptr)
            {
                cout << "����ʧ��" << endl;
            }
            else
            {
                s->data = x;
                //����ͷ�壨��β���һЩ��
                //��������Ϊ����
                if (t->first_child == nullptr)
                {
                    t->first_child = s;
                    s->first_child = nullptr;
                    s->bro = nullptr;
                }
                else //����Ĳ��ǳ���
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
    Tree_Node<T>* Tree_Link; //��ָ��
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