#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<iostream>
#include<vector>
using namespace std;

class Trajet;
class Billet;
class Voyageur
{
    private:
        int numVoyageur;
        string nomVoyageur;
        string prenomVoyageur;
        vector<Billet *>listeBillet;
    public:
        //constructeur
        Voyageur(int,string,string);

        //getters
        int getNumVoyageur();
        string getNomVoyageur();
        string getPrenomVoyageur();
        vector<Billet *> getListeBillet();

        //Billet *billet;
        Trajet *trajet;

        virtual void achatBillet(Billet *);
        void archiverToutBillet();
        virtual ~Voyageur();

    protected:


};
class Normal:public Voyageur
{
    private:

    public:
        //constructeur
        Normal(int,string,string);
        void achatBillet(Billet *);
};
class Insulaire:public Voyageur
{
    private:

    public:
        //constructeur
        Insulaire(int,string,string);
        void achatBillet(Billet *);
};
class InsulaireSecondaire: public Voyageur
{
    private:

    public:
        //constructeur
        InsulaireSecondaire(int,string,string);
        void achatBillet(Billet *);
};
#endif // VOYAGEUR_H
