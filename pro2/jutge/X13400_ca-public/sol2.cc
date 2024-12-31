// gerard.rius.husillos@estudiantat.upc.edu L23
// sergio.garcia.pasalodos@estudiantat.upc.edu L51

#include <algorithm>
#include <iostream>
#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int pos = Cjt_estudiants::cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());

    if (pos >= Cjt_estudiants::MAX_NEST || pos < 0) {
        b = false;
        return;
    }

    b = vest[pos].consultar_DNI() == est.consultar_DNI();

    if (b) return;

    for (int i = nest; i > pos; i--) {
        vest[i] = vest[i - 1];
    }

    vest[pos] = est;

    nest++;

    if (est.te_nota())
        incrementar_interval(est.consultar_nota());
}
/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
 si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int pos = Cjt_estudiants::cerca_dicot(vest, 0, nest - 1, dni);

    if (pos >= Cjt_estudiants::MAX_NEST || pos < 0) {
        b = false;
        return;
    }

    b = vest[pos].consultar_DNI() == dni;

    if (!b) return;

    if (vest[pos].te_nota())
        decrementar_interval(vest[pos].consultar_nota());

    for (int i = pos; i < nest; i++) {
        vest[i] = vest[i + 1];
    }
    
    nest--;
}
/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
 amb el dni dni; si b, aquest estudiant ha quedat eliminat
 del paràmetre implícit */

void Cjt_estudiants::incrementar_interval(double x) {
    size_t i = (unsigned int)x;
    if (x >= 10) i = 9;

    intervals[i]++;
}
/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha incrementat en una unitat el valor de
 la posició d'"intervals" corresponent a x */

void Cjt_estudiants::decrementar_interval(double x) {
    size_t i = (unsigned int)x;
    if (x >= 10) i = 9;

    intervals[i]--;
}
