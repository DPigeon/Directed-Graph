#ifndef UNDIRECTEDGRAPH_H_
#define UNDIRECTEDGRAPH_H_
#include "Edge.h"
#include "Graph.h"

template <class T>
class UnDirectedGraph: public Graph<T>
{
    // display DirectGraph to the output stream
    friend ostream &operator << (ostream &output,UnDirectedGraph &dg){
    	for (int i=0; i<dg.counter1; i++){
    		for (int j=0; j<dg.NodeListMatrix[i][dg.MAXnumberOfPath]; j++)
    	    {
    			output << dg.gNode[dg.NodeListMatrix[i][j]].getNode();
    	        for (size_t k=0; k<dg.Edge_Size; k++){
    	        	if (dg.gNode[dg.NodeListMatrix[i][j]].getNode()==dg.gEdge[k].getFirstNode() && dg.gNode[dg.NodeListMatrix[i][j+1]].getNode()==dg.gEdge[k].getSecondNode())
    	        		output << " --(" << dg.gEdge[k].getEdgeWeight() << ")--> ";
    	        }
    	    }
    	        cout << endl;
    	}
    	return output;
    }
private:
    int **EdgeMatrix; // (Node_size*Node_size matix) store all Edges in matrix form (if there has been an Edge, we put 1 in the matrix)
    int **NodeListMatrix; // store final result (Node_size*Node_size matix)
    int MAXnumberOfPath; // maximum number of path
    int counter1; // increase i value of NodeListMatrix
    int counter2; // increase j value of NodeListMatrix
    int counter3; // count number of Edges from Node[i]
    int OnetoZero; // remove an edge from EdgeMatrix to avoid repeating path
    int check;
public:
    UnDirectedGraph(Graph<T>*); // regular constructor (copy all variables from Graph to UnDirectedGraph)
    UnDirectedGraph(const UnDirectedGraph<T> &); // copy constructor
    void print();
    ~UnDirectedGraph (); // destructor
    void flipMatrix(int,int);
    void checkPath(int**,int,int);
    void pathList(UnDirectedGraph<T> &,const Node<T> &);
    bool checkInitialRow(int);
};

#endif /* UNDIRECTEDGRAPH_H_ */
