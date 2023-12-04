#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct game {
    int player;
    struct game *preptr;
    struct game *nxtptr;
};

typedef struct game game;
game *head = NULL;

void insertion(int plr) {
    game* newplayer = (game*)malloc(sizeof(game));
    if (newplayer == NULL) {
        printf("Out of memory\n");
        return;
    }
    newplayer->player = plr;
    newplayer->preptr = NULL;
    newplayer->nxtptr = NULL;

    if (head == NULL) {
        head = newplayer;
        head->preptr = head;
        head->nxtptr = head;
    } else {
        game *temp = head->preptr;
        while (temp->nxtptr != head) {
            temp = temp->nxtptr;
        }
        temp->nxtptr = newplayer;
        newplayer->preptr = temp;
        newplayer->nxtptr = head;
        head->preptr = newplayer;
    }
}
 int count1=1;
game *winPlayer;
int display(int nofchairs) {
    if (head == NULL) {
        printf("List is empty.\n");
        
    }
    game *temp = head;
    
    game *pre = head->preptr;
    int count = count1;
    int countplayer=0;
   
    printf("\nPlayers' positions: ");
    do {
        if(temp->player!=0){
            printf("%d ", temp->player);
            countplayer++;
            winPlayer=temp;
        }
        if(temp->player==0){
            printf("%d ", temp->player);
        }
        temp = temp->nxtptr;
        count++;
        
    } while (count<=nofchairs);
    // nofchairs-=1;
    count1++;
    if (countplayer == 1) {
        printf("\n%d is win\n", winPlayer->player);
        return 0;
    }
}

void move(int pos) {
    game *temp = head;
    game *temp1 = head;
    game *rev = head;

    if (pos == 0) {
        int count = 1;
        while (count < 5 && temp != NULL) {
            temp = temp->nxtptr;
            count++;
        }
    }

    for (int i = 0; i <= pos - 1; i++) {
        temp = temp->nxtptr;
    }

    if (temp->player == 0) { 
        rev = head->preptr;
        temp->player = head->player;
        temp->preptr = temp1->preptr;
        rev->nxtptr = head->nxtptr;

        head = head->nxtptr;
        if (head->player == 0)
            head = head->nxtptr;
    } else if (temp->player != 0) {
        printf("Player is out");
        game *next = head;
        game *pre = head;
        next = head->nxtptr;
        pre = head->preptr;

        next->preptr = head->preptr;
        pre->nxtptr = head->nxtptr;
        free(head);
        head = next;
        if (head->player == 0) {
            head = head->nxtptr;
        }
    }
}

int main() {
    int players, nofchair, ran, choise,dis;
    printf("ENTER TOTAL NUMBER OF PLAYERS: ");
    scanf("%d", &players);
    nofchair = players * 2;

    int j = 1;
    for (int i = 1; i <= nofchair; i++) {
        if (i % 2 != 0) {
            insertion(j);
            j++;
        } else {
            insertion(0);
        }
    }
    while (1) {
        dis = display(nofchair);
        if (dis == 0) {
            return 0;
        }
        srand(time(0));
        ran = rand() % (nofchair / 2);
        if(ran==0)
            ran += 1;
       

        printf("\n Random Number is:%d ", ran);
        printf("\n Enter 0 for continue move: ");
        scanf("%d", &choise);
        switch (choise) {
            case 0:
    
                    move(ran);
                
            default:
                return (0);
            }
            
    }
}