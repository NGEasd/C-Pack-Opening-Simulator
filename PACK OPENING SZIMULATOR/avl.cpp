#include <iostream>
#include <string>
#include <iomanip>
#include "players.h"
#include "avl.h"

// fa lebontasa
template<class T>
void AVLFa<T>::destroyTree(Node<T>* node) 
{
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}


// magassag meghatarozasa
template<class T>
int AVLFa<T>::height(Node<T>* node) 
{
    if (node == nullptr)
        return 0;
    return node->height;
}


// balanszfaktor kiszamolasa magassag alapjan
template<class T>
int AVLFa<T>::balanceFactor(Node<T>* node) 
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}


// jobbra forgatas
template<class T>
Node<T>* AVLFa<T>::rightRotate(Node<T>* y) 
{
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

 
// balra forgatas
template<class T>
Node<T>* AVLFa<T>::leftRotate(Node<T>* x) 
{
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


// beszuras
template<class T>
Node<T>* AVLFa<T>::insert(Node<T>* node, T key) 
{
    if (node == nullptr)
        return new Node<T>{ key, nullptr, nullptr, 1 };

    // bal alfa, ha kisebb az elem
    if (key < node->key)
        node->left = insert(node->left, key);

    // nagyobb, vagy egyenlo!!! elem eseten
    else
        node->right = insert(node->right, key);

    // magassagok ujraszamolasa
    node->height = 1 + max(height(node->left), height(node->right));

    // balanszfaktor ujraszamolasa
    int balance = balanceFactor(node);

    // fa kiegyensulyozasa

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


// minimalis elem (nem hasznalom)
template<class T>
Node<T>* AVLFa<T>::minValueNode(Node<T>* node) 
{
    Node<T>* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}


// torles
template<class T>
Node<T>* AVLFa<T>::deleteNode(Node<T>* root, T key) 
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node<T>* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else {
            Node<T>* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


// kiiras roviden
template<class T>
void AVLFa<T>::printShortA(Node<T>* node) 
{
    if (node != nullptr) {
        printShortA(node->left);
        std::cout << "| " << std::setw(15) << std::left << node->key.getName() << " | " << std::setw(15) << std::left << node->key.getClub()
            << " | " << std::setw(2) << node->key.getOvr() << " |" << std::endl;
        printShortA(node->right);
    }
}

template<class T>
void AVLFa<T>::printShortD(Node<T>* node) 
{
    if (node != nullptr) {
        printShortD(node->right);
        std::cout << "| " << std::setw(15) << std::left << node->key.getName() << " | " << std::setw(15) << std::left << node->key.getClub()
            << " | " << std::setw(2) << node->key.getOvr() << " |" << std::endl;
        printShortD(node->left);
    }
}

// kiiras hosszan
template<class T>
void AVLFa<T>::printLongA(Node<T>* node) 
{
    if (node != nullptr) {
        printLongA(node->left);
        std::cout << "| " << std::setw(15) << std::left << node->key.getName() << " | " << std::setw(20) << std::left << node->key.getPosition()
            << " | " << std::setw(18) << std::left << node->key.getClub() << " | " << std::setw(18) << std::left << node->key.getLeague()
            << " | " << std::setw(18) << std::left << node->key.getNation() << " | " << std::setw(2) << node->key.getOvr() << " |" << std::endl;
        printLongA(node->right);
    }
}

template<class T>
void AVLFa<T>::printLongD(Node<T>* node) 
{
    if (node != nullptr) {
        printLongD(node->right);
        std::cout << "| " << std::setw(15) << std::left << node->key.getName() << " | " << std::setw(20) << std::left << node->key.getPosition()
            << " | " << std::setw(18) << std::left << node->key.getClub() << " | " << std::setw(18) << std::left << node->key.getLeague()
            << " | " << std::setw(18) << std::left << node->key.getNation() << " | " << std::setw(2) << node->key.getOvr() << " |" << std::endl;
        printLongD(node->left);
    }
}

// konstruktor
template<class T>
AVLFa<T>::AVLFa() : root(nullptr) {}

// destruktor
template<class T>
AVLFa<T>::~AVLFa() 
{
    destroyTree(root);
}

// beszuras
template<class T>
void AVLFa<T>::insert(T key) 
{
    root = insert(root, key);
}

// eltavolitas
template<class T>
void AVLFa<T>::remove(T key) 
{
    root = deleteNode(root, key);
}

// kereses (egyszeruen)
template<class T>
Node<T>* AVLFa<T>::search(T key) 
{
    Node<T>* current = root;
    while (current != nullptr) {
        if (current->key == key)
            return current;
        else if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return nullptr;
}


// kiirasok
template<class T>
void AVLFa<T>::printShortAsc() 
{
    printShortA(root);
    std::cout << std::endl;
}
template<class T>
void AVLFa<T>::printShortDes() 
{
    printShortD(root);
    std::cout << std::endl;
}
template<class T>
void AVLFa<T>::printLongAsc() 
{
    printLongA(root);
    std::cout << std::endl;
}
template<class T>
void AVLFa<T>::printLongDes() 
{
    printLongD(root);
    std::cout << std::endl;
}

// segedkereses, direkt player tipusu objektumra
// felhasznalja a search metodust
template<class T>
bool AVLFa<T>::searchPlayer(Player& megvan) 
{
    Node<Player>* eredmeny = search(megvan);
    if (eredmeny != nullptr) {
        megvan = eredmeny->key;
        return true;
    }
    return false;
}

// zokkenomentes player tipus hasznalatahoz
template class AVLFa<Player>;