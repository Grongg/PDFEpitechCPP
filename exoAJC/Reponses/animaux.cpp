#include "animaux.hpp"

int main()
{
    Patrice pat1("El pato1", 1.90, "Pipellette", 9);
    Patrice pat2("El pato2", 1.91, "Pipellette", 15);
    Guillaume guigui1("Le G1", 1.80, "Le counter de Alexandre", true);
    Guillaume guigui2("Le G2", 1.82, "Le counter de Alexandre", false);
    Camille camille1("Camille1", 1.70, "Gros cerveau", true);
    Camille camille2("Camille2", 1.73, "Gros cerveau", false);
    Lou lou1("lou1", 1.75, "Un grand pouvoir Magic", "feu");
    Lou lou2("lou2", 1.78, "Un grand pouvoir Magic", "eau");

    pat1.afficherDetails();
    pat2.afficherDetails();
    guigui1.afficherDetails();
    guigui2.afficherDetails();
    camille1.afficherDetails();
    camille2.afficherDetails();
    lou1.afficherDetails();
    lou2.afficherDetails();

    return 0;
}
