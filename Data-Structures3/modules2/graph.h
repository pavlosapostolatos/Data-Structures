#include "hash1.h"
#include "graphtypes.h"
Graph UGCreate();
void UGAddVertex(Graph*, Vertex);
void UGRemoveVertex(Graph, Vertex);
void UGAddEdge(Graph, Vertex, Vertex);
void UGRemoveEdge(Graph, Vertex, Vertex);
Nbr UGShortestPath(Graph, Vertex, Vertex);
Nbr UGGetAdjacent(Graph, Vertex);
void UGDestroy(Graph);
void UGVisit(Graph );
void HTRearrenge(Hash , KeyType , Content );
Nbr deletefirstNei(Nbr );
Nbr DeleteNei(Nbr , Content );
Content Pop(Nbr* );
Nbr insertfirst(Nbr ,Content );
void HTInsertWithList(Hash* , KeyType , ItemType );
int minDistance(int *,Boolean* ,int );
Nbr printPath(Content* ,int* , int ) ;

