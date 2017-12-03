#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list_element
{
    int i;
    int j;
    //char a;
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

void push(list_element* r, int i, int j)
{
    if (r == NULL)
    {
        printf ("Warning! Your pointer was NULL\nNow it is a list element* you wanted to push.");
        r = list_new();
        r->i = i;
        r->j = j;
    }
    else
    {
    while (r->next != NULL)
    {
        r = r->next;
    }

    r->next = list_new();
    r->next->prev = r;
    r->next->i = i;
    r->next->j = j;
    }
}
//Pod slovom 'izvlech' ya ponimayu 'schitat' element, ne udalaya ego.
void pop(list_element* r, int* i, int* j)
{
    if (r == NULL)
    {
        printf ("List does not exist");
        i = NULL;
        j = NULL;
    }
    else
    {
        while (r->next != NULL)
        {
            r = r->next;
        }
        *i = r->i;
        *j = r->j;

    }
}


//This function should be used like "<head pointer> = unshift(<head pointer>,<int>)"
list_element* unshift (list_element* r, int i, int j)
{
    if (r == NULL)
    {
        printf ("Warning! Your pointer was NULL\nNow it is a list element* you wanted to unshift.");
        r = list_new();
        r->i = i;
        r->j = j;
        return r;
    }
    else
    {
        r->prev = list_new();
        r->prev->next = r;
        r->prev->i = i;
        r->prev->j = j;
        return r->prev;

    }

}

void shift (list_element* r, int* i, int* j)
{
    if (r == NULL)
    {
        printf ("List does not exist");
        i = NULL;
        j = NULL;
    }
    else
    {
        *i = r->i;
        *j = r->j;
    }
}

void print_list (list_element* a)
{
    int i = 0;
    list_element* cel = a;
    while (cel!=NULL)
    {
        printf("N%d = [%d,%d]\n",i,cel->i,cel->j);
        cel = cel->next;
        i = i+1;
    }

}






int tr(int i, int j, char* str, int M)
{
    if (str[i*M + j] == '#')
    {
        return 0;
    }
    else if (str[i*M + j + 1] == '.')
    {
        return 1;
    }
    else if (str[i*(M+1) + j] == '.')
    {
        return 2;
    }
    else if ((str[i*M + j + 1] == '#') && (str[i*(M+1) + j] == '#'))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N, M, Y, No, step;
    int i = 0;
    scanf("%d %d", &N, &M);
    char* onestr = malloc((M)*sizeof(char));
    char* str = malloc((M*N)*sizeof(char));
    //char matr = malloc(N* sixeof(str));

    scanf("%s", str);

    for (i = 1; i < N; i++)
    {
        scanf("%s", onestr);
        //printf("Onestr[%d]: %s", i, onestr);
        strcat(str,onestr);
    }
    //str[M*N+1] = '\0';
    printf("Maze: %s\n",str);
    list_element* r = list_new();
    r->i = 0;
    r->j = 0;
    No = 0;
    Y = 0;
    while ((Y == 0) && (No == 0))
    {

        step = tr(r->i, r->j, str, M);
        if (step == 0)//way is blocked -> go back and mark this way as the wrong one or exit the maze
        {
            str[r->i*M + r->j] = '#';
            if (r->prev == NULL)
            {
                N = 1;
            }
            else
            {
                r = r->prev;
            }
        }
        else if (step == 1)//we can go right -> go right
        {
            push(r,r->i,r->j+1);
            r = r->next;
        }
        else if (step == 2)//We can go down -> go down
        {
            push(r,r->i+1,r->j);
            r = r->next;
        }
        else//something went wrong
        {
            printf("Something went wrong.\nPerhaps your map contains wrong symbols.\n(You should use only '#' and '.')");
            return -1;
        }

        if ((r->i == N) && (r->j == M))
        {
            Y = 1;//We have found the exit!
        }

        //setinghelp
        printf("%s\n",str);
        printf("[%d,%d]\nstep = %d\n",r->i,r->j,step);
        getchar();
    }
    while (r->prev != NULL)
    {
        r = r->prev;
    }
    if (No == 1)
    {
        printf("There is no exit out of this maze.");
    }
    else
    {
        printf("There is at least one way out:\n");
        print_list(r);
    }


    return 0;
}
