//MESOUAK Salaheddin  BOUHALI Walid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "choix.h"

int choix_joueur() {
    //Initialisation du g�n�rateur pseudo-al�atoires
    srand(time(NULL));
    //Pour avoir un num�ro entre 0 et 3 qui pr�sente le num�ro de joueur
    int joueur = rand()%4;
    return joueur;
}

int choix_numero(){
    //Initialisation du g�n�rateur pseudo-al�atoires
    srand(time(NULL));
    //On a ajouter un 1 car le d�s commence de 1 jusqu'� 6, on ne peut pas avoir 0
    int numero_a_jouer = rand()%6+1;  
    return numero_a_jouer;
}



