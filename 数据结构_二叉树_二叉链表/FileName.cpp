#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��ջ������ʵ�ַǵݹ�������ȱ���
template<class T>
class stack_Node
{
public:
    T data;
    stack_Node<T>* next;
};
template<class T>
class m_stack
{
public:
    stack_Node<T>* head;
public:
    m_stack()
    {
        head = new stack_Node<T>;
        if (head == nullptr)
        {
            cout << "����ʧ��" << endl;
        }
        else
        {
            head->next = nullptr;
        }
    }
    void m_push(T k)
    {
        stack_Node<T>* s = new stack_Node<T>;
        s->next = head->next;
        s->data = k;
        head->next = s;
    }
    T m_pop()
    {
        if (m_empty())
        {
            cout << "ջ��" << endl;
        }
        else
        {
            //pָ��Ҫɾ������Ԫ�ڵ�
            stack_Node<T>* p = head->next;
            T k = p->data;
            head->next = p->next;
            delete p;
            p = nullptr;
            return k;
        }
    }
    bool m_empty()
    {
        if (head->next == nullptr)
            return true;
        else
            return false;
    }
    void get_top()
    {
        if (m_empty())
        {
            cout << "ջ��" << endl;
        }
        else
        {
            cout << head->next->data << endl;
        }
    }
};
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
    int lflag;
    int rflag;//�������ָ��ָ����Ǻ��ӽڵ㣨0��������ǰ����� ��1��
