#include <stdlib.h>
#include <stdio.h>
#include "cre_tab.h"

char tab1[4][4];
char tab2[16][4];
char mots_trouve[16][40];
int points[40];

void printMots(){
    int i;
    int j;
    for(i=0;i<40;i++){
        printf ("\n");
        for(j=0;j<16;j++){
            printf("%c",mots_trouve[j][i]);
        }
        
    }
    
}

void score(int coordone[33],int ligne){
    int point=0;
    int d;
    int i,j;
    int MT=0;
    int MD=0;
    int letre=0;
    
    for (d=0;coordone[d]!=20;d=d+2){// pour chaqueu coordonné donné on met la lettre dans le mot_trouvé[][ligne] formant ainsi des mots et on met le score de ce mot dans point[ligne] au même endroit
        
        j=coordone[d];
        d++;
        i=coordone[d];
        
        
        mots_trouve[letre][ligne]=tab2[j][i];
        letre++;
        
        
        if(tab2[4*j+1][i]=='L'){
            if(tab2[4*j+2][i]=='T')
                point = point + (tab2[4*i+3][j]-'0');
            else if(tab2[4*j+2][i]=='D')
                point = point + 2 * (tab2[4*i+3][j]-'0');
        }
        
        
        
        else if(tab2[4*j+1][i]=='M'){
            if(tab2[4*j+2][i]=='T')
                MT=1;
            else if(tab2[4*j+2][i]=='D')
                MD=1;
        }
        
        
        
        point= point + tab2[4*i+3][j];
    }
    
    if (MT==1)
        point=point*3;
    else if(MD==1)
        point=point*2;
    points[ligne]=point;
    
}

/*int main(){
    int test[33]={1,2,3,2,1,0,0,1,1,2,20};
    cre_tab1();
    complet_tab();
    printab(tab2);
    printf("\n");
    score(test,1);
    printMots();
    return (0);
}*/