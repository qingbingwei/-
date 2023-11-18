#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdexcept>
using namespace std;
template<class T>
class ArrayList
{
public:
    ArrayList(int Num) :size(0) //初始化构造函数
    {
        date = new T[Num];      
        if (data == nullptr)
        {
            cout << "开辟失败" << endl;
        }
        length = Num;
    }
    void AddEle(ArrayList* pa, T ele)//增添元素
    {
        //判断是否超过最大容量
        try
        {
            if (pa->size < pa->length)
            {
                pa->date[size] = ele;
                pa->size++;
            }
            else
            {
                throw runtime_error("空间已满，是否扩容 Y/N");
            }
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            char ch(0);
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                T* date_copy = new T[size + 1];
                for (size_t i = 0; i < pa->length; i++)
                {
                    date_copy[i] = date[i];
                }//将值存储到新空间
                delete[] date;
                if (date != nullptr)
                {
                    date = nullptr;
                }
                date = date_copy;
                date_copy = nullptr;
                pa->length++;
                date[length - 1] = ele;
                pa->size++;
            }
            else
            {
                cout << "不进行扩容，无法增添新元素" << endl;
                return;
            }
        }
    }
    int FindEle(ArrayList* pa, T ele)//查找元素
    {
        for (size_t i = 0; i < pa->size; i++)
        {
            if (pa->date[i] == ele)
            {
                return i;
            }
        }
        return -1;
    }
    void DelEle(ArrayList* pa, T ele)
    {
        int index = pa->FindEle(pa, ele);
        if (index == -1)
        {
            cout << "查无此元素" << endl;
        }
        else
        {
            for (size_t i = index + 1; i < pa->size; i++)
            {
                pa->date[i - 1] = pa->date[i];
            }
            pa->size--;
        }
    }
    void InsertEle(ArrayList* pa, T ele, int index_)
    {
        //判断是否超过最大容量
        try
        {
            if (pa->size < pa->length)
            {
                for (size_t i = pa->size; i > index_; i--)
                {
                    pa->date[i] = pa->date[i - 1];
                }
                pa->date[index_] = ele;
                pa->size++;
            }
            else
            {
                throw runtime_error("空间已满，是否扩容 Y/N");
            }
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            char ch(0);
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                T* date_copy = new T[size + 1];
                for (size_t i = 0; i < pa->length; i++)
                {
                    date_copy[i] = date[i];
                }//将值存储到新空间
                delete[] date;
                if (date != nullptr)
                {
                    date = nullptr;
                }
                date = date_copy;
                date_copy = nullptr;
                pa->length++;
                date[length - 1] = ele;
                pa->size++;
            }
            else
            {
                cout << "不进行扩容，无法增添新元素" << endl;
                return;
            }
        }
    }
    void ChangeEle(ArrayList* pa, T ele, int index_)
    {
        pa->date[index_] = ele;
    }
public:
    T* date; //指针模拟数组
    int length; //理论最大容量
    int size; //实际大小
};

int main()
{
    ArrayList<int> myarr(10);
    myarr.AddEle(&myarr, 10);
    myarr.AddEle(&myarr, 11);
    myarr.AddEle(&myarr, 12);
    myarr.AddEle(&myarr, 13);
    myarr.AddEle(&myarr, 14);
    myarr.InsertEle(&myarr, 15, 5);
    myarr.AddEle(&myarr, 16);
    myarr.AddEle(&myarr, 17);
    cout << myarr.FindEle(&myarr, 11) << endl;
    myarr.DelEle(&myarr, 16);
    for (size_t i = 0; i < myarr.size; i++)
    {
        cout << myarr.date[i] << ' ';
    }
    return 0;
}