#include "traversee.h"
Traversee::Traversee()
{
    cout<<"pas de traversee"<<endl;
}

Traversee::Traversee(string nm,Trajet *tra)
{
    //ctor
    nomTraversee = nm;
    trajet = tra;
    //tra->ajoutTraversee(this);
}
string Traversee::getNomTraversee()
{
    return nomTraversee;
}
Trajet * Traversee::getTrajet()
{
    return trajet;
}
void Traversee::afficheTraversee()
{
    cout<<"Ce trajet passe par la traverse : "<<getNomTraversee()<<endl;
}
Traversee::~Traversee()
{
    //dtor
}
