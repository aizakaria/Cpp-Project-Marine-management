#include "trajet.h"
#include "billet.h"
#include<fstream>

//constructeur par defaut
Trajet::Trajet()
{

}

//constructeur
Trajet::Trajet(string pDepart,string pArrivee,string date_t,string hDepart,string hArrivee)
{
    portDepart = pDepart;
    portArrivee = pArrivee;
    date = date_t;
    heureDepart = hDepart;
    heureArrivee = hArrivee;
}

//les accesseurs
string Trajet::getPortDepart()
{
    return portDepart;
}

string Trajet::getPortArrivee()
{
    return portArrivee;
}

string Trajet::getDate()
{
    return date;
}

string Trajet::getHeureDepart()
{
    return heureDepart;
}

string Trajet::getHeureArrivee()
{
    return heureArrivee;
}

vector<Navire *> Trajet::getNavire()
{
    return listNavires;
}

vector<MembreEquipage *> Trajet::getlisteMembreEquipage()
{
    return listeMembreEquipage;
}

Billet * Trajet::getBillet()
{
    return billet;
}

//les methodes d'ajout
void Trajet::ajoutTraversee(Traversee *travers)
{
    listeTraversee.push_back(travers);
}
void Trajet::ajoutNavire(Navire *nav)
{
    listNavires.push_back(nav);
}

void Trajet::ajoutVoyageur(Voyageur *voy, Billet *billet)
{
    if(billet->getQuantite()==0)
    {
        cout<<"Erreur d'ajout! Le nombre de billet est epuise."<<endl;
    }
    else
    {
        listeVoyageur.push_back(voy);
        float oldbillet = billet->getQuantite();
        billet->setQuantite(oldbillet-1);
    }
}

//les methodes d'affichage
void Trajet::afficheTrajet()
{
    cout<<"Port Depart : "<<getPortDepart()<<" Port Arrive : "<<getPortArrivee()<<" Date Trajet : "<<getDate()<<" Heure Depart : "<<getHeureDepart()<<" Heure Arrivee : "<<getHeureArrivee()<<endl;
}

void Trajet::afficheTraversee()
{
    cout<<"Liste des traversee : "<<endl;
     vector<Traversee *>::iterator it;
     for(it = listeTraversee.begin();it!=listeTraversee.end();it++)
     {
            cout<<(*it)->getNomTraversee()<<endl;
     }
}
void Trajet::afficheNavire()
{
    cout<<"Navire utilse : "<<endl;
     vector<Navire *>::iterator it;
     for(it = listNavires.begin();it!=listNavires.end();it++)
     {
            cout<<(*it)->getNomNavire()<<endl;
     }
}

void Trajet::affichetoutVoyageur()
{
    int compteur=0;
    ofstream fichierPassager("ArchivePassagers.txt");

    cout<<"Liste des passagers concernant ce trajet : "<<endl;
     vector<Voyageur *>::iterator it;
     fichierPassager<<"Liste de tout les passagers :"<<endl;
     for(it = listeVoyageur.begin();it!=listeVoyageur.end();it++)
     {
            cout<<(*it)->getNomVoyageur()<<" "<<(*it)->getPrenomVoyageur()<<endl;
            compteur++;

        if(fichierPassager)
        {
            //contenu fichier
            fichierPassager<<"Nom : "<<(*it)->getNomVoyageur()<<"  Prenom : "<<(*it)->getPrenomVoyageur()<<endl;
        }
        else
        {
            cout<<"Erreur: Impossible d ouvrir le fichier."<<endl;
        }
     }
     cout<<"Ce Trajet comporte "<<compteur<<" voyageurs."<<endl;
}


//destructeur
Trajet::~Trajet()
{
    //dtor
}
