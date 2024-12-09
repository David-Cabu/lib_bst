#include <iostream>
using namespace std;

//class node

class Node
{
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

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

    Node* insertI(int k) {
        Node* temp_root{ this };
        Node* root{ this };
        while (root != NULL)
        {
            temp_root = root;
            if (k < root->data)
            {
                root = root->lchild;
            }
            else if (k > root->data)
            {
                root = root->rchild;
            }
            else if (k == root->data)
            {
                weight++;
                return temp_root;
            }
        }
        if (k > temp_root->data)
        {
            temp_root->rchild = new Node{ k };
        }
        else
        {
            temp_root->lchild = new Node{ k };
        }
        return this;
    }

    Node* insertR(int k) {              // inserimento ricorsivo di k
        Node* temp_root{ this };
        if (temp_root == NULL)
        {
            temp_root = new Node{ k };
            return temp_root;
        }
        if (k < temp_root->data)
        {
            temp_root->lchild = this->lchild->insertR(k);
        }
        else if (k > temp_root->data)
        {
            temp_root->rchild = this->rchild->insertR(k);
        }
        else if (k == temp_root->data)
        {
            temp_root->weight++;
        }
        return this;
    };  

    void inOrder() {
        Node* root{ this };
        if (root == nullptr) {
            return;
        }
        Node* lRoot{ root->lchild };
        lRoot->inOrder();
        cout << root->data << " ";
        Node* rRoot{ root->rchild };
        rRoot->inOrder();
    }

    bool searchI(int k) {
        Node* Root{ this };
        while (Root!=NULL)
        {
            if (Root->data == k)
            {
                return true;
            }
            else if (Root->data <= k)
            {
                Root = Root->rchild;
                continue;
            }
            else if (Root->data>=k)
            {
                Root = Root->lchild;
                continue;
            }
        }
        return false;
    }

    bool searchR(int k) {
        Node* root{ this };
        if (root == NULL)
        {
            return false;
        }
        else if (root->data==k)
        {
            return true;
        }
        else if (root->data<k)
        {
            root = root->rchild;
            return root->searchR(k);
        }
        else if (root->data>k)
        {
            root=root->lchild;
            return root->searchR(k);
        }
    }

    Node* deleteNode(int k) {
        if (this==NULL)
        {
            return this;
        }
        else if (this->data<k)
        {
            this->rchild=rchild->deleteNode(k);
        }
        else if (this->data>k)
        {
            this->lchild=lchild->deleteNode(k);
        }
        else if (this->data==k)
        {
            if (this->lchild==NULL&&this->rchild==NULL)
            {
                delete this;
                return nullptr;
            }
            else if (this->lchild!=NULL&&this->rchild==NULL)
            {
                Node* my_ptr{ this->lchild };
                delete this;
                return my_ptr;
            }
            else if (this->rchild != NULL && this->lchild == NULL)
            {
                Node* my_ptr{ this->rchild };
                delete this;
                return my_ptr;
            }
            else if (this->lchild!=NULL&&this->rchild!=NULL)
            {
                Node* my_ptr{ this->rchild };
                while (my_ptr->lchild!=NULL)
                {
                    if (my_ptr==NULL)
                    {
                        break;
                    }
                    my_ptr = my_ptr->lchild;
                }
                this->data = my_ptr->data;
                this->rchild = rchild->deleteNode(my_ptr->data);
            }

        }
        return this;
    }

};








////funzione per visitare nodo, figlio sinistro, figlio destro (preorder)
//void preorder_traversal(node* root) {
//    if (root == nullptr) {
//        return;
//    }
//    cout << root->value << " ";
//    preorder_traversal(root->lchild);
//    preorder_traversal(root->rchild);
//}
//
//
////funzione per visitare figlio sinistro, nodo, figlio destro (inorder)
//void inorder_traversal(node* root) {
//    if (root == nullptr) {
//        return;
//    }
//    inorder_traversal(root->lchild);
//    cout << root->value << " ";
//    inorder_traversal(root->rchild);
//}
//
//
////funzione per visitare figlio sinistro, figlio destro, nodo  (postorder)
//void postorder_traversal(node* root) {
//    if (root == nullptr) {
//        return;
//    }
//    postorder_traversal(root->lchild);
//    postorder_traversal(root->rchild);
//    cout << root->value << " ";
//}
//
//
////funzione per trovare l'altezza di un albero
//int bst_height(node* root) {
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int l = bst_height(root->lchild);
//    int r = bst_height(root->rchild);
//    return max(l, r) + 1;
//}
//
//
////funzione per verificare se l'albero e' un bst
//bool verify_bst(node* root) {
//    if (root->lchild != NULL)
//    {
//        if (root->lchild->value < root->value)
//        {
//            verify_bst(root->lchild);
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
//        return true;
//    }
//    if (root->rchild != NULL)
//    {
//        if (root->rchild->value > root->value)
//        {
//            verify_bst(root->rchild);
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
//        return true;
//    }
//    return true;
//}