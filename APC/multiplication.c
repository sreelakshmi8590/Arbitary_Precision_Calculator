#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void multiplication_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **reshead,Dlist **restail)
{
    Dlist *temp1=*t1;
    Dlist *temp2=*t2;
    Dlist *rh1=NULL,*rt1=NULL,*rh2=NULL,*rt2=NULL;//partial result head and tail
    Dlist *rh3=NULL,*rt3=NULL;
    int count=0;
    while(temp2!=NULL)
    {
        int carry=0;
        rh2=rt2=NULL;
        for(int i=0;i<count;i++)
        {
            dl_insert_first(&rh2,&rt2,0);
        }
        temp1=*t1;
        while(temp1!=NULL)
        {
            
            int prod=(temp1->data*temp2->data)+carry;
            carry=prod/10;
            prod=prod%10;

            dl_insert_first(&rh2,&rt2,prod);
            temp1=temp1->prev;
        }
        
        if(carry)
            dl_insert_first(&rh2,&rt2,carry);
        
            addition_operation(&rh1,&rt1,&rh2,&rt2,&rh3,&rt3);
            dl_delete_list(&rh1, &rt1);
            dl_delete_list(&rh2, &rt2);
            rh1=rh3;
            rt1=rt3;
            rh3=rt3=NULL;
        
        temp2=temp2->prev;
        count++;
    }
    *reshead = rh1;
    *restail = rt1;
    Dlist *tmp = *reshead;
    while (tmp && tmp->data == 0 && tmp->next != NULL)
    {
        *reshead = tmp->next;
        (*reshead)->prev = NULL;
        free(tmp);
        tmp = *reshead;
    }
}