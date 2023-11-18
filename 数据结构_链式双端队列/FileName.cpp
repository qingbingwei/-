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
            cout << "开辟失败" << endl;
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
    //规定第一次入队时，中间节点固定存放右边第一次入队元素
    void En_deque_left(T k)
    {
        q_Node<T>* s = new q_Node<T>;
        s->date = k;
        s->pre = left->pre;
        s->next = left;
        left->pre = s;
        left = s;
        cout << left->date << "入队" << endl;
    }
    void Del_deque_left()
    {
        //判空
        if (left == right)
        {
            cout << "队空" << endl;
        }
        else
        {
            //存储出队节点
            q_Node<T>* q = left;
            left = left->next;
            left->pre = nullptr;
            cout << q->date << "出队" << endl;
            delete q;
            q = nullptr;
        }
    }
    void En_deque_right(T k)
    {
        q_Node<T>* s = new q_Node<T>;
        right->date = k;
        cout << right->date << "入队" << endl;
        s->pre = right;
        s->next = right->next;
        right->next = s;
        right = s;
    }
    void Del_deque_right()
    {
        //判空
        if (left == right)
        {
            cout << "队空" << endl;
        }
        else
        {
            //存储出队元素
            q_Node<T>* s = right;
            right = right->pre;
            right->next = nullptr;
            //从逻辑上实现出队
            cout << right->date << "出队" << endl;
            delete s;
            s = nullptr;
        }
    }
    void m_empty()
    {
        if (left == right)
        {
            cout << "队空" << endl;
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