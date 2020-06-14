#ifndef HashTable_h
#define HashTable_h

#include <iostream>

#include "LinkNode.h"
#include "LinkedList.h"

template<typename T, int NumBuckets>
class HashTable
{
private:
    //SinglyLinkedList<T> array[NumBuckets];
    SinglyLinkedList<T>* array;
    int numBuckets;
    int numBucketsUsed;
    int numNodes;
    
    //SinglyLinkedList<T>** buckets_;
    void resize();
public:
    //Ctor
    HashTable();
    
    //Dtor
    ~HashTable();
    
    //Conversion operator
    const unsigned hash(unsigned key);
    
    //HashTable Operations
    void insert(T inputData);
    bool find(T inputData);
    void remove(T inputData);
    void print();
    
    //Efficiency related
    int size() { return numNodes; }
    double getLoadFactor(); //percetage of buckets used
    int getLongestList();
    double getAverageListSize(); //average non empty bucket size

};

template<typename T, int NumBuckets>
HashTable<T,NumBuckets>::HashTable() : numBuckets(NumBuckets),numBucketsUsed(0),numNodes(0)
{
    array = new SinglyLinkedList<T>[numBuckets];
    
}

//template<typename T, int NumBuckets>
//HashTable<T,NumBuckets>::HashTable() : numBuckets(NumBuckets), numBucketsUsed(0),numNodes(0), buckets_(new SinglyLinkedList<T>*[numBuckets])
//{ }

template<typename T, int NumBuckets>
HashTable<T,NumBuckets>::~HashTable()
{
    delete [] array;
    array = nullptr;
}

template<typename T, int NumBuckets>
void HashTable<T, NumBuckets>::insert(T inputData)
{
    if (getLoadFactor() > 0.75)
    {
        //resize();
        //std::cout<<"resized to: " << numBuckets << std::endl;
        auto index = hash(inputData);

        if ( array[index].isEmpty() )
        {
            array[index].insertAscending(inputData);
            numNodes++;
            numBucketsUsed++;
        } // No collision
        else
        {
            array[index].insertAscending(inputData);
            numNodes++;
        } // Collision
    } // Resize needed
    else
    {
        auto index = hash(inputData);

        if ( array[index].isEmpty() )
        {
            array[index].insertAscending(inputData);
            numNodes++;
            numBucketsUsed++;
        } // No collision
        else
        {
            array[index].insertAscending(inputData);
            numNodes++;
        } // Collision
    } // No resize needed
    
}

template<typename T, int NumBuckets>
void HashTable<T,NumBuckets>::resize()
{
    std::cout<<"Resize called"<<std::endl;
    SinglyLinkedList<T>* temp = new SinglyLinkedList<T>[2*numBuckets];
    
    for (auto i = 0; i < numBuckets; i++) // for the old array of lists
    {
        //Traverse down each node of the list
        for (auto i = 0; i < array[i].getCount(); i++)
        {
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
    }
    numBuckets*=2;
    delete [] array;
    array = temp;
}


template<typename T, int NumBuckets>
bool HashTable<T,NumBuckets>::find(T inputData)
{
    auto index = hash(inputData);
    
    if( array[index].isEmpty())
       return false;
    else return ( array[index].find(inputData) != 0 );
}

template<typename T, int NumBuckets>
void HashTable<T,NumBuckets>::remove(T inputData)
{
    auto index = hash(inputData);
    
    if( array[index].isEmpty() )
    {
        std::cerr << "Nothing to Remove" << std::endl;
        return;
    }
    if (array[index].find(inputData) == 0)
    {
        std::cerr << "Data not found" << std::endl;
        return;
    }
    else if (array[index].find(inputData) != 0)
    {
        array[index].deleteNode(inputData);
        numNodes--;
    }
    else
        std::cerr << "Uncaught error." << std::endl;
}

template<typename T, int NumBuckets>
const unsigned HashTable<T,NumBuckets>::hash(unsigned key)
{
    return key % NumBuckets;
}

template<typename T, int NumBuckets>
void HashTable<T,NumBuckets>::print()
{
    for (auto i = 0; i < numBuckets; i++)
    {
        std::cout << "Bucket " << i+1 << " :";
        array[i].print();
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
