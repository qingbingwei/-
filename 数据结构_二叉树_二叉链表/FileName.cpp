#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��ʽ���У�����ʵ�ֹ�����ȱ���
template<class T>
class q_Node
{
public:
    T data;
    q_Node<T>* next;
};
template<class T>
class Link_queue
{
public:
    q_Node<T>* head;//ָ��ͷ�ڵ��ָ��
    q_Node<T>* rear;//ָ���βԪ�����ڽڵ��ָ��
public:
    Link_queue()
    {
        head = new q_Node<T>;
        rear = head;
        if (head == nullptr)
        {
            cout << "����ʧ��" << endl;
        }
        else
        {
            head->next = nullptr;
            rear->next = nullptr;
        }
    }
    bool m_Empty()
    {
        if (head->next == nullptr)
        {
            return true;
        }
        return false;
    }
    void En_queue()
    {

    }
    void Del_queue()
    {

    }
};
template<class T>
class Binary_Tree_Node
{
public:
    T data;
    Binary_Tree_Node<T>* left;
    Binary_Tree_Node<T>* right;
};
template<class T>
class Binary_Tree
{
public:
    Binary_Tree(T k)
    {
        root = new Binary_Tree_Node<T>;
        if (root == nullptr)
        {
            cout << "����ʧ��" << endl;
        }
        else
        {
            root->data = k;
            root->left = nullptr;
            root->right = nullptr;
        }
    }
    Binary_Tree_Node<T>* Find(Binary_Tree_Node<T>* ro, T fx)
    {
        //���õݹ�ʵ��,����ǰ�����ֵܱ�ʾ�����ҷ�����ͬ
        if (ro == nullptr || ro->data == fx)
        {
            return ro;
        }
        if (ro->left != nullptr)
        {
            Binary_Tree_Node<T>* f = Find(ro->left, fx);
            if (f != nullptr && f->data == fx)
            {
                return f;
            }
        }
        if (ro->right != nullptr)
        {
            Binary_Tree_Node<T>* f = Find(ro->right, fx);
            if (f != nullptr && f->data == fx)
            {
                return f;
            }
        }
        return nullptr;//fx������
    }
    void Right_Insert(T x, T fx)
    {
        Binary_Tree_Node<T>* f = Find(root, fx);
        if (f != nullptr)
        {
            Binary_Tree_Node<T>* s = new Binary_Tree_Node<T>;
            s->data = x;
            s->left = nullptr;
            s->right = nullptr;
            f->right = s;
        }
    }
    void Left_Insert(T x, T fx)
    {
        Binary_Tree_Node<T>* f = Find(root, fx);
        if (f != nullptr)
        {
            Binary_Tree_Node<T>* s = new Binary_Tree_Node<T>;
            s->data = x;
            s->left = nullptr;
            s->right = nullptr;
            f->left = s;
        }
    }
    //�������ı���

    //��α���--������ȱ���
    void Level_Order()
    {

    }
    //������ȱ���(���Եݹ�ʵ��)
    //�������
    void pre_Order()
    {

    }
    //�������
    void mid_Order()
    {

    }
    //�������
    void last_Order()
    {

    }
public:
    //���ڵ�
    Binary_Tree_Node<T>* root;
};
int main()
{
    Binary_Tree<int> tree(100);
    tree.Left_Insert(15, 100);
    tree.Left_Insert(19, 15);
    cout << tree.root->data << endl;
    cout << tree.root->left->data << endl;
    cout << tree.root->left->left->data << endl;
    return 0;
}