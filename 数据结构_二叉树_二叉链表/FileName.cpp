#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//链式队列，用于实现广度优先遍历
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
    q_Node<T>* head;//指向头节点的指针
    q_Node<T>* rear;//指向队尾元素所在节点的指针
public:
    Link_queue()
    {
        head = new q_Node<T>;
        rear = head;
        if (head == nullptr)
        {
            cout << "开辟失败" << endl;
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
            cout << "开辟失败" << endl;
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
        //运用递归实现,与先前孩子兄弟表示法查找方法相同
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
        return nullptr;//fx不存在
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
    //二叉树的遍历

    //层次遍历--广度优先遍历
    void Level_Order()
    {

    }
    //深度优先遍历(均以递归实现)
    //先序遍历
    void pre_Order()
    {

    }
    //中序遍历
    void mid_Order()
    {

    }
    //后序遍历
    void last_Order()
    {

    }
public:
    //根节点
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