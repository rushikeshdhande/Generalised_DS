///////////////////////////////////////////////////
//      Generalised Data Structure Library
///////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------
Type                    Name of class for node      Name of class for Functionality
---------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode               SinglyLLL          Done
Singly Cirular           SinglyCLLnode               SinglyCLL          Done
Doubly Linear            DoublyLLLnode               DoublyLLL          Done
Doubly Circular          DoublyCLLnode               DoublyCLL          Done
Stack                    Stacknode                   Stack              Done
Queue                    Queuenode                   Queue              Done
---------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear Linlked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
public:
    T data;
    SinglyLLLnode<T> *next;

    SinglyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyLLL
{
private:
    SinglyLLLnode<T> *first;
    int iCount;

public:
    SinglyLLL();
    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T, int);
    void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout << "Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Rushikesh Baban Dhande
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if (this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for (iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//          Singly Circular LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyCLLnode
{
public:
    T data;
    SinglyCLLnode<T> *next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyCLL
{
private:
    SinglyCLLnode<T> *first;
    SinglyCLLnode<T> *last;
    int iCount;

public:
    SinglyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout << "Object of Singly Circular Linked List gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> *temp = first;

    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    if ((pos < 1) || (pos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);
        SinglyCLLnode<T> *temp = first;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 1) || (pos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        SinglyCLLnode<T> *temp = first;
        SinglyCLLnode<T> *target = NULL;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

template <class T>
void SinglyCLL<T>::Display()
{
    if (first == NULL && last == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    SinglyCLLnode<T> *temp = first;
    cout << "->";
    do
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    } while (temp != last->next);
    cout << "\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//          Doubly Linear Linlked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
public:
    T data;
    DoublyLLLnode *next;
    DoublyLLLnode *prev;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
private:
    DoublyLLLnode<T> *first;
    int iCount;

public:
    DoublyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if (this->first == NULL) // LL is empty
    {
        return;
    }
    else if (this->first->next == NULL) // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else // LL contains more than 1 node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

template <class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if (this->first == NULL) // LL is empty
    {
        return;
    }
    else if (this->first->next == NULL) // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else // LL contains more than 1 node
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

template <class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout << "\nNULL<=>";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Doubly Circular LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyCLLnode
{
public:
    T data;
    DoublyCLLnode *next;
    DoublyCLLnode *prev;

    DoublyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCLL
{
private:
    DoublyCLLnode<T> *first;
    DoublyCLLnode<T> *last;
    int iCount;

public:
    DoublyCLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout << "Object of Doubly Circular Linked List gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    if ((pos < 1) || (pos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);
        DoublyCLLnode<T> *temp = first;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 1) || (pos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        DoublyCLLnode<T> *temp = first;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

template <class T>
void DoublyCLL<T>::Display()
{
    if (first == NULL && last == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    DoublyCLLnode<T> *temp = first;
    cout << "<=>";
    do
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    } while (temp != last->next);
    cout << "\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//                  Stack using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
public:
    T data;
    Stacknode<T> *next;

    Stacknode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class Stack
{
private:
    Stacknode<T> *first;
    int iCount;

public:
    Stack();

    void push(T);
    T pop();
    T peep();
    void Display();
    int Count();
};

template <class T>
Stack<T>::Stack()
{
    cout << "Stack gets created succesfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void Stack<T>::push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
T Stack<T>::pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template <class T>
T Stack<T>::peep()
{
    T Value = 0;

    if (this->first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

template <class T>
void Stack<T>::Display()
{
    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
public:
    T data;
    Queuenode<T> *next;

    Queuenode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class Queue
{
private:
    Queuenode<T> *first;
    Queuenode<T> *last;

    int iCount;

public:
    Queue();

    void enqueue(T);
    T dequeue();
    void Display();
    int Count();
};

template <class T>
Queue<T>::Queue()
{
    cout << "Queue gets created succesfully...\n";

    this->first = NULL;
    this->last = NULL;

    this->iCount = 0;
}

template <class T>
void Queue<T>::enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if (this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
}

template <class T>
T Queue<T>::dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template <class T>
void Queue<T>::Display()
{
    Queuenode<T> *temp = this->first;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | - ";
        temp = temp->next;
    }

    cout << "\n";
}

template <class T>
int Queue<T>::Count()
{
    return this->iCount;
}

//////////////////////////////// End of Library //////////////////////////////////

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();

    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->InsertAtPos(105, 4);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    delete obj;

    ///////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout << "Number of elements are : " << dobj->Count() << "\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout << "Number of elements are : " << dobj->Count() << "\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout << "Number of elements are : " << dobj->Count() << "\n";

    dobj->DeleteLast();

    dobj->Display();

    cout << "Number of elements are : " << dobj->Count() << "\n";

    dobj->InsertAtPos('$', 4);

    dobj->Display();

    cout << "Number of elements are : " << dobj->Count() << "\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout << "Number of elements are : " << dobj->Count() << "\n";

    delete dobj;

    ///////////////////////////////////////////////////////////////////////

    SinglyCLL<int> *scobj = new SinglyCLL<int>();

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);

    scobj->Display();

    iRet = scobj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    scobj->InsertLast(101);
    scobj->InsertLast(111);
    scobj->InsertLast(121);

    scobj->Display();

    iRet = scobj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    scobj->DeleteFirst();
    scobj->Display();

    iRet = scobj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    scobj->DeleteLast();

    scobj->Display();

    iRet = scobj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    scobj->InsertAtPos(105, 4);

    scobj->Display();

    iRet = scobj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    scobj->DeleteAtPos(4);

    scobj->Display();

    iRet = scobj->Count();
    cout << "Number of nodes are : " << iRet << "\n";

    delete scobj;

    ///////////////////////////////////////////////////////////////////////

    DoublyCLL<char> *dcobj = new DoublyCLL<char>();

    dcobj->InsertFirst('A');
    dcobj->InsertFirst('B');
    dcobj->InsertFirst('C');

    dcobj->Display();

    cout << "Number of elements are : " << dcobj->Count() << "\n";

    dcobj->InsertLast('X');
    dcobj->InsertLast('Y');
    dcobj->InsertLast('Z');

    dcobj->Display();

    cout << "Number of elements are : " << dcobj->Count() << "\n";

    dcobj->DeleteFirst();

    dcobj->Display();

    cout << "Number of elements are : " << dcobj->Count() << "\n";

    dcobj->DeleteLast();

    dcobj->Display();

    cout << "Number of elements are : " << dcobj->Count() << "\n";

    dcobj->InsertAtPos('$', 4);

    dcobj->Display();

    cout << "Number of elements are : " << dcobj->Count() << "\n";

    dcobj->DeleteAtPos(4);

    dcobj->Display();

    cout << "Number of elements are : " << dcobj->Count() << "\n";

    delete dcobj;

    ///////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    cout << "Return value of peep is : " << sobj->peep() << "\n";

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    cout << "Poped element is : " << sobj->pop() << "\n";

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    cout << "Poped element is : " << sobj->pop() << "\n";

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    sobj->push('e');

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    delete sobj;

    ///////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();

    cout << "Number of elements in queue are : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();

    cout << "Number of elements in queue are : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();

    cout << "Number of elements in queue are : " << qobj->Count() << "\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout << "Number of elements in queue are : " << qobj->Count() << "\n";

    delete qobj;

    return 0;
}
