#ifndef MEMBREEQUIPAGE_H
#define MEMBREEQUIPAGE_H
#include<iostream>

using namespace std;

class Trajet;
class Navire;
class MembreEquipage
{
    private:
        string idMembre;
        string nomMembre;
        string prenomMembre;
        Trajet *trajet;
        Navire *navire;
    public:
        //constructeur
        MembreEquipage(string,string,string);

        //getters
        string getIdMembre();
        string getNomMembre();
        string getPrenomMembre();
        Trajet * getTrajet();
        Navire * getNavire();
        //methode d'ffichage
        void virtual afficheMembre();

        //destructeur
        virtual ~MembreEquipage();
};

class Capitaine:public MembreEquipage
{
   private:
       float tonnageMaximum;
   public:
    //constructeur
    Capitaine(float,string,string,string);

    //getters
    float getTonnageMax();

    //methode d'affichage
    void afficheMembre();
};

class Second:public MembreEquipage
{
   private:
       float tonnageMaximum;
   public:
    //constructeur
    Second(float,string,string,string);

    //getters
    float getTonnageMax();

    //methode d'affichage
    void afficheMembre();
};
class Matelot:public MembreEquipage
{
public:
    //constructeur
    Matelot(string,string,string);

    //methode d'affichage
    void afficheMembre();
};

#endif // MEMBREEQUIPAGE_H
