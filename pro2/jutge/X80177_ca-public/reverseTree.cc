#include "reverseTree.hh"

// Pre:
// Post: retorna el revessat de t.
BinTree<int> reverseTree(BinTree<int> t) {
    if (t.left().empty() && t.right().empty()) return t;

    BinTree<int> new_left = BinTree<int>();
    BinTree<int> new_right = BinTree<int>();

    if (!t.right().empty()) new_left = reverseTree(t.right());
    if (!t.left().empty()) new_right = reverseTree(t.left());

    return BinTree<int>(t.value(), new_left, new_right);
}
