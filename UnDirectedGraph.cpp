#include <iostream>
#include "Edge.h"
#include "Graph.h"
#include "UnDirectedGraph.h"
#include <stdlib.h>

using namespace std;

// copy all variables from Graph to DirectGraph
template <class T>
UnDirectedGraph<T>::UnDirectedGraph(Graph<T>* temp){
    counter1=0;
    counter2=0;
    counter3=0;
    OnetoZero=0;
    check=0;
    // point to base class(Graph class) to get Nodes and Edges data
    UnDirectedGraph<T>* ptr=static_cast<UnDirectedGraph<T>*>(temp);
    Graph<T>::Node_Size=ptr->Node_Size;
    Graph<T>::gNode=new Node<T>[Graph<T>::Node_Size];
    for (size_t i=0; i< Graph<T>::Node_Size; i++)
        Graph<T>::gNode[i]=ptr->gNode[i];
    Graph<T>::Edge_Size=ptr->Edge_Size;
    Graph<T>::gEdge=new Edge<T>[Graph<T>::Edge_Size];
    for (size_t i=0; i< Graph<T>::Edge_Size ; i++)
    	Graph<T>::gEdge[i]=ptr->gEdge[i];
    // initialize all value of matrix NodeMatrix to 0
    EdgeMatrix=new int *[ Graph<T>::Node_Size];
    for (size_t i=0 ; i< Graph<T>::Node_Size ; i++){
        *(EdgeMatrix+i) = new int [ Graph<T>::Node_Size];
    }
    for (size_t i=0; i< Graph<T>::Node_Size; i++)
        for (size_t j=0; j< Graph<T>::Node_Size; j++)
            *(*(EdgeMatrix+i)+j)=0;
    // check Edge and change value from 0 to 1
    for (size_t k=0; k< Graph<T>::Edge_Size; k++){
        for (size_t i=0; i< Graph<T>::Node_Size; i++){
            for (size_t j=0; j< Graph<T>::Node_Size; j++){
                if (Graph<T>::gEdge[k].getFirstNode()==Graph<T>::gNode[i].getNode() && Graph<T>::gEdge[k].getSecondNode()==Graph<T>::gNode[j].getNode())
                {
                    // since it's undirected graph, there is no difference between the Edge from i to j and j to i
                    EdgeMatrix[i][j]=1;
                    EdgeMatrix[j][i]=1;
                }
            }
        }
    }
    // find the maximum number of path
    int count=0;
    MAXnumberOfPath=0;
    for (size_t i=0; i< Graph<T>::Node_Size; i++){
        for (size_t j=0; j< Graph<T>::Node_Size; j++){
            if (EdgeMatrix[i][j]==1)
                count++;
        }
        MAXnumberOfPath=MAXnumberOfPath+count;
        count=0;
    }
    MAXnumberOfPath=MAXnumberOfPath/2;

    // initialize all value of matrix NodeListMatrix to 0
    NodeListMatrix=new int *[MAXnumberOfPath];
    for (int i=0 ; i<MAXnumberOfPath ; i++){
        *(NodeListMatrix+i) = new int [MAXnumberOfPath+1]; // add one more colume for storing number of Edges from Node[i]
    }
    for (int i=0; i<MAXnumberOfPath; i++)
        for (int j=0; j<MAXnumberOfPath+1; j++)
            *(*(NodeListMatrix+i)+j)=0;
}

// copy constructor
template <class T>
UnDirectedGraph<T>::UnDirectedGraph(const UnDirectedGraph<T>& temp): Graph<T>(temp){
    MAXnumberOfPath=temp.MAXnumberOfPath;
    counter1=temp.counter1;
    counter2=temp.counter2;
    counter3=temp.counter3;
    OnetoZero=temp.OnetoZero;
    check=temp.check;
    // copy all values of EdgeMatrix
    EdgeMatrix=new int *[Graph<T>::Node_Size];
    for (size_t i=0 ; i< Graph<T>::Node_Size ; i++){
        *(EdgeMatrix+i) = new int [Graph<T>::Node_Size];
    }
    for (size_t i=0; i< Graph<T>::Node_Size; i++)
        for (size_t j=0; j< Graph<T>::Node_Size; j++)
            *(*(EdgeMatrix+i)+j)=*(*(temp.EdgeMatrix+i)+j);
    // copy all values of NodeListMatrix
    NodeListMatrix=new int *[counter1];
    for (int i=0 ; i<counter1 ; i++){
        *(NodeListMatrix+i) = new int [temp.MAXnumberOfPath];
    }
    for (int i=0; i<counter1; i++){
        for (int j=0; j<temp.MAXnumberOfPath+1; j++)
            *(*(NodeListMatrix+i)+j)=*(*(temp.NodeListMatrix+i)+j);
    }
}

