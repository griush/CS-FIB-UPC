#include "treeOfSumsOfAncestors.hh"

// Pre:
// Post: Retorna un arbre d'enters t' amb la mateixa estructura que t.
//       Per a cada posició p, el valor guardat a t' a posició p és igual a la suma
//       dels valors guardats a t a posició p i a posicions ancestres de p.
BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t) {
    int val = t.value();

    BinTree<int> left = BinTree<int>();
    if (!t.left().empty())
        left = treeOfSumsOfAncestors(BinTree<int>(val + t.left().value(), t.left().left(), t.left().right()));
    
    BinTree<int> right = BinTree<int>();
    if (!t.right().empty())
        right = treeOfSumsOfAncestors(BinTree<int>(val + t.right().value(), t.right().left(), t.right().right()));

    return BinTree<int>(val, left, right);
}