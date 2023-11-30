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
    void En_queue(T k)
    {
        q_Node<T>* s = new q_Node<T>;
        if (s == nullptr)
        {
            cout << "����ʧ��" << endl;

        }
        else
        {
            //�½ڵ�����β
            s->data = k;
            s->next = nullptr;
            rear->next = s;
            rear = s;
        }
    }
    T Del_queue()
    {
        //����ʱ��Ҫע���Ƿ�����Ԫ�ڵ����
        T x(0);//�������Ԫ��
        //�п�
        //1.head->next == nullptr
        //2.head == rear
        if (m_Empty())
        {
            cout << "�ӿ�" << endl;
        }
        else
        {
            q_Node<T>* p = head->next;
            x = head->next->data;
            head->next = head->next->next;
            if (head->next == nullptr)//ɾ��Ψһ�ڵ�ʱ�����βָ���ΪҰָ��
            {
                rear = head;
            }
            delete p;
            p = nullptr;
            return x;
        }
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
        Binary_Tree_Node<T>* x = nullptr;
        Link_queue<Binary_Tree_Node<T>*> m_queue;
        //�ж����ǿ�
        if (root == nullptr)
        {
            cout << "����" << endl;
            return;
        }
        //���ڵ����
        m_queue.En_queue(root);//�����������ӽڵ㲻ͬ
        while (!m_queue.m_Empty())
        {
            x = m_queue.Del_queue();
            cout << x->data << ' ';
            if (x->left != nullptr)
            {
                m_queue.En_queue(x->left);
            }
            if (x->right != nullptr)
            {
                m_queue.En_queue(x->right);
            }
        }
    }
    //������ȱ���(���Եݹ�ʵ��)
    //�������
    void pre_Order(Binary_Tree_Node<T>* ro)
    {
        //���ڣ�ro == nullptr
        //1.������ڵ�����
        //2.�жϸ���ǿգ��ݹ���ã�����ro->left
        //3.�жϸ��ҷǿգ��ݹ���ã�����ro->right
        if (ro == nullptr)
        {
            return;
        }
        cout << ro->data << ' ';
        if (ro->left != nullptr)
        {
            pre_Order(ro->left);
        }
        if (ro->right != nullptr)
        {
            pre_Order(ro->right);
        }
    }
    //����������ı�������ڵ�����˳��
    void mid_Order(Binary_Tree_Node<T>* ro)
    {
        if (ro == nullptr)
        {
            return;
        }
        if (ro->left != nullptr)
        {
            mid_Order(ro->left);
        }
        cout << ro->data << ' ';
        if (ro->right != nullptr)
        {
            mid_Order(ro->right);
        }
    }
    //����������ı�������ڵ�����˳��
    void last_Order(Binary_Tree_Node<T>* ro)
    {
        if (ro == nullptr)
        {
            return;
        }
        if (ro->left != nullptr)
        {
            last_Order(ro->left);
        }
        if (ro->right != nullptr)
        {
            last_Order(ro->right);
        }
        cout << ro->data << ' ';
    }
public:
    //���ڵ�
    Binary_Tree_Node<T>* root;
};
int main()
{
    Binary_Tree<char> tree('A');
    /*tree.Left_Insert(15, 100);
    tree.Left_Insert(19, 15);
    cout << tree.root->data << endl;
    cout << tree.root->left->data << endl;
    cout << tree.root->left->left->data << endl;*/
    tree.Left_Insert('B', 'A');
    tree.Right_Insert('C', 'B');
    tree.Left_Insert('D', 'C');
    tree.Right_Insert('E', 'A');
    tree.Right_Insert('F', 'E');
    tree.Left_Insert('G', 'F');
    tree.Right_Insert('K', 'G');
    tree.Left_Insert('H', 'G');
    tree.Level_Order();
    cout << endl;
    tree.pre_Order(tree.root);
    cout << endl;
    tree.mid_Order(tree.root);
    cout << endl;
    tree.last_Order(tree.root);
    return 0;
}