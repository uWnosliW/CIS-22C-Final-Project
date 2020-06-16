//Keith
#ifndef HashTable_h
#define HashTable_h

#include <iostream>

#include "LinkNode.h"
#include "LinkedList.h"

template<typename T, int NumBuckets>
class HashTable
{
private:
    SinglyLinkedList<T>* array;
    int numBuckets;
    int numBucketsUsed;
    int numNodes;

private:
    void resize();
    const unsigned hash(unsigned key);
    
public:
    //Ctor
    HashTable();
    
    //Dtor
    ~HashTable();
    
    //HashTable Operations
    // Description: inserts a node into hashtable
    // Pre: T inputData - data to insert
    // Post: node gets inserted and certain pointers are modified, table gets resized if a critical load factor is reached
    // Return:
    void insert(T inputData);
    
    // Description: finds an object in hashtable
    // Pre: T inputData - data to find
    // Post:
    // Return: object if found
    T find(T inputData);
    
    // Description: removes an object from hashtable
    // Pre: T inputData - data to remove
    // Post: modifies linkedlist that object is found in
    // Return: true if deletion was successful
    bool remove(T inputData);
    
    // Description: prints hashtable contents
    // Pre:
    // Post: 
    // Return:
    void print();
    
    //Efficiency related
    int size() { return numNodes; }
    double getLoadFactor(); //percetage of buckets used
    int getLongestList();
    double getAverageListSize(); //average non empty bucket size

};

template<typename T, int NumBuckets>
HashTable<T,NumBuckets>::HashTable() : numBuckets(NumBuckets),numBucketsUsed(0),numNodes(0), array(new SinglyLinkedList<T>[NumBuckets])
{ }

template<typename T, int NumBuckets>
HashTable<T,NumBuckets>::~HashTable()
{
    delete [] array;
    array = nullptr;
}

template<typename T, int NumBuckets>
void HashTable<T, NumBuckets>::insert(T inputData)
{
    if (getLoadFactor() >= 0.75)
    {
        resize();
        //std::cout<<"resized to: " << numBuckets << std::endl;
        auto index = hash(inputData);
        
        if (array[index].isEmpty())
        {
            numBucketsUsed++;
        } //No collision
        
        array[index].insertAscending(inputData);
        numNodes++;

    } // Resize needed
    else
    {
        auto index = hash(inputData);

        if (array[index].isEmpty())
        {
            numBucketsUsed++;
        } //No collision
        
        array[index].insertAscending(inputData);
        numNodes++;
    } // No resize needed
    
}

template<typename T, int NumBuckets>
void HashTable<T,NumBuckets>::resize()
{
    SinglyLinkedList<T>* temp = new SinglyLinkedList<T>[2*numBuckets];
    numBuckets*=2;

    for (auto i = 0; i < numBuckets/2; i++) // for the old array of lists
    {
        //Traverse down each node of the list
        //Get data from each node and hash it, then insert into new array
        LinkNode<T>* nodePtr = nullptr;
        nodePtr = array[i].getStart();
        
        while (nodePtr != nullptr)
        {
            auto index = hash(nodePtr->data);
            temp[index].insertAscending(nodePtr->data);
            
            nodePtr = nodePtr->next;
        }
    }
    delete [] array;
    array = temp;
}


template<typename T, int NumBuckets>
T HashTable<T,NumBuckets>::find(T inputData)
{
    auto index = hash(inputData);
    
    if( array[index].isEmpty())
       return T();
    else
        return array[index].find(inputData);
}

template<typename T, int NumBuckets>
bool HashTable<T,NumBuckets>::remove(T inputData)
{
    auto index = hash(inputData);
    
    if( array[index].isEmpty() )
    {
        return false;
    }
    if (array[index].find(inputData) == 0)
    {
        return false;
    }
    else if (array[index].find(inputData) != 0)
    {
        return array[index].deleteNode(inputData);
        numNodes--;
    }
    else
        return false;
}

template<typename T, int NumBuckets>
const unsigned HashTable<T,NumBuckets>::hash(unsigned key)
{
    //std::cout<<"key: " << key << " hash: " << key%numBuckets << std::endl;
    return key % numBuckets;
}

template<typename T, int NumBuckets>
void HashTable<T,NumBuckets>::print()
{
    for (auto i = 0; i < numBuckets; i++)
    {
        if(!array[i].isEmpty())
        {
            std::cout << "Bucket " << i+1 << " :" << std::endl;
            array[i].print();
        }
    }
}

template<typename T, int NumBuckets>
double HashTable<T, NumBuckets>::getLoadFactor()
{
    return static_cast<double>(numBucketsUsed)/numBuckets;
}

template<typename T, int NumBuckets>
int HashTable<T, NumBuckets>::getLongestList()
{
    int largest = 0;
    
    for (auto i = 0; i < numBuckets; i++)
    {
        if ( (!array[i].isEmpty()) && (array[i].getCount() > largest) )
            largest = array[i].getCount();
    }
    return largest;
}

template<typename T, int NumBuckets>
double HashTable<T, NumBuckets>::getAverageListSize()
{
    double averageListSize = 0;
    
    for (auto i = 0; i < numBuckets; i++)
    {
        if (! (array[i].isEmpty()) )
            averageListSize += array[i].getCount();
    }
    return (averageListSize/numBucketsUsed);
}



#endif /* HashTable_h */