template <class T>
UnDirectedGraph<T>::~UnDirectedGraph(){
    delete [] EdgeMatrix;
    delete [] NodeListMatrix;
}

template <class T>
void UnDirectedGraph<T>::flipMatrix(int row, int size){
    int* temp=new int[size];
    for (int j=0; j<size; j++){
        temp[j]=NodeListMatrix[row][size-j-1];
    }
    for (int j=0; j<size; j++)
        NodeListMatrix[row][j]=temp[j];
    delete [] temp;
}


// checkPath(NodeMatrix , first Node , 0(to find the first 1 in NodeMatrix)
template <class T>
void UnDirectedGraph<T>::checkPath(int **a,int i,int checkOne){
    static int iValue=i;
    int jValue=0;
    for(size_t j=0; j< Graph<T>::Node_Size; j++){
        if (EdgeMatrix[i][j]==1){
            jValue=j;
            // we just have to add this line in UnDirectedGraph
            EdgeMatrix[j][i]=0;
            checkOne=1;
            break;
        }
    }
    if (checkOne==1){
        counter3++;
        // if j be equal to first node the there is a circule
        if (iValue==jValue)
        {
            cout << "There is a circle in the Graph" << endl;
            exit(1);
        }
        else
            checkPath(EdgeMatrix,jValue,0);
    }
    NodeListMatrix[counter1][counter2]=i;
    counter2++;
    if (OnetoZero==1)
        EdgeMatrix[i][jValue]=0;
    OnetoZero++;
    if (OnetoZero==counter3+1){
        NodeListMatrix[counter1][MAXnumberOfPath]=OnetoZero;
        counter3=0;
        OnetoZero=0;
        if(checkInitialRow(iValue)){
            flipMatrix(counter1,NodeListMatrix[counter1][MAXnumberOfPath]);
            if (counter1!=0){
                for (int ii=0; ii<counter1; ii++){
                    check=1;
                    for(int j=0 ; j<NodeListMatrix[counter1][MAXnumberOfPath] ; j++){
                        if(NodeListMatrix[counter1][j]!=NodeListMatrix[ii][j])
                        {
                            check=0;
                            break;
                        }
                    }
                    // if it was equal break otherwise continue checking
                    if(check==1)
                    {
                        break;
                    }
                }
                if(check==1)
                {
                    for(int j=0; j<MAXnumberOfPath+1; j++)
                        NodeListMatrix[counter1][j]=0;
                }
                else{
                    check=0;
                    counter1++;
                }
            }
            else
                counter1++;
            counter2=0;
            checkPath(EdgeMatrix,iValue,0);
        }
    }
}

template <class T>
void UnDirectedGraph<T>::pathList(UnDirectedGraph<T>& a, const Node<T>& n){
    // first we should check the node
    int i=-1;
    for (size_t p=0; p< Graph<T>::Node_Size; p++){
        if (Graph<T>::gNode[p].getNode()==n.getNode())
            i=p;
    }
    if (i==-1){
        cout << "Node does not exit in the Node list" << endl;
        return;
    }
    a.checkPath(EdgeMatrix, i, 0);
}

template <class T>
bool UnDirectedGraph<T>::checkInitialRow(int InitialRow){
    static int i=0;
    for (size_t k=0; k< Graph<T>::Node_Size; k++){
        if (EdgeMatrix[InitialRow][k]!=0)
            return true;
    }
    i++;
    if (i==1)
        return true;
    return false;
}

template <class T>
void UnDirectedGraph<T>::print(){
    for (int i=0; i<counter1; i++){
        for (int j=0; j<NodeListMatrix[i][MAXnumberOfPath]; j++)
            cout << Graph<T>::gNode[NodeListMatrix[i][j]].getNode() << " " ;
        cout << endl;
    }
}

template class UnDirectedGraph<int>;
