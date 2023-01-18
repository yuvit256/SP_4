#ifndef GRAPH_
#define GRAPH_
#define INFINITE 999999999

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int id;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct Dijkstra {
    pnode node;
    int weight;
    int tag;
    struct Dijkstra *next;
} dijkstra, *pdijkstra;

node* creatGraph(int numOfNodes);

pnode getNode(int id, pnode *head);

void appendEdge(pnode temp,int dest,int w,pnode *head);

void addEdge(pnode *head,int src);

void freeGraph(pnode *head);

void freeEdges(pnode p);

void dltEdge(pnode *head,int n);

void dltNode(pnode *head);

void addNode(pnode *head);

int shortestPath(pnode head,int src,int dest);

int TSP(pnode head);

#endif























// # include <stdio.h>
// # include<stdlib.h>
// # define TRUE 1
// # define FALSE 0

// typedef struct node{
//     int id;
//     int edge_size;
//     struct node *next;
//     struct edge *My_edges ;
// }node,*pnode; 

// typedef struct edge{
//     float val;
//     struct edge *next_edge;
//     struct node *connect_to;   
// }edge,*pedge;

// node *  creat_graph(int num_of_nodes);

// void print_graph(node * graph);

// void edd_adge(node *graph);

// void coneected(int dest,node *p);

// void del_E(node *p);