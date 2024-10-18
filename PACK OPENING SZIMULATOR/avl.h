#ifndef AVL_H
#define AVL_H

template<class T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;
    int height;
};

template<class T>
class AVLFa {
private:

    // gyoker
    Node<T>* root;

    // destruktohoz
    void destroyTree(Node<T>* node);

    // segedfuggvenyek
    int height(Node<T>* node);
    int balanceFactor(Node<T>* node);
    Node<T>* rightRotate(Node<T>* y);
    Node<T>* leftRotate(Node<T>* x);
    Node<T>* insert(Node<T>* node, T key);
    Node<T>* minValueNode(Node<T>* node);
    Node<T>* deleteNode(Node<T>* root, T key);

    // a kiirashoz szukseges fuggvenyek
    // megj. hasznaljak a player classt a getter metodusk miatt
    // igy a kiiras lehet veszit az altalanossagbol
    // viszont amugyan is, ha komolyabb adatokat akarunk megjeleniteni
    // nem aratnak segedfuggvenyek
    void printShortA(Node<T>* node);
    void printShortD(Node<T>* node);
    void printLongA(Node<T>* node);
    void printLongD(Node<T>* node);

public:

    AVLFa();
    ~AVLFa();

    void insert(T key);
    void remove(T key);
    Node<T>* search(T key);

    // a kiirato segedfuggvenyek alapjan
    void printShortAsc();
    void printShortDes();
    void printLongAsc();
    void printLongDes();

    // segedfuggveny -> Player classhez
    bool searchPlayer(Player& megvan);
};

#endif
