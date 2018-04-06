#ifndef GRAPH_H_
#define GRAPH_H_
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

using namespace std;

template <class T>
class Graph
{
	 // display Graph to the output stream
	friend ostream &operator << (ostream &output,Graph &g){
		output<<"G = {"<<g.Node_Size<<", "<<g.Edge_Size<<"}"<<endl;
	    return output;
	}
protected:
    Node<T> *gNode;
    size_t Node_Size;
    Edge<T> *gEdge;
    size_t Edge_Size;

public:
    Graph(); // default constructor
    Graph(const Graph<T> &); // copy constructor
    void addNode(Node<T> &); // added in vertices to Graph
    void removeNode(const Node<T> &); //removes a Node from the Node list
    void listNode() const; // return all the Nodes in Graph
    void addEdge(Edge<T> &); //added in edges to Graph
    void removeEdge(const Edge<T> &); //remove an Edge from the Edge list
    void listEdge() const; // return all the Edges in Graph
    bool checkEdge(const Edge<T> &); // check the Edge exist in the Graph or not
    virtual ~Graph(); // virtual destructor
};

#endif /* GRAPH_H_ */

