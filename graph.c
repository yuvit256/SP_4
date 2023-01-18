#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

node *creatGraph(int numOfNodes)
{
    node *head = NULL;
    pnode newNode, temp = NULL;
    int i;
    head = (pnode)malloc(sizeof(node));
    if (head == NULL)
    {
        exit(0);
    }
    head->id = 0;
    head->next = NULL;
    head->edges = NULL;
    temp = head;
    for (i = 1; i < numOfNodes; i++)
    {
        newNode = (pnode)malloc(sizeof(node));
        if (newNode == NULL)
        {
            break;
        }
        newNode->id = i;
        newNode->next = NULL;
        newNode->edges = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

pnode getNode(int id, pnode *head)
{
    pnode temp = *head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

void appendEdge(pnode temp, int dest, int w, pnode *head)
{
    if (temp->edges == NULL)
    {
        temp->edges = (pedge)malloc(sizeof(edge));
        if (temp->edges == NULL)
        {
            exit(0);
        }
        temp->edges->weight = w;
        temp->edges->next = NULL;
        node *D = getNode(dest, head);
        temp->edges->endpoint = &(*D);
    }
    else
    {
        pedge n = temp->edges;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = (pedge)malloc(sizeof(edge));
        if (n == NULL)
        {
            exit(0);
        }
        n->next->next = NULL;
        n->next->weight = w;
        node *D = getNode(dest, head);
        n->next->endpoint = &(*D);
    }
}

void addEdge(pnode *head, int src)
{
    int dest;
    int w;
    pnode temp = getNode(src, head);
    while (scanf("%d", &dest) != 0 && scanf("%d", &w) != 0)
    {
        if ((dest >= 'A' && dest <= 'Z') || (w >= 'A' && w <= 'Z'))
        {
            break;
        }
        if ((dest >= 'a' && dest <= 'z') || (w >= 'a' && w <= 'z'))
        {
            break;
        }
        appendEdge(temp, dest, w, head);
    }
}

void freeGraph(pnode *head)
{
    pnode tempNode = *head;
    while (tempNode != NULL)
    {
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            pedge tempEdgefree = tempEdge;
            tempEdge = tempEdge->next;
            free(tempEdgefree);
        }
        node *tempFree = tempNode;
        tempNode = tempNode->next;
        free(tempFree);
    }
}

void freeEdges(pnode p)
{
    if (p->edges != NULL)
    {
        pedge temp = p->edges;
        while (temp != NULL)
        {
            pedge p1 = NULL;
            p1 = temp;
            temp = temp->next;
            free(p1);
        }
    }
    else
    {
        free(p->edges);
    }
}

void dltEdge(pnode *head, int n)
{
    pnode tempNode = *head;
    while (tempNode != NULL)
    {
        if (tempNode->id != n && tempNode->edges != NULL)
        {
            if (tempNode->edges->endpoint->id != n)
            {
                pedge tempEdge = tempNode->edges;
                while (tempEdge->next != NULL)
                {
                    if (tempEdge->next->endpoint->id == n)
                    {
                        pedge p1 = tempEdge->next;
                        tempEdge->next = tempEdge->next->next;
                        free(p1);
                        break;
                    }
                    tempEdge = tempEdge->next;
                }
            }
            else
            {
                if (tempNode->edges->next == NULL)
                {
                    pedge p1 = tempNode->edges;
                    tempNode->edges = NULL;
                    free(p1);
                }
                else
                {
                    pedge p1 = tempNode->edges;
                    tempNode->edges = p1->next;
                    free(p1);
                }
            }
        }
        tempNode = tempNode->next;
    }
}

void dltNode(pnode *head)
{
    int D = 0;
    scanf("%d", &D);
    dltEdge(head, D);
    pnode tempNode = *head;
    node *p = NULL;
    if (tempNode->id != D)
    {
        while (tempNode->next->id != D)
        {
            tempNode = tempNode->next;
        }
        p = tempNode->next;
        tempNode->next = tempNode->next->next;
        freeEdges(p);
        free(p);
    }
    else
    {
        p = *head;
        *head = p->next;
        freeEdges(p);
        free(p);
    }
}

void addNode(pnode *head)
{
    int src;
    scanf("%d", &src);
    int dest;
    int w;
    pnode temp = getNode(src, head);
    if (temp == NULL)
    {
        pnode inGraph = *head;
        while (inGraph->next != NULL)
        {
            inGraph = inGraph->next;
        }
        pnode newNode = (pnode)(malloc(sizeof(node)));
        newNode->id = src;
        newNode->edges = NULL;
        newNode->next = NULL;
        inGraph->next = newNode;
        while (scanf("%d", &dest) != 0 && scanf("%d", &w) != 0)
        {
            if ((dest >= 'A' && dest <= 'Z') || (w >= 'A' && w <= 'Z'))
            {
                break;
            }
            if ((dest >= 'a' && dest <= 'z') || (w >= 'a' && w <= 'z'))
            {
                break;
            }
            appendEdge(newNode, dest, w, head);
        }
    }
    else
    {
        freeEdges(temp);
        temp->edges = NULL;
        while (scanf("%d", &dest) != 0 && scanf("%d", &w) != 0)
        {
            if ((dest >= 'A' && dest <= 'Z') || (w >= 'A' && w <= 'Z'))
            {
                break;
            }
            if ((dest >= 'a' && dest <= 'z') || (w >= 'a' && w <= 'z'))
            {
                break;
            }
            appendEdge(temp, dest, w, head);
        }
    }
}

int weight;
int arrLen;
pnode pGraph;
void inputArray(int *fromArr, int *toArr, int arrLenght)
{
    for (int i = 0; i < arrLenght; i++)
    {
        toArr[i] = fromArr[i];
    }
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dltDijk(pdijkstra dijkstra)
{
    while (dijkstra != NULL)
    {
        pdijkstra temp = dijkstra;
        dijkstra = dijkstra->next;
        free(temp);
    }
}

pdijkstra min(pdijkstra head)
{
    pdijkstra Node = NULL;
    while (head != NULL)
    {
        if (!head->tag && head->weight < INFINITE && (Node == NULL || Node->weight < head->weight))
        {
            Node = head;
        }
        head = head->next;
    }
    if (Node != NULL)
    {
        Node->tag = 1;
    }
    return Node;
}

pdijkstra useDijkstra(pdijkstra head, int id)
{
    while (head != NULL)
    {
        if (head->node->id == id)
        {
            return head;
        }

        head = head->next;
    }
    return NULL;
}

pdijkstra RunDijkstra(pnode open, int src)
{
    pdijkstra head = NULL;
    pdijkstra *n = &head;
    while (open != NULL)
    {
        (*n) = (pdijkstra)malloc(sizeof(dijkstra));
        if ((*n) == NULL)
        {
            exit(0);
        }
        (*n)->node = open;
        if (open->id == src)
        {
            (*n)->weight = 0;
        }
        else
        {
            (*n)->weight = INFINITE;
        }
        (*n)->tag = 0;
        (*n)->next = NULL;
        n = &((*n)->next);
        open = open->next;
    }
    return head;
}

void arrPermotation(int *arr, int arrLength)
{
    int tempWeight = 0;
    for (int i = 0; i < arrLength - 1; ++i)
    {
        int D = shortestPath(pGraph, arr[i], arr[i + 1]);
        if (D == -1)
        {
            tempWeight = INFINITE;
            return;
        }
        tempWeight += D;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
}

 void permotation(int start, int *arr, int arrLength)
    {
        if (start == arrLength - 1)
        {
            arrPermotation(arr, arrLength);
            return;
        }
        for (int i = start; i < arrLength; ++i)
        {
            int *arrCopy = (int *)(calloc(arrLength, sizeof(int)));
            inputArray(arr, arrCopy, arrLength);
            swap(arrCopy, start, i);
            permotation(start + 1, arrCopy, arrLength);
            free(arrCopy);
        }
    }

int TSP(pnode head)
{
    weight = INFINITE;
    arrLen = -1;
    pGraph = head;
    scanf("%d", &arrLen);
    int *arr = (int *)(calloc(arrLen, sizeof(int)));
    for (int i = 0; i < arrLen; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *arrCopy = (int *)(calloc(arrLen, sizeof(int)));
    inputArray(arr, arrCopy, arrLen);
    permotation(0, arrCopy, arrLen);
    free(arr);
    free(arrCopy);
    if (weight == INFINITE)
    {
        weight = -1;
    }
    return weight;
}

int shortestPath(pnode head, int src, int dest)
{
    pdijkstra dijkstraHead = RunDijkstra(head, src);
    pdijkstra temp = min(dijkstraHead);
    while (temp != NULL)
    {
        pedge E_ind = temp->node->edges;
        while (E_ind != NULL)
        {
            pdijkstra n = useDijkstra(dijkstraHead, E_ind->endpoint->id);
            int res = temp->weight + E_ind->weight;
            if (n->weight > res)
            {
                n->weight = res;
            }
            E_ind = E_ind->next;
        }
        temp = min(dijkstraHead);
    }
    int D = useDijkstra(dijkstraHead, dest)->weight;
    if (D == INFINITE)
    {
        D = -1;
    }
    dltDijk(dijkstraHead);
    return D;
}
