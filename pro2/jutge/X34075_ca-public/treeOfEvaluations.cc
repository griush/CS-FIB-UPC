#include "treeOfEvaluations.hh"

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els valors true,false i els operadors and,or,not.
// Post: Retorna un arbre binari de booleans
//       que té el mateix conjunt de posicions que t.
//       A més a més, per a cada posició p, el subarbre a posició p de t
//       representa una expressió que s'avalua a true si i només si
//       hi ha el valor true a la posició p de l'arbre retornat.
BinTree<bool> treeOfEvaluations(BinTree<string> t) {
    if (t.empty()) return BinTree<bool>();

    if (t.value() == "true") return BinTree<bool>(true);
    if (t.value() == "false") return BinTree<bool>(false);

    auto l = treeOfEvaluations(t.left());
    auto r = treeOfEvaluations(t.right());

    if (t.value() == "and") return BinTree<bool>(l.value() && r.value(), l, r);
    if (t.value() == "or") return BinTree<bool>(l.value() || r.value(), l, r);
    if (t.value() == "not") return BinTree<bool>(!l.value(), l, r);

    return BinTree<bool>();
}

