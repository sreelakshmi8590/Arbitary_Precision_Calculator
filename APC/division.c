#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

int division_operation(Dlist **h1,Dlist **t1,Dlist **h2,Dlist **t2,Dlist **rh,Dlist **rt)
{
    int count=0;
    if(*h1==NULL)
    {
        dl_insert_first(rh,rt,0);
        return SUCCESS;
    }
    while(1)
    {
        int len1=0,len2=0;
        Dlist *temp1=*h1;
        Dlist *temp2=*h2;
        
        while(temp1)
        {
            len1++;
            temp1=temp1->next;
        }
        while(temp2)
        {
            len2++;
            temp2=temp2->next;
        }
        if(len1<len2)
        {
            break;
        }
        // if numbers have same length
        if(len1==len2)
        {
            temp1=*h1;
            temp2=*h2;
            while(temp1 && temp2 && temp1->data == temp2->data)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            if (temp1 && temp2 && temp1->data < temp2->data)
                break;
        }
        Dlist *nh=NULL,*nt=NULL;
        subtraction_operation(h1, t1, h2, t2, &nh, &nt);
        *h1=nh;
        *t1=nt;
         count++;
    } 
    dl_insert_first(rh,rt,count);
        
    return SUCCESS;
}