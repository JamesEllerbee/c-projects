#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define BUF 10

char uinpt[BUF];

const char* get_input()
{   
    printf("> ");
    fgets(uinpt, BUF, stdin);
    return uinpt;
}

void menu()
{
    puts("1: Add vertice(s) to graph");
    puts("2: Print the current graph");
    puts("9: Quit");
}

int main()
{
    puts("Welcome to Joey's Graph builder version 1.");
    _init_graph();
    int choice = 1;
    while(choice != 9)
    {
        menu(); 
        choice = atoi(get_input());
        switch(choice)
        {
            case 1:
                puts("Adding new vertice(s).");
                define_vertice();
            break;
            case 2:
                display_graph();
            break;
            case 9:
                puts("Exiting the program.");
                clean_up_graph();
            break;
            default:
                puts("invaild input.");
            break;
        }
    }
    return 0;
}