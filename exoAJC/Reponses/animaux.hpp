#ifndef ANIMAUX_HPP_
# define ANIMAUX_HPP_
# include <iostream>
# include <iomanip>
# include <string>
# include <algorithm>
# include <cmath>

using namespace std;

class CreatureMythique
{
private:
    string nom;
    double taille;
    string pouvoir;

public:
    CreatureMythique(string _nom, double _taille, string _pouvoir);
    ~CreatureMythique();
    void afficherDetails();
};

CreatureMythique::CreatureMythique(string _nom, double _taille, string _pouvoir) 
                            : nom(_nom), taille(_taille), pouvoir(_pouvoir)
{}

CreatureMythique::~CreatureMythique()
{}

void CreatureMythique::afficherDetails()
{
    cout << "\nVoici les détails de votre Creature mythique:" << endl;
    cout << "Nom: " << nom << endl;
    cout << "Taille: " << fixed << setprecision(2) << taille << "m" << endl;
    cout << "Pouvoir: " << pouvoir << endl;
}

class Patrice : CreatureMythique
{
private:
    int orteilles;
public:
    Patrice(string _nom, double _taille, string _pouvoir, int _orteilles) ;
    ~Patrice();
    void afficherDetails();
};

Patrice::Patrice(string _nom, double _taille, string _pouvoir, int _orteilles) : CreatureMythique(_nom, _taille, _pouvoir), orteilles(_orteilles)
{}

void Patrice::afficherDetails()
{
    CreatureMythique::afficherDetails();
    cout << "Orteilles: " << orteilles << endl;
}

Patrice::~Patrice()
{}

class Guillaume : CreatureMythique
{
private:
    bool isPharisien;
public:
    Guillaume(string _nom, double _taille, string _pouvoir, bool _isPharisien) ;
    ~Guillaume();
    void afficherDetails();
};

Guillaume::Guillaume(string _nom, double _taille, string _pouvoir, bool _isPharisien) 
            : CreatureMythique(_nom, _taille, _pouvoir), isPharisien(_isPharisien)
{}

void Guillaume::afficherDetails()
{
    CreatureMythique::afficherDetails();
    if (isPharisien)
        cout << "Est-il un pharisien: OUI" << endl;
    else
        cout << "Est-il un pharisien: non";
}

Guillaume::~Guillaume()
{}

class Camille : CreatureMythique
{
private:
    bool isSick;
public:
    Camille(string _nom, double _taille, string _pouvoir, bool _isSick) ;
    ~Camille();
    void afficherDetails();
};

Camille::Camille(string _nom, double _taille, string _pouvoir, bool _isSick) 
            : CreatureMythique(_nom, _taille, _pouvoir), isSick(_isSick)
{}

void Camille::afficherDetails()
{
    CreatureMythique::afficherDetails();
    if (isSick)
        cout << "Est-il malade: OUI" << endl;
    else
        cout << "Est-il malade: non";
}

Camille::~Camille() {}

class Lou : CreatureMythique
{
private:
    string element;
public:
    Lou(string _nom, double _taille, string _pouvoir, string _element) ;
    ~Lou();
    void afficherDetails();
};

Lou::Lou(string _nom, double _taille, string _pouvoir, string _element) 
            : CreatureMythique(_nom, _taille, _pouvoir), element(_element)
{}

void Lou::afficherDetails()
{
    CreatureMythique::afficherDetails();
    cout << "Element: " << element << endl;
}

Lou::~Lou() {}

#endif