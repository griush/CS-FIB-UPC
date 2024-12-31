#include "evaluate.hh"
#include "utils.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(BinTree<string> t) {
    if (isNumber(t.value())) return mystoi(t.value());

    if (t.value() == "+") return evaluate(t.left()) + evaluate(t.right());
    if (t.value() == "*") return evaluate(t.left()) * evaluate(t.right());
    if (t.value() == "-") return evaluate(t.left()) - evaluate(t.right());

    return -1; // If correct test case input, this is unreachable.
}