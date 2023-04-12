#include "membreequipage.h"
#include<fstream>
using namespace std;

//constructeur
MembreEquipage::MembreEquipage(string id,string nom,string prenom)
{
    idMembre = id;
    nomMembre = nom;
    prenomMembre = prenom;
}

//getters
string MembreEquipage::getIdMembre()
{
    return idMembre;
}
string MembreEquipage::getNomMembre()
{
    return nomMembre;
}
string MembreEquipage::getPrenomMembre()
{
    return prenomMembre;
}
Trajet * MembreEquipage::getTrajet()
{
    return trajet;
}

//affichage
void MembreEquipage::afficheMembre()
{
    cout<<"Nom : "<<getNomMembre()<<" prenom : "<<getPrenomMembre()<<endl;
}

//constructeur
Capitaine::Capitaine(float tonnMax,string id,string N,string P) : MembreEquipage(id,N,P)
{
    tonnageMaximum = tonnMax;
}

//getters
float Capitaine::getTonnageMax()
{
    return tonnageMaximum;
}
//affichage
void Capitaine::afficheMembre()
{
    cout<<"Les informations du capitaine :"<<endl;
    MembreEquipage::afficheMembre();
    cout<<"Le tonnage max est : "<<getTonnageMax()<<endl;
}


//constructeur
Second::Second(float tonnMax,string id,string N,string P) : MembreEquipage(id,N,P)
{
    tonnageMaximum = tonnMax;
}

//getters
float Second::getTonnageMax()
{
    return tonnageMaximum;
}

//affichage
void Second::afficheMembre()
{
    cout<<"Les informations du second :"<<endl;
    MembreEquipage::afficheMembre();
    cout<<"Le tonnage max est : "<<getTonnageMax()<<endl;
}

//constructeur
Matelot::Matelot(string id,string N,string P):MembreEquipage(id,N,P)
  {

  }

//affichage
void Matelot::afficheMembre()
{
    cout<<"Les informations du matelot :"<<endl;
    MembreEquipage::afficheMembre();
}

MembreEquipage::~MembreEquipage()
{
    //dtor
}
