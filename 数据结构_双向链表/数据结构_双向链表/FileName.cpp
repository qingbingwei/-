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
            cout << "����ʧ��" << endl;
        }
        else
        {
            m_head->next = nullptr;
            m_head->pre = nullptr;
        }
    }
    //���Һ���
    LinkList* Find(LinkList* head, T k)
    {
        Node<T>* pt = head->m_head->next;
        while (pt->next != nullptr)
        {
            if (pt->date == k)
            {
                cout << "�ҵ���" << endl;
                return head;
            }
            pt = pt->next;
        }
        if (pt->next == nullptr)
        {
            cout << "û�ҵ�" << endl;
        }
        return head;
    }
    //ͷ�庯��
    LinkList* head_insert(LinkList* head, T k)
    {
        Node<T>* s = new Node<T>;
        if (s == nullptr)
        {
            cout << "����ʧ��" << endl;
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
    //β�庯��
    LinkList* tail_insert(LinkList* head, T k)
    {
        Node<T>* s = new Node<T>;
        if (s == nullptr)
        {
            cout << "����ʧ��" << endl;
        }
        else
        {
            s->date = k;
            s->next = nullptr;
            //���ҵ����һ���ڵ�
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
    //�м����
    LinkList* mid_insert(LinkList* head, T x, T k)
    {
        Node<T>* s = new Node<T>;
        if (s == nullptr)
        {
            cout << "����ʧ��" << endl;
        }
        else
        {
            s->date = k;
            //��x���ڽڵ�
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
    //ɾ��
    LinkList* del(LinkList* head, T k)
    {
        //����k���ڽڵ�
        Node<T>* pt = head->m_head->next;//k
        Node<T>* pr = head->m_head;//ptǰһ���ڵ�
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
    //�޸�
    LinkList* Change(LinkList* head, T x, T k)
    {
        //����x���ڽڵ�
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