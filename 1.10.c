#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_element
{
    char a[20];
    char b[10];
    struct list_element* next;
    struct list_element* prev;
} list_element;

list_element* create_list_element(char a[20], char b[10])
{
    list_element* p = malloc(sizeof(list_element));
    strcpy(p->a,a);
    strcpy(p->b,b);
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insert_into_list (list_element* a, list_element* b)
{
    list_element* c = a->next;
    a->next = b;
    b->prev = a;
    b->next = c;
    if (c!=NULL)
    {
        c->prev = b;
    }

}

void print_list (list_element* a)
{
    list_element* cel = a;
    while (cel!=NULL)
    {
        printf(" Fam= %s\n tel= %s\n",cel->a,cel->b);
        cel = cel->next;
    }

}

void FreeAll(list_element* a)
{
    list_element* dub;
    while (a != NULL)
    {
        dub = a->next;
        free(a);
        a = dub;
    }

}

list_element* get_by_number(list_element* a, int n)
{
    int i;
    list_element* cur =a;
    for (i=0;i<n;i++)
    {
        if (cur == NULL)
        {
            printf("%d element does not exist",n);
            return NULL;
        }
        else
        {
            cur = cur->next;
        }

    }
    return cur;
}

void ins (list_element* a,char fam[20],char tel[10])
{
    int k = 0;
    list_element* cur = a;
    while (cur != NULL)
    {
        if (strcmp(cur->a,fam) == 0)
        {
            printf("Changed. Old value = %s\n",cur->b);
            strcpy(cur->b,tel);
            k = k+1;
        }
        cur = cur->next;
    }
    if (k == 0)
    {
        insert_into_list(a,create_list_element(fam,tel));
        printf("OK\n");
    }

}

void find (list_element* a,char fam[20])
{
    int k = 0;
    list_element* cur = a;
    while (cur != NULL)
    {
        if (strcmp(cur->a,fam) == 0)
        {
            printf("%s\n",cur->b);
            k = k+1;
        }
        cur = cur->next;
    }
    if (k == 0)
    {
        printf("NO\n");
    }
    if (k>1)
    {
        printf("Attention! You have a couple of people with same surnames!");
    }
}

int main()
{

    char enter[30];
    char fam[20];
    char tel[10];
    list_element* r = create_list_element("0","0");
    printf("INSERT - insert new name\nFIND - find some\nExit (or End) to exit program\n");
    scanf("%s",enter);
    while (enter[0] != 'E')
    {

        if (enter[0] == 'I')
        {

            printf("You want to insert\n");
            scanf("%s",fam);
            scanf("%s",tel);
            ins(r, fam, tel);
        }
        else if (enter[0] == 'F')
        {
            printf("You want to find\n");
            scanf("%s",fam);
            find(r, fam);
        }
        else
        {
            printf("What?! Repeat, please.\n");
        }
        scanf("%s",enter);
    }
    printf("Exit");

    FreeAll(r);
    return 0;
}
