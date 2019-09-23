#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define BUF 10

struct vertex
{
    int vertex_id;
    int num_edges;
    struct vertex** edges;
    struct vertex* next;
};

struct vertex* S;
struct vertex* _cur;

void _init_graph()
{

    char uinput[BUF];
    puts("how many edges will the first vertice have?");
    printf("> ");
    fgets(uinput, BUF, stdin);
    //puts(uinput);
    printf("Creating first vertice with %s undefined edges.\n", uinput);
    S = malloc(sizeof(struct vertex));
    S->vertex_id = 0;
    S->num_edges = atoi(uinput);
    S->edges = malloc(sizeof(struct vertex)*atoi(uinput));
    S->next = NULL;
    _cur = S;
}

void display_graph()
{
    puts("vertice\t| edges");
    while(_cur != NULL)
    {
        printf("%d\t| ", _cur->vertex_id);
        for(int i = 0; i < _cur->num_edges; i++)
        {
            printf("%d ", _cur->edges[i]->vertex_id);
        }
        printf("\n");
        _cur = _cur->next;
    }
    puts(" ");


}

void define_vertice()
{
    _cur = S;
    int new_vertice_id = _cur->vertex_id + 1;
    if(_cur != NULL)
    {
        for(int i = 0; i < _cur->num_edges; i++)
        {
            if(_cur->edges[i] == NULL)
            {
                struct vertex* new_vertice = malloc(sizeof(struct vertex));
                new_vertice->vertex_id = new_vertice_id;
                char uinpt[BUF];
                printf("How many edges will vertice #%d have?\n> ", new_vertice_id);
                fgets(uinpt, BUF, stdin);
                new_vertice->num_edges = atoi(uinpt);
                new_vertice->next = NULL;
                _cur->edges[i] = new_vertice;
                if(_cur->next == NULL)
                {
                    _cur->next = new_vertice;
                }
                else
                {
                    //move to end
                }
                new_vertice_id++;
            }
        }
    }
}

void clean_up_graph()
{
    free(S);
    //TODO clean all the vertex in a the graph
}