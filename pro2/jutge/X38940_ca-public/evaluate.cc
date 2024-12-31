#include "evaluate.hh"

bool evaluate(const BinTree<string> t) {
    if (t.value() == "true") return true;
    else if(t.value() == "false") return false;
    else if (t.value() == "and") return evaluate(t.left()) && evaluate(t.right());
    else if (t.value() == "or") return evaluate(t.left()) || evaluate(t.right());
    else if (t.value() == "not") return !evaluate(t.left());
    
    return false;
}
