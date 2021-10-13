#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask5declare.h"

int main(){
	listnode sim;
	data key;
	int i;
	printf("give word to find similars\n");
	scanf("%s",key);	 
	sim=similar(key);
	return 0;
}
