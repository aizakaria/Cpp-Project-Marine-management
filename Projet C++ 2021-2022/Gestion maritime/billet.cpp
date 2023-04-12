#include "billet.h"

//constructeur
Billet::Billet(int quant,float tar , Trajet * traj)
{
    quantite = quant;
    tarif = tar;
    trajet = traj;
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
