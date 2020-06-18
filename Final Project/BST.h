//Keith and Wilson
#ifndef BST_h
#define BST_h

#include <iostream>
#include "BSTNode.h"
#include "Queue.h"
#include "Airline.h"
template<typename T>
class BST
{
private:
    BSTNode<T>* root;
    int count;
    int searchQueries;
    int searchOperations;
    int insertionQueries;
    int insertionOperations;
    // Description: finds a specific object in the BST
    // Pre: BSTNode<T>* nodePtr - root node
    //      T inputData - object to find
    // Post:
    // Return: pointer to BSTNode if found, nullptr otherwise
    BSTNode<T>* search(BSTNode<T>* nodePtr, T inputData);
    
    // Description: finds a specific object in the BST
    // Pre: BSTNode<T>* nodePtr - root node
    //      T inputData - object to find
    // Post:
    // Return: pointer to BSTNode if found, nullptr otherwise
    void insert(BSTNode<T>*& nodePtr, BSTNode<T>*& newNode);
    
    // Description: finds a specific object in the BST
    // Pre: BSTNode<T>* nodePtr - root node
    //      T inputData - object to find
    // Post:
    // Return: pointer to BSTNode if found, nullptr otherwise
    void printInOrder(BSTNode<T>* nodePtr, std::ostream &out) const;
    
    // Description: Prints BST preorder
    // Pre:
    // Post:
    // Return:
    void printPreOrder(BSTNode<T>* nodePtr, std::ostream &out) const;
    
    // Description: Prints BST preorder
    // Pre:
    // Post:
    // Return:
    void printPostOrder(BSTNode<T>* nodePtr, std::ostream &out) const;
    
    // Description: prints BST as an indented tree sideways
    // Pre:
    // Post:
    // Return:
    void printIndentedTree(int level, int parentLevel, bool left, BSTNode<T>* nodePtr, std::ostream &out = std::cout) const;
    
    // Description: Prints BST preorder
    // Pre:
    // Post:
    // Return:
    bool remove(T inData, BSTNode<T>*& nodePtr);
    
public:
    //Ctor
    BST() : root(nullptr),count(0),searchQueries(0), searchOperations(0), insertionQueries(0), insertionOperations(0) { }
    
    //Dtor
    ~BST() { clear(root); }
    
    int getSearchQueries() const {return searchQueries;}
    int getSearchOperations() const {return searchOperations;}
    int getInsertionQueries() const {return insertionQueries;}
    int getInsertionOperations() const {return insertionOperations;}
    
    //BST Operations
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    BSTNode<T>* search(T inputData)
    {
        searchQueries++;
        return search(root, inputData);
    }
    
    // Description: inserts a node into bst
    // Pre: T inputData - data to insert
    // Post: node gets inserted and certain pointers are modified
    // Return:
    void insertNode(T inputData);
    
    // Description: deletes an element into bst
    // Pre: T inputData - data to delete
    // Post: node gets deleted and certain pointers are modified
    // Return: true if deletion was successful
    bool deleteNode(T inputData);
    
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    void printInOrder(std::ostream &out = std::cout) const { printInOrder(root,out); }
    
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    void printPreOrder(std::ostream &out = std::cout) const { printPreOrder(root,out); }
    
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    void printPostOrder(std::ostream &out = std::cout) const { printPostOrder(root,out); }
    
    // Description: prints BST in order
    // Pre:
    // Post:
    // Return:
    void printBreadthFirst(std::ostream &out = std::cout) const;
    
    // Description: prints BST as an indented tree sideways
    // Pre:
    // Post:
    // Return:
    void printIndentedTree(int level = 0, std::ostream &out = std::cout) const {printIndentedTree(0,0,false, root,out);}
    
    // Description: shows how many nodes are in the BST
    // Pre:
    // Post:
    // Return: number of nodes
    int getCount() const { return count; }
    
    
    // Description: shows if BST is empty
    // Pre:
    // Post:
    // Return: true if BST is empty
    bool isEmpty() const { return count == 0; }
    
    
    
    // Description: deletes all BSTNodes
    // Pre:
    // Post: deletes all BSTNodes count set to 0
    // Return:
    void clear(BSTNode<T>* nodePtr);
};
template <typename T>
BSTNode<T>* BST<T>::search(BSTNode<T>* nodePtr, T inputData)
{
    searchOperations++;
    T data = nodePtr->getData();
    //std::cout<<"searching "<<data<<endl;
    if(data == inputData)
    {
        return nodePtr;
    }
    if(data > inputData)
    {
        return nodePtr->getLeft() != nullptr ? search(nodePtr->getLeft(),inputData):nullptr;
    }
    else
    {
        return nodePtr->getRight() != nullptr ? search(nodePtr->getRight(), inputData):nullptr;
    }
}

template<typename T>
void BST<T>::insert(BSTNode<T>*& nodePtr, BSTNode<T>*& newNode)
{
    insertionOperations++;
    BSTNode<T>* curr = nodePtr;
    if(curr == nullptr)
    {
        root = newNode;
        return;
    }
    while((newNode -> getData() < curr -> getData() && curr -> getLeft() != nullptr) ||
          (newNode -> getData() > curr -> getData() && curr -> getRight() != nullptr))
    {
        insertionOperations++;
        curr = (newNode -> getData() < curr -> getData())? curr -> getLeft(): curr->getRight();
    }
    //Airline temp = newNode->getData(), temp2 = curr -> getData();
    //cout<<"insert comp: "<<temp<< temp2<<endl;
    if(newNode -> getData() < curr -> getData())
    {
        curr -> setLeft(newNode);
    }
    else
    {
        curr -> setRight(newNode);
    }
}

