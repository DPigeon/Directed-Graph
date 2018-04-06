#ifndef EDGE_H_
#define EDGE_H_
#include "Node.h"

template <class T>
class Edge
{
    // display Edge to the output stream
    friend ostream &operator << (ostream &output,Edge &e){
    	output << "(" << e.getFirstNode() << "," << e.getSecondNode() << ")"  << " Weight:" << e.getEdgeWeight() << endl;
    	return output;
    }
private:
    T firstNode;
    T secondNode;
    int EdgeWeight;
public:
    Edge();  // default constructor
    Edge(T,T,int);  // regular constructor
    Edge(const Edge<T> &); // copy constructor
    ~Edge();  // destructor
    void getEdge() const; // print Edge
    void setEdge(T,T,int);  // modeifes the Edge
    T getFirstNode() const;  //resturn firstNode in Edge
    T getSecondNode() const;  // return secondNode in Edge
    int getEdgeWeight() const; // return Edge Weight
};

#endif
