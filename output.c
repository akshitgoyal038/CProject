#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int main(){
    int choice;
    while(1){
        choice=take_choice();
        switch(choice){
            case 1: round_robin();
            break;
            case 2: shortest();
            break;
            case 3: priority_scheduling();
            break;
            case 4: exit(0);
            break;
        }
    }
    return 0;
}