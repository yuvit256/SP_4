#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

void build_graph_cmd(pnode *head, int numOfNodes)
{
    pnode *nodes = (pnode *)malloc(sizeof(node) * numOfNodes);
    memset(nodes, 0, sizeof(*nodes));
    *head = nodes[0];
    nodes[numOfNodes - 1] = (pnode)malloc(sizeof(node));
    nodes[numOfNodes - 1]->next = NULL;
    nodes[numOfNodes - 1]->node_num = numOfNodes - 1;
    nodes[numOfNodes - 1]->edges = NULL;
    for (int i = 0; i <= numOfNodes - 2; i++)
    {
        nodes[i] = (pnode)malloc(sizeof(node));
        nodes[i]->node_num = i;
        nodes[i]->next = nodes[i + 1];
        nodes[i]->edges = NULL;
    }

    char n;
    scanf(" %c", &n);
    if (n != 'n')
    {
        return;
    }

    char input = '\0';
    int count = 0;
    while (1)
    {
        char j;
        scanf(" %c", &j);
        int i = j - '0';
        scanf(" %c", &input);
        do
        {
            int pos = input - '0';
            scanf(" %c", &input);
            int num = input - '0';
            nodes[i]->edges = (pedge)malloc(sizeof(edge));
            nodes[i]->edges->weight = num;
            nodes[i]->edges->next = nodes[pos]->edges;
            nodes[i]->edges->endpoint = nodes[pos]->next;
            scanf(" %c", &input);
        } while ((input != 'n') && (input - '0' != '\0'));
        count++;
        if (count == numOfNodes - 1)
        {
            break;
        }
    }
    free(nodes);
}

// void insert_node_cmd(pnode *head, int newNode)
// {
//     pnode *temp = (pnode *)malloc(sizeof(node));
//     int i = 0;
// }

int main()
{
    char choice;
    while (scanf("%c", &choice) != EOF)
    {
        switch (choice)
        {
        case 'A':
        { // Creating a new graph
            char numOfNodes = 0;
            scanf(" %c", &numOfNodes);
            int numOfNodesInt = numOfNodes - '0';
            pnode *head = (pnode *)malloc(sizeof(node) * numOfNodesInt);
            memset(head, 0, sizeof(*head));
            printf("You have selected to create a graph\n");
            build_graph_cmd(head, numOfNodesInt);
            break;
        }
        case 'B':
        { // Adding a new node if not allready exist in the graph

            break;
        }
        case 'D':
        { // Removing a node
            /* code */
            break;
        }
        case 'S':
        { // Returning the shortest path between two number
            /* code */
            break;
        }
        case 'T':
        { // Calculate the shortest path between several vetices(nodes)
            /* code */
            break;
        }
        }
        return 0;
    }
}