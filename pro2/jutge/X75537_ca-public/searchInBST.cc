#include "searchInBST.hh"

// Pre: t és un BST
// Post: Retorna cert si i només si x apareix a t
bool searchInBST(BinTree<int> t, int x) {
    if (t.value() == x) return true;

    if (t.value() > x and not t.left().empty()) return searchInBST(t.left(), x);
    if (t.value() < x and not t.right().empty()) return searchInBST(t.right(), x);

    return false;
}
