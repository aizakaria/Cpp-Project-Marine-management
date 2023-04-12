#include "billet.h"

//constructeur
Billet::Billet(int quant,float tar , Trajet * traj,Voyageur *voy)
{
    quantite = quant;
    tarif = tar;
    trajet = traj;
    voyageur = voy;
}
//getters && setters
int Billet::getQuantite()
{
    return quantite;
}

void Billet::setQuantite(int quant)
{
    quantite = quant;
}

Voyageur * Billet::getVoyageur()
{
    return voyageur;
}
Trajet * Billet::getTrajet()
{
    return trajet;
}
float Billet::getTarif()
{
    return tarif;
}
void Billet::setTarif(float tar)
{
    tarif = tar;
}

//affichage
void Billet::afficheBillet()
{
    cout<<"Les informations concernat le billet sont :"<<endl<<"La quantite : "<<quantite<<endl<<"Tarif : "<<tarif<<endl<<"Trajet Depart : "<<trajet->getPortDepart()<<endl<<"Trajet Arrivee : "<<trajet->getPortArrivee()<<endl;
}

Billet::~Billet()
{
    //dtor
}
