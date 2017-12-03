#include <stdio.h>
#include <stdlib.h>

typedef struct list_element
{
    char a;
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
//new element in the end
void push(list_element* r, char a)
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
//read last element
void pop(list_element* r, char* x)
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


//This function should be used like "<head pointer> = unshift(<head pointer>,<char>)"
list_element* unshift (list_element* r, char a)
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
//read first element
void shift (list_element* r, char* x)
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
        printf("N%d = %c\n",i,cel->a);
        cel = cel->next;
        i = i+1;
    }

}



int main()
{
    char s;
    int i,F;
    int n = 0;
    list_element* r,p = list_new();
    while (s != '\0')
    {
        scanf("%c",&s);
        if (((s == ')')&&(r->a == '(')) | ((s == '}')&&(r->a == '{')))
        {
            r = r->prev;
        }
        else
        {
            push(r,s);
        }
        n++;
    }

    F = 1;
    while (F == 1)
    {
        F = 0;
        for (i = 0; i < n; i++)
        {


        }
    }

    return 0;
}
