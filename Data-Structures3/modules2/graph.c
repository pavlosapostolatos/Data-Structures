#include "graph.h"
Graph UGCreate()
{
	return HTCreate();
}

/*REMEMBER HTGetindex is exactly like HTGET but without that 1 union item command.instead of writing different 
"versions" of those functions that include a union item command we call HTGetindex for searching and end up writing 
1 line instead of 40*/

Nbr UGGetAdjacent(Graph graph, Vertex vertex)
{
	int h1;
	if ((h1 = HTGetindex(graph, vertex)) != -1)
	{

		return graph->table[h1]->item.adj;
	}
	return NULL;
}

void UGAddVertex(Graph *graph, Vertex vertex)
{
	Graph temp = *graph;
	ItemType pitem;
	pitem.adj = NULL;
	if (HTGetindex(temp, vertex) != -1)
		return;//if it exists it does nothing
	HTInsertWithList(graph, vertex, pitem); 
}

void UGRemoveVertex(Graph graph, Vertex vertex)
{
	Nbr temp2, temp;
	int h1;
	if ((h1 = HTGetindex(graph, vertex)) != -1)
	{
		temp = graph->table[h1]->item.adj;
		temp2 = temp;
		while (temp2 != NULL)
		{
			temp = temp2->link;
			UGRemoveEdge(graph, vertex, temp2->cell->key);//we remove all connections to the vertex we are about to delete
			temp2 = temp;
		}
		//while(temp!=NULL) temp=Delete(temp,temp->cell);
		graph->table[h1]->item.adj = temp;
		HTRemove(graph, vertex);//included hash table function to remove entry 
	}
	else
		printf("didnt find vertex\n");
}

void UGRemoveEdge(Graph graph, Vertex vertex1, Vertex vertex2)
{
	int h1, h2;
	if ((h1 = HTGetindex(graph, vertex1)) != -1 && (h2 = HTGetindex(graph, vertex2)) != -1)//both must exist
	{
		graph->table[h1]->item.adj = DeleteNei(graph->table[h1]->item.adj, graph->table[h2]);//remove vertex2 from vertex1 Adjacency list
		graph->table[h2]->item.adj = DeleteNei(graph->table[h2]->item.adj, graph->table[h1]);//remove vertex` from vertex1 Adjacency list
	}
}

void UGAddEdge(Graph graph, Vertex vertex1, Vertex vertex2)
{
	int h1, h2;
	Content *Table = graph->table;
	Nbr edges;
	if ((h1 = HTGetindex(graph, vertex1)) != -1 && (h2 = HTGetindex(graph, vertex2)) != -1)
	{
		for (edges = Table[h1]->item.adj; edges != NULL; edges = edges->link)
			if (strcmp(edges->cell->key, Table[h2]->key) == 0)
				return;//if edge already exists do nithing.useful for ask3
		Table[h1]->item.adj = insertfirst(Table[h1]->item.adj, Table[h2]);//add vertex2 to vertex1 Adjacency list
		Table[h2]->item.adj = insertfirst(Table[h2]->item.adj, Table[h1]);//add vertex1 to vertex2 Adjacency list
	}
	else
		printf("didnt find keys\n");
}

//REMEMBER in Adjacency lists i add pointers to the malloced vertexes/hashtable entries not the strings themselves.
//that way the functions have direct access to the vertexes with no need of calling search functions

Nbr insertfirst(Nbr list1, Content list2)//fast insertion in Adjacency is done by inserting at head with O(1) not last with O(n)
{
	Nbr newl;
	newl = (Nbr)malloc(sizeof(n));
	newl->cell = list2;
	if (list1 == NULL)
		newl->link = NULL;
	else
		newl->link = list1;
	return newl;
}

void UGDestroy(Graph graph)
{
	int i;
	Content *Table = graph->table;
	for (i = 0; i < graph->size; i++)
		if (Table[i] != NULL && Table[i]->deleted == 0)
		{
			UGRemoveVertex(graph, Table[i]->key);
			//free(Table[i]);
		}
	free(Table);
	free(graph);
}

void HTInsertWithList(Hash *hash, KeyType Key, ItemType Item)//insert function had to be tweaked because of graph specialties compared to a hashtable
{
	Hash temphash = *hash;
	Content *Table = temphash->table;
	int h, i, step = 1;
	Content cell;
	Hash newhash;
	if (load(temphash) < 0.5)
	{
		h = hashcode(Key, temphash->size);
		while (Table[h] != NULL && Table[h]->deleted == 0 && strcmp(Table[h]->key, Key) != 0)
		{
			h -= step;
			if (h < 0)
				h += temphash->size;
		}
		if (Table[h] == NULL)
		{
			cell = (Content)malloc(sizeof(Entry));
			cell->key = (char *)malloc(MAXKEYSIZE * sizeof(char));
			strcpy(cell->key, Key);
			cell->item.adj = Item.adj;//remember NULL is always inserted here.a new vertex has no edges.they are added by UGAddEdge
			cell->deleted = 0;
			temphash->table[h] = cell;
		}
		else if (Table[h]->deleted == 1)
		{
			Table[h]->key = (char *)malloc(MAXKEYSIZE * sizeof(char));
			strcpy(Table[h]->key, Key);
			Table[h]->item.adj = Item.adj;
			Table[h]->deleted = 0;
		}
		else if (strcmp(Table[h]->key, Key) == 0)
			return; //in the graph there is no item add or update.also we shpuldnt update the item because it is an Adjacency list and it would break the graph
	}
	else
	{
		newhash = CustomHTCreate(2 * temphash->size);
		for (i = 0; i < temphash->size; i++)
			if (Table[i] != NULL && Table[i]->deleted == 0)
				HTRearrenge(newhash, Table[i]->key, Table[i]);//we readd the vertexes without mallocing new space and neither freeing any because we would lose the data and get segmentation fault
		HTInsertWithList(&newhash, Key, Item);
		*hash = newhash;
	}
}

