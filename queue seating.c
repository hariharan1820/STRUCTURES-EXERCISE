#include <stdio.h>
#include <stdlib.h>
struct subjct
{
    int roll_number;
    struct subject* ptr;  
};
typedef struct subjct sub;
struct queue {
    sub* front;
};
struct queue *createqueue() {
    struct queue *p = (struct queue *)malloc(sizeof(struct queue));
    p->front = NULL;
    return p;
}
void enqueue(struct queue *s, int rollnumber) {
    sub *newnode = (sub *)malloc(sizeof(sub));
    newnode->roll_number = rollnumber;
    newnode->ptr = NULL;
    if (s->front == NULL)
      s->front=newnode;
    else {
      sub *temp = s->front;
      while (temp->ptr!=NULL) {
      temp = temp->ptr;
      }
      temp->ptr = newnode;
      
    }
}
void displayQueue(struct queue *s) {
    if (s->front == NULL) {
        printf("Queue is empty.\n"); 
        return;
    }

    printf("\nContents of the queue:\n");
    sub *current = s->front;
    while (current != NULL) {
        printf("%d ", current->roll_number);
        current = current->ptr;
    }
}
int main()
{
    int  remaining;

    int sub1,sub2,sub3,numofsub,totalstudent;
    int numberoftables, capacity, studentpertable, batch;
    int count,count1;

    printf("ENTER TOTAL NUMBER OF TABLE:");
    scanf("%d",&numberoftables);
    printf("ENTER CAPACITY OF TABLE(3/4/5):");
    scanf("%d", &capacity);
    printf("ENTER NUMBER OF SUBJECT(2/3)");
    scanf("%d", &numofsub);
    switch (numofsub)
    {case 2:
        printf("ENTER NUMBER OF STUDENT WRITE SUB1:");
        scanf("%d", &sub1);
        printf("ENTER NUMBER OF STUDENT WRITE SUB2:");
        scanf("%d", &sub2);
        totalstudent=sub1+sub2;
    break;
    case 3:
        printf("ENTER NUMBER OF STUDENT WRITE SUB1:");
        scanf("%d", &sub1);
        printf("ENTER NUMBER OF STUDENT WRITE SUB2:");
        scanf("%d", &sub2);
        printf("ENTER NUMBER OF STUDENT WRITE SUB3:");
        scanf("%d", &sub3);
        totalstudent = sub1 + sub2 + sub3;
    break;
    }
        
    switch(numofsub)
    {
        case 2:
            if (numofsub == 2 && capacity ==5)
            {
            studentpertable = 3;
            } else
            {
            studentpertable=2;
            }
        break;
        case 3:
            studentpertable=3;
            printf("ENTER PER TABLE IS: 2");
        break;
    }
    
    if (numofsub == 2)
    {
        struct queue* s1 =createqueue();
        for (int rollnum = 1; rollnum <= sub1; rollnum++)
        {
            enqueue(s1,rollnum);
        }
        struct queue* s2 =createqueue();
        for (int rollnum = 1; rollnum <= sub2; rollnum++)
        {
            enqueue(s2,rollnum);
        }
        displayQueue(s1);
        displayQueue(s2);
        sub *current = s1->front;
        sub *current1 = s2->front;
        printf("\n");

        int spr=(numberoftables*studentpertable);
        for(int i=spr;spr<=i&&i<=totalstudent;)
        {
            batch++;
            i=i+spr;
        }batch=batch+1;
        printf("\n\nTOTAL STUDENTS:%d",totalstudent);
        printf("\n\nSTUDENT PER ROOM:%d",spr);
        printf("\nTotal number of batch:%d ", batch);



    for (int b = 1; b <= batch; b++) {
        printf("**********************************************");
        printf("\nBatch %d:",b);
        for (int i = 1; i <= numberoftables; i++)
        {   printf("\nTABLE %d: ",i);
            for(int j=1;j<=capacity;j++)
            {//printf("pos :%d :",j);
            
            if ((j == 1 || j == 5)&&(count<sub1))
                {
                if (current != NULL)
                {
                    printf("%d ", current->roll_number);
                    current = current->ptr; 
                    count += 1;
                    
                }       
            }
            else if ((j == 3)&&(count<=sub1)&&(count1<sub2))
                {
                    if (current1 != NULL)
                    {
                        printf("%d ", current1->roll_number);
                        current1 = current1->ptr;
                        count1 +=1;
                    }
                }
            else if ((j == 1 || j == 5) && (count >= sub1)&&(count1<sub2))
            {
                if (current1 != NULL)
                {
                    printf("%d ", current1->roll_number);
                    current1 = current1->ptr;
                    count1 +=1;
                }}
            else
                {
                    printf("x.");
                }
            }
            //printf("\ncount:%d",count1);
            printf("\n");
        }
    }
    }
    
    else
    {
        struct queue* s1 =createqueue();
        for (int rollnum = 1; rollnum <= sub1; rollnum++)
        {
            enqueue(s1,rollnum);
        } 
        struct queue* s2 =createqueue();
        for (int rollnum = 1; rollnum <= sub2; rollnum++)
        {
            enqueue(s2,rollnum);
        }
        struct queue* s3 =createqueue();
        for (int rollnum = 1; rollnum <= sub3; rollnum++)
        {
            enqueue(s3,rollnum);
        }
        
    
    }
    
}
    












