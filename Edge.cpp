#include <iostream>
#include "Node.h"
#include "Edge.h"

using namespace std;

// default constructor
template <class T>
Edge<T>::Edge(){
    firstNode=0;
    secondNode=0;
    EdgeWeight=0;
}

// regular constructor
template <class T>
Edge<T>::Edge(T firstNode, T secondNode, int EdgeWeight){
    this->firstNode = firstNode;
    this->secondNode = secondNode;
    this->EdgeWeight=EdgeWeight;
}

// copy constructor
template <class T>
Edge<T>::Edge(const Edge<T>& temp){
    firstNode=temp.firstNode;
    secondNode=temp.secondNode;
    EdgeWeight=temp.EdgeWeight;
}

// destructor
template <class T>
Edge<T>::~Edge(){

}

// print Edge
template <class T>
void Edge<T>::getEdge() const{
    cout << "(" << firstNode << "," << secondNode << ")";
}

// modeifes the Edge
template <class T>
void Edge<T>::setEdge(T firstNode, T secondNode, int EdgeWeight){
    this->firstNode=firstNode;
    this->secondNode=secondNode;
    this->EdgeWeight=EdgeWeight;
}

//resturn firstNode in Edge
template <class T>
T Edge<T>::getFirstNode() const{
    return firstNode;
}

// return secondNode in Edge
template <class T>
T Edge<T>::getSecondNode() const{
    return secondNode;
}

// return Edge Weight
template <class T>
int Edge<T>::getEdgeWeight() const{
    return EdgeWeight;
}

template class Edge<int>;
