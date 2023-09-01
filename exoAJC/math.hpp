#ifndef MATH_H
# define MATH_H
# include <iostream>
# include <string>
# include <algorithm>
# include <cmath>

using namespace std;

class Forme
{
private:
    /* data */
public:
    int aire();
};


int Forme::aire()
{

}

class Rectangle : Forme
{
private:
    int largeur;
    int hauteur;
public:
    Rectangle(int _largeur, int _hauteur);
    ~Rectangle();
    int aire();
};

Rectangle::Rectangle(int _largeur, int _hauteur) : largeur(_largeur), hauteur(_hauteur)
{
}

Rectangle::~Rectangle()
{
}

int Rectangle::aire()
{
    return  this->largeur * this->hauteur;
}

class Cercle : Forme
{
private:
   int rayon;
public:
    Cercle(int _rayon);
    ~Cercle();
    int aire();
};

Cercle::Cercle(int _rayon) :  rayon(_rayon)
{
}

Cercle::~Cercle()
{
}

int Cercle::aire()
{
    return  M_PI * this->rayon * this->rayon;
}

#endif 