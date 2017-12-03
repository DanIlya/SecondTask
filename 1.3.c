#include <stdio.h>
#include <stdlib.h>

typedef struct list_element
{
    int a;
    struct list_element* prev;
    struct list_element* next;
} list_element;

list_element* list_new()
{
    list_element* p =(list_element*) malloc(sizeof(list_element));

    p->next = NULL;
    p->prev = NULL;
    return p;
}

void list_deleate(list_element* r)
{
    list_element* Next = r->next;
    while (Next != NULL)
    {
        Next = r->next;
        free(r);
        r = Next;
    }
    free(r);
}

void push(list_element* r, int a)
{
    if (r == NULL)
    {
        printf ("Warning! Your pointer was NULL\nNow it is a list element* you wanted to push.");
        r = list_new();
        r->a = a;
    }
    else
    {
    while (r->next != NULL)
    {
        r = r->next;
    }

    r->next = list_new();
    r->next->prev = r;
    r->next->a = a;

    }
}
//Pod slovom 'izvlech' ya ponimayu 'schitat' element, ne udalaya ego.
void pop(list_element* r, int* x)
{
    if (r == NULL)
    {
        printf ("List does not exist");
        x = NULL;
    }
    else
    {
        while (r->next != NULL)
        {
            r = r->next;
        }
        *x = r->a;

    }
}


//This function should be used like "<head pointer> = unshift(<head pointer>,<int>)"
list_element* unshift (list_element* r, int a)
{
    if (r == NULL)
    {
        printf ("Warning! Your pointer was NULL\nNow it is a list element* you wanted to unshift.");
        r = list_new();
        r->a = a;
        return r;
    }
    else
    {
        r->prev = list_new();
        r->prev->next = r;
        r->prev->a = a;
        return r->prev;

    }

}

void shift (list_element* r, int* x)
{
    if (r == NULL)
    {
        printf ("List does not exist");
        x = NULL;
    }
    else
    {
        *x = r->a;
    }
}

//This function gives you the reversed list as a result
list_element* reverse(list_element* r)
{
    if (r == NULL)
    {
        printf("List does not exist");
        return NULL;
    }
    else
    {
        list_element* p = list_new();
        p->a = r->a;
        //list_element* Next = NULL;
        while (r->next != NULL)
        {
            p = unshift(p,r->next->a);

            r = r->next;
        }

        return p;
    }

}

void print_list (list_element* a)
{
    int i = 0;
    list_element* cel = a;
    while (cel!=NULL)
    {
        printf("N%d = %d\n",i,cel->a);
        cel = cel->next;
        i = i+1;
    }

}



int main()
{
    int i;
    int x,y;
    list_element* r = list_new();
    r->a = 0;
   for (i = 1; i<11; i++)
    {
        push(r,i);
    }


    print_list(r);
    pop(r,&x);
    shift(r,&y);
    printf("popped = %d\nshifted = %d",x,y);

    list_deleate(r);

    return 0;
}
