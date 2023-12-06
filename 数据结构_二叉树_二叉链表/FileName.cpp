#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//链栈，用于实现非递归深度优先遍历
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
            cout << "开辟失败" << endl;
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
            cout << "栈空" << endl;
        }
        else
        {
            //p指向要删除的首元节点
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
            cout << "栈空" << endl;
        }
        else
        {
            cout << head->next->data << endl;
        }
    }
};
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
    void En_queue(T k)
    {
        q_Node<T>* s = new q_Node<T>;
        if (s == nullptr)
        {
            cout << "开辟失败" << endl;

        }
        else
        {
            //新节点插入队尾
            s->data = k;
            s->next = nullptr;
            rear->next = s;
            rear = s;
        }
    }
    T Del_queue()
    {
        //出队时需要注意是否是首元节点出队
        T x(0);//保存出队元素
        //判空
        //1.head->next == nullptr
        //2.head == rear
        if (m_Empty())
        {
            cout << "队空" << endl;
        }
        else
        {
            q_Node<T>* p = head->next;
            x = head->next->data;
            head->next = head->next->next;
            if (head->next == nullptr)//删除唯一节点时避免队尾指针成为野指针
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
    int rflag;//标记左右指针指向的是孩子节点（0），还是前驱后继 （1）
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
            cout << "开辟失败" << endl;
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
        //运用递归实现,与先前孩子兄弟表示法查找方法相同
        if (ro == nullptr || ro->data == fx)
        {
            return ro;
        }
        //在线索化之后进行额外判断，判断是真孩子还是前驱后继
        if (ro->left != nullptr && ro->lflag == 0)
        {
            Binary_Tree_Node<T>* f = Find(ro->left, fx);
            if (f != nullptr && f->data == fx)
            {
                return f;
            }
        }
        //在线索化之后进行额外判断，判断是真孩子还是前驱后继
        if (ro->right != nullptr && ro->rflag == 0)
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
        Binary_Tree_Node<T>* x = nullptr;
        Link_queue<Binary_Tree_Node<T>*> m_queue;
        //判断树非空
        if (root == nullptr)
        {
            cout << "树空" << endl;
            return;
        }
        //根节点入队
        m_queue.En_queue(root);//入队数据与入队节点不同
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
    //深度优先遍历(均以递归实现)
    //先序遍历
    void pre_Order(Binary_Tree_Node<T>* ro)
    {
        //出口，ro == nullptr
        //1.输出根节点数据
        //2.判断根左非空，递归调用，传入ro->left
        //3.判断根右非空，递归调用，传入ro->right
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
    //中序遍历（改变输出根节点数据顺序）
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
    //后序遍历（改变输出根节点数据顺序）
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
    //深度优先遍历（非递归实现,基于链栈）
    //先序遍历
    void pre_Order_non_recursion()
    {
        m_stack<Binary_Tree_Node<T>*> s;
        if (root == nullptr)
        {
            cout << "树空" << endl;
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
    //中序遍历
    void mid_Order_non_recursion()
    {
        m_stack<Binary_Tree_Node<T>*> s;
        //用node从根节点开始遍历
        if (root == nullptr)
        {
            return;
        }
        Binary_Tree_Node<T>* node = root;
        Binary_Tree_Node<T>* nd = nullptr;//存储出栈元素
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
    //后序遍历
    void last_Order_non_recursion()
    {
        m_stack<Binary_Tree_Node<T>*> s;
        if (root == nullptr)
        {
            return;
        }
        Binary_Tree_Node<T>* node = root;
        Binary_Tree_Node<T>* nd = nullptr;//存储栈顶元素
        Binary_Tree_Node<T>* pre = nullptr;
        //需要知道右子树是否被遍历了，所以创建pre
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
                    //如果栈顶元素右孩子存在并且没有被访问，遍历右孩子
                    node = nd->right;
                }
                else
                {
                    //访问栈顶
                    nd = s.m_pop();
                    cout << nd->data << ' ';
                    pre = nd;
                    node = nullptr;
                }
            }
        }
    }
    //线索化，使用递归遍历操作
    void visit_thread(Binary_Tree_Node<T>* ro)
    {
        if (ro->left == nullptr)
        {
            ro->left = pre_in_thread;
            ro->lflag = 1;//加上标记
        }
        //先判断前驱是否为空
        if (pre_in_thread != nullptr && pre_in_thread->right == nullptr)
        {
            //前驱与后继两两对应，为其前驱加上后继
            pre_in_thread->right = ro;
            pre_in_thread->rflag = 1;
        }
        pre_in_thread = ro;
    }
    //1.如果一个节点其左孩子指针域为空，那么将该指针域指向其前驱节点
    //2.如果一个节点其右孩子指针域为空，那么将该指针域指向其后继节点
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
    //避免前序线索化与后续线索化出现死循环，递归时通过lflag与rflag进行判断
    //中序遍历不会出现上述情况，但为了格式统一和严谨，也加上
    void pre_threading(Binary_Tree_Node<T>* ro)
    {
        //出口，ro == nullptr
        //1.进行线索化
        //2.判断根左非空，递归调用，传入ro->left
        //3.判断根右非空，递归调用，传入ro->right
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

    //只需要掌握找中序遍历的前驱与后继
    //因为先序与后序遍历通过线索化找前驱与后继时效率无明显提升且过于复杂

    //某一节点前驱为其左子树最靠右节点
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
                //找左子树最靠右节点
                Binary_Tree_Node<T>* p = x->left;
                while (p->right != nullptr && p->rflag == 0)
                {
                    p = p->right;
                }
                return p;
            }
        }
    }
    //某一节点后继为其右子树最靠左节点
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
                //找右子树最靠左节点
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
    //根节点
    Binary_Tree_Node<T>* root;
    //用于记录线索化时遍历至某一节点的前驱节点
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