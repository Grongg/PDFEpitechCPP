#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void echange(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sommeTableau(int *tab, int taille)
{
    int res = 0;

    for (int i = 0; i < taille; i++)
        res += tab[i];
    cout << "Resultat: " << res << endl;
}

void copieChaine(const char *source, char *destination)
{
    for (int i = 0; source[i] !='\n'; i++)
    {
        destination[i] = source[i];
    }
}

void dispTab(int **tab, int lignes, int colonnes)
{
    for (int i = 0; i < lignes; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            cout << "|" << tab[i][j] << "|";
        }
        cout << endl;
    }
}

int **creerMatrice(int **matrice, int lignes, int colonnes)
{
    matrice = new int*[lignes];
    for (int i = 0; i < lignes; i++)
    {
        matrice[i] = new int[colonnes];
        for (int j = 0; j < colonnes; j++)
        {
            matrice[i][j] = 0;
        } 
    }
    return matrice;
}

void dispValAddrAndPointAddr(int *a)
{
    cout << "Addresse: " << &a << endl;
    cout << "Pointeur: " << a << endl;
    cout << "Valeur: " << *a << endl;
}

int main()
{
    int a = 4;
    int b = 5;
    char test[40];
    int tab1[5] = {1, 2, 3, 4, 5};
    int **tab2;
    
    echange(&a, &b);
    cout << "a: " << a << " et b: " << b << endl;
    sommeTableau(tab1, 5);
    copieChaine("Exemple", test);
    cout << "Test: " << test << endl;
    tab2 = creerMatrice(tab2, 5, 5);
    dispTab(tab2, 5, 5);
    dispValAddrAndPointAddr(&a);

    delete(tab2);
    for (int i = 0; i < 5; i++)
    {
        delete(tab2[i]);
    }
    
    return 0;
}