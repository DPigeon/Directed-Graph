#ifndef DIRECTGRAPH_H_
#define DIRECTGRAPH_H_

#include "Edge.h"
#include "Graph.h"

template <class T>
class DirectGraph: public Graph<T>
{
    // display DirectGraph to the output stream
    friend ostream &operator << (ostream &output,DirectGraph &dg){
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
    int **NodeListMatrix; // store final result(all possible path)
    int MAXnumberOfPath; // maximum number of path
    int counter1; // increase i value of NodeListMatrix
    int counter2; // increase j value of NodeListMatrix
    int counter3; // count number of Edges from Node[i]
    int OnetoZero; // remove an edge from EdgeMatrix to avoid repeating path
    int check;
public:
    DirectGraph(Graph<T>*); // regular constructor (copy all variables from Graph to DirectGraph)
    DirectGraph(const DirectGraph &); // copy constructor
    void print();
    ~DirectGraph();
    void flipMatrix(int,int);
    void checkPath(int**,int,int);
    void pathList(DirectGraph<T> &,const Node<T> &);
    bool checkInitialRow(int);
};

#endif /* DIRECTGRAPH_H_ */
