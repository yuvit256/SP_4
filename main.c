#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    pnode temp = NULL;
    pnode *head = &temp;
    char choise;
    char userDec;
    int numOfNodes = 0;
    int src = 0;
    while (scanf("%c", &choise) != EOF)
    {
        if(choise == 'A')
        {
            freeGraph(head);
            scanf("%d", &numOfNodes);
            *head =  creatGraph(numOfNodes);
            scanf("%c", &userDec);
            while(scanf("%c", &userDec)!=0){
                if(userDec == 'n')
                {
                scanf("%d",&src);
                addAdge(head,src);
                }
                else
                {
                    break;
                }
            }
            choise = userDec;
        }
        if(choise == 'B')
        {
            addNode(head);
            continue;
        }
        if(choise == 'D')
        {
            delNode(head);
            continue;
        }
        if(choise == 'S')
        {
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortestPath(*head, src, dest);
            printf("Dijsktra shortest path: %d \n",dis);
            continue;
        }
        if(choise == 'T')
        {
            int tsp = TSP(*head);
            printf("TSP shortest path: %d \n",tsp);
            continue;
        }
    }
    freeGraph(head);
    return 0;
}

