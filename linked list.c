#include<stdio.h>
#include<stdlib.h>


struct student
{
    int roll_number;
    char name[20];
    struct student* ptr;  
};
typedef struct student s; //Define struct student as S. s--node name
s* head = NULL;           // at initial list is empty so we point head eq
void insertion(int rollnumber, char sname[]) 
{
    s* newstudent = (s*)malloc(sizeof(s));
    if (newstudent == NULL)
    {
        printf("Out of memory\n");
        return;
    }
    newstudent->roll_number = rollnumber;
    strcpy(newstudent->name, sname);
    newstudent->ptr = NULL;

    if (head == NULL) 
    {
        head = newstudent;
    } 
    else 
    {
        s* temp = head;
        while (temp->ptr != NULL)
        {
            temp = temp->ptr;
        }
        temp->ptr = newstudent;
    }
}

void display() 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    s* temp = head;
    printf("Student records:\n");
    while (temp != NULL) 
    {
        printf("Roll Number: %d, Name: %s\n", temp->roll_number, temp->name);
        temp = temp->ptr;
    }
}

int main()
{
    while(1)
    {
        int choise,rollnumber;
        char sname[20];
        printf("\n*****************************************************************");
        printf("\n1.INSERT A DATA ");
        printf("\n2.DISPLAY THE DATA ");
        printf("\n3.DELETET A DATA ");
        printf("\n4.EXIT ");
        printf("\nenter the choise you want to perform :");
        scanf("%d",&choise);
        printf("\n*****************************************************************");
        
        
        switch(choise)
        {
            case 1:
                printf("\nENTER THE ROLL NUMBER :");
                scanf("%d",&rollnumber);
                printf("\nENTER THE NAME:");
                scanf("%s",&sname);
                insertion(rollnumber,sname);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nENTER THE POSITION :");
                printf("\nENTER THE VALUE:");
                //delete();
                break;
            case 4:
                return(0);
                
            default:
                printf("\nINVALID CHOISE");
                


        }

    }
}


