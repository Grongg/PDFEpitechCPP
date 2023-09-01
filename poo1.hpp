#ifndef POO1_HPP_
# define POO1_HPP_
# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

class Emprunteur
{
private:
    string nom;
    Livre *listeLivres[5];
    int nombreLivresEmpruntes;

public:
    Emprunteur(string);
    ~Emprunteur();
};

Emprunteur::Emprunteur(string _nom)
        : nom(_nom), nombreLivresEmpruntes(0)
{}

Emprunteur::~Emprunteur()
{
}

class Livre
{
private:
    string titre;
    string auteur;
    int anneePublication;
    int nbrPages;
    bool estEmprunte;

public:
    Livre(string, string, int, int);
    ~Livre();
    string getTitre();
    string getAuteur();
    int getAnneePublication();
    int getnbrPages();
    void setTitre(string);
    void setAuteur(string);
    void setAnneePublication(int);
    void setnbrPages(int);
    void afficherInfo();
    bool estAncien();
};

Livre::Livre(string _titre, string _auteur, int _anneePublication, int _nbrPages) 
    : titre(_titre), auteur(_auteur), anneePublication(_anneePublication), nbrPages(_nbrPages), estEmprunte(false)
{}

string Livre::getTitre()
{
    return this->titre;
}

void Livre::setTitre(string titre)
{
    this->titre = titre;
}

void Livre::setAuteur(string auteur)
{
    this->auteur = auteur;
}

void Livre::setAnneePublication(int anneePublication)
{
    this->anneePublication = anneePublication;
}

void Livre::setnbrPages(int nbrPages)
{
    this->nbrPages = nbrPages;
}

string Livre::getAuteur()
{
    return this->auteur;
}

int Livre::getAnneePublication()
{
    return this->anneePublication;
}

int Livre::getnbrPages()
{
    return this->nbrPages;
}

void Livre::afficherInfo()
{
    cout << "Voici les informations du livre:" << endl;
    cout << "Titre: " << this->titre << endl;
    cout << "Auteur: " << this->auteur << endl;
    cout << "Année de publication: " << this->anneePublication << endl;
    cout << "Nombre de page: " << this->nbrPages << endl;
}

bool Livre::estAncien()
{
    if ((2023 - this->anneePublication) > 30)
    {
        return true;
    }
    return false;
}

Livre::~Livre()
{
    cout << "Le livre \"" << this->titre << "\" à bien été supprimé." << endl;
} 



#endif