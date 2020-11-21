#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define null -32


 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
struct employee
{
    char name[30];
    int id;
    int salary;
};

struct Node
{
    struct employee emp;
    struct Node *next;
    struct Node *prev;
};

struct Node *tos=NULL;
struct Node *create (struct employee  e)
{
   struct Node* New=(struct Node *)malloc(1*sizeof(struct Node));
    New->emp=e;

    New->next=New->prev=NULL;
}

void push ( struct Node * pnode)
{
    if(tos == NULL)
    {
        tos=pnode;
    }
    else
    {
        pnode->prev=tos;
        tos=pnode;
    }
}

struct Node *pop()
{
    if(tos==NULL)
    {
        return NULL;
    }
    else
    {
       struct Node * temp=tos;
        tos=tos->prev;
        temp->prev=NULL;
        return temp;

    }
};

int main()
{
int c=1;
char f;
int k=0;
struct Node *ptr=NULL;
struct employee emp;

    char arr[3][10]={"push","pop","display"};
    int i,j,row;
     printf("\t\t\main menu\n");
   printf("\t\t\------------");

   while(c>0)
   {


   for(i=0;i<3;i++)
   {
      gotoxy(20,i+5);
      textattr( 15);
      printf("%s\n",arr[i]);
   }
        gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);

  char d;
   d=getch();
if(d==27)break;
if(d==9)
{
    gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
           if(k==2)
            {
            k=0;
            gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
            }
           else
           {
               k=k+1;
               gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
           }
}
   if(d == -32)
   {
       d=getch();
       if(d==80)
       {
           gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
           if(k==2)
            {
            k=0;
            gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
            }
           else
           {
               k=k+1;
               gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
           }
       }
       else if (d==72)
       {
           gotoxy(20,k+5);
      textattr( 15);
      printf("%s\n",arr[k]);
         if(k==0)
         {
             k=2;
             gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
         }
         else{
                k=k-1;
                gotoxy(20,k+5);
      textattr( 1);
      printf("%s\n",arr[k]);
         }


       }
       else if (d==27)
       {

    break;
       }


}
      else if ( d==13)
{
    if (k==0)
    {
          system("cls");
            printf("enter the name\n");
             scanf("%s",emp.name);
            printf("enter the id\n");
            scanf("%d",&emp.id);
            printf("enter the salary\n");
            scanf("%d",&emp.salary);
          ptr=  create (emp);
          push(ptr);
       getch();
            system("cls");
             textattr( 15);
         printf("\t\t\main menu\n");
   printf("\t\t\------------");


    }
    else if(k==1)
    {
         system("cls");
               textattr( 15);
     ptr=pop();
      getch();
           system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");


    }
    else if (k==2)
    {
          system("cls");
            textattr( 15);
        ptr=tos;
        while(ptr !=NULL)
        {
            printf("%s\n",ptr->emp.name);
            printf("%d\n",ptr->emp.id);
            printf("%d\n",ptr->emp.salary);
            ptr=ptr->prev;

        }
         system("cls");
            textattr( 15);
                printf("\t\t\main menu\n");
   printf("\t\t\------------");

    }

   }




    }
    return 0;
   }




