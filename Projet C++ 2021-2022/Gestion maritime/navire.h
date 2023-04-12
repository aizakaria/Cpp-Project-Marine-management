#ifndef NAVIRE_H
#define NAVIRE_H
#include<iostream>
#include<list>
#include<vector>
#include"membreequipage.h"
using namespace std;
class Trajet;
class Compagnie;
class Capitaine;
class Matelot;
class Second;
class MembreEquipage;
class Second;
class Navire
{
    private:
        string NomNavire;
        float tonnage;
        int capaciteMarchandise;
        Trajet *trajet;
        Compagnie *compagnie;
        vector<Capitaine *>listeCapitaine;
        vector<Second *>listeSecond;
        vector<Matelot *>listeMatelot;
    public:
        Navire(string,float,int,Trajet *);
        string getNomNavire();
        float getTonnage();
        int getCapaciteMarchandise();
        Trajet * getTrajet();
        Compagnie *getCompagnie();
        vector<Capitaine *>getlisteCapitaine();
        vector<Second *>getlisteSecond();
        vector<Matelot *>getlisteMatelot();

        void ajoutCapitaine(Capitaine *);
        void ajoutSecond(Second *);
        void ajoutMatelot(Matelot *);
        void archiveToutMembreEquipage();
};
class NavireDeFret : public Navire
{
   private:
       string idNavFret;
   public:
       NavireDeFret(string,string,float,int,Trajet *tra);
       string getIdNav();
};
class NavireMixte : public Navire
{
private :
    int nbrPassagers;
public :
    NavireMixte(int,string,string,float,int,Trajet *tra);
    int getNbrPassagers();
};
#endif // NAVIRE_H
