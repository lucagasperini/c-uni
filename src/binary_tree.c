#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int binary_tree_value_t;
typedef int binary_tree_index_t;

struct binary_tree_node_t {
        binary_tree_value_t value;
        binary_tree_index_t index;
        struct binary_tree_node_t* left;
        struct binary_tree_node_t* right;
        struct binary_tree_node_t* parent;
};

struct binary_tree_t  {
        struct binary_tree_node_t* root;
};

static inline void copy_binary_tree_value(binary_tree_value_t* dest, const binary_tree_value_t* src)
{
        *dest = *src;
}

static inline void clear_binary_tree_value(binary_tree_value_t* dest)
{
        
}

void init_binary_tree(struct binary_tree_t* ptr)
{
        ptr->root = NULL;
}

static inline void clear_binary_tree_node(struct binary_tree_node_t* ptr)
{
        // if the node has parent
        if(ptr->parent != NULL) {
                // if this node is left child
                if(ptr->parent->left == ptr) {
                        ptr->parent->left = NULL;
                } else if(ptr->parent->right == ptr)  { // if this node is right child
                        ptr->parent->right = NULL;
                }
                ptr->parent = NULL;
        }
        clear_binary_tree_value(&(ptr->value));
        free(ptr);
}

static inline void swap_binary_tree_node(struct binary_tree_node_t* o, struct binary_tree_node_t* n)
{
        if(o->parent != NULL) {

        }
        // if o has a parent 
        if(o->parent->left == o) {
                o->parent->left = n;
        } else {

        }
}


static inline struct binary_tree_node_t* init_binary_tree_node(struct binary_tree_node_t* p, const binary_tree_index_t i, const binary_tree_value_t val)
{
        struct binary_tree_node_t* t = (struct binary_tree_node_t*) malloc(sizeof(struct binary_tree_node_t));
        t->parent = p;
        copy_binary_tree_value(&(t->value), &val);
        t->index = i;
}

struct binary_tree_node_t* min_binary_tree_node(const struct binary_tree_node_t* node) 
{
        if(node == NULL) {
                return NULL;
        }

        struct binary_tree_node_t* t = node;
        while(t->left != NULL) {
                t = t->left;
        }
        return t;
}

struct binary_tree_node_t* max_binary_tree_node(struct binary_tree_node_t* node) 
{
        if(node == NULL) {
                return NULL;
        }

        struct binary_tree_node_t* t = node;
        while(t->right != NULL) {
                t = t->right;
        }
        return t;
}


struct binary_tree_node_t* next_binary_tree_node(struct binary_tree_node_t* node) 
{
        if(node == NULL) {
                return NULL;
        }
        //if this have right child, then take min
        if(node->right != NULL) {
                return min_binary_tree_node(node->right);
        } else { // else take first parent bigger than this
                struct binary_tree_node_t* p = node->parent;

                while(p != NULL && p->index < node->index) {
                        p = p->parent;
                }
                return p;
        }
}

struct binary_tree_node_t* prev_binary_tree_node(const struct binary_tree_node_t* node) 
{
        if(node == NULL) {
                return NULL;
        }

        return max_binary_tree_node(node->left);
                //if this have left child, then take max
        if(node->left != NULL) {
                return max_binary_tree_node(node->left);
        } else { // else take first parent lower than this
                struct binary_tree_node_t* p = node->parent;
                
                while(p != NULL && p->index > node->index) {
                        p = p->parent;
                }
                return p;
        }
}

struct binary_tree_node_t* min_binary_tree(struct binary_tree_t* ptr) 
{
        assert(ptr != NULL);

        return min_binary_tree_node(ptr->root);
}

struct binary_tree_node_t* max_binary_tree(struct binary_tree_t* ptr) 
{
        assert(ptr != NULL);
        
        return max_binary_tree_node(ptr->root);
}

struct binary_tree_node_t* next_binary_tree(struct binary_tree_t* ptr) 
{
        assert(ptr != NULL);

