/*
 -----Description-----
 Name : APC (Arbitary Precision Calculation)Project
 Date : 26 - 12 - 2025
 Author : Sreelakshmi k
*/
#include"dll.h"
#include<stdio.h>
int main(int argc,char *argv[])
{

    Dlist *head1=NULL;
    Dlist *tail1=NULL;
    Dlist *head2=NULL;
    Dlist *tail2=NULL; 
    int digit,res_sign=+1;
    int sign1 = +1, sign2 = +1;
    int i=0;
    if (argv[1][0] == '-')
    {
        sign1 = -1;
        i++;
    }
    for(;argv[1][i];i++)
    {
        digit=argv[1][i]-48;
        dl_insert_last1(&head1,&tail1,digit);
    }
    i=0;
    if (argv[3][0] == '-')
    {
        sign2 = -1;
        i++;
    }
    for(;argv[3][i];i++)
    {
        digit=(argv[3][i])-48;
        dl_insert_last2(&head2,&tail2,digit);
    }
    Dlist *reshead=NULL;
    Dlist *restail=NULL;

    switch(argv[2][0])
    {
        case '+':
        if(sign1 == sign2)
        {
            addition_operation(&head1,&tail1,&head2,&tail2,&reshead,&restail);
            res_sign=sign1;
        }
        else
        {
            if(compare(head1, head2)>=0)
            {
                subtraction_operation(&head1, &tail1, &head2, &tail2, &reshead, &restail);
                res_sign=sign1;
            }
            else
            {
                subtraction_operation(&head2, &tail2, &head1, &tail1, &reshead, &restail);
                res_sign=sign2;
            }

        }
        print_result(reshead,res_sign);
        break;
        case '-':
            int temp_sign2=-sign2;
            
             if (sign1 == temp_sign2)
            {
                addition_operation(&head1, &tail1, &head2, &tail2, &reshead, &restail);
                res_sign=sign1;
            }
            else
            {
                if(compare(head1, head2)>=0)
                {
                    subtraction_operation(&head1, &tail1, &head2, &tail2, &reshead, &restail);
                    res_sign=sign1;
                }
                else
                {
                    subtraction_operation(&head2, &tail2, &head1, &tail1, &reshead, &restail);
                    res_sign=temp_sign2;
                }
            }
            print_result(reshead,res_sign);
            break;
        case '*':
        case 'x':
        case 'X':
            multiplication_operation(&head1,&tail1,&head2,&tail2,&reshead,&restail);
            res_sign=sign1 * sign2;
            print_result(reshead,res_sign);
            break;
        case '/':
            if(strcmp(argv[1],argv[3])==0)
            {
                dl_insert_first(&reshead,&restail,1);
                print_result(reshead,res_sign);
                break;
            }
            else if(strcmp(argv[3],"0")==0)
            {
                printf("Invalid !! Divisor cannot be ZERO..\n");
                break;
            }
            else if(strcmp(argv[1],"0")==0)
            {
                dl_insert_first(&reshead,&restail,0);
                print_result(reshead,res_sign);
                break;
            }
            else if((strlen(argv[1])) < (strlen(argv[3])))
            {
                dl_insert_first(&reshead,&restail,0);
                print_result(reshead,res_sign);
                break;
            }
            else if((strlen(argv[1])) == (strlen(argv[3])))
            {
                int i=0;
                while(argv[1][i] && argv[3][i])
                {
                    if((argv[1][i]-48) < (argv[3][i]-48))
                    {
                        dl_insert_first(&reshead,&restail,0);
                        print_result(reshead,res_sign);
                    }
                    else if((argv[1][i]-48) > (argv[3][i]-48))
                    {
                        break;
                    }
                    i++;
                }
            }  

            division_operation(&head1,&tail1,&head2,&tail2,&reshead,&restail);
            res_sign=sign1 * sign2;
            print_result(reshead,res_sign); 
            break;
    }
}
int dl_insert_last1(Dlist **head1, Dlist **tail1, int digit)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
        return FAILURE;
    else
    {
        new->data=digit;
        new->prev=NULL;
        new->next=NULL;
        if(*head1==NULL && *tail1==NULL)
        {
            *head1=new;
            *tail1=new;
        }
        else
        {
            new->prev=*tail1;
            (*tail1)->next=new;
            *tail1=new;
        }
    }
    return SUCCESS;
}
int dl_insert_last2(Dlist **head2, Dlist **tail2, int digit)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
        return FAILURE;
    else
    {
        new->data=digit;
        new->prev=NULL;
        new->next=NULL;
        if(*head2==NULL && *tail2==NULL)
        {
            *head2=new;
            *tail2=new;
        }
        else
        {
            new->prev=*tail2;
            (*tail2)->next=new;
            *tail2=new;
        }
    }
    return SUCCESS;
}
int dl_insert_first(Dlist **rh, Dlist **rt, int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
        return FAILURE;
    else
    {
        new->data=data;
        new->next=NULL;
        new->prev=NULL;
        
    }
    if(*rh==NULL&& *rt==NULL)
    {
        
        *rh=new;
        *rt=new;
    }
    else
    {
        new->next=*rh;
        (*rh)->prev=new;
        *rh=new;
        
    }
    return SUCCESS;
}
void print_result(Dlist *reshead,int res_sign)
{
	/* Cheking the list is empty or not */
	if (reshead == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Result -> ");

        if(res_sign== -1)
            printf("-");
	    while (reshead)		
	    {
		    /* Printing the list */
		    printf("%d ", reshead -> data);

		    /* Travering in forward direction */
		    reshead = reshead -> next;
		    if (reshead)
		        printf(" ");
	    }
    	printf("\n");
    }
}
void swap_numbers(Dlist **h1, Dlist **t1,Dlist **h2, Dlist **t2)
{
    Dlist *temp=*h1;
    *h1=*h2;
    *h2=temp;

    temp=*t1;
    *t1=*t2;
    *t2=temp;
}
int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head==NULL && *tail==NULL)
        return FAILURE;
    else
    {
        Dlist *temp=*head;
        Dlist *mid;
        while(temp!=*tail)
        {
            mid=temp->next;
            free(temp);
            temp=mid;
        }
        *head=NULL;
        *tail=NULL;
    }
}
int compare(Dlist *h1,Dlist *h2)
{
    int len1 = 0, len2 = 0;
    Dlist *t1 = h1, *t2 = h2;

    while (t1) 
    {
        len1++;
        t1 = t1->next; 
    }
    while (t2) 
    {
        len2++; 
        t2 = t2->next; 
    }

    if (len1 > len2) 
        return 1;
    if (len1 < len2) 
        return -1;
    while(h1 && h2)
    {
        if(h1->data > h2->data)
            return 1;
        if(h1->data < h2->data)
            return -1;
        h1=h1->next;
        h2=h2->next;
    }
    return 0;
}
