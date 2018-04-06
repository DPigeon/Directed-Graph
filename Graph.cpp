#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

using namespace std;

// default constructor
template <class T>
Graph<T>::Graph(){
    Node_Size=0;
    gNode=new Node<T>[0];
    Edge_Size=0;
    gEdge=new Edge<T>[0];
}

// copy constructor
template <class T>
Graph<T>::Graph(const Graph<T>& temp){
    Node_Size=temp.Node_Size;
    gNode=new Node<T>[Node_Size];
    for(size_t i=0; i<Node_Size; i++)
        gNode[i]=temp.gNode[i];
    Edge_Size=temp.Edge_Size;
    gEdge=new Edge<T>[Edge_Size];
    for(size_t i=0; i<Edge_Size; i++)
        gEdge[i]=temp.gEdge[i];
}

//shouldnt it search for the id first to see if it unique ? then add it if not found
// added in vertices to Graph
template <class T>
void Graph<T>::addNode(Node<T> &n){
	try {
		if(Node_Size > 100) //change the limit if wanted
			throw Node_Size;
		// We need to search for it first
		for (size_t i = 0; i < Node_Size; i++)    {
			if (gNode[i].getNode() == n.getNode() && gNode[i].getWeight() == n.getWeight())  {
				cout << "Node (" << n.getNode() << "," << n.getWeight() << ") " << " exist in the list " << endl;
				return;
			}
		}
		Node<T> *temp;
		temp = new Node<T>[Node_Size];
		for(size_t i=0; i<Node_Size ; i++)
			temp[i]=gNode[i];
		delete [] gNode;
		if(Node_Size==0){
			gNode=new Node<T>[1];
			gNode[0]=n;
			Node_Size++;
		} else {
			gNode=new Node<T>[Node_Size+1];
			for(size_t i=0; i<Node_Size ; i++)
				gNode[i]=temp[i];
			gNode[Node_Size]=n;
			Node_Size++;
		}
		delete [] temp;
		} catch (int i) {
				cout<<"Exception: You have more than "<<i<<" nodes and it is not permitted."<<endl;
		}
}

//removes a Node from the Node list
template <class T>
void Graph<T>::removeNode(const Node<T>& n){
    // We need to search for it first
    for (size_t i = 0; i < Node_Size; i++)    {
        if (gNode[i].getNode() == n.getNode() && gNode[i].getWeight() == n.getWeight())  {
            // We need to shift the  elements of the array
            for (size_t j = i; j < Node_Size-1; j++) {
                gNode[j] = gNode[j+1]; //shifts the elements of the array
            }
            Node_Size--;
            return;
        }
    }
    cout << "Node " << n.getNode() << " cannot be found " << endl;
}

// return all the Nodes in Graph
template <class T>
void Graph<T>::listNode() const{
    switch(Node_Size)
    {
        //A graph can be empty with no vertex
        case 0:
        {
            cout << "Node List: " << "There is no Node in the list" << endl;
            break;
        }
        case 1:
        {
            cout << "Node List: ";
            gNode[0].printNode();
            break;
        }
        default:
        {
            cout << "Node List: ";
            for(size_t i=0; i<Node_Size-1 ; i++){
                gNode[i].printNode();
                cout << ",";
            }
            gNode[Node_Size-1].printNode();
        }
    }
    cout << endl;
}

// check the Edge exist in the Graph or not
template <class T>
bool Graph<T>::checkEdge(const Edge<T> &arg){
    int check1=0;  // check the first node of an Edge
    int check2=0;  // check the second node of an Edge
    for (size_t i=0; i<Edge_Size; i++){
        if (arg.getFirstNode()==gEdge[i].getFirstNode() && arg.getSecondNode()==gEdge[i].getSecondNode() && arg.getEdgeWeight()==gEdge[i].getEdgeWeight())
        {
            cout << "Edge exist in the Edge list" << endl;
            break;
        }
    }
        for(size_t i=0 ; i<Node_Size ; i++){
           if(arg.getSecondNode()==gNode[i].getNode())
               check2=1;
           if(arg.getFirstNode()==gNode[i].getNode())
               check1=1;
        }
    if(check1==0 && check2==0){
        cout << "Nodes " << arg.getFirstNode() << " and " << arg.getSecondNode() << " do not exist in the Nodelist" << endl;
        return false;
    }
    if(check1==0 && check2!=0){
        cout << "Node " << arg.getFirstNode() << " does not exist in the Nodelist"<< endl;
        return false;
    }
    if(check1!=0 && check2==0){
        cout << "Node " << arg.getSecondNode() << " does not exist in the Nodelist"<< endl;
        return false;
    }
    return true;
}

//added in edges to Graph
template <class T>
void Graph<T>::addEdge(Edge<T> &e){
	try {
		if(Node_Size < 2)
			throw Node_Size;
		// We need to search for it first
		if(checkEdge(e)){
			Edge<T> *temp;
			temp = new Edge<T>[Edge_Size];
			for(size_t i=0; i<Edge_Size ; i++)
				temp[i]=gEdge[i];
			delete [] gEdge;
			if(Edge_Size==0){
				gEdge=new Edge<T>[1];
				gEdge[0]=e;
				Edge_Size++;
			}
			else{
				gEdge=new Edge<T>[Edge_Size+1];
				for(size_t i=0; i<Edge_Size ; i++)
					gEdge[i]=temp[i];
				gEdge[Edge_Size]=e;
				Edge_Size++;
			}
			delete [] temp;
		}
	} catch (int i) {
			cout<<"Exception: You have "<<i<<" nodes and you need more than 2 to add an edge."<<endl;
	}
}

//remove an Edge from the Edge list
template <class T>
void Graph<T>::removeEdge(const Edge<T>& e){
    // We need to search for it first
    for (size_t i = 0; i < Edge_Size; i++)    {
        if (gEdge[i].getFirstNode() == e.getFirstNode() && gEdge[i].getSecondNode() == e.getSecondNode())  {
            // We need to shift the  elements of the array
            for (size_t j = i; j < Edge_Size-1; j++) {
                gEdge[j] = gEdge[j+1]; //shifts the elements of the array
            }
            Edge_Size--;
            return;
        }
    }
    cout << "Edge (" << e.getFirstNode() << "," << e.getSecondNode() << ") cannot be found " << endl;
}

// return all the Edges in Graph
template <class T>
void Graph<T>::listEdge() const{
    switch(Edge_Size)
    {
       // A graph can be empty with no edge.
        case 0:
        {
            cout << "Edge List: " << "There is no Edge in the list" << endl;
            break;
        }
        case 1:
        {
            cout << "Edge List: ";
            gEdge[0].getEdge();
            break;
        }
        default:
        {
            cout << "Edge List: ";
            for(size_t i=0; i<Edge_Size-1 ; i++){
                gEdge[i].getEdge();
                cout << ",";
            }
            gEdge[Edge_Size-1].getEdge();
        }
    }
    cout << endl;
}

// virtual destructor
template <class T>
Graph<T>::~Graph(){
    // cout << "graph destructor called" << endl;
    delete [] gNode;
    delete [] gEdge;
}

template class Graph<int>;
