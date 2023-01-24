//MESOUAK Salaheddin  BOUHALI Walid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "creation.h"


int creation_des_tubes(int tubes[9][2]) {
    int i;
    for(i=0;i<9;i++) {
        if (pipe(tubes[i])==-1) {
            fprintf(stderr,"Erreur lors de l'ouverture de pipes[%d] \n", i);
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}


