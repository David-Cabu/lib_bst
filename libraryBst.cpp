#include "libraryBst.h"

using namespace std;

Node* Node::insertI(int k) {
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

Node* Node::insertR(int k) {              // inserimento ricorsivo di k
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

void Node::inOrder() {
    if (this == NULL) {
        return;
    }
    lchild->inOrder();
    cout << data << " ";
    rchild->inOrder();
}

bool Node::searchI(int k) {
    Node* Root{ this };
    while (Root != NULL)
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
        else if (Root->data >= k)
        {
            Root = Root->lchild;
            continue;
        }
    }
    return false;
}

bool Node::searchR(int k) {
    Node* root{ this };
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == k)
    {
        return true;
    }
    else if (root->data < k)
    {
        root = root->rchild;
        return root->searchR(k);
    }
    else if (root->data > k)
    {
        root = root->lchild;
        return root->searchR(k);
    }
}

Node* Node::deleteNode(int k) {
    if (this == NULL)
    {
        return this;
    }
    else if (this->data < k)
    {
        this->rchild = rchild->deleteNode(k);
    }
    else if (this->data > k)
    {
        this->lchild = lchild->deleteNode(k);
    }
    else if (this->data == k)
    {
        if (this->lchild == NULL && this->rchild == NULL)
        {
            delete this;
            return nullptr;
        }
        else if (this->lchild != NULL && this->rchild == NULL)
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
        else if (this->lchild != NULL && this->rchild != NULL)
        {
            Node* my_ptr{ this->rchild };
            while (my_ptr->lchild != NULL)
            {
                if (my_ptr == NULL)
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

bool Node::isBst() {
    if (this->lchild != NULL)
    {
        if (this->lchild->data < this->data)
        {
            lchild->isBst();
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
    if (this->rchild != NULL)
    {
        if (this->rchild->data > this->data)
        {
            rchild->isBst();
        }
        else
        {
            return false;
        }

    }
    else {
        return true;
    }
}

void Node::preOrder() {
    if (this == NULL)
    {
        return;
    }
    cout << data << " ";
    lchild->preOrder();
    rchild->preOrder();
}

void Node::postOrder() {
    if (this == NULL)
    {
        return;
    }
    lchild->postOrder();
    rchild->postOrder();
    cout << data << " ";
}