template<typename T>
void BST<T>::insertNode(T inputData)
{
    BSTNode<T>* newNode = nullptr;
    insertionQueries++;
    newNode = new BSTNode<T>(inputData);
    count++;
    //std::cout << "Create new node obj for " << inputData << std::endl;
    insert(root, newNode);
}
template<typename T>
void BST<T>::printInOrder(BSTNode<T>* nodePtr, std::ostream &out) const
{
    if (nodePtr != nullptr)
    {
        printInOrder(nodePtr->getLeft(),out);
        T t = nodePtr->getData();
        out << t << std::endl;
        printInOrder(nodePtr->getRight(),out);
    }
}
template<typename T>
void BST<T>::printIndentedTree(int level, int parentLevel, bool left, BSTNode<T>* nodePtr, std::ostream &out) const
{
    if (nodePtr != nullptr)
    {
        printIndentedTree(level+1, level, false, nodePtr->getRight(),out);
        string dash = "--------------";
        string space = "              ";
        string spacing = "";
        for(int i=0;i<parentLevel;i++)
        {
            spacing+= space;
        }
        if(level>parentLevel)
        {
            if(left)
            {
                spacing+="         \\------";
            }
            else
            {
                spacing+="         /------";
            }
            for(int i=0;i<level-parentLevel-1;i++)
            {
                spacing+=space;
            }
        }
        std::string t = nodePtr->getData().getKey();
        out << spacing<< t << std::endl;
        printIndentedTree(level+1, level, true, nodePtr->getLeft(),out);
    }
}
template<typename T>
void BST<T>::printPreOrder(BSTNode<T>* nodePtr, std::ostream &out) const
{
    if (nodePtr != nullptr)
    {
        T t = nodePtr->getData();
        out << t << std::endl;
        printPreOrder(nodePtr->getLeft(),out);
        printPreOrder(nodePtr->getRight(),out);
    }
}
template<typename T>
void BST<T>::printPostOrder(BSTNode<T>* nodePtr, std::ostream &out) const
{
    if (nodePtr != nullptr)
    {
        printPostOrder(nodePtr->getLeft(),out);
        printPostOrder(nodePtr->getRight(),out);
        T t = nodePtr->getData();
        out << t << std::endl;
    }
}
template<typename T>
void BST<T>::printBreadthFirst(std::ostream &out) const
{
    Queue<BSTNode<T>*> next;
    BSTNode<T>* curr;
    next.enqueue(root);
    while(!next.isEmpty())
    {
        curr = next.peekFront();
        out<<curr->getData()<<std::endl;
        next.dequeue();
        if(curr->getLeft())
        {
            next.enqueue(curr->getLeft());
        }
        if(curr->getRight())
        {
            next.enqueue(curr->getRight());
        }
    }
}
template<typename T>
void BST<T>::clear(BSTNode<T>* nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->getLeft())
            clear(nodePtr->getLeft());
        if (nodePtr->getRight())
            clear(nodePtr->getRight());
        delete nodePtr;
    }
}

template<typename T>
bool BST<T>::remove(T inData, BSTNode<T>*& nodePtr)
{
    //cout<<"Removing "<<nodePtr -> getData()<<" "<<nodePtr -> getLeft()<<" "<<nodePtr->getRight()<<endl;
    BSTNode<T>* prev = nullptr;
    BSTNode<T>* curr = nodePtr;
    while(curr != nullptr)
    {
        //cout<<curr -> getData()<<curr -> getLeft()<<" "<<curr -> getRight()<<" "<<prev<<endl;
        if(inData > curr->getData())
        {
            prev = curr;
            curr = curr->getRight();
        }
        else if(inData < curr->getData())
        {
            prev = curr;
            curr = curr->getLeft();
        }
        else
        {
            if (curr -> getLeft() == nullptr && curr -> getRight() == nullptr)
            {
               if (prev == nullptr)
               {
                   nodePtr = nullptr;
               }
               else if (prev -> getLeft() == curr)
               {
                   prev -> setLeft(nullptr);
               }
               else
               {
                   prev -> setRight(nullptr);
               }
            }
            else if (curr -> getLeft() != nullptr && curr -> getRight() == nullptr)
            {
                if (prev == nullptr)
                {
                     nodePtr = curr->getLeft();
                }
                else if (prev->getLeft() == curr)
                {
                    prev->setLeft(curr->getLeft());
                }
                else
                {
                    prev->setRight(curr->getLeft());
                }
            }
            else if (curr->getLeft() == nullptr && curr->getRight() != nullptr)
            {
               if (prev == nullptr)
               {
                   nodePtr = curr -> getRight();
               }
               else if (prev->getLeft() == curr)
               {
                   prev->setLeft(curr->getRight());
               }
               else
               {
                   prev->setRight(curr->getRight());
               }
            }
            else {
                BSTNode<T>* next = curr->getRight();
                while (next->getLeft() != nullptr)
                {
                    next = next -> getLeft();
                }
                T tempData = next -> getData();
                remove(tempData, nodePtr);
                curr->setData(tempData);
            }
            return true;
             // Node found and removed
        }
    }
    return false;
}

template<typename T>
bool BST<T>::deleteNode(T inputData)
{
    count--;
    return remove(inputData, root);
}
#endif /* BST_h */
