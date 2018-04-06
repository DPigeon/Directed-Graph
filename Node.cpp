#include <iostream>
#include "Node.h"

using namespace std;

// default constructor
template <class T>
Node<T>::Node(){
    node=0;
    NodeWeight=0;
}

// regular constructor
template <class T>
Node<T>::Node(int node, T NodeWeight){
    this->node = node;
    this->NodeWeight = NodeWeight;
}

// copy constructor
template <class T>
Node<T>::Node(const Node<T>& temp){
    node=temp.node;
    NodeWeight=temp.NodeWeight;
}

// destructor
template <class T>
Node<T>::~Node(){
//   cout << "destructor of Node called" << endl;
}

// print Node
template <class T>
void Node<T>::printNode() const{
    cout << node << " (" << NodeWeight << ") ";
}

// modifies the Node
template <class T>
void Node<T>::setNode(int n,int nw){
    node=n;
    NodeWeight=nw;
}

// returns the Node
template <class T>
int Node<T>::getNode() const{
    return node;
}

// return Node Weight
template <class T>
int Node<T>::getWeight() const{
    return NodeWeight;
}

template class Node<int>;
