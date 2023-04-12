#ifndef BILLET_H
#define BILLET_H
#include<iostream>
#include<vector>
#include<list>
#include"trajet.h"
using namespace std;
class Trajet;
class Voyageur;
class Billet
{
    private:
        int quantite;
        float tarif;
        Voyageur *voyageur;

    public:
        //constructeur
        Billet(int,float, Trajet*);
        Trajet *trajet;

        int getQuantite();
        void setQuantite(int);
        float getTarif();
        void setTarif(float);
        Voyageur * getVoyageur();

        void afficheBillet();
        virtual ~Billet();
};

#endif // BILLET_H
