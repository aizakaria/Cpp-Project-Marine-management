#ifndef TRAJET_H
#define TRAJET_H
#include<vector>
#include<iostream>
#include<list>
#include"traversee.h"
#include"navire.h"
#include"voyageur.h"
#include"membreequipage.h"


using namespace std;
class MembreEquipage;
class Navire;
class Billet;
class Traversee;
class Trajet
{
    private:
        string portDepart;
        string portArrivee;
        string date;
        string heureDepart;
        string heureArrivee;

        vector<Navire *>listNavires;
        vector<MembreEquipage *>listeMembreEquipage;
        vector<Voyageur *>listeVoyageur;
        Navire *navire;
        Billet *billet;
        Compagnie *compagnie;
    public:
        //constructeur
        Trajet();
        Trajet(string,string,string,string,string);//type de trajet avec traverse

        //les acceseurs
        string getPortDepart();
        string getPortArrivee();
        string getDate();
        string getHeureDepart();
        string getHeureArrivee();
        Billet * getBillet();

        //les getters pour les listes
        vector<Traversee *>listeTraversee;
        vector<Navire *>getNavire();
        vector<MembreEquipage *>getlisteMembreEquipage();

        //les methodes d'ajout
        void ajoutTraversee(Traversee *);
        void ajoutNavire(Navire *);
        void ajoutVoyageur(Voyageur *,Billet*);

        //les methodes d'affichage
        void afficheMembreEquipage();
        void afficheNavire();
        void afficheTrajet();
        void afficheTraversee();
        void affichetoutVoyageur();

        //destructeur
        virtual ~Trajet();
    protected:


};

#endif // TRAJET_H
