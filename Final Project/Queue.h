//Wilson Wu and Keith
//Lab 4
//Implement Stacks and Queues as derived classes of Linked List

#ifndef Queue_h
#define Queue_h
#include "LinkedList.h"
#include "LinkNode.h"

template<typename T> class Queue : protected SinglyLinkedList<T>
{
public:
    Queue(): SinglyLinkedList<T>(){};
    virtual ~Queue();
    
    // Description: enqueues element to the end of the queue
    // Pre:
    // Post: new node created and becomes the tail of the queue
    // Return:
    void enqueue(T obj);
    
    // Description: dequeues first element of the queue
    // Pre:
    // Post: first node is deleted and the start pointer now points to the second node
    // Return:
    void dequeue();
    
    // Description: shows first element in queue
    // Pre:
    // Post:
    // Return: first element in the queue
    T peekFront();
    
    // Description: shows last element in queue
    // Pre:
    // Post:
    // Return: last element in the queue
    T peekRear();
    
    // Description: delete all elements from queue
    // Pre:
    // Post: delete all elements and reset start and end pointers
    // Return:
    void clear();
    
    // Description: shows if queue is empty
    // Pre:
    // Post:
    // Return: true if queue is empty
    bool isEmpty();
protected:
private:
};


template<typename T>
void Queue<T>::enqueue(T obj)
{
    SinglyLinkedList<T>::appendNode(obj);
}

template<typename T>
void Queue<T>::dequeue()
{
    SinglyLinkedList<T>::deleteNode(SinglyLinkedList<T>::start -> data);
}

template<typename T>
T Queue<T>::peekFront()
{
    return SinglyLinkedList<T>::start -> data;
}

template<typename T>
T Queue<T>::peekRear()
{
    return SinglyLinkedList<T>::end -> data;
}

template<typename T>
void Queue<T>::clear()
{
    SinglyLinkedList<T>::clear();
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return SinglyLinkedList<T>::isEmpty();
}

template<typename T>
Queue<T>::~Queue()
{
    LinkNode<T>* nodePtr;
    LinkNode<T>* next;
    nodePtr = SinglyLinkedList<T>::start;
    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}

#endif /* Queue_h */
