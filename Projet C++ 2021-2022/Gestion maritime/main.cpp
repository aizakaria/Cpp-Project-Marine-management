#include <iostream>
#include<fstream>
#include"traversee.h"
#include"trajet.h"
#include"navire.h"
#include"voyageur.h"
#include"billet.h"
#include"compagnie.h"
#include"membreequipage.h"

using namespace std;

int main()
{
    cout<<"--------------------------------------------"<<endl;
    cout<<"---------Projet Gestion Maritime------------"<<endl;
    cout<<"------BRAHIMI Ismail / AJLI Zakaria---------"<<endl;
    cout<<"--------------------------------------------"<<endl;
    //creation d'un compagnie
    Compagnie comp("air France");

    //creation de 3 trajets
    Trajet t1("Limoges","Paris","Lundi","15h","20h");
    Trajet t2("Limoges","Bordeaux","Mardi","5h","10h");
    Trajet t3("Limoges","Toulouse","Vendredi","6h","11h");

    //creation de 3 traversees appartenant au premier trajet t1
    Traversee trav1("Poitiers",&t1);
    Traversee trav2("La rochelle",&t1);
    Traversee trav3("Angers",&t1);

    //creation d'un traversee appartenant au troisieme trajet t3
    Traversee trav4("Brive",&t3);

    //creation de 2 navires parcourant le premier trajet
    Navire n1("Navire1",300.0,2500,&t1);
    Navire n2("Navire2",250.0,1500,&t1);

    //creation de 2 navires parcourant le troisieme trajet
    Navire n3("Navire3",210.0,1100,&t3);

    //creation de 5 voyageurs
    Voyageur voy1(1,"permier","voyageur");
    Normal norm1(2,"permier","normal");
    Normal norm2(3,"deuxieme","normal");
    Normal norm3(4,"troisieme","normal");
    Insulaire insu1(121,"premier","insulaire");
    Insulaire insu2(15,"deuxieme","insulaire");
    Insulaire insu3(154,"troisieme","insulaire");
    InsulaireSecondaire insusecond1(14,"premier","insulaire secondaire");
    InsulaireSecondaire insusecond2(64,"deuxieme","insulaire secondaire");
    InsulaireSecondaire insusecond3(43,"troisieme","insulaire secondaire");

    //creation des billets
    Billet b1(2,100.0,&t1);
    Billet b2(5,200.0,&t2);
    Billet b3(6,100.0,&t1);
    Billet b4(2,200.0,&t2);
    Billet b5(1,100.0,&t1);
    Billet b6(3,200.0,&t3);


    //affectation des traversees a un trajet
    t1.ajoutTraversee(&trav1);
    t1.ajoutTraversee(&trav2);
    t1.ajoutTraversee(&trav3);
    t3.ajoutTraversee(&trav4);

    //affectation des navires a un trajet
    t1.ajoutNavire(&n1);
    t1.ajoutNavire(&n2);
    t3.ajoutNavire(&n3);
    cout<<"----------------------------------------------------------------"<<endl;
    //achat des billets
    norm1.achatBillet(&b2);
    norm1.achatBillet(&b3);
    norm2.achatBillet(&b4);

    //test de l'epuisement de la quantite des billets
    insu1.achatBillet(&b5);
    insu2.achatBillet(&b5); //ERREUR EPUISEMENT
    cout<<"----------------------------------------------------------------"<<endl;
    //Archiver de tout les billets d'un voyageur
    norm1.archiverToutBillet();
    cout<<"----------------------------------------------------------------"<<endl;
    //Ajout d'un voyageur
    t1.ajoutVoyageur(&insu1,&b2);
    t1.ajoutVoyageur(&insu2,&b2);
    t1.ajoutVoyageur(&norm1,&b1);
    t1.ajoutVoyageur(&norm2,&b4);

    //ajout d'un trajet
    comp.ajoutTrajet(&t1);
    comp.ajoutTrajet(&t2);
    comp.ajoutTrajet(&t3);
    cout<<"----------------------------------------------------------------"<<endl;

     //test creation, ajout et affichage des membres d'equipage
    Capitaine cap1(50.0,"id1","premier","capitaine");
    Capitaine cap2(150.0,"id2","deuxieme","capitaine");

    Matelot mat1("id1","premier","matelot");
    Matelot mat2("id2","deuxieme","matelot");
    Matelot mat3("id3","troisieme","matelot");
    Matelot mat4("id4","quatrieme","matelot");
    Matelot mat5("id5","cinquieme","matelot");
    Matelot mat6("id6","sixieme","matelot");
    Matelot mat7("id7","septieme","matelot");


    Navire nav1("3wita",50.0,100,&t1);
    nav1.ajoutCapitaine(&cap1);
    nav1.ajoutCapitaine(&cap2); //ERREUR MAXIMUM 1 capitaine dans chaque navire

    nav1.ajoutMatelot(&mat1);
    nav1.ajoutMatelot(&mat2);
    nav1.ajoutMatelot(&mat3);
    nav1.ajoutMatelot(&mat4);
    nav1.ajoutMatelot(&mat5);
    nav1.ajoutMatelot(&mat6);
    nav1.ajoutMatelot(&mat7);//ERRUER MAXIMUM 6 Matelots
    cout<<"----------------------------------------------------------------"<<endl;

    //affichage des traversees d'un trajets
    t1.afficheTraversee();
    cout<<"----------------------------------------------------------------"<<endl;
    //affichage d'un navire
    t1.afficheNavire();
    cout<<"----------------------------------------------------------------"<<endl;
    //affichage d'un trajet
    t2.afficheTrajet();
    cout<<"----------------------------------------------------------------"<<endl;
    //affichage des informations d'un billet
    b2.afficheBillet();
    b1.afficheBillet();
    cout<<"----------------------------------------------------------------"<<endl;
    //affichage de tout les voyageurs d'un trajet
    t1.affichetoutVoyageur();
    cout<<"----------------------------------------------------------------"<<endl;
    //affichage de tout les trajets
    comp.afficheToutTrajet();

    cout<<"----------------------------------------------------------------"<<endl;
    //affichage d'un membre d'equipage
    cap1.afficheMembre();
    cout<<"----------------------------------------------------------------"<<endl;
    //archiver tout les membres d'equipage d'un navire dans un fichier
    nav1.archiveToutMembreEquipage();


    return 0;
}
