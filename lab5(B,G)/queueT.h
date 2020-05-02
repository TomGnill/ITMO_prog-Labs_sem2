
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
    
    T  push(T item) //добавить элемент в очередь
    {

      
            if (count == maximum){
                throw "queue full";
        }
      
        T* p2;
        p2 = p;
        try {
            // попытка выделить новый фрагмент пам€ти дл€ p, но на 1 больше
            p = new T[count + 1];

            // скопировать данные из участка на который указывает p2 (старые данные)
            // в участок, на который указывает p
            for (int i = 0; i < count; i++)
                p[i] = p2[i];

            // скопировать последний элемент
            p[count] = item;

            // увеличить количество элементов на 1
            count++;

            // освободить предварительно выделенную пам€ть
            if (count > 1)
                delete[] p2;
        }
        catch (bad_alloc e)
        {
            // если пам€ть не выделена
            cout << e.what() << endl; // вывести сообщение об ошибке

            // вернуть старый указатель на p
            p = p2;
        }
    }
    queueT& operator=(const queueT& obj)
    {
        T* p2; // указатель на дополнительную пам€ть

        try {
            // попытка выделить новый участок пам€ти дл€ p2
            p2 = new T[obj.count];

            // если пам€ть выделена успешно,
            // можно освобождать предварительно выделенную пам€ть дл€ p
            if (count > 0)
                delete[] p;

            // скопировать obj в текущий объект
            p = p2; // перенаправить p на p2
            count = obj.count;

            // заполнить значени€ми
            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        }
        catch (bad_alloc e)
        {
            // если пам€ть не выделилась, то вывести соответствующее сообщение
            cout << e.what() << endl;
        }
        return *this; // вернуть текущий объект
    }

    void pop()
    {
        if (count == 0)
            return 0;

        // заполнить элемент, который выт€гиваетс€ из очереди
        T item;

        item = p[0];

        // сформировать новый участок пам€ти, который на 1 меньше
        try {
            T* p2;

            // попытка выделить пам'€ть
            p2 = new T[count - 1];

            count--; // уменьшить количество элементов в очереди

            // p=>p2
            for (int i = 0; i < count; i++)
                p2[i] = p[i + 1]; // копируютс€ все кроме первого элемента

              // освободить участок, на который указывает p
            if (count > 0)
                delete[] p;

            // перенаправить p на p2
            p = p2;

            // вернуть item
            return item;
        }
        catch (bad_alloc e)
        {
            // если пам€ть не выделилась, то вернуть 0
            cout << e.what() << endl;
            return 0;
        }
    }

   
   
    ~queueT() //деструктор
    {
        if (count > 0)
            delete[] p;
    }

   
    T GetItem()  // вз€ть первый элемент из очереди не выт€гива€ его
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

    
    void clear()// очистка очереди
    {
        if (count > 0)
        {
            delete[] p;
            count = 0;
        }
    }

    
    bool IsEmpty()// проверка существовани€ элементов в очереди
    {
        return count == 0;
    }

  
    int GetN()  // количество элементов в очереди
    {
        return count;
    }

   
    void print(const char* objName)  //вывод очереди
    {
        cout << "Object: " << objName << endl;
        for (int i = 0; i < count; i++)
            cout << p[i] << "\t";
        cout << endl;
        cout << "---------------------" << endl;
    }
};