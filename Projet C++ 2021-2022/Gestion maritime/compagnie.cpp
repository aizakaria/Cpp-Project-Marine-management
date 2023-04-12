#include "compagnie.h"
#include<fstream>

//constructeur
Compagnie::Compagnie(string nomComp)
{
    nomCompagnie = nomComp;
}

//getters
string Compagnie::getNomCompagnie()
{
    return nomCompagnie;
}
vector<Navire *> Compagnie::getListeNavire()
{
    return listeNavire;
}

//methode pour le trie
bool comparateurTrajet(Trajet *traj1,Trajet *traj2)
{
    if(traj1->getDate() == traj2->getDate())
        return (traj1->getHeureDepart() < traj2->getHeureDepart());
    else return (traj1->getDate() < traj2->getDate());
}

//methode d'qjout
void Compagnie::ajoutTrajet(Trajet *trajet)
{
    listeTrajet.push_back(trajet);
}

void Compagnie::afficheToutTrajet()
{
    ofstream fichierTrajet("ArchiveTrajets.txt");

    list<Trajet *>::iterator it;
    cout<<"Les trajets de la compagnie sont : "<<endl;
    listeTrajet.sort(comparateurTrajet);
    fichierTrajet<<"Liste de tout les trajets :"<<endl;
    for(it=listeTrajet.begin();it!=listeTrajet.end();it++)
    {
        (*it)->afficheTrajet();
        //fichier archive
        if(fichierTrajet)
        {
            //contenu fichier
            fichierTrajet<<"Port Depart : "<<(*it)->getPortDepart()<<"  Port Arrive : "<<(*it)->getPortArrivee()<<" Date : "<<(*it)->getDate()<<" Heure Depart : "<<(*it)->getHeureDepart()<<" Heure Arrivee : "<<(*it)->getHeureArrivee()<<endl;
        }
        else
        {
            cout<<"Erreur: Impossible d ouvrir le fichier."<<endl;
        }
    }
}
Compagnie::~Compagnie()
{
    //dtor
}
