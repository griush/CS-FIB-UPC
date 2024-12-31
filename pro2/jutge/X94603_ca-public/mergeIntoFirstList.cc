#include "mergeIntoFirstList.hh"

void mergeIntoFirstList(list<int> &l1, list<int> l2) {
    list<int>::iterator it1 = l1.begin();
    list<int>::iterator it2 = l2.begin();

    while (it1 != l1.end() && it2 != l2.end()) {
        if (*it1 > *it2) {
            l1.insert(it1, *it2);
            it2++;
        } else {
            it1++;
        }
    }

    while (it2 != l2.end()) {
        l1.insert(it1, *it2);
        it2++;
    }
}