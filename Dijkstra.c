#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

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

void delDijk(pdijkstra dijkstra)
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
    delDijk(dijkstraHead);
    return D;
}

void PermotitionOfArr(int *arr, int arrLength)
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

void permotion(int start, int *arr, int arrLength)
{
    if (start == arrLength - 1)
    {
        PermotitionOfArr(arr, arrLength);
        return;
    }
    for (int i = start; i < arrLength; ++i)
    {
        int *arrCopy = (int *)(calloc(arrLength, sizeof(int)));
        inputArray(arr, arrCopy, arrLength);
        swap(arrCopy, start, i);
        permotion(start + 1, arrCopy, arrLength);
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
    permotion(0, arrCopy, arrLen);
    free(arr);
    free(arrCopy);
    if (weight == INFINITE)
    {
        weight = -1;
    }
    return weight;
}
