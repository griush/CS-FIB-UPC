#include <map>
#include <string>
#include "execute.hh"

int main()
{
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
    map<string,int> var2val;
	string s;
  	while (cin >> t and not t.empty()) {
    	istringstream mycin(s);
        execute(var2val, t);
  	}
}

// Pre:  t és un arbre no buit d'strings que representa una expressió correcta
//       sobre dígits i variables que guarden dígits, i els operadors +,* mòdul 10.
//       En particular, l'arrel de t és o bé +, o bé *, o bé un dígit, o bé una variable.
//       var2val és un mapeig de variables a dígits.
// Post: Retorna l'avaluació de l'expressió representada per t reemplaçant les variables
//       pels seus corresponents valors definits a var2val, o per 0 si no estan definides.
int evaluate(map<string,int> &var2val, BinTree<string> t) {
    if (t.value() == "+") return (evaluate(var2val, t.left()) + evaluate(var2val, t.right())) % 10;
    if (t.value() == "*") return (evaluate(var2val, t.left()) * evaluate(var2val, t.right())) % 10;
    if (t.value() >= "0" and t.value() <= "9") return stoi(t.value());
    return var2val[t.value()];
}

// Pre:  t és un arbre no buit d'strings que representa una instrucció correcta
//       del llenguatge de programació descrit a l'enunciat.
//       En particular, o bé és l'arbre buit,
//       o bé la seva arrel és, o bé =, o bé print, o bé if, o bé while,
//       o bé list, cas en el cual, representa una subllista d'instruccions.
// Post: S'ha simulat l'execució d'aquesta instrucció, modificant var2val
//       i escrivint el que calgui per la sortida estandar,
//       d'acord a aquesta simulació.
void execute(map<string,int> &var2val, BinTree<string> t) {
    if (t.empty()) return;
    if (t.value() == "=") {
        var2val[t.left().value()] = evaluate(var2val, t.right());
        return;
    }
    if (t.value() == "print") {
        cout << evaluate(var2val, t.left()) << endl;
        return;
    }
    if (t.value() == "if") {
        if (evaluate(var2val, t.left()) != 0) execute(var2val, t.right());
        return;
    }
    if (t.value() == "while") {
        while (evaluate(var2val, t.left()) != 0) execute(var2val, t.right());
        return;
    }
    
    execute(var2val, t.left());
    execute(var2val, t.right());
}
