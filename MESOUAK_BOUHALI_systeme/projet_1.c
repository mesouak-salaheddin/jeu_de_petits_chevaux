//MESOUAK Salaheddin  BOUHALI Walid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

#include "creation.h"
#include "choix.h"


int main(int argc, char* argv[]) {
    int pid ;
    int tubes[9][2];
    int i;


    printf("Le pid du pere est : %d\n\n\n", getpid());
    creation_des_tubes(tubes);

    for (i = 0; i < 4; i++) { //C'est le nombre des processus fils = 4
        pid = fork();
        if (pid == -1) {
            printf("Erreur de creation de fils\n");
            return 2; //Pour sortir de la condition
        }
        if (pid == 0) {
            //Dans cette étape on va commencer le traitement des processus fils
            int score_de;
            int tour_joueur;
            int dernier_joueur;

            if (read(tubes[i][0], &tour_joueur, sizeof(int)) == -1) {
                printf("Erreur de lecture tube[%d]\n",i);
                return 3; //Pour sortir de la condition
            }

            //initialisation du joueur au fin du tour
            if( tour_joueur == 0){
                dernier_joueur = 3;
            }else{
                dernier_joueur = tour_joueur - 1;
            }

            //si le fils est le meme joueur choisi par le processus pere
            if(i == tour_joueur){
                score_de = choix_numero();
                printf("le joueur %d lance le de et transmets  : %d\n", i , score_de);
                if (write(tubes[i + 4][1], &score_de, sizeof(int)) == -1){
                    printf("Erreur d'ecriture tubes [%d]\n",i+4);
                    return 4; //Pour sortir de la condition
                }

            }//On va traiter le comportement des autres processus fils
            else if(i == dernier_joueur){

                //cas ou le dernier joueur est le fils numero 0
                if ( dernier_joueur == 0 ){
                        //lecture dans le dernier tube 
                        if (read(tubes[7][0], &score_de, sizeof(int)) == -1) {
                            printf("Erreur de lecture tube [7]\n");
                            return 3; //Pour sortir de la condition
                        }
                        printf("le fils %d recoi : %d\n", i, score_de);

                        //ecriture dans le pipe specifique qui rend l'information au pere
                        if (write(tubes[8][1], &score_de, sizeof(int)) == -1) {
                            printf("Erreur d'ecriture tube[8]\n");
                            return 4; //Pour sortir de la condition
                        }
                }else{
                    if (read(tubes[i + 3][0], &score_de, sizeof(int)) == -1) {
                        printf("Erreur de lecture tubes [%d]\n",i+3);
                        return 3; //Pour sortir de la condition
                    }
                    printf("le fils %d recoi : %d\n", i, score_de);
                    if (write(tubes[8][1], &score_de, sizeof(int)) == -1) {
                        printf("Erreur d'ecriture tubes [8]\n");
                        return 4; //Pour sortir de la condition
                    }
                }
            }else if (i == 0){
                if (read(tubes[7][0], &score_de, sizeof(int)) == -1) {
                    printf("Erreur de lecture tubes [7]\n");
                    return 3; //Pour sortir de la condition
                }
                printf("le fils %d recoi : %d\n", i, score_de);
                if (write(tubes[i + 4][1], &score_de, sizeof(int)) == -1) {
                    printf("Erreur de d'ecriture tubes [%d]\n",i+4);
                    return 4; //Pour sortir de la condition
                }

            }else {    
                if (read(tubes[i + 3][0], &score_de, sizeof(int)) == -1) {
                    printf("Erreur de lecture tubes [%d]\n",i+3);
                    return 3; //Pour sortir de la condition
                }
                printf("le fils %d recoi : %d\n", i, score_de);
                if (write(tubes[i + 4][1], &score_de, sizeof(int)) == -1) {
                    printf("Erreur de d'ecriture tubes [%d]\n\n\n",i+4);
                    return 4; //Pour sortir de la condition
                }
            }
            return 0;
        }
    }

    //comportement du processus pere
    
    int joueur_choisi; 
    joueur_choisi = choix_joueur();
    printf("processus choisi le fils %d pour commencer le jeu\n", joueur_choisi);

    for(int j = 0;j<4;j++){
        if (write(tubes[j][1], &joueur_choisi, sizeof(int)) == -1) {
            printf("Erreur d'ecriture\n");
            return 4;
        }
    }

    if (read(tubes[8][0], &joueur_choisi, sizeof(int)) == -1) {
        printf("erreur de lecture\n");
        return 3;
    }
    printf("Le resultat final est %d\n", joueur_choisi);
    // Pour être sur qu'on a pas un processus zombie
    for (i = 0; i < 4; i++) {
        wait(NULL);
    }
    return 0;
}