        return next_binary_tree_node(ptr->root);
}

struct binary_tree_node_t* prev_binary_tree(struct binary_tree_t* ptr) 
{
        assert(ptr != NULL);
        
        return prev_binary_tree_node(ptr->root);
}


void insert_binary_tree(struct binary_tree_t* ptr, const binary_tree_index_t i, const binary_tree_value_t val) 
{
        assert(ptr != NULL);

        if(ptr->root == NULL) {
                ptr->root = init_binary_tree_node(NULL, i, val);
                return;
        }

        // tmp
        struct binary_tree_node_t* t = ptr->root;

        // find parent of final insert or already have this insert
        while(t != NULL) {
                
                if(t->index > i) { // should we go left?
                        if(t->left == NULL) {
                                // insert left
                                t->left = init_binary_tree_node(t, i, val);
                                return;
                        } else {
                                // go left
                                t = t->left;
                        }
                } else if (t->index < i) { // should we go right?
                        if(t->right == NULL) {
                                // insert right
                                t->right = init_binary_tree_node(t, i, val);
                                return;
                        } else {
                                // go right
                                t = t->right;
                        }
                } else { // same index
                        copy_binary_tree_value(&(t->value), &val); // then substitute
                        return;
                }
        }
}

struct binary_tree_node_t* find_binary_tree_node(const struct binary_tree_node_t* ptr, const binary_tree_index_t i)
{
        // tmp
        struct binary_tree_node_t* t = ptr;

        // find parent of final insert or already have this insert
        while(t != NULL) {
                
                if(t->index > i) { // go left
                        t = t->left;
                } else if (t->index < i) { // go right
                        t = t->right;
                } else { // same index
                        return t; // then return this value
                }
        }

        return NULL;
}

struct binary_tree_node_t* find_binary_tree(const struct binary_tree_t* ptr, const binary_tree_index_t i)
{
        assert(ptr != NULL);

        return find_binary_tree_node(ptr->root, i);
}

void remove_binary_tree_node(struct binary_tree_node_t* ptr, const binary_tree_index_t i)
{
        if(ptr == NULL) { // if cant find element
                return;
        }
        // if this is root, can cause problem with binary_tree_t, than cant permit
        assert(ptr->parent != NULL);
        // parent
        struct binary_tree_node_t* p = ptr->parent;

        // if ptr has no child, then just remove ptr
        if(ptr->left == NULL && ptr->right == NULL) {
                clear_binary_tree_node(ptr);
                return;
        }

        // if ptr has left child, then link parent with it
        if(ptr->left != NULL && ptr->right == NULL) {
                // ptr is left child of p
                if(p->left == ptr) {
                        p->left = ptr->left;
                        ptr->left->parent = p;
                } else { // ptr is right child of p
                        p->right = ptr->left;
                        ptr->left->parent = p;
                }
                clear_binary_tree_node(ptr);
                return;
        }

        // if ptr has right child, then link parent with it
        if(ptr->left == NULL && ptr->right != NULL) {
                // ptr is left child of p
                if(p->left == ptr) {
                        p->left = ptr->right;
                        ptr->right->parent = p;
                } else { // ptr is right child of p
                        p->right = ptr->right;
                        ptr->right->parent = p;
                }
                clear_binary_tree_node(ptr);
                return;
        }

        // if ptr has both child
        if(ptr->left != NULL && ptr->right != NULL) {
                // then search for next
                struct binary_tree_node_t* next = next_binary_tree_node(ptr);
                // if we have a close next, then replace removed element with next 
                if(next->parent == ptr) {
                        // link next parent with removed element parent
                        next->parent = ptr->parent;
                        // next has removed element parent left child
                        next->left = ptr->left;
                        // removed element left child has next as parent
                        ptr->left->parent = next;
                                
                } else { // if we are not a close next
                        // if next has right child, link it to his parent at left side 
                        if(next->right != NULL && next->parent != ptr) {
                                next->parent->left = next->right;
                                next->right->parent = next->parent;
                        }

                        // unlink next with his parent
                        next->parent->left = NULL;
                        // left child of removed element has next as parent
                        ptr->left->parent = next;
                        // right child of removed element has next as parent
                        ptr->right->parent = next;
                        // next has left child = left child of removed element
                        next->left = ptr->left;
                        // next has right child = right child of removed element
                        next->right = ptr->right;
                        // next has parent = parent of removed element
                        next->parent = p;
                }

                clear_binary_tree_node(ptr);
                // link again with the parent
                if(p->left == NULL) {
                        p->left = next;
                } else if (p->right == NULL) {
                        p->right = next;
                }
                return;
        }
}

