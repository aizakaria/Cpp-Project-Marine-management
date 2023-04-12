#ifndef COMPAGNIE_H
#define COMPAGNIE_H
#include<iostream>
#include<vector>
#include<list>
#include"navire.h"
#include"compagnie.h"
#include"trajet.h"
using namespace std;
class Navire;
class Trajet;
class Compagnie
{
    private:
        string nomCompagnie;
        vector <Navire *> listeNavire;
        list<Trajet *>listeTrajet;
    public:
        //constructeur
        Compagnie(string);

        string getNomCompagnie();
        vector<Navire *> getListeNavire();
        list<Trajet *>getListeTrajet();

        void ajoutTrajet(Trajet*);
        void afficheToutTrajet();
        virtual ~Compagnie();


    protected:
};

#endif // COMPAGNIE_H
