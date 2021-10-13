#include "similar.h"
#include "ask6declare.h"
void MakePaths(Graph *graph, Vertex word, Vertex end,char** lex,int n)
{
	listnode sim = similar(word,lex,n);
	Graph temp = *graph;
	for (; sim != NULL; sim = sim->next)
	{
		if (HTGetindex(temp, sim->airport) == -1 || strcmp(end, sim->airport) == 0)
		{
			if (strcmp(end, sim->airport) != 0 )
				UGAddVertex(graph, sim->airport);//add every similar to word that doesnt already exist into the graph
			temp = *graph;
			UGAddEdge(temp, word, sim->airport);//and also add an edge between each similar and word because they have a 1 letter difference
			if (strcmp(end, sim->airport) == 0)
				return;//if one path reached the destination return so that other can reach it to
			MakePaths(graph, sim->airport, end,lex,n);
		}
		else
			UGAddEdge(temp, word, sim->airport);//if it exists we just add the edge.this function checks if the edge already exists and does nothing if so
	}//we also dont want to have a recursion.for example cat wll produce cot and in cot will produce cat again.we dont want to do a recursion with cat because we will get stuck in a nedless loop
}


char** takewords(int* size,char* word){
	FILE *fp;
	char** lex;
	char** newar;
	int i,k, n,wordsize=strlen(word);
	char buffer[11];
	n = countlines("words");
	printf("file has %d lines\n",n);
	fp = fopen("words", "r");
	if (!fp)
		return NULL;
	lex = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		lex[i] = (char *)malloc(11 * sizeof(char));
	i = -1;
	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		if(strlen(buffer)==wordsize){
		i++;
		strcpy(lex[i],buffer);//we only store the words with the same length as the src and dest because only those can be similar with them
		}
	}
	qsort(lex, i+1, sizeof(char *), myCompare);
	printf("%d words in lexiko\n",i+1);
	(*size)=i+1;
	newar = (char **)malloc((i+1) * sizeof(char *));
	for (k = 0; k < i+1; k++)
		newar[k] = (char *)malloc(11 * sizeof(char));
	for (k = 0; k < i+1; k++)
		strcpy(newar[k],lex[k]);
	for(int k=0;k<n;k++) 
		free(lex[k]);//we delete the useless space
	free(lex);
	return newar;
}