void remove_binary_tree(struct binary_tree_t* ptr, const binary_tree_index_t i)
{
        assert(ptr != NULL);
        struct binary_tree_node_t* r = ptr->root;

        if(r == NULL) {
                return;
        }
        // if we want remove the root
        if(r->index == i) {
                // if root has no child, then just remove root and set as NULL
                if(r->left == NULL && r->right == NULL) {
                        clear_binary_tree_node(r);
                        ptr->root = NULL;
                        return;
                }
                // if root has left child, then remove it and set child as new root
                if(r->left != NULL && r->right == NULL) {
                        ptr->root = r->left;
                        clear_binary_tree_node(r);
                        return;
                }

                // if root has right child, then remove it and set child as new root
                if(r->left == NULL && r->right != NULL) {
                        ptr->root = r->right;
                        clear_binary_tree_node(r);
                        return;
                }

                // if root has both child
                if(r->left != NULL && r->right != NULL) {
                        // then search for next
                        struct binary_tree_node_t* next = next_binary_tree_node(r);
                        // if we have a close next, then replace root with next 
                        if(next->parent == r) {
                                // next is root, so no parent
                                next->parent = NULL;
                                // next has root left child
                                next->left = r->left;
                                // root left child has next as parent
                                r->left->parent = next;

                        } else { // if we are not a close next

                                // if next has right child, link it to his parent at left side 
                                if(next->right != NULL && next->parent != r) {
                                        next->parent->left = next->right;
                                        next->right->parent = next->parent;
                                }

                                // unlink next with his parent
                                next->parent->left = NULL;
                                // left child of root has next as parent
                                r->left->parent = next;
                                // right child of root has next as parent
                                r->right->parent = next;
                                // next has left child = left child of root
                                next->left = r->left;
                                // next has right child = right child of root
                                next->right = r->right;
                                // next has parent = NULL, is new root 
                                next->parent = NULL;
                        }

                        clear_binary_tree_node(r);
                        // set next as new root
                        ptr->root = next;
                        return;
                }

        }
        struct binary_tree_node_t* found = find_binary_tree_node(ptr->root, i);
        if(found != NULL) {
                remove_binary_tree_node(found, i);
        }
}

struct binary_tree_queue_node_data_t {
        struct binary_tree_node_t* node;
        size_t level;
};

struct binary_tree_queue_node_t {
        struct queue_node_t* next;
        struct binary_tree_queue_node_data_t data;
};

struct binary_tree_queue_t {
        struct binary_tree_queue_node_t* head;
        struct binary_tree_queue_node_t* tail;
};

void init_binary_tree_queue_t(struct binary_tree_queue_t* queue)
{
        queue->head = NULL;
        queue->tail = NULL;
}

struct binary_tree_queue_node_t* init_binary_tree_queue_node_t(struct binary_tree_node_t* n, size_t level)
{
        struct binary_tree_queue_node_t* ret = (struct binary_tree_queue_node_t*)
                malloc(sizeof(struct binary_tree_queue_node_t));
        ret->next = NULL;
        ret->data.node = n;
        ret->data.level = level;
}