void HTRearrenge(Hash hash, KeyType Key, Content block)
{
	Hash temphash = hash;
	Content *Table = temphash->table;
	int h, step = 1;
	h = hashcode(Key, temphash->size);
	while (Table[h] != NULL)
	{
		h -= step;
		if (h < 0)
			h += temphash->size;
	}
	temphash->table[h] = block;
}

void UGVisit(Graph graph)//we were advised to use the algoirthm in page 55 of Graphs.pdf to print the graph
{
	Stack C = NULL, vx;//stack uses Nbr (adjacency list struct internally through typedef
	Content x, w;
	int i;
	for (i = 0; i < graph->size; i++)
		if (graph->table[i] != NULL)
			graph->table[i]->visited = FALSE;
	for (i = 0; graph->table[i] == NULL; i++)
		continue;//find first not empty entry
	C = insertfirst(C, graph->table[i]);
	while (C != NULL)
	{
		x = Pop(&C);
		if (x->visited == FALSE)
		{
			printf("%s-", x->key);
			x->visited = TRUE;
			vx = x->item.adj;
			while (vx != NULL)
			{
				w = vx->cell;
				if (w->visited == FALSE)
					C = insertfirst(C, w);//print edges
				vx = vx->link;
			}
		}
	}
	printf("\n");
	printf("vertexes without edges:\n");
	for (i = 0; i < graph->size; i++)
		if (graph->table[i] != NULL && graph->table[i]->deleted == 0 && graph->table[i]->visited == FALSE)
			printf("%s-", graph->table[i]->key);
	printf("\n");
}

Content Pop(Nbr *C)
{
	if ((*C) == NULL)
		return NULL;
	Content temp = (*C)->cell;
	Stack a = *C;
	(*C) = (*C)->link;
	free(a);
	return temp;
}

Nbr DeleteNei(Nbr List, Content node)
{
	//int found=0;
	Nbr newlist, templist, prev_list;
	if (List == NULL)
		return List;
	if (List->cell == node)
		return deletefirstNei(List);
	else
	{
		templist = List;
		newlist = List;
	}
	while (newlist != NULL)
	{
		if (newlist->cell == node)
		{
			//found = 1;
			prev_list->link = newlist->link; //αφου ο ενδιάμεσος κόμβος διαγραφεται ο αριστερός και ο δεξης συνδεονται
			free(newlist);
		}
		prev_list = newlist;
		newlist = newlist->link;
	}
	//printf("node was %s found\n", found ? "" : "not");
	return templist;
}

Nbr deletefirstNei(Nbr List)
{
	Nbr newlist, templist;
	templist = List;
	newlist = List->link;
	free(templist);
	return newlist;
}

Nbr UGShortestPath(Graph graph, Vertex vertex1, Vertex vertex2)
{
	int i, u, count = 0, src, dest, v = HTSize(graph);
	Graph board = CustomHTCreate(v);
	Nbr edges, path;
	Boolean connection;//i dont want the algorithm to waste time examining the distances of empty vertexes.i put all non vertexes in a new board without empty cells
	for (i = 0; i < graph->size; i++)
		if (graph->table[i] != NULL && graph->table[i]->deleted == 0)
		{
			board->table[count] = graph->table[i];
			if (strcmp(board->table[count]->key, vertex1) == 0)
				src = count;//store the index of src and dest
			else if (strcmp(board->table[count]->key, vertex2) == 0)
				dest = count;
			count++;
		}
	int *dist = (int *)malloc(v * sizeof(int));
	int *parent = (int *)malloc(v * sizeof(int));
	Boolean *w = (Boolean *)malloc(v * sizeof(Boolean));
	for (i = 0; i < v; i++)//the following code is the exact algorithm that was described to us in piazza
	{
		dist[i] = INT_MAX;
		w[i] = FALSE;
		parent[i] = -1;
	}
	dist[src] = 0;
	for (count = 0; count < v - 1; count++)
	{
		u = minDistance(dist, w, v);//vertex with minimum dist[u], among those with W[u] = false
		w[u] = TRUE;//first node to to get returned here is always src
		if (u == dest)
			break;//when we reach a node his minimum distance from src has been found
		for (i = 0; i < v; i++)//examine distance of all vertexes
		{
			connection = FALSE;
			for (edges = UGGetAdjacent(graph, board->table[u]->key); edges != NULL && connection == FALSE; edges = edges->link)
				if (strcmp(edges->cell->key, board->table[i]->key) == 0)
					connection = TRUE;
			if (w[i] == FALSE && connection == TRUE && dist[u] + 1 < dist[i])
			{
				parent[i] = u;//save that we have to pass through u to get to i
				dist[i] = dist[u] + 1;//one pass through a vertex means one more distance point
			}
		}
	}
	path = printPath(board->table, parent, dest);
	free(dist);
	free(parent);
	free(w);
	free(board->table);
	free(board);
	return path;
}

Nbr printPath(Content *table, int *parent, int dest)
{
	Nbr path = NULL;
	int i;
	for (i = dest; i != -1; i = parent[i])
	{
		path = insertfirst(path, table[i]);
		printf("%s ", table[i]->key);//we follow the parent aray back to src 
	}
	printf("\n");
	return path;
}

int minDistance(int *dist, Boolean *w, int v)
{
	int min = INT_MAX, i, min_index;

	for (i = 0; i < v; i++)
		if (w[i] == FALSE && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}
	return min_index;
}
