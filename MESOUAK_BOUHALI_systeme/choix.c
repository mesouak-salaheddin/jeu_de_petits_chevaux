//MESOUAK Salaheddin  BOUHALI Walid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "choix.h"

int choix_joueur() {
    //Initialisation du générateur pseudo-aléatoires
    srand(time(NULL));
    //Pour avoir un numéro entre 0 et 3 qui présente le numéro de joueur
    int joueur = rand()%4;
    return joueur;
}

int choix_numero(){
    //Initialisation du générateur pseudo-aléatoires
    srand(time(NULL));
    //On a ajouter un 1 car le dés commence de 1 jusqu'à 6, on ne peut pas avoir 0
    int numero_a_jouer = rand()%6+1;  
    return numero_a_jouer;
}



