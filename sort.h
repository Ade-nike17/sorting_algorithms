#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
  * struct heapint_s - Binary heap node
  *
  * @pos: Relative position on array
  * @parent: Pointer to the parent node
  * @cleft: Pointer to the left child node
  * @cright: Pointer to the right child node
  */
typedef struct heapint_s
{
	size_t pos;
	struct heapint_s *parent;
	struct heapint_s *cleft;
	struct heapint_s *cright;
} heapint_t;

/* prototype functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *create_listint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);

/* Task functions */
void bubble_sort(int *, size_t);
void selection_sort(int *, size_t);

/* Quick sort functions */
void swap(int *a, int *b);
int lomuto_partition(int *array, int high, int low, size_t size);
void _quicksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/* Shell sort functions */
void shell_sort(int *, size_t);
void knuth_seq_sort(int *, size_t, size_t);

/* Heap sort functions */
void heap_sort(int *, size_t);
heapint_t *find_pos(heapint_t *, size_t);
void fill_heap(heapint_t **, heapint_t *, int *);
void insert_branck(heapint_t **, heapint_t *, int *);
int pop_heap(heapint_t **, int *);

#endif /* SORT_H */
