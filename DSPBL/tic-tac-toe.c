#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char arr[9];
int gameover(){
    if(arr[2]==arr[1] && arr[2]==arr[3]&& (arr[3]=='O' || arr[3]=='X'))
        return 1;
    else if(arr[5]==arr[4] && arr[4]==arr[6] && (arr[6]=='O' || arr[6]=='X'))
        return 1;
    else if(arr[8]==arr[7] && arr[8]==arr[9] && (arr[8]=='O' || arr[8]=='X'))
        return 1;
    else if(arr[5]==arr[1] && arr[5]==arr[9] && (arr[9]=='O' || arr[9]=='X'))
        return 1;
    else if(arr[3]==arr[5] && arr[5]==arr[7] && (arr[4]=='O' || arr[4]=='X'))
        return 1;
    else if(arr[1]==arr[4] && arr[4]==arr[7] && (arr[4]=='O' || arr[4]=='X'))
        return 1;
    else if(arr[2]==arr[5] && arr[5]==arr[8] && (arr[5]=='O' || arr[5]=='X'))
        return 1;
    else if(arr[3]==arr[6] && arr[6]==arr[9] && (arr[9]=='O' || arr[9]=='X'))
        return 1;
    else 
        return 0;
}
void display(){
    printf("\n");
    printf("| ");
    for(int i=1;i<=9;i++){
        printf("%c | ",arr[i]);
        if(i%3==0 && i!=1)
            printf("\n_____________\n");
        if(i%3==0 && i!=9)
            printf("| ");
    }
}
void assign(){
    for(int i=1;i<=9;i++){
        arr[i]='_';
    }
}
void game(){
    char player1,player2;
    char ab[10],p2[10];
    int x1;
    printf("Enter name of player-1 : ");
    scanf("%s",ab);
    printf("Enter name of player-2 : ");
    scanf("%s",p2);
    while(1){
        printf("The choice of %s is ( O or X ) : ",ab);
        scanf(" %c",&player1);
        if(player1!='O' && player1!='X'){
            printf("Invalid Input!!!\n");
            continue;
        }
        else
            break;
    }
    printf("\n");
    printf("| ");
    for(int i=1;i<=9;i++){
        printf("%d | ",i);
        if(i%3==0 && i!=1)
            printf("\n_____________\n");
        if(i%3==0 && i!=9)
            printf("| ");
    }
    assign();
    display();
    if(player1=='O')
        player2='X';
    else
        player2='O';
    for(int i=0;i<9;i++){
        int x=5;
        if(i%2==0){
            do{
                printf("\n%s Enter the number of the box : ",ab);
                scanf("%d",&x1);
                if(arr[x1]!='_'){
                    printf("Invalid input\n");
                }
                else{
                    arr[x1]=player1;
                    x=0;
                    display();
                    if(gameover()){
                        printf("\n%s has won\n",ab);
                        return;
                    }
                }
            }while(x!=0);
        }
        else{
            
            x=5;
            do{
                printf("\n%s Enter the number of the box : ",p2);
                scanf("%d",&x1);
                 if(arr[x1]!='_'){
                    printf("Invalid input\n");
                }
                else{
                    arr[x1]=player2;
                    x=0;
                display();
                if(gameover()){
                    printf("\n%s has won\n",p2);
                    return;
                } 
                }
            }while(x!=0);
        }
    }
    printf("\nIt's A Draw %s and %s!!!!\n",ab,p2);
}
int main()
{
    int ch;
    while(1){
        game();
        printf("\nDo you want to play again (1/0) : ");
        scanf("%d",&ch);
        if(ch==0)
            exit(0);
    }
    return 0;
}
