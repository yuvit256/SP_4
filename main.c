#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    pnode temp = NULL;
    pnode *head = &temp;
    char choice;
    char userDec;
    int numOfNodes = 0;
    int src = 0;
    while (scanf("%c", &choice) != EOF)
    {
        if(choice == 'A')
        {
            freeGraph(head);
            scanf("%d", &numOfNodes);
            *head =  creatGraph(numOfNodes);
            scanf("%c", &userDec);
            while(scanf("%c", &userDec)!=0){
                if(userDec == 'n')
                {
                scanf("%d",&src);
                addEdge(head,src);
                }
                else
                {
                    break;
                }
            }
            choice = userDec;
        }
        if(choice == 'B')
        {
            addNode(head);
            continue;
        }
        if(choice == 'D')
        {
            dltNode(head);
            continue;
        }
        if(choice == 'S')
        {
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortestPath(*head, src, dest);
            printf("Dijsktra shortest path: %d \n",dis);
            continue;
        }
        if(choice == 'T')
        {
            int tsp = TSP(*head);
            printf("TSP shortest path: %d \n",tsp);
            continue;
        }
    }
    freeGraph(head);
    return 0;
}

