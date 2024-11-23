#include <iostream>
using namespace std;

//struttura node

class Node
{
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int* ptr) :
        data{ 0 }, weight{ 1 }, lchild{ nullptr }, rchild{ nullptr } {};
    Node(int k) :
        data{ k }, weight{ 1 }, lchild{ nullptr }, rchild{ nullptr } {};
    ~Node() {};
    Node(const Node& s) {
        data = s.data;
        weight = s.weight;
        lchild = s.lchild;
        rchild = s.rchild;
    }
    int getData() {
        return data;
    }
    Node* getLchild() {
        return lchild;
    }
    Node* getRchild() {
        return rchild;
    }
    void setWeight() {
        weight += 1;
    }
    void setLchild(Node* parameter_lchild) {
        lchild = parameter_lchild;
    }
    void setRchild(Node* parameter_rchild) {
        rchild = parameter_rchild;
    }
};





//variabili globali per le varie funzioni
int old_node_value{ 0 };
char LorR_child{ ' ' };


Node* insertR(Node* root,int k) {
    Node* ptr_root{ root };
    while (root != NULL)
    {
        if (k < root->getData())
        {
            root = root->getLchild();
            continue;
        }
        else if (k > root->getData())
        {
            root = root->getRchild();
            continue;
        }
        else if (k == root->getData())
        {
            root->setWeight();
            return ptr_root;
        }
    }
    root = new Node(k);

    return ptr_root;
}


////funzione per creare un nuovo nodo
//node* new_leaf(node* root, int num) {
//    if (root == NULL)
//    {
//        if (LorR_child == 'r')
//        {
//            cout << "E' stato aggiunto il nodo con valore " << num << " nel ramo destro del nodo con valore " << old_node_value << endl;
//            root = new node{ num };
//        }
//        else if (LorR_child == 'l')
//        {
//            cout << "E' stato aggiunto il nodo con valore " << num << " nel ramo sinistro del nodo con valore " << old_node_value << endl;
//            root = new node{ num };
//        }
//        else {
//        cout << "E' stato aggiunto il nodo con valore " << num << " come root principale" << endl;
//            root = new node{ num };
//        }
//        LorR_child = ' ';
//        old_node_value = 0;
//        return root;
//    }
//    else if (num > root->value)
//    {
//        old_node_value = root->value;
//        LorR_child = 'r';
//        root->rchild = new_leaf(root->rchild, num);
//    }
//    else if (num < root->value)
//    {
//        old_node_value = root->value;
//        LorR_child = 'l';
//        root->lchild = new_leaf(root->lchild, num);
//    }
//    else if (num == root->value)
//    {
//        root->wieght++;
//        cout << "Il numero " << num << " e' gia' presente come nodo, e' quindi stato aggiunta un unita' al suo peso" << endl;
//        cout << "Il valore della root " << num << " e' gia' comparso " << root->wieght << " volte" << endl;
//    }
//    return root;
//}
//
//
//
////funzione per trovare un nodo
//node* find_value(node* root, int num_find) {
//    if (num_find == root->value)
//    {
//        if (LorR_child == 'r')
//        {
//            cout << "E' stato trovato il nodo con valore " << num_find << " nel ramo destro del nodo con valore " << old_node_value << endl;
//        }
//        else if (LorR_child == 'l')
//        {
//            cout << "E' stato trovato il nodo con valore " << num_find << " nel ramo sinistro del nodo con valore " << old_node_value << endl;
//        }
//        else {
//            cout << "E' stato trovato il nodo con valore " << num_find << " come root principale" << endl;
//        }
//        LorR_child = ' ';
//        old_node_value = 0;
//        return root;
//    }
//    else if (num_find > root->value)
//    {
//        if (root->rchild == NULL)
//        {
//            cout << "Non e' stato trovato il nodo con valore " << num_find;
//            LorR_child = ' ';
//            old_node_value = 0;
//            return nullptr;
//        }
//        old_node_value = root->value;
//        LorR_child = 'r';
//        find_value(root->rchild, num_find);
//    }
//    else if (num_find < root->value)
//    {
//        if (root->lchild == NULL)
//        {
//            cout << "Non e' stato trovato il nodo con valore " << num_find;
//            LorR_child = ' ';
//            old_node_value = 0;
//            return nullptr;
//        }
//        old_node_value = root->value;
//        LorR_child = 'l';
//        find_value(root->lchild, num_find);
//    }
//
//
//    return nullptr;
//
//}
//
//
////funzione per creare un albero con numeri casuali
//node* ranodm_tree(node* root, int node_quantity, int max_value) {
//    srand(time(NULL));
//    int num{ 0 };
//    for (int i = 0; i < node_quantity; i++)
//    {
//        num = rand() % max_value + 1;
//        cout << num << endl;
//        root = new_leaf(root, num);
//    }
//    return root;
//}
//
//
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
//node* remove_node(node* root, int remove_value) {
//    if (root == NULL)
//    {
//        cout << "non e' stato trovato il valore " << remove_value << endl;
//    }
//    else if (root->value > remove_value)
//    {
//        root->lchild = remove_node(root->lchild, remove_value);
//    }
//    else if (root->value < remove_value)
//    {
//        root->rchild = remove_node(root->rchild, remove_value);
//    }
//    else if (root->value == remove_value)
//    {
//        if (root->lchild != NULL && root->rchild != NULL)
//        {
//            int temp_value{ root->value };
//            node* temp_node{ root };
//            root = root->rchild;
//            while (root != NULL)
//            {
//                if (root->lchild == NULL) {
//                    break;
//                }
//                root = root->lchild;
//            }
//            temp_node->value = root->value;
//            root->value = temp_value;
//
//            delete root;
//            cout << "E' stato rimosso il valore " << remove_value << endl;
//
//            return temp_node;
//        }
//        else if (root->lchild != NULL && root->rchild == NULL)
//        {
//            new_tree_ptr = root->lchild;
//            delete root;
//            cout << "E' stato rimosso il valore " << remove_value << endl;
//
//            return new_tree_ptr;
//        }
//        else if (root->lchild == NULL && root->rchild != NULL)
//        {
//            new_tree_ptr = root->rchild;
//            delete root;
//            cout << "E' stato rimosso il valore " << remove_value << endl;
//
//            return new_tree_ptr;
//
//        }
//        else if (root->lchild == NULL && root->rchild == NULL)
//        {
//            cout << "E' stato rimosso il valore " << remove_value << endl;
//            delete root;
//            return nullptr;
//        }
//    }
//    return root;
//}
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