// gerard.rius.husillos@estudiantat.upc.edu L23
// sergio.garcia.pasalodos@estudiantat.upc.edu L51

#include <algorithm>
#include <iostream>
#include "Cjt_estudiants.hh"

#include <cmath>

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    if (Cjt_estudiants::MAX_NEST <= nest) return;

    int pos = Cjt_estudiants::cerca_dicot(vest, 0, nest-1, est.consultar_DNI());
    
    if (nest != 0 && vest[pos].consultar_DNI() == est.consultar_DNI()) {
        b = true;
        return;
    }

    b = false;

    vest.resize(Cjt_estudiants::MAX_NEST - 1);
    vest.insert(vest.begin() + pos, est);

    nest++;

    if (est.te_nota())
        incrementar_interval(est.consultar_nota());
}
/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
 si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    if (nest == 0) {
        b = false;
        return;
    }
    int pos = Cjt_estudiants::cerca_dicot(vest, 0, nest-1, dni);

    if (vest[pos].consultar_DNI() != dni) {
        b = false;
        return;
    }

    b = true;

    if (vest[pos].te_nota())
        decrementar_interval(vest[pos].consultar_nota());

    vest.erase(vest.begin() + pos);
    vest.resize(Cjt_estudiants::MAX_NEST);
    nest--;
}
/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
 amb el dni dni; si b, aquest estudiant ha quedat eliminat
 del paràmetre implícit */

void Cjt_estudiants::incrementar_interval(double x) {
    if (x < 0 || x > Estudiant::nota_maxima()) return;

    size_t i = floor(x);
    if (x == 10.0) i = 9;

    intervals[i]++;
}
/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha incrementat en una unitat el valor de
 la posició d'"intervals" corresponent a x */

void Cjt_estudiants::decrementar_interval(double x) {
    if (x < 0 || x > Estudiant::nota_maxima()) return;

    size_t i = floor(x);
    if (x == 10.0) i = 9;

    intervals[i]--;
}
/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha decrementat en una unitat el valor de
 la posició d'"intervals" corresponent a x */