void enqueue_binary_tree_queue_t(struct binary_tree_queue_t* queue, struct binary_tree_node_t* n, size_t level)
{

        if(queue->tail == NULL) {
                queue->tail = init_binary_tree_queue_node_t(n, level);
                queue->head = queue->tail;
                return;
        }

        struct binary_tree_queue_node_t* tmp = init_binary_tree_queue_node_t(n, level);
        queue->tail->next = tmp;
        queue->tail = tmp;
}

struct binary_tree_queue_node_data_t dequeue_binary_tree_queue_t(struct binary_tree_queue_t* queue)
{
        struct binary_tree_queue_node_data_t data;
        data.node = NULL;
        if(queue->tail == NULL) {
                return data;
        }

        struct binary_tree_queue_node_t* tmp = queue->head;
        data = tmp->data;
        queue->head = queue->head->next;
        // if we have one element, then tail should be updated too
        if(queue->head == NULL) {
                queue->tail = NULL;
        }
        free(tmp);
        return data;
}

void print_binary_tree_node(struct binary_tree_node_t* node)
{
        size_t level_counter = 0;
        struct binary_tree_queue_t queue;
        init_binary_tree_queue_t(&queue);
        enqueue_binary_tree_queue_t(&queue, node, level_counter);
        
        while(true) {
                struct binary_tree_queue_node_data_t data = dequeue_binary_tree_queue_t(&queue);
                if(data.node == NULL) {
                        break;
                }
                if(data.level > level_counter) {
                        level_counter = data.level;
                        putchar('\n');
                }

                printf(" |%d| ", data.node->index);

                // if we have left child, add it to queue
                if(data.node->left != NULL) {
                        enqueue_binary_tree_queue_t(&queue, data.node->left, level_counter+1);
                }
                // if we have right child, add it to queue
                if(data.node->right != NULL) {
                        enqueue_binary_tree_queue_t(&queue, data.node->right, level_counter+1);
                }
        }

        putchar('\n');
}

void print_binary_tree(struct binary_tree_t* node)
{
        assert(node != NULL);
        print_binary_tree_node(node->root);
}

int main(int argc, char** argv)
{
        struct binary_tree_t t;
        init_binary_tree(&t);
        insert_binary_tree(&t, 50, 10);
        insert_binary_tree(&t, 15, 10);
        insert_binary_tree(&t, 100, 10);
        insert_binary_tree(&t, 3, 10);
        insert_binary_tree(&t, 8, 10);
        insert_binary_tree(&t, 1, 10);
        insert_binary_tree(&t, 65, 10);
        insert_binary_tree(&t, 33, 10);
        insert_binary_tree(&t, 24, 10);
        insert_binary_tree(&t, 35, 10);
        insert_binary_tree(&t, 300, 10);
        insert_binary_tree(&t, 66, 10);
        insert_binary_tree(&t, 64, 10);
        insert_binary_tree(&t, 333, 10);
        insert_binary_tree(&t, 269, 10);

        print_binary_tree(&t);

        remove_binary_tree(&t, 66);
        remove_binary_tree(&t, 65);
        remove_binary_tree(&t, 100);

        print_binary_tree(&t);

        remove_binary_tree(&t, 50);

        print_binary_tree(&t);

        remove_binary_tree(&t, 64);
        remove_binary_tree(&t, 269);
        print_binary_tree(&t);
        remove_binary_tree(&t, 300);
        remove_binary_tree(&t, 333);
        print_binary_tree(&t);

        binary_tree_index_t max = max_binary_tree(&t)->index;
        binary_tree_index_t min = min_binary_tree(&t)->index;
        binary_tree_index_t root = t.root->index;
        binary_tree_index_t next = next_binary_tree(&t)->index;
        binary_tree_index_t prev = prev_binary_tree(&t)->index;

        printf("Max index: %d\n", max);
        printf("Min index: %d\n", min);
        printf("Root index: %d\n", root);
        printf("Root next index: %d\n", next);
        printf("Root prev index: %d\n", prev);

        return 0;
}