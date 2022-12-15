#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

typedef int linked_list_data;

#define LINKED_LIST_ALLOC 1024

struct linked_list_node {
        linked_list_data data;
        void* next;
};

struct linked_list {
        struct linked_list_node* head;
        size_t num;
        //size_t chunk;
        //linked_list_data* ptr;
};

void linked_list_init(struct linked_list* ll)
{
        ll->head = NULL;
        ll->num = 0;
        //ll->chunk = LINKED_LIST_ALLOC;
        //ll->ptr = (linked_list_node*)malloc(ll->chunk * sizeof(linked_list_node));
}

struct linked_list_node* linked_list_node_init(linked_list_data value)
{
        struct linked_list_node* n = (struct linked_list_node*)malloc(sizeof(struct linked_list_node));
        n->next = NULL;
        n->data = value;
}


struct linked_list_node* linked_list_last_node(struct linked_list* ll)
{
        struct linked_list_node* current = ll->head;
        if(!current) 
                return NULL;

        while(current->next) {
                current = current->next;
        }
        return current;
}

void linked_list_append(struct linked_list* ll, linked_list_data value)
{
        struct linked_list_node* last = linked_list_last_node(ll);
        if(last == NULL) {
                ll->head = linked_list_node_init(value);
                ll->num = 1;
        } else {
                last->next = linked_list_node_init(value);
                ll->num++;
        }
}

void linked_list_delete(struct linked_list* ll, linked_list_data value)
{
        struct linked_list_node* current = ll->head;
        if(!current) 
                return;

        struct linked_list_node* next;

        while(next = current->next) {
                current = current->next;
        }
        return;
        

}

struct linked_list_node* linked_list_search(struct linked_list* ll, linked_list_data value)
{
        struct linked_list_node* current = ll->head;
        if(!current) 
                return NULL;

        while(current && current->data != value) {
                current = current->next;
        }

        return current;
}

int main(int argc, char** argv)
{

        return 0;
}