#ifndef BSTNode_h
#define BSTNode_h

#include <iostream>

template<typename T>
class BSTNode
{
private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
public:
    //Ctor
    BSTNode() : left(nullptr), right(nullptr){ }
    BSTNode(T inputData) : data(inputData), left(nullptr), right(nullptr) { }
    
    //Dtor
    ~BSTNode() = default;
    
    //Getters
    T getData() const { return data; }
    BSTNode<T>*& getLeft() { return left; }
    BSTNode<T>*& getRight() { return right; }
    
    //Setters
    void setData(const T inputData) { data = inputData; }
    void setLeft(BSTNode<T>* inputNode) { left = inputNode; }
    void setRight(BSTNode<T>* inputNode) { right = inputNode; }
    
    //overload << for testing
    friend std::ostream& operator<< (std::ostream& out, const BSTNode<T>& obj)
    {
        out << "data: " << obj.data << " left: " << obj.left << " right: " << obj.right << std::endl;
        return out;
    }

};

#endif /* BSTNode_h */
