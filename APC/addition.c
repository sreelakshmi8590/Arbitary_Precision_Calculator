#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void addition_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **rh,Dlist **rt)
{
    Dlist *temp1=*t1;
    Dlist *temp2=*t2;
    int carry=0;
    int sum;
    while(temp1!=NULL || temp2!=NULL)
    {
        sum=carry;
        if(temp1!=NULL && temp2!=NULL)
        {
            sum=sum+temp1->data + temp2->data;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        else if(temp1==NULL &&temp2!=NULL)
        {
            sum=sum + temp2->data;
            temp2=temp2->prev;
        }
        else if(temp1!=NULL &&temp2==NULL)
        {
            sum=sum + temp1->data;
            temp1=temp1->prev;
        }
        if(sum>9)
        {
            carry=1;
            sum=sum%10;
        }
        else
        {
            carry=0;
        }
        dl_insert_first(rh,rt,sum);
    }
    if(carry==1)
        dl_insert_first(rh,rt,carry);
    Dlist *temp = *rh;
    while (temp && temp->data == 0 && temp->next != NULL)
    {
        *rh = temp->next;
        (*rh)->prev = NULL;
        free(temp);
    }
}