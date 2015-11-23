
#include <stdlib.h>
#include <stdio.h>

// pour l'aléatoire
#include <time.h>
#define N 100

char tab1[4][4];
char tab2[16][4];


void printab(char tab[16][4]){
    int i;
    int j;
    for(i=0;i<4;i++){
        printf("\n");
        for(j=0;j<4;j++){
            printf("| %c (%c", tab[4*j][i],tab[4*j+3][i]);
            
	    if(tab[4*j+1][i]=='L'){
	    	if(tab[4*j+2][i]=='T')
			printf("++");
	    	else if(tab[4*j+2][i]=='D')
	    		printf("+ ");
		}
		
	    else if(tab[4*j+1][i]=='M'){
	    	if(tab[4*j+2][i]=='T')
			printf("**");
	    	else if(tab[4*j+2][i]=='D')
	    		printf("* ");
		}
	    else
	    		printf("  ");
	   printf(")|");    	
        }
    }
    printf("\n+ :Lettre compt double\n++ :Lettre compt triple \n* :mot compt double\n** :mot compt triple"); 
}

int my_rand (int max) // génère un nombre aléatoir entre 0 et max

{
    static int tab[N];
    static int first = 0;
    int index;
    int rn;
    
    if (first == 0)
     {
        int i;
        
        srand (time (NULL));
        for (i = 0; i < N; i++)
            tab[i] = rand();
        first = 1;
     }
    index = (int)(rand() / RAND_MAX * (N - 1));
    rn = tab[index]%max;
    tab[index] = rand();
    return (rn);
}


void cre_tab1(){
    int i;
    int j;
    int chose;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++){
            chose = my_rand (1000); // le nombre aléatoire parmet de sortir une lettre suivant sa fréquance d'aparition en langue francaise
            if (chose<84){
                tab1[i][j]='a';
            }
            else if(chose>=84 && chose < 94){
                tab1[i][j]='b';
            }
            else if(chose>=94 && chose < 125){
                tab1[i][j]='c';
            }
            else if(chose>=125 && chose < 167){
                tab1[i][j]='d';
            }
            else if(chose>=167 && chose < 340){
                tab1[i][j]='e';
            }
            else if(chose>=340 && chose < 355){
                tab1[i][j]='f';
            }
            else if(chose>=355 && chose < 368){
                tab1[i][j]='g';
            }
            else if(chose>=368 && chose < 375){
                tab1[i][j]='h';
            }
            else if(chose>=375 && chose < 449){
                tab1[i][j]='i';
            }
            else if(chose>=449 && chose < 452){
                tab1[i][j]='j';
            }
            else if(chose>=452 && chose < 453){
                tab1[i][j]='k';
            }
            else if(chose>=453 && chose < 513){
                tab1[i][j]='l';
            }
            else if(chose>=513 && chose < 533){
                tab1[i][j]='m';
            }
            else if(chose>=533 && chose < 604){
                tab1[i][j]='n';
            }
            else if(chose>=604 && chose < 657){
                tab1[i][j]='o';
            }
            else if(chose>=657 && chose < 687){
                tab1[i][j]='p';
            }
            else if(chose>=687 && chose < 697){
                tab1[i][j]='q';
            }
            else if(chose>=697 && chose < 763){
                tab1[i][j]='r';
            }
            else if(chose>=763 && chose < 843){
                tab1[i][j]='s';
            }
            else if(chose>=843 && chose < 914){
                tab1[i][j]='t';
            }
            else if(chose>=914 && chose < 981){
                tab1[i][j]='u';
            }
            else if(chose>=981 && chose < 993){
                tab1[i][j]='v';
            }
            else if(chose>=993 && chose < 994){
                tab1[i][j]='w';
            }
            else if(chose>=994 && chose < 997){
                tab1[i][j]='x';
            }
            else if(chose>=997 && chose < 999){
                tab1[i][j]='y';
            }
            else
                tab1[i][j]='z';
            }

        }
    

void complet_tab(){//passage de tab1 (que les lettres) à tab2 (les lettres + les bonus + les points)
    int i;
    int j;
    int chose;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
        
            tab2[4*i][j]=tab1[i][j];
            
            
            chose=my_rand (40);//attribution des bonus dans les 2 cases suivant chaque carractère
            if (chose<2){
                tab2[4*i+1][j]='M';
                tab2[4*i+2][j]='T';
            }
            else if(chose>=2 && chose < 5){
     		 tab2[4*i+1][j]='M';
                 tab2[4*i+2][j]='D';
            }
            else if(chose>=5 && chose < 9){
     		 tab2[4*i+1][j]='L';
                 tab2[4*i+2][j]='T';
            }
            else if(chose>=9 && chose < 14){
     		 tab2[4*i+1][j]='L';
                 tab2[4*i+2][j]='D';
            }
            else{
     		 tab2[4*i+1][j]=' ';
                 tab2[4*i+2][j]=' ';
            }
            
            
            
            chose = my_rand (16);//attribution des score dans la case suivant
            if (chose<2){
                tab2[4*i+3][j]='3';
            }
            else if(chose>=2 && chose < 5){
     		 tab2[4*i+3][j]='2';
            }
            else{
     		 tab2[4*i+3][j]='1';
            }
            
            
    	}
    }
	

}

/*int main(){
     cre_tab1();
     complet_tab();
     printab(tab2);
     printf("\n");
     return (0);
                      
                    }*/
                    
