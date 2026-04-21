#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void subtraction_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **rh,Dlist **rt)
{
    *rh=NULL,*rt=NULL;
    Dlist *temp1=*t1;
    Dlist *temp2=*t2;
    int borrow=0;
    int d1,d2,diff;
    while(temp1!=NULL || temp2!=NULL)
    {
        //when length of temp1 is less then store with zeros
        if(temp1!=NULL)
            d1=temp1->data;
        else
            d1=0;
        //when length of temp2 is less then store with zeros
        if(temp2!=NULL)
            d2=temp2->data;
        else
            d2=0;

        d1=d1-borrow;
        //when the frst argument digit is smaller
        if(d1<d2)
        {
            diff=(d1+10)-d2;
            borrow=1;
        }
        //when the frst argument digit is greater
        else
        {
            diff=d1-d2;
            borrow=0;
        }
        dl_insert_first(rh, rt, diff);
        if (temp1!=NULL)
            temp1=temp1->prev;
        if (temp2!=NULL)
            temp2=temp2->prev;
        
    }
    //delete leading zeros
    Dlist *temp = *rh;
    while (temp && temp->data == 0 && temp->next != NULL)
    {
        *rh = temp->next;
        (*rh)->prev = NULL;
        free(temp);
    }
    
}