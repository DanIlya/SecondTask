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
    list_element* r = list_new();//head pointer
    r->a = 'h';
    list_element* dub;
    list_element* head = r;//one more head pointer

    scanf("%c",&s);
    while (s != '\n')//enter list
    {
        push(r,s);
        n++;
        scanf("%c",&s);
    }
    //We delete every () and {} pair until the list will be completely destroyed (which means that it was correct)
    F = 1;
    while (F == 1)
    {
        F = 0;
        r = head; //going back to the head
        i = 0;
        while (i < n)
        {
            r = r->next;
            if (r->next == NULL)//we have come to the end
            {
                i = n;
            }
            else if (((r->a == '(') && (r->next->a == ')')) | ((r->a == '{') && (r->next->a == '}')))
            {
                    dub = r->next->next;
                    if (r->next->next != NULL)
                    {
                        r->next->next->prev = r->prev;
                    }
                    free(r->next);
                    r = r->prev;
                    free(r->next);
                    r->next = dub;
                    n = n-2;
                    F = 1;
            }
            i++;
        }

    }
    if ((r->next != NULL) | (r->a != 'h'))//list is not destroyed (or one of the brackets tried to escape in the head) -> it is wrong
    {
        printf("It is wrong");
    }
    else
    {
        printf("It is correct");
    }
    list_deleate(r);
    return 0;
}
