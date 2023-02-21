#include <stdio.h>
#include <stdlib.h>

typedef int heap_value;
typedef int heap_index;

struct heap_item {
        heap_index index;
        heap_value value;
};

struct max_heap {
        struct heap_item** root;
        size_t alloc;
        size_t items;
};

void init_max_heap(struct max_heap* heap)
{
        heap->root = NULL;
        heap->items = 0;
        heap->alloc = 0;
}

void init_max_heap_alloc(struct max_heap* heap, size_t alloc)
{
        heap->root = (struct heap_item**)malloc(sizeof(struct heap_item*) * alloc);
        heap->alloc = alloc;
        heap->items = 0;
}

struct heap_item** realloc_heap(struct heap_item** root, size_t alloc)
{
        if(root) {
                if(alloc == 0) {
                        return NULL;
                }

                return (struct heap_item**)realloc(root, sizeof(struct heap_item*) * alloc);
        } else {
                if(alloc == 0) {
                        alloc = 1;
                }

                return (struct heap_item**)malloc(sizeof(struct heap_item*) * alloc);
        }
}

struct heap_item* init_heap_item(heap_index index, heap_value value)
{
        struct heap_item* ptr = (struct heap_item*)malloc(sizeof(struct heap_item));
        ptr->index = index;
        ptr->value = value;
        return ptr;
}

size_t parent_heap(size_t item)
{
        if(item == 0) {
                return 0;
        }

        return (item - 1) / 2;
}

size_t left_child_heap(size_t item)
{
        return (item * 2) + 1;
}

size_t right_child_heap(size_t item)
{
        return left_child_heap(item) + 1;
}

size_t last_node_heap(size_t heap_items)
{
        return (heap_items - 2) / 2;
}

void swap_heap_item(struct heap_item** root, size_t i1, size_t i2)
{
        struct heap_item* tmp = root[i1];
        root[i1] = root[i2];
        root[i2] = tmp;
}

void insert_max_heap(struct max_heap* heap, heap_index index, heap_value value)
{
        size_t pos = heap->items++;
        if(pos < heap->alloc) {
                heap->root = realloc_heap(heap->root, heap->alloc * 2);
        }
        // Add at end of heap
        heap->root[pos] = init_heap_item(index, value);

        size_t child = pos;
        size_t parent = parent_heap(child);
        // Iter where check if this child is bigger that parent 
        while(heap->root[parent]->index < heap->root[child]->index && child != 0) {
                // swap child with parent
                swap_heap_item(heap->root, parent, child);
                // Check level above
                child = parent;
                parent = parent_heap(child);
        }
}

void restore_max_heap(struct max_heap* heap, size_t i)
{
        if(heap->items <= 1) {
                return;
        }

        const size_t last_node = last_node_heap(heap->items);
        while(i <= last_node) {
                size_t i_left = left_child_heap(i);
                size_t i_right = right_child_heap(i);
                // max is left
                size_t i_max_child = i_left;
                // but if we have a right child, check if max is the right child
                if(i_right < heap->items)
                        i_max_child = heap->root[i_left]->index > heap->root[i_right]->index ? i_left : i_right;

                // if max child is bigger than parent, then swap
                if(heap->root[i]->index < heap->root[i_max_child]->index) {
                        swap_heap_item(heap->root, i, i_max_child);
                } else { // otherwise exit
                        return;
                }
                // now parent is at max child position
                i = i_max_child;
        }
}

void build_max_heap(struct max_heap* heap, struct heap_item** arr, size_t num)
{
        heap->root = arr;
        heap->items = num;
        heap->alloc = num;

        // index of last no-leaf element
        size_t last_node = last_node_heap(num);

        // restore all no-leaf element (leaf element are already max heap)
        for(size_t i = last_node; i >= 0; i--) {
                restore_max_heap(heap, i);
        }
}

void sort_max_heap(struct max_heap* heap)
{
        size_t keep_items = heap->items;

        while(--heap->items) {
                // swap last with root (last is now sorted)
                swap_heap_item(heap->root, 0, heap->items);
                // restore max heap from root, excluding last, so finding new root element
                restore_max_heap(heap, 0);
        }

        // restore heap size
        heap->items = keep_items;
}

void print_heap(struct heap_item** root, size_t num)
{
        size_t level = 0;
        for(size_t i = 0; i < num; i++) {
                printf(" |%d| ", root[i]->index);
                if(i == level) {
                        putchar('\n');
                        level = (level + 1) * 2;
                }
        }
}

int main(int argc, char** argv)
{
        struct max_heap heap;
        init_max_heap_alloc(&heap, 10);

        insert_max_heap(&heap, 3, 10);
        insert_max_heap(&heap, 1, 10);
        insert_max_heap(&heap, 2, 10);
        insert_max_heap(&heap, 10, 10);
        insert_max_heap(&heap, 43, 10);
        insert_max_heap(&heap, 54, 10);
        insert_max_heap(&heap, 34, 10);
        insert_max_heap(&heap, 22, 10);
        insert_max_heap(&heap, 25, 10);
        insert_max_heap(&heap, 5, 10);
        insert_max_heap(&heap, 87, 10);
        insert_max_heap(&heap, 11, 10);
        insert_max_heap(&heap, 100, 10);
        insert_max_heap(&heap, 40, 10);
        insert_max_heap(&heap, 8, 10);


        print_heap(heap.root, heap.items);

        sort_max_heap(&heap);

        print_heap(heap.root, heap.items);

        return 0;
}