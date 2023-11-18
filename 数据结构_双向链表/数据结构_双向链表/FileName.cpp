#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
using namespace std;
template<class T>
class Node
{
public:
    T date;
    Node* next;
    Node* pre;
};
template<class T>
class LinkList
{
public:
    Node<T>* m_head;
public:
    LinkList()
    {
        m_head = new Node<T>;
        if (m_head == nullptr)
        {
            cout << "开辟失败" << endl;
        }
        else
        {
            m_head->next = nullptr;
            m_head->pre = nullptr;
        }
    }
    //查找函数
    LinkList* Find(LinkList* head, T k)
    {
        Node<T>* pt = head->m_head->next;
        while (pt->next != nullptr)
        {
            if (pt->date == k)
            {
                cout << "找到了" << endl;
                return head;
            }
            pt = pt->next;
        }
        if (pt->next == nullptr)
        {
            cout << "没找到" << endl;
        }
        return head;
    }
    //头插函数
    LinkList* head_insert(LinkList* head, T k)
    {
        Node<T>* s = new Node<T>;
        if (s == nullptr)
        {
            cout << "开辟失败" << endl;
        }
        else
        {
            s->date = k;
            s->next = head->m_head->next;
            s->pre = head->m_head;
            head->m_head->next = s;
            if (s->next != nullptr)
            {
                s->next->pre = s;
            }
        }
        return head;
    }
    //尾插函数
    LinkList* tail_insert(LinkList* head, T k)
    {
        Node<T>* s = new Node<T>;
        if (s == nullptr)
        {
            cout << "开辟失败" << endl;
        }
        else
        {
            s->date = k;
            s->next = nullptr;
            //先找到最后一个节点
            Node<T>* pt = head->m_head;
            while (pt != nullptr)
            {
                if (pt->next == nullptr)
                {
                    break;
                }
                pt = pt->next;
            }
            pt->next = s;
            s->pre = pt;
        }
        return head;
    }
    //中间插入
    LinkList* mid_insert(LinkList* head, T x, T k)
    {
        Node<T>* s = new Node<T>;
        if (s == nullptr)
        {
            cout << "开辟失败" << endl;
        }
        else
        {
            s->date = k;
            //找x所在节点
            Node<T>* pt = head->m_head;
            while (pt->date != x)
            {
                pt = pt->next;
            }
            s->next = pt->next;
            s->pre = pt;
            pt->next = s;
            if (s->next != nullptr)
            {
                s->next->pre = s;
            }
        }
        return head;
    }
    //删除
    LinkList* del(LinkList* head, T k)
    {
        //查找k所在节点
        Node<T>* pt = head->m_head->next;//k
        Node<T>* pr = head->m_head;//pt前一个节点
        while (pt->date != k)
        {
            pt = pt->next;
            pr = pr->next;
        }
        pr->next = pt->next;
        if (pt->next != nullptr)
        {
            pt->next->pre = pr;
        }
        delete pt;
        pt = nullptr;
        return head;
    }
    //修改
    LinkList* Change(LinkList* head, T x, T k)
    {
        //查找x所在节点
        Node<T>* pt = head->m_head->next;//x
        while (pt->date != x)
        {
            pt = pt->next;
        }
        pt->date = k;
        return head;
    }
    void My_print(LinkList* head)
    {
        Node<T>* pt = head->m_head->next;
        while (1)
        {
            cout << pt->date << endl;
            pt = pt->next;
            if (pt->next == nullptr)
            {
                cout << pt->date << endl;
                break;
            }
        }
    }
};


int main()
{
    LinkList<int> l;
    l.head_insert(&l, 1);
    l.head_insert(&l, 2);
    l.head_insert(&l, 3);
    l.tail_insert(&l, 4);
    l.tail_insert(&l, 5);
    l.tail_insert(&l, 6);
    l.mid_insert(&l, 5, 1111);
    l.Change(&l, 1111, 2222);
    l.Find(&l, 2222);
    l.del(&l, 2222);
    l.Find(&l, 2222);
    l.My_print(&l);
    return 0;
}