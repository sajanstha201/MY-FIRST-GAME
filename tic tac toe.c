#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
char value[10]={'1','1','2','3','4','5','6','7','8','9'};
void writing(int , int);
void layout();
int win();
int main()
{
    int n=1,i,choice=0,winner=0,check=1;
    for(i=1;i<=9;i++)
    {
        layout();//print the layout of game
        n=(i%2!=0)?1:2;
        printf("\nPlayer %d = ",n);
        scanf("%d",&choice);
        printf("\n");
        //to check whether players enter correct number
        if(choice<1||choice>9)
        {
            printf("Invalid choice\n");
            break;
        }
        //to check whether players enter concident number or not
        if(value[choice]=='X'||value[choice]=='O')
        {
            printf("Invalid \n");
            break;
        }
        writing(choice,n);//writes the enter value in game(inside only)
        system("clear");
        winner=win();//decide the winner and return 1 for 1st player 2 for 2nd player
        if(winner==1||winner==2)
        {
            layout();//print the layout of game
            printf("\nplayer %d wins the game\n",winner);
            break;
        }
    }
    if(winner==0)
        printf("\nNobody wins the game\n");

}

//this function is for printing the formate of tic tac toe
void layout()
{
    for(int i=1;i<=9;i++)
    {
        if(i==3||i==6)
        {
            printf("%c",value[i]);
            printf("\n   ||   ||   ");
            printf("\n===||===||===\n");
        }
        else if(i==9)
        {
            printf("%c",value[i]);
        }
        else
        {
            printf(" %c ",value[i]);
            printf("||");
        }
    }
}

//this function take the choice of players and enter respective value to the position
void writing(int choice,int n)
{
     if(n==1)
        value[choice]='O';
     else if (n==2)
        value[choice]='X';
}
//function that check the winner of the game
int win()
{
    for(int i=1;i<=9;i++)
    {
        if(i==1||i==4||i==7)
        {
            if(value[i]==value[i+1]&&value[i+1]==value[i+2])
                if(value[i]=='X') 
                    return 2;
                else
                    return 1;
        }
        if(i==1||i==2||i==3)
        {
            if(value[i]==value[i+3]&&value[i+3]==value[i+6])
                if(value[i]=='X')
                    return 2;         
                else
                    return 1;
        }
        if(i==1)
        {
            if(value[i]==value[i+4]&&value[i+4]==value[i+8]&&value[i])
                 if(value[i]=='X')
                    return 2;
                else
                    return 1;
        }
        if(i==3)
        {
            if(value[i]==value[i+2]&&value[i+2]==value[i+4]&&value[i])
                 if(value[i]=='X')
                    return 2;
                else
                    return 1;
        }
    }
}
