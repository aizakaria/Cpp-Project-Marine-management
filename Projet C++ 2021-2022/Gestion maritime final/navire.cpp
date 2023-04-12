#include "navire.h"
#include<fstream>
#include "membreequipage.h"

//constructeur
Navire::Navire(string nomV,float tonn,int capacite,Trajet *tra)
{
    NomNavire = nomV;

    tonnage = tonn;
    capaciteMarchandise = capacite;
    trajet = tra;

}
//getters
string Navire::getNomNavire()
{
    return NomNavire;
}
float Navire::getTonnage()
{
    return tonnage;
}
int Navire::getCapaciteMarchandise()
{
    return capaciteMarchandise;
}
Trajet * Navire::getTrajet()
{
    return trajet;
}
Compagnie * Navire::getCompagnie()
{
    return  compagnie;
}
vector<Capitaine *> Navire::getlisteCapitaine()
{
    return listeCapitaine;
}
vector<Second *> Navire::getlisteSecond()
{
    return listeSecond;
}
vector<Matelot *> Navire::getlisteMatelot()
{
    return listeMatelot;
}

//ajout
void Navire::ajoutCapitaine(Capitaine *capitaine)
{
    if(listeCapitaine.size()>=1)
    {
        cout<<"Erreur ! Ce navire contient deja un capitaine."<<endl;
    }
    else
    {
        cout<<"Ajout du capitaine avec succes!"<<endl;
         listeCapitaine.push_back(capitaine);
    }
}

void Navire::ajoutSecond(Second *second)
{

     if(listeSecond.size()>=1)
    {
        cout<<"Erreur ! Ce navire contient deja un second."<<endl;
    }
    else
    {
        cout<<"Ajout du second avec succes!"<<endl;
         listeSecond.push_back(second);
    }
}
void Navire::ajoutMatelot(Matelot *matelot)
{

     if(listeMatelot.size()>=6)
    {
        cout<<"Erreur ! Ce navire contient deja 6 matelots."<<endl;
    }
    else
    {
        cout<<"Ajout du matelot avec succes!"<<endl;
         listeMatelot.push_back(matelot);
    }
}


void Navire::archiveToutMembreEquipage()
{
    ofstream fichierMembreEquipage("archiveMembreEquipage.txt");
     vector<Capitaine *>::iterator it;
     vector<Second *>::iterator it1;
     vector<Matelot *>::iterator it2;
     fichierMembreEquipage<<"Liste des capitaines : "<<endl;
     for(it = listeCapitaine.begin();it!=listeCapitaine.end();it++)
     {

        if(fichierMembreEquipage)
        {
            //contenu fichier
            fichierMembreEquipage<<"Id membre : "<<(*it)->getIdMembre()<<" Nom : "<<(*it)->getNomMembre()<<"  Prenom : "<<(*it)->getPrenomMembre()<<" Tonnage : "<<(*it)->getTonnageMax()<<endl;
        }
        else
        {
            cout<<"Erreur: Impossible d ouvrir le fichier."<<endl;
        }
     }
     fichierMembreEquipage<<"Liste des seconds : "<<endl;
     for(it1 = listeSecond.begin();it1!=listeSecond.end();it1++)
     {

        if(fichierMembreEquipage)
        {
            //contenu fichier
            fichierMembreEquipage<<"Id membre : "<<(*it1)->getIdMembre()<<" Nom : "<<(*it1)->getNomMembre()<<"  Prenom : "<<(*it1)->getPrenomMembre()<<" Tonnage : "<<(*it1)->getTonnageMax()<<endl;
        }
        else
        {
            cout<<"Erreur: Impossible d ouvrir le fichier."<<endl;
        }
     }
     fichierMembreEquipage<<"Liste des matelots : "<<endl;
     for(it2 = listeMatelot.begin();it2!=listeMatelot.end();it2++)
     {

        if(fichierMembreEquipage)
        {
            //contenu fichier
            fichierMembreEquipage<<"Id membre : "<<(*it2)->getIdMembre()<<" Nom : "<<(*it2)->getNomMembre()<<"  Prenom : "<<(*it2)->getPrenomMembre()<<endl;
        }
        else
        {
            cout<<"Erreur: Impossible d ouvrir le fichier."<<endl;
        }
     }
      cout<<"Les membres d'equipage sont archives avec succes !"<<endl;
}

//constructeur
NavireDeFret::NavireDeFret(string id,string nomV,float tonn,int capacite,Trajet *tra) : Navire(nomV,tonn,capacite,tra)
{
    idNavFret = id;
}

//constructeur
NavireMixte::NavireMixte(int passagers,string id,string nomV,float tonn,int capacite,Trajet *tra) : Navire(nomV,tonn,capacite,tra)
{
    nbrPassagers = passagers;
}
int NavireMixte::getNbrPassagers()
{
    return nbrPassagers;
}




