#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
using namespace std;
template<class T>
class q_Node
{
public:
    T date;
    q_Node* next;
    q_Node* pre;
};
template<class T>
class LinkDequeue
{
public:
    q_Node<T>* right;
    q_Node<T>* left;
public:
    LinkDequeue()
    {
        left = new q_Node<T>;
        if (left == nullptr)
        {
            cout << "����ʧ��" << endl;
        }
        else
        {
            right = left;
            right->next = nullptr;
            right->pre = nullptr;
            left->next = nullptr;
            left->pre = nullptr;
        }
    }
    //�涨��һ�����ʱ���м�ڵ�̶�����ұߵ�һ�����Ԫ��
    void En_deque_left(T k)
    {
        q_Node<T>* s = new q_Node<T>;
        s->date = k;
        s->pre = left->pre;
        s->next = left;
        left->pre = s;
        left = s;
        cout << left->date << "���" << endl;
    }
    void Del_deque_left()
    {
        //�п�
        if (left == right)
        {
            cout << "�ӿ�" << endl;
        }
        else
        {
            //�洢���ӽڵ�
            q_Node<T>* q = left;
            left = left->next;
            left->pre = nullptr;
            cout << q->date << "����" << endl;
            delete q;
            q = nullptr;
        }
    }
    void En_deque_right(T k)
    {
        q_Node<T>* s = new q_Node<T>;
        right->date = k;
        cout << right->date << "���" << endl;
        s->pre = right;
        s->next = right->next;
        right->next = s;
        right = s;
    }
    void Del_deque_right()
    {
        //�п�
        if (left == right)
        {
            cout << "�ӿ�" << endl;
        }
        else
        {
            //�洢����Ԫ��
            q_Node<T>* s = right;
            right = right->pre;
            right->next = nullptr;
            //���߼���ʵ�ֳ���
            cout << right->date << "����" << endl;
            delete s;
            s = nullptr;
        }
    }
    void m_empty()
    {
        if (left == right)
        {
            cout << "�ӿ�" << endl;
        }
    }
};
int main()
{
    LinkDequeue<int> dq;
    dq.En_deque_left(6);
    dq.En_deque_left(5);
    dq.En_deque_left(4);
    dq.En_deque_right(3);
    dq.Del_deque_left();
    dq.Del_deque_left();
    dq.Del_deque_right();
    dq.Del_deque_right();
    return 0;
}