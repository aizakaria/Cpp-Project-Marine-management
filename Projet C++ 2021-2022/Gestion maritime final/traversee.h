#ifndef TRAVERSEE_H
#define TRAVERSEE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Trajet;
class Traversee
{

    protected:

    private:
        string nomTraversee;
        Trajet *trajet;
    public:
        Traversee();
        Traversee(string,Trajet *tra);
        string getNomTraversee();
        Trajet * getTrajet();
        void afficheTraversee();
        virtual ~Traversee();



};

#endif // TRAVERSEE_H