public:
    Binary_Tree_Node()
    {
        lflag = 0;
        rflag = 0;
    }
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
            pre_in_thread = nullptr;
        }
    }
    Binary_Tree_Node<T>* Find(Binary_Tree_Node<T>* ro, T fx)
    {
        //���õݹ�ʵ��,����ǰ�����ֵܱ�ʾ�����ҷ�����ͬ
        if (ro == nullptr || ro->data == fx)
        {
            return ro;
        }
        //��������֮����ж����жϣ��ж����溢�ӻ���ǰ�����
        if (ro->left != nullptr && ro->lflag == 0)
        {
            Binary_Tree_Node<T>* f = Find(ro->left, fx);
            if (f != nullptr && f->data == fx)
            {
                return f;
            }
        }
        //��������֮����ж����жϣ��ж����溢�ӻ���ǰ�����
        if (ro->right != nullptr && ro->rflag == 0)
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
    //������ȱ������ǵݹ�ʵ��,������ջ��
    //�������
    void pre_Order_non_recursion()
    {
        m_stack<Binary_Tree_Node<T>*> s;
        if (root == nullptr)
        {
            cout << "����" << endl;
            return;
        }
        s.m_push(root);
        while (!s.m_empty())
        {
            Binary_Tree_Node<T>* nd = s.m_pop();
            cout << nd->data << ' ';
            if (nd->right != nullptr)
            {
                s.m_push(nd->right);
            }
            if (nd->left != nullptr)
            {
                s.m_push(nd->left);
            }
        }
    }
    //�������
    void mid_Order_non_recursion()
    {
        m_stack<Binary_Tree_Node<T>*> s;
        //��node�Ӹ��ڵ㿪ʼ����
        if (root == nullptr)
        {
            return;
        }
        Binary_Tree_Node<T>* node = root;
        Binary_Tree_Node<T>* nd = nullptr;//�洢��ջԪ��
        while (!s.m_empty() || node != nullptr)
        {
            if (node != nullptr)
            {
                s.m_push(node);
                node = node->left;
            }
            else
            {
                nd = s.m_pop();
                cout << nd->data << ' ';
                node = nd->right;
            }
        }
    }
    //�������
    void last_Order_non_recursion()
    {
        m_stack<Binary_Tree_Node<T>*> s;
        if (root == nullptr)
        {
            return;
        }
        Binary_Tree_Node<T>* node = root;
        Binary_Tree_Node<T>* nd = nullptr;//�洢ջ��Ԫ��
        Binary_Tree_Node<T>* pre = nullptr;
        //��Ҫ֪���������Ƿ񱻱����ˣ����Դ���pre
        while (!s.m_empty() || node != nullptr)
        {
            if (node != nullptr)
            {
                s.m_push(node);
                node = node->left;
            }
            else
            {
                nd = s.head->next->data;
                if (nd->right != nullptr && pre != nd->right)
                {
                    //���ջ��Ԫ���Һ��Ӵ��ڲ���û�б����ʣ������Һ���
                    node = nd->right;
                }
                else
                {
                    //����ջ��
                    nd = s.m_pop();
                    cout << nd->data << ' ';
                    pre = nd;
                    node = nullptr;
                }
            }
        }
    }
    //��������ʹ�õݹ��������
    void visit_thread(Binary_Tree_Node<T>* ro)
    {
        if (ro->left == nullptr)
        {
            ro->left = pre_in_thread;
            ro->lflag = 1;//���ϱ��
        }
        //���ж�ǰ���Ƿ�Ϊ��
        if (pre_in_thread != nullptr && pre_in_thread->right == nullptr)
        {
            //ǰ������������Ӧ��Ϊ��ǰ�����Ϻ��
            pre_in_thread->right = ro;
            pre_in_thread->rflag = 1;
        }
        pre_in_thread = ro;
    }
    //1.���һ���ڵ�������ָ����Ϊ�գ���ô����ָ����ָ����ǰ���ڵ�
    //2.���һ���ڵ����Һ���ָ����Ϊ�գ���ô����ָ����ָ�����̽ڵ�
    void mid_threading(Binary_Tree_Node<T>* ro)
    {
        if (ro == nullptr)
        {
            return;
        }
        if (ro->left != nullptr && ro->lflag == 0)
        {
            mid_threading(ro->left);
        }
        visit_thread(ro);
        if (ro->right != nullptr && ro->rflag == 0)
        {
            mid_threading(ro->right);
        }
    }
    //����ǰ�������������������������ѭ�����ݹ�ʱͨ��lflag��rflag�����ж�
    //�������������������������Ϊ�˸�ʽͳһ���Ͻ���Ҳ����
    void pre_threading(Binary_Tree_Node<T>* ro)
    {
        //���ڣ�ro == nullptr
        //1.����������
        //2.�жϸ���ǿգ��ݹ���ã�����ro->left
        //3.�жϸ��ҷǿգ��ݹ���ã�����ro->right
        if (ro == nullptr)
        {
            return;
        }
        visit_thread(ro);
        if (ro->left != nullptr && ro->lflag == 0)
        {
            pre_threading(ro->left);
        }
        if (ro->right != nullptr && ro->rflag == 0)
        {
            pre_threading(ro->right);
        }
    }
    void last_threading(Binary_Tree_Node<T>* ro)
    {
        if (ro == nullptr)
        {
            return;
        }
        if (ro->left != nullptr && ro->lflag == 0)
        {
            last_threading(ro->left);
        }
        if (ro->right != nullptr && ro->rflag == 0)
        {
            last_threading(ro->right);
        }
        visit_thread(ro);
    }

    //ֻ��Ҫ���������������ǰ������
    //��Ϊ������������ͨ����������ǰ������ʱЧ�������������ҹ��ڸ���

    //ĳһ�ڵ�ǰ��Ϊ����������ҽڵ�
    Binary_Tree_Node<T>* Find_mid_pre(T k)
    {
        Binary_Tree_Node<T>* x = Find(root, k);
        if (x != nullptr)
        {
            if (x->lflag == 1)
            {
                return x->left;
            }
            else
            {
                //����������ҽڵ�
                Binary_Tree_Node<T>* p = x->left;
                while (p->right != nullptr && p->rflag == 0)
                {
                    p = p->right;
                }
                return p;
            }
        }
    }
    //ĳһ�ڵ���Ϊ�����������ڵ�
    Binary_Tree_Node<T>* Find_mid_last(T k)
    {
        Binary_Tree_Node<T>* x = Find(root, k);
        if (x != nullptr)
        {
            if (x->rflag == 1)
            {
                return x->right;
            }
            else
            {
                //�����������ڵ�
                Binary_Tree_Node<T>* p = x->right;
                while (p->left != nullptr && p->lflag == 0)
                {
                    p = p->left;
                }
                return p;
            }
        }
    }
public:
    //���ڵ�
    Binary_Tree_Node<T>* root;
    //���ڼ�¼������ʱ������ĳһ�ڵ��ǰ���ڵ�
    Binary_Tree_Node<T>* pre_in_thread;
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
    cout << endl;
    tree.pre_Order_non_recursion();
    cout << endl;
    tree.mid_Order_non_recursion();
    cout << endl;
    tree.last_Order_non_recursion();
    cout << endl;
    cout << endl;
    cout << endl;
    tree.mid_threading(tree.root);
    Binary_Tree_Node<char>* ans1;
    Binary_Tree_Node<char>* ans2;
    ans1 = tree.Find_mid_pre('A');
    ans2 = tree.Find_mid_last('A');
    cout << ans1->data << ' ';
    cout << ans2->data << ' ';
    return 0;
}