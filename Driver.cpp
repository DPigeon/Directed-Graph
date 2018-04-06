/*
 * Driver.cpp file
 *
 *  Created on: 2017-10-02
 *      Author: Kasra & David (GitHub: DPigeon)
 */

#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "DirectGraph.h"
#include "UnDirectedGraph.h"

using namespace std;

void testNode(){
    cout << "--------default constructor---------" << endl;
    Node<int> n0;  // default constructor
    cout << "Node 0: " << n0;
    cout << "--------regular constructor---------" << endl;
    Node<int> n1(15,3);  // regular constructor
    cout << "Node 1: " << n1;
    cout << "--------copy constructor---------" << endl;
    Node<int> n2(n1);  // copy constructor
    cout << "Node 2: " << n2;
    cout << "--------modifies the Node---------" << endl;
    n2.setNode(10,2); // modifies the Node
    cout << "Node 2: " << n2;
};

void testEdge(){
    cout << "--------default constructor---------" << endl;
    Edge<int> e0;  // default constructor
    cout << "Edge 0: " << e0;
    cout << "--------regular constructor---------" << endl;
    Edge<int> e1(5,10,20);  // regular constructor
    cout << "Edge 1: " << e1;
    cout << "--------copy constructor---------" << endl;
    Edge<int> e2(e1);  // copy constructor
    cout << "Edge 2: " << e2;
    cout << "--------modifies the Node---------" << endl;
    e2.setEdge(1, 10, 15); // modifies the Node
    cout << "Edge 2: " << e2;
};

void testGraph(){
    cout << "--------default constructor empty Graph with no vertex or edge---------" << endl;
    Graph<int> a;
    a.listNode();
    a.listEdge();
    cout << "--------add Nodes and Edges to the Graph---------" << endl;
    Node<int> b1(1,1);
    a.addNode(b1);
    Node<int> b2(2,0);
    a.addNode(b2);
    Node<int> b3(3,0);
    a.addNode(b3);
    Node<int> b4(4,0);
    a.addNode(b4);

    Edge<int> d0(1,2,1);
    a.addEdge(d0);
    Edge<int> d1(1,4,0);
    a.addEdge(d1);
    Edge<int> d2(2,3,0);
    a.addEdge(d2);

    a.listNode();
    a.listEdge();
    cout << "--------copy constructor---------" << endl;
    Graph<int> g(a);
    g.listNode();
    g.listEdge();

    cout << "--------add a duplicate Node (1,1)---------" << endl;
    Node<int> b5(1,1);
    a.addNode(b5);
    cout << "--------add a duplicate Node 1 with different Weight 5---------" << endl;
    Node<int> b6(1,5);
    a.addNode(b6);
    a.listNode();
    cout << "--------add a duplicate Edge (1,2,1)---------" << endl;
    Edge<int> d3(1,2,1);
    a.addEdge(d3);
    cout << "--------add a duplicate Edge (1,2,5) with different Weight---------" << endl;
    Edge<int> d4(1,2,5);
    a.addEdge(d4);
    a.listEdge();
    cout << "--------add an Edge (1,20,5) which one of the Nodes does not exist in the Node List---------" << endl;
    Edge<int> d5(1,20,5);
    a.addEdge(d5);
    cout << "--------remove Node (1,1)---------" << endl;
    a.removeNode(b1);
    a.listNode();
    cout << "--------remove Edge (1,2,1)---------" << endl;
    a.removeEdge(d0);
    a.listEdge();

    cout<<a; //tests the operator output
};

void testDirectGraph(){
    Graph<int> a;
    Node<int> b1(1,0);
    a.addNode(b1);
    Node<int> b2(2,0);
    a.addNode(b2);
    Node<int> b3(3,0);
    a.addNode(b3);
    Node<int> b4(4,0);
    a.addNode(b4);
    Node<int> b5(5,0);
    a.addNode(b5);
    Node<int> b6(6,0);
    a.addNode(b6);

    Edge<int> d0(1,2,0);
    a.addEdge(d0);
    Edge<int> d1(1,4,0);
    a.addEdge(d1);
    Edge<int> d2(2,3,4);
    a.addEdge(d2);
    Edge<int> d3(2,4,0);
    a.addEdge(d3);
    Edge<int> d4(2,5,0);
    a.addEdge(d4);
    Edge<int> d5(3,4,0);
    a.addEdge(d5);
    Edge<int> d6(5,3,0);
    a.addEdge(d6);
    Edge<int> d7(6,3,0);
    a.addEdge(d7);
    Edge<int> d8(6,5,0);
    a.addEdge(d8);

    a.listNode();
    a.listEdge();

    DirectGraph<int> z(&a);
    z.pathList(z,b1);
    cout << "--------path list---------" << endl;
    cout << z;
    cout << "--------another way of printing path---------" << endl;
    z.print();

    cout << "--------copy constructor---------" << endl;
    DirectGraph<int> z2(z);
    z2.print();
};

void testUndirectedGraph(){
    Graph<int> a;
    Node<int> b1(1,0);
    a.addNode(b1);
    Node<int> b2(2,0);
    a.addNode(b2);
    Node<int> b3(3,0);
    a.addNode(b3);
    Node<int> b4(4,0);
    a.addNode(b4);
    Node<int> b5(5,0);
    a.addNode(b5);
    Node<int> b6(6,0);
    a.addNode(b6);

    Edge<int> d1(1,2,0);
    a.addEdge(d1);
    Edge<int> d2(1,3,0);
    a.addEdge(d2);
    Edge<int> d3(2,4,0);
    a.addEdge(d3);
    Edge<int> d4(2,5,0);
    a.addEdge(d4);
    Edge<int> d5(3,6,0);
    a.addEdge(d5);

    a.listNode();
    a.listEdge();

    UnDirectedGraph<int> z(&a);
    z.pathList(z,b1);
    cout << "--------path list---------" << endl;
    cout << z;
    cout << "--------another way of printing path---------" << endl;
    z.print();

    cout << "--------copy constructor---------" << endl;
    UnDirectedGraph<int> z2(z);
    z2.print();
};

int main() {
//    testNode();
//    testEdge();
//    testGraph();
    testDirectGraph();
//    testUndirectedGraph();
    return 0;
}
