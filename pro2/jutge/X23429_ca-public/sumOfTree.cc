#include "sumOfTree.hh"

// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinTree<int> t) {
    int sum = t.value();

    if (!t.left().empty()) sum += sumOfTree(t.left());
    if (!t.right().empty()) sum += sumOfTree(t.right());

    return sum;
}
