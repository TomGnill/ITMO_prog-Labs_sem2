
#include <iostream>
#include"Exception.h"
#include <queue>  
#include <stdexcept>
#include <cassert>
using namespace std;
 template <typename T>
class queueT 
{
private:
    
    T* p;
    int count;
    int maximum;
   

public:

    queueT() { 
        count = 0; 
    };

    queueT(const queueT& obj)
    {
        count = obj.count;
    }
   int selectM(int max)
    {
        maximum=max;
        return max;
    }
    
    T  push(T item) //�������� ������� � �������
    {

      
            if (count == maximum){
                throw "queue full";
        }
      
        T* p2;
        p2 = p;
        try {
            // ������� �������� ����� �������� ������ ��� p, �� �� 1 ������
            p = new T[count + 1];

            // ����������� ������ �� ������� �� ������� ��������� p2 (������ ������)
            // � �������, �� ������� ��������� p
            for (int i = 0; i < count; i++)
                p[i] = p2[i];

            // ����������� ��������� �������
            p[count] = item;

            // ��������� ���������� ��������� �� 1
            count++;

            // ���������� �������������� ���������� ������
            if (count > 1)
                delete[] p2;
        }
        catch (bad_alloc e)
        {
            // ���� ������ �� ��������
            cout << e.what() << endl; // ������� ��������� �� ������

            // ������� ������ ��������� �� p
            p = p2;
        }
    }
    queueT& operator=(const queueT& obj)
    {
        T* p2; // ��������� �� �������������� ������

        try {
            // ������� �������� ����� ������� ������ ��� p2
            p2 = new T[obj.count];

            // ���� ������ �������� �������,
            // ����� ����������� �������������� ���������� ������ ��� p
            if (count > 0)
                delete[] p;

            // ����������� obj � ������� ������
            p = p2; // ������������� p �� p2
            count = obj.count;

            // ��������� ����������
            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        }
        catch (bad_alloc e)
        {
            // ���� ������ �� ����������, �� ������� ��������������� ���������
            cout << e.what() << endl;
        }
        return *this; // ������� ������� ������
    }

    void pop()
    {
        if (count == 0)
            return 0;

        // ��������� �������, ������� ������������ �� �������
        T item;

        item = p[0];

        // ������������ ����� ������� ������, ������� �� 1 ������
        try {
            T* p2;

            // ������� �������� ���'���
            p2 = new T[count - 1];

            count--; // ��������� ���������� ��������� � �������

            // p=>p2
            for (int i = 0; i < count; i++)
                p2[i] = p[i + 1]; // ���������� ��� ����� ������� ��������

              // ���������� �������, �� ������� ��������� p
            if (count > 0)
                delete[] p;

            // ������������� p �� p2
            p = p2;

            // ������� item
            return item;
        }
        catch (bad_alloc e)
        {
            // ���� ������ �� ����������, �� ������� 0
            cout << e.what() << endl;
            return 0;
        }
    }

   
   
    ~queueT() //����������
    {
        if (count > 0)
            delete[] p;
    }

   
    T GetItem()  // ����� ������ ������� �� ������� �� ��������� ���
    {
        try {
            if (count == 0)
                throw "queue is empoty.";
        }
        catch (const char * exception)
        {
            cerr << "Error:" << exception << "\n";
        }
        if (count > 0)
            return p[0];
        else
            return 0;
       
    }

    
    void clear()// ������� �������
    {
        if (count > 0)
        {
            delete[] p;
            count = 0;
        }
    }

    
    bool IsEmpty()// �������� ������������� ��������� � �������
    {
        return count == 0;
    }

  
    int GetN()  // ���������� ��������� � �������
    {
        return count;
    }

   
    void print(const char* objName)  //����� �������
    {
        cout << "Object: " << objName << endl;
        for (int i = 0; i < count; i++)
            cout << p[i] << "\t";
        cout << endl;
        cout << "---------------------" << endl;
    }
};