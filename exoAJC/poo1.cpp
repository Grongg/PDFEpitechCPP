#include "poo1.hpp"

int main()
{
    Livre livre1("Harry Potter", "J.K. Rowling", 1997, 450);
    Livre livre2("Les Misérables", "Victor Hugo", 1862, 1500);
    Livre livre3("Dune", "Frank Herbert", 1965, 800);

    livre1.afficherInfo();
    cout << livre1.estAncien() << endl;
    livre2.afficherInfo();
    cout << livre2.estAncien() << endl;
    livre3.afficherInfo();
    cout << livre3.estAncien() << endl;
    return 0;
}