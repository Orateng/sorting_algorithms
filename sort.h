#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1

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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_s(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void shell_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void cocktail_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void heap_sort(int *array, size_t size);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t size, int left, int right);
int hoare_partition(int *array, size_t size, int left, int right);




#endif
