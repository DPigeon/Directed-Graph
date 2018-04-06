#ifndef NODE_H_
#define NODE_H_

using namespace std;

template <class T>
class Node
{
    // display Node to the output stream
    friend ostream &operator << (ostream &output,Node &n){
    	output << n.node << " with node value: (" << n.NodeWeight << ") " << endl;;
    	return output;
    }
private:
    int node; //id of node
    T NodeWeight; //value
public:
    Node();  // default constructor
    Node(int,T);  // regular constructor
    Node(const Node<T> &);  // copy constructor
    ~Node();  // destructor
    void printNode() const; // print Node
    void setNode(int,int); // modifies the Node
    int getNode() const; // returns the Node
    int getWeight() const; // return Node weight
};
#endif

