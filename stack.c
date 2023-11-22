#include<stdio.h>
#include <string.h>
#include<stdlib.h>
struct student
{
    int roll_number;
    char name[5];
    struct student* ptr;  
};
typedef struct student s;
s*top=NULL;

void push(int rollnumber,char sname[])
{
    s* newstudent = (s*)malloc(sizeof(s)); 
    newstudent->roll_number = rollnumber;
    strcpy(newstudent->name, sname);
    newstudent -> ptr =top;
    top = newstudent;
}

void pop()
{   s* temp=top;
    top= top-> ptr;
    free(temp);
}
void display(int action,int ser)
{ 
    s* temp = top;
    while (temp != NULL) 
    { 
        switch (action)
        {
            case 1:
                printf("\n| Roll Number: %d, Name: %s |", temp->roll_number, temp->name  );
                break;
            case 2:
                if(temp->roll_number==ser)
                {
                    printf("\n| Roll Number: %d, Name: %s |<--search found", temp->roll_number, temp->name  );
                }
                else 
                {
                    printf("\n| Roll Number: %d, Name: %s |", temp->roll_number, temp->name  ); 
                    printf(" SEARCH NOT FOUND");
                }
                // else
                // {
                // }
                break;
        }
            temp = temp->ptr;

        
}
    printf("\n  -------------------------------");
}

int main()
{
    int choise,rollnumber,ser;
        char sname[5];
    while(1)
    {
        printf("\n*****************************************************************");
        printf("\n1.PUSH A DATA ");
        printf("\n2.POP THE DATA ");
        printf("\n3.display A DATA ");
        printf("\n4.SEARCH A DATA ");
        printf("\n5.PRESS ANY KEY TO EXIT ");
        printf("\nenter the choise you want to perform :");
        scanf("%d",&choise);
        printf("*****************************************************************");
    
     switch(choise)
        {
            case 1:
                printf("\nENTER THE ROLL NUMBER :");
                scanf("%d",&rollnumber);
                printf("ENTER THE NAME:");
                scanf("%s",&sname);
                push(rollnumber,sname);
                break;
            case 2:
                pop();
                break;
            case 3:
                display(1,0);
                break;
            case 4:
                printf("\nENTER THE ROLL NUMBER :");
                scanf("%d",&ser);
                display(2,ser);
                break;
            case 5:
                return(0);
            default:
                printf("\nINVALID CHOISE");

        }
    }
}