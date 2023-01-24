//MESOUAK Salaheddin BOUHALI Walid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>


int main(int argc, char **argv) {
    
    int nbrfils = 4;
    int res = 0;

    for (int i = 0; i < nbrfils; i++) {
        res = fork();

        if (res == 0){

            printf("le processus fils est de pid: %d\n", getpid()); 
            exit(0);
        }
    }
   
    while (res != -1){
        res= wait(NULL);
        if(res == - 1){
            printf("tous les fils sont mort\n");
        }
        else{
            printf("le fils de pid: %d est mort\n", res);
        }
    }


    return 0;
}