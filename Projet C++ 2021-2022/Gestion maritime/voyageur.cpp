#include "voyageur.h"
#include "billet.h"
#include<fstream>

//constructzur
Voyageur::Voyageur(int num,string nom,string prenom)
{
    numVoyageur = num;
    nomVoyageur = nom;
    prenomVoyageur = prenom;
}

//getters
int Voyageur::getNumVoyageur()
{
    return numVoyageur;
}
string Voyageur::getNomVoyageur()
{
    return nomVoyageur;
}
string Voyageur::getPrenomVoyageur()
{
    return prenomVoyageur;
}
vector<Billet *> Voyageur::getListeBillet()
{
    return listeBillet;
}

void Voyageur::achatBillet(Billet *b)
{
    listeBillet.push_back(b);
}

void Voyageur::archiverToutBillet()
{
    ofstream fichierBillet("ArchiveBillets.txt");

    cout<<"Billet archive avec succes !"<<endl;
     vector<Billet *>::iterator it;
     fichierBillet<<"Liste de tout les billets :"<<endl;
     for(it = listeBillet.begin();it!=listeBillet.end();it++)
     {
            cout<<"Tarif : "<<(*it)->getTarif()<<endl;

        if(fichierBillet)
        {
            //contenu fichier
            fichierBillet<<"Quantite : "<<(*it)->getQuantite()<<"  Tarif : "<<(*it)->getTarif()<<endl;
        }
        else
        {
            cout<<"Erreur: Impossible d ouvrir le fichier."<<endl;
        }
     }
}

//constructeur
Normal::Normal(int num,string nom,string prenom):Voyageur(num,nom,prenom)
{


}

void Normal::achatBillet(Billet *b)
{
    if(b->getQuantite()==0)
    {
        cout<<"Erreur d'achat! Le nombre de billet est epuise."<<endl;
    }
    else
    {
    getListeBillet().push_back(b);
    cout<<"Billet normal achete avec succes !"<<endl;
    float oldbillet = b->getQuantite();
    b->setQuantite(oldbillet-1);
    }

}
Insulaire::Insulaire(int num,string nom,string prenom):Voyageur(num,nom,prenom)
{

}

void Insulaire::achatBillet(Billet *b)
{
    if(b->getQuantite()==0)
    {
        cout<<"Erreur d'achat! Le nombre de billet est epuise."<<endl;
    }
    else
    {
    float oldtarif = b->getTarif();
    b->setTarif(oldtarif-(oldtarif*0.50));
    getListeBillet().push_back(b);
    cout<<"Billet insulaire achete avec succes !"<<endl;
    float oldbillet = b->getQuantite();
    b->setQuantite(oldbillet-1);
    }
}

//constructeur
InsulaireSecondaire::InsulaireSecondaire(int num,string nom,string prenom):Voyageur(num,nom,prenom)
{

}

void InsulaireSecondaire::achatBillet(Billet *b)
{
   if(b->getQuantite()==0)
    {
        cout<<"Erreur d'achat! Le nombre de billet est epuise."<<endl;
    }
    else
    {
    float oldtarif = b->getTarif();
    b->setTarif(oldtarif-(oldtarif*0.25));
    getListeBillet().push_back(b);
    cout<<"Billet insulaire secondaire achete avec succes !"<<endl;
    float oldbillet = b->getQuantite();
    b->setQuantite(oldbillet-1);
    }
}
Voyageur::~Voyageur()
{
    //dtor
}
