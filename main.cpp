#include <iostream>
#include <string>

using namespace std;

struct Personaj {
    string nume;
    int nivel;
    int puncteViata;

    Personaj() : nume("Necunoscut"), nivel(1), puncteViata(100) {}
    Personaj(string n, int niv, int pViata) : nume(n), nivel(niv), puncteViata(pViata) {}
    Personaj(const Personaj& altPersonaj) : nume(altPersonaj.nume), nivel(altPersonaj.nivel), puncteViata(altPersonaj.puncteViata) {}

    Personaj& operator=(const Personaj& altPersonaj) {
        if (this != &altPersonaj) {
            nume = altPersonaj.nume;
            nivel = altPersonaj.nivel;
            puncteViata = altPersonaj.puncteViata;
        }
        return *this;
    }

    bool operator==(const Personaj& altPersonaj) const {
        return (nume == altPersonaj.nume && nivel == altPersonaj.nivel && puncteViata == altPersonaj.puncteViata);
    }

    friend istream& operator>>(istream& is, Personaj& personaj) {
        cout << "Introduceti numele: ";
        is >> personaj.nume;
        cout << "Introduceti nivelul: ";
        is >> personaj.nivel;
        cout << "Introduceti punctele de viata: ";
        is >> personaj.puncteViata;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Personaj& personaj) {
        os << "Nume: " << personaj.nume << ", Nivel: " << personaj.nivel << ", Puncte de viata: " << personaj.puncteViata;
        return os;
    }
};

int main() {
    Personaj p1;
    cout << p1 << endl;

    Personaj p2("Erou", 5, 200);
    cout << p2 << endl;

    Personaj p3 = p2;
    cout << p3 << endl;

    if (p2 == p3) {
        cout << "Personajele sunt egale!" << endl;
    }

    Personaj p4;
    cin >> p4;
    cout << p4 << endl;

    return 0;
}
