//Wilson ueues as derived classes of Linked List

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
#include "LinkNode.h"
using std::cout;
using std::endl;
using std::string;

template <typename T>
class SinglyLinkedList
{
protected:
    int count;
    int searchQueries;
    int searchOperations;
    int insertionQueries;
    int insertionOperations;
    LinkNode<T>* start;
    LinkNode<T>* end;
    
public:
    //Ctor
    SinglyLinkedList() : count(0), start(nullptr), end(nullptr), searchQueries(0), searchOperations(0), insertionQueries(0), insertionOperations(0) { }
    
    //Dtor
    virtual ~SinglyLinkedList();
    
    //Getter for head node
    LinkNode<T>* getStart() {return start; }
    
    //Insert into linked list in ascending order
    void insertAscending(T inputData);
    
    // Description: shows number of elements in the list
    // Pre:
    // Post:
    // Return: length of list
    int getCount() { return count; }
    
    //Setters
    // Description: increments length of list
    // Pre:
    // Post: adds 1 to count
    // Return:
    void incrementCount() { count++; }
    
    // Description: decrements length of list
    // Pre:
    // Post: subtract 1 from count
    // Return:
    void decrementCount() { count--; }
    
    //Generic List type implementation functions
    
    
    // Description: increments length of list
    // Pre:
    // Post: adds 1 to count
    // Return:
    T find(T obj);
    
    // Description: prints elements of the list in order
    // Pre:
    // Post:
    // Return:
    virtual void print() const;
    
    // Description: shows if the linked list is empty
    // Pre:
    // Post:
    // Return: true if the list is empty
    virtual bool isEmpty();
    
    // Description: deletes all elements in the list
    // Pre:
    // Post: deletes all elements in the array and resets the start and end pointers
    // Return:
    virtual void clear();
    
    // Description: shows name of the data structure
    // Pre:
    // Post:
    // Return: returns "Linked List"
    virtual string getStructName() { return "Linked List"; }
    
    //Node Operations
    
    // Description: returns node with specific element
    // Pre:
    // Post:
    // Return: node with inputdata
    LinkNode<T>* getNode(T inputData);
    
    // Description: inserts node to end of list
    // Pre:
    // Post: inserts node to end of list, updates pointer of second last node
    // Return:
    void appendNode(T inputData);
    
    // Description: inserts node to start of list
    // Pre:
    // Post: inserts node to start of list, updates start pointer
    // Return:
    void prependNode(T inputData);
    
    // Description: inserts new node after finding a certain node
    // Pre:
    // Post: finds obj then points it to a new node with inputdata
    // Return:
    void insertNode(T obj, T inputData);
    
    // Description: deletes an element from linked list
    // Pre:
    // Post: deletes node with inputdata
    // Return:
    bool deleteNode(T inputData);
    
};

template <typename T>
T SinglyLinkedList<T>::find(T obj)
{
    searchQueries++;
    if (isEmpty())
        return T();
    else
    {
        LinkNode<T>* nodePtr = nullptr;
        nodePtr = start;
        
        while (nodePtr != nullptr)
        {
            searchOperations++;
            if (nodePtr->data == obj)
                return nodePtr->data;
            
            nodePtr = nodePtr->next;
        }
        searchOperations++;
        return T();
    }
}
template<typename T>
void SinglyLinkedList<T>::insertAscending(T inputData)
{
    LinkNode<T>* newNode = nullptr;
    LinkNode<T>* nodePtr = nullptr;
    LinkNode<T>* previousNode = nullptr;

    newNode = new LinkNode<T>;
    newNode->data = inputData;

    if (isEmpty())
    {
        start = newNode;
        newNode->next = nullptr;
        incrementCount();
    }
    else
    {
        nodePtr = start;

        while (nodePtr != nullptr && nodePtr->data < inputData)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr)
        {
            start = newNode;
            newNode->next = nodePtr;
        } // if target is first node
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        } // else insert after previous node
        incrementCount();
    }
}
template <typename T>
bool SinglyLinkedList<T>::isEmpty()
{
    return (start == nullptr);
}

template <typename T>
LinkNode<T>* SinglyLinkedList<T>::getNode(T obj)
{
    if (start == nullptr)
        return nullptr;
    else
    {
        LinkNode<T>* nodePtr = start;
        while (nodePtr != nullptr)
        {
            if (nodePtr->data == obj)
                return nodePtr;
            nodePtr = nodePtr->next;
        }
    }
    return nullptr;
}

template <typename T>
void SinglyLinkedList<T>::prependNode(T inputData)
{
    LinkNode<T>* newNode = new LinkNode<T>;
    newNode -> data = inputData;
    if(isEmpty())
    {
        start = newNode;
        end = newNode;
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = start;
        start = newNode;
    }
    incrementCount();
}

template <typename T>
void SinglyLinkedList<T>::appendNode(T inputData)
{
    LinkNode<T>* newNode = nullptr; // Points to new node
    LinkNode<T>* nodePtr = nullptr; // Move through the list
    
    //Make new node, populate with data and set next to nullptr
    newNode = new LinkNode<T>;
    newNode->data = inputData;
    newNode->next = nullptr;
    
    if (isEmpty())
    {
        start = newNode;
        end = newNode;
    }
    else
    {
        nodePtr = start;      //start traversing from start node
        
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;   //set nodePtr to the next node
        }
        
        //insert newNode and end as next
        nodePtr->next = newNode;
        end = nodePtr->next;
    }
    incrementCount();
}

template <typename T>
void SinglyLinkedList<T>::insertNode(T obj, T inputData)
{
    insertionQueries++;
    if(end -> data == obj)
    {
        appendNode(inputData);
    }
    else
    {
        LinkNode<T>* currNode = start; //Get to correct index
        while(currNode->data!=obj)
        {
            insertionOperations++;
            if (currNode->next == nullptr)
                break;
            currNode = currNode -> next;
        }
        insertionOperations++;
        LinkNode<T>* newNode = new LinkNode<T>;//insert new LinkNode
        newNode -> data = inputData;
        newNode -> next = currNode -> next;
        currNode -> next = newNode;
        incrementCount();
    }
}

template <typename T>
bool SinglyLinkedList<T>::deleteNode(T inputData)
{
    LinkNode<T>* nodePtr = nullptr;
    LinkNode<T>* previous = nullptr;
    
    if (isEmpty())
        return false;
    
    //If we are deleting first node
    if (start->data == inputData)
    {
        nodePtr = start->next;
        delete start;
        start = nodePtr;
        decrementCount();
        return true;
    } else
    {
        nodePtr = start;
        //Traverse through list
        while (nodePtr != nullptr && nodePtr->data != inputData)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
            
            end = nodePtr;
        }
        
        //If not the last node
        if (nodePtr)
        {
            previous->next = nodePtr->next;
            delete nodePtr;
            return true; 
        }
        decrementCount();
    }
    return false;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    if (!isEmpty())
        clear();
}

template<typename T>
void SinglyLinkedList<T>::clear()
{
    LinkNode<T>* nodePtr;
    LinkNode<T>* next;
    
    nodePtr = start;
    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
    
    start = nullptr;
    end = nullptr;
    count = 0;
}

template<typename T>
void SinglyLinkedList<T>::print() const
{
    LinkNode<T>* nodePtr;
    nodePtr = start;
    
    while (nodePtr != nullptr)
    {
        T temp = nodePtr->data;
        
        cout << temp << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
#endif /* LinkedList_h */
