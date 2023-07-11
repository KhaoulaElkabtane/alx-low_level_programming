#include "main.h"
#include <stdio.h>
#include <stdlib.h>


char *create_array(unsigned int size, char c)
{
        char *tab;
	int i;
	if(size == 0){
		return NULL;
	}
	tab=(char*)malloc(size*sizeof(char));
	if(tab==NULL){
		return NULL;
	}else{
		for(i=0 ;i<(int)size ;i++){
			tab[i]=c;
		}
		return tab;
	}
}
