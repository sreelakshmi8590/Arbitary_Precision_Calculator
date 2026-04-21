#ifndef DLL_H
#define DLL_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;


//function declaration
int dl_insert_last1(Dlist **head1, Dlist **tail1, int digit);
int dl_insert_last2(Dlist **head2, Dlist **tail2, int digit);
void print_result(Dlist *reshead,int res_sign);
int dl_insert_first(Dlist **rh, Dlist **rt, int data);

void addition_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **rh,Dlist **rt);

void subtraction_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **rh,Dlist **rt);
void swap_numbers(Dlist **h1, Dlist **t1,Dlist **h2, Dlist **t2);

void multiplication_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **rh,Dlist **rt);
int dl_delete_list(Dlist **head, Dlist **tail);

int division_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **rh,Dlist **rt);
int compare(Dlist *h1,Dlist *h2);

#endif