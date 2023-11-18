#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdexcept>
using namespace std;
template<class T>
class ArrayList
{
public:
    ArrayList(int Num) :size(0) //��ʼ�����캯��
    {
        date = new T[Num];      
        if (data == nullptr)
        {
            cout << "����ʧ��" << endl;
        }
        length = Num;
    }
    void AddEle(ArrayList* pa, T ele)//����Ԫ��
    {
        //�ж��Ƿ񳬹��������
        try
        {
            if (pa->size < pa->length)
            {
                pa->date[size] = ele;
                pa->size++;
            }
            else
            {
                throw runtime_error("�ռ��������Ƿ����� Y/N");
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
                }//��ֵ�洢���¿ռ�
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
                cout << "���������ݣ��޷�������Ԫ��" << endl;
                return;
            }
        }
    }
    int FindEle(ArrayList* pa, T ele)//����Ԫ��
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
            cout << "���޴�Ԫ��" << endl;
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
        //�ж��Ƿ񳬹��������
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
                throw runtime_error("�ռ��������Ƿ����� Y/N");
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
                }//��ֵ�洢���¿ռ�
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
                cout << "���������ݣ��޷�������Ԫ��" << endl;
                return;
            }
        }
    }
    void ChangeEle(ArrayList* pa, T ele, int index_)
    {
        pa->date[index_] = ele;
    }
public:
    T* date; //ָ��ģ������
    int length; //�����������
    int size; //ʵ�ʴ�С
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