//
//  graph.c
//  BFS
//
//  Created by TungDT on 8/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "graph.h"
#include "queue.h"

int front;
int rear;
int queue[QUEUE_SIZE];

node* create_node(int vertex)
{
    node* n = malloc(sizeof(node));
    n->vertex = vertex;
    n->next = NULL;
    return n;
}
graph* init_graph(int n_vertices)
{
    graph* g = malloc(sizeof(graph));
    g->n_vertices = n_vertices;
    
    g->adj_lists = malloc(n_vertices * sizeof(node*));
    g->visited   = malloc(n_vertices * sizeof(int));
    g->urls      = malloc(n_vertices * sizeof(char*));
    
    for (int i = 0; i < n_vertices; i++)
    {
        g->adj_lists[i] = NULL;
        g->visited[i] = WHITE;
    }
    
    return g;
}
graph* read_graph(char* finput)
{
    FILE *fp = fopen(finput, "r");
    if (fp == NULL)
    {
        printf("File %s not found!\n", finput);
        exit(1);
    }
    int n_urls;
    fscanf(fp, "%d", &n_urls);
    graph* g = init_graph(n_urls);
    for (int i = 0; i < n_urls; i++)
    {
        char url[250];
        fscanf(fp, "%s", url);
        add_url(g, i, url);
    }
    int n_edges;
    fscanf(fp, "%d", &n_edges);
    for (int i = 0; i < n_edges; i++)
    {
        int src, dest;
        fscanf(fp, "%d", &src);
        fscanf(fp, "%d", &dest);
        add_edge(g, src, dest);
    }
    return g;
}
void add_edge(graph* g, int src, int dest)
{
    // Add edge from src to dest
    node* dest_node = create_node(dest);
    dest_node->next = g->adj_lists[src];
    g->adj_lists[src] = dest_node;
    
    // Add edge from dest to src
    node* src_node = create_node(src);
    src_node->next = g->adj_lists[dest];
    g->adj_lists[dest] = src_node;
}
void bfs(graph* g, int start)
{
    // TODO
    clear_queue();
    enqueue(start);

    while (!is_empty())
    {
        int current_node = dequeue();
        node *ptr = g->adj_lists[current_node];
        while(ptr != NULL)
        {
            if (g->visited[ptr->vertex] == WHITE)
            {
                enqueue(ptr->vertex);
                g->visited[ptr->vertex] = GREY;

            }
            ptr = ptr->next;
        }
        g->visited[current_node] = BLACK;

        printf("web: %s\n", g->urls[current_node]);
    }
}

void visit(graph* g, int vertex)
{
    char* url = g->urls[vertex];
    printf("Download %s ... done!\n", url);
}

void add_url(graph* g, int vertex, char* url)
{
    unsigned long int len = strlen(url);
    g->urls[vertex] = malloc(sizeof(char) * len);
    strcpy(g->urls[vertex], url);
}

void delete_graph(graph** g)
{
    free((*g)->visited);
    for (int i = 0; i < (*g)->n_vertices; i++)
    {
        free((*g)->adj_lists[i]);
        free((*g)->urls[i]);
    }
    free((*g)->adj_lists);
    free((*g)->urls);
}
