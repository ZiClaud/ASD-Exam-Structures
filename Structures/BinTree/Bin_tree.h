//
// Created by ziclaud on 21/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_BIN_TREE_H
#define ASD_EXAM_STRUCTURES_BIN_TREE_H

#include <iostream>

using namespace std;

template<class T, class N>
class Bin_tree {
    static const int NIL = -1;

public:

    // tipi
    typedef T value_type;
    typedef N Nodo;

    // operatori
    virtual void create() = 0;

    virtual bool empty() const = 0;

    virtual Nodo root() const = 0;

    virtual Nodo parent(Nodo) const = 0;

    virtual Nodo sx(Nodo) const = 0;

    virtual Nodo dx(Nodo) const = 0;

    virtual bool sx_empty(Nodo) const = 0;

    virtual bool dx_empty(Nodo) const = 0;

    //virtual void costr(Bin_tree<T,N>);
    virtual void erase(Nodo) = 0;

    virtual T read(Nodo) const = 0;

    virtual void write(Nodo, value_type) = 0;

    virtual void ins_root() = 0;

    virtual void ins_sx(Nodo) = 0;

    virtual void ins_dx(Nodo) = 0;

    // funzioni di servizio da implementare qui
    //virtual void previsit(Nodo);
    //virtual void invisita(Nodo);
    //virtual void postvisit(Nodo);

    virtual void print() const;

private:
    virtual void printSubTree(const Nodo) const;
};

template<class T, class N>
void Bin_tree<T, N>::print() const {
    if (!empty())
        printSubTree(root());
    else
        cout << "[]" << endl;
    cout << endl;
}

template<class T, class N>
void Bin_tree<T, N>::printSubTree(const Nodo n) const {
    cout << "[" << read(n) << ", ";
    if (!sx_empty(n))
        printSubTree(sx(n));
    else cout << "NIL";
    cout << ", ";
    if (!dx_empty(n))
        printSubTree(dx(n));
    else cout << "NIL";
    cout << " ]";
}

template<class T, class N>
ostream &operator<<(ostream &out, const Bin_tree<T, N> &t) {
    t.print();
    return out;
}

#endif //ASD_EXAM_STRUCTURES_BIN_TREE_H
