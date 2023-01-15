#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

void build_graph_cmd(struct GRAPH_NODE_ *head)
{
    char numOfNodes = scanf("%c", &numOfNodes);
    int numOfNodesInt = numOfNodes - '0';
    printf("The number is: %d\n", numOfNodesInt);
    struct GRAPH_NODE_ *graph;
    char input1;
    scanf("%c", &input1);
    if (input1 != 'n')
    {
        printf("Invalid input\n");
        exit(1);
    }
    for (int i = numOfNodesInt - 1; i >= 0; i--)
    {
        graph = (struct GRAPH_NODE_ *)malloc(sizeof(struct GRAPH_NODE_));
        graph->next = head->next;
        graph->node_num = i;
        head = graph;
    }
    struct GRAPH_NODE_ *temp = head;
    temp = temp->next->next;
    while (scanf("%c", &input1) != 'n')
    {
        struct edge_ *edges = (struct edge_ *)malloc(sizeof(struct edge_));
        edges->weight = temp->node_num;
        temp = temp->next->next;
    }
}

int main()
{
    char input;
    struct GRAPH_NODE_ *pgraph = (struct GRAPH_NODE_ *)malloc(sizeof(struct GRAPH_NODE_));
    memset(pgraph, 0, sizeof(*pgraph));
    while (scanf("%c", &input) != EOF)
    {
        if (input == 'A')
        {
            printf("You have selected to create a graph\n");
            build_graph_cmd(pgraph);
            break;
        }
        // case 'B':
        // { // Adding a new node if not allready exist in the graph

        //     break;
        // }
        // case 'D':
        // { // Removing a node
        //     /* code */
        //     break;
        // }
        // case 'S':
        // { // Returning the shortest path between two number
        //     /* code */
        //     break;
        // }
        // case 'T':
        // { // Calculate the shortest path between several vetices(nodes)
        //     /* code */
        //     break;
        // }
    }
    return 0;
}
