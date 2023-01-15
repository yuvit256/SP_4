
void build_graph_cmd(pnode *head){
    head = NULL;
    int i = 0;
    int numOfNodes;
    scanf("%d", &numOfNodes);
    char n;
    scanf("%c", &n);
    while(i<numOfNodes)
    {
        struct GRAPH_NODE_* head  = (struct GRAPH_NODE_*) malloc(sizeof(struct GRAPH_NODE_));
        // The node we are handling now
        while((head->node_num = scanf("%d", &(head->node_num))) &&  (head->node_num!='n')){
            struct edge_ * edge = (struct edge_*) malloc(sizeof(struct edge_));
            edge->endpoint = scanf("%d", &(edge->endpoint));
            edge->weight = scanf("%d", &(edge->weight));
        }
        i++;
    }
}