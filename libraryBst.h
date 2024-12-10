#include <iostream>
using namespace std;

//class node

class Node
{
public:
    Node(int k) :
        data{ k }, weight{ 1 }, lchild{ nullptr }, rchild{ nullptr } {};
    ~Node() {};
    Node(const Node& s) {
        data = s.data;
        weight = s.weight;
        lchild = s.lchild;
        rchild = s.rchild;
    }

    Node* insertI(int k);

    Node* insertR(int k);

    bool searchI(int k);

    bool searchR(int k);

    Node* deleteNode(int k);

    bool isBst();

    void inOrder();

    void preOrder();

    void postOrder();


private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;
};