#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//board
int arr[3][3]={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};


void smartMode(int);
void evilMode(int);
void playerMode(int*);
int checkValidPath(int);
void updateCell(int, int);
int isvalidPosition(int);

//cost of path calculation

int * getPathCost(int);

//termination task
int draw();
int win(int);

int main(void)
{
    int ch;
    system("cls");

    do{
        // MENU :           
        printf("\nEnter Your Choice :");
        printf("\n1. Want to play with Smart Computer");
        printf("\n2. Want to play with Evil Computer");
        printf("\n3. Want to play with Player");
        printf("\n4. Exit");

        printf("\n\n");

        scanf("%d", &ch);

        system("cls");

        }while(ch > 5 || ch <0);

        //exit
        if(ch == 4)
                return 0;


        // Board
        int player=-1;//first player start
        do
        {
            system("cls");
            printf("\n####################### TIC TAC TOI GAME  ###########################");
                printf("\nFirst Player\t:\tO");// -1 ----> first player ---> O 
                printf("\nSecond Player\t:\tX");// 0 ----> second player --> X
                printf("\n\n\n\n");
               printf("     |     |     \n");
               for(int i=0; i<3 ; i++)
               {
                    if(arr[0][i] == -1)
                        printf("  O  |");
                    else if(arr[0][i] == 0)
                        printf("  X  |");
                    else
                        printf("  %d  |", arr[0][i]);

               }
               printf("\b");
               printf("\n");

               printf("_____|_____|_____\n");
               printf("     |     |     \n");

               for(int i=0; i<3 ; i++)
               {
                    if(arr[1][i] == -1)
                        printf("  O  |");
                    else if(arr[1][i] == 0)
                        printf("  X  |");
                    else
                        printf("  %d  |", arr[1][i]);

               }
               printf("\b");
               printf("\n");

               printf("_____|_____|_____\n");
               printf("     |     |     \n");
           
                for(int i=0; i<3 ; i++)
               {
                    if(arr[2][i] == -1)
                        printf("  O  |");
                    else if(arr[2][i] == 0)
                        printf("  X  |");
                    else
                        printf("  %d  |", arr[2][i]);

               }
               printf("\b");
               printf("\n");

               printf("     |     |     \n\n");

                printf("\n\n\n\n");
                printf("\n#####################################################################");
                printf("\n\n");

            //check match draw or win

            if(win(-1))// first win
            {
                    printf("\nPlayer 1 won !!!");
                    printf("\n\n\n\n");
                    printf("\n#####################################################################");
                    break;
            }
            else if(win(0))//second win
            {
                    printf("\nPlayer 2 won !!!");
                    printf("\n\n\n\n");
                    printf("\n#####################################################################");
                    break;
            }
            else if(draw())
            {
                    printf("\nDraw");
                    printf("\n\n\n\n");
                    printf("\n#####################################################################");
                    break;
            }
            

            //========================================================================================

            switch(ch)
            {
                case 1 : //smartMode
                        smartMode(player);
                        break;

                case 2 : //evilMode
                        evilMode(player);
                        break;

                case 3 : //player mode
                        
                        playerMode(&player);
                        break;
            }
        } while (1);
        printf("\nPress any To Exit ...");
        while((int)getch() !=13);
        
    return 0;
}

// int valid position
int isvalidPosition(int pos)
{
        int flag = 1;

        if ((arr[(pos-1)/3][(pos-1)%3] == -1) || (arr[(pos-1)/3][(pos-1)%3] == 0))
                flag = 0;

        return flag;
}

int checkValidPath(int path)
{
    int pos=-1;

    switch(path)
    {
        //horizontal path
        case 0 ... 2: 
        for(int i=0; i<3; i++)
        {
            if((arr[path][i] !=0) && (arr[path][i] !=-1))
            {
                pos=path*3+i+1;
                break;
            }
        }
        break;

        //vartical path
        case 3 ... 5: 
        for(int i=0; i<3; i++)
        {
            if((arr[i][path%3] !=0) && (arr[i][path%3] !=-1))
            {
                pos=i*3+(path%3) +1;
                break;
            }
        }
        break;

        // principle diagonal
        case 6 :
        for(int i=0; i<3; i++)
        {
            if((arr[i][i] !=0) && (arr[i][i] !=-1))
            {
                pos=i*3+i+1;
                break;
            }
        }
        break;

        // other diagonal
        case 7 :
        for(int i=0; i<3; i++)
        {
            if((arr[2-i][i] !=0) && (arr[2-i][i] !=-1))
            {
                pos=(2-i)*3+i+1;
                break;
            }
        }
        break;
    }

    return pos;
}


//draw match

int draw()
{
    int flag=1;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j] != 0 && arr[i][j] != -1)
            {
                    flag=0;
                    break;
            }
        }
        if(!flag)
        {
            break;
        }
    }

    return flag;
}

// win

int win(int val)
{
    int flag=0;
    if(
            (arr[0][0] == val) && (arr[1][1] == val) && (arr[2][2] == val) ||
            (arr[2][0] == val) && (arr[1][1] == val) && (arr[0][2] == val) ||
            (arr[0][0] == val) && (arr[0][1] == val) && (arr[0][2] == val) ||
            (arr[1][0] == val) && (arr[1][1] == val) && (arr[1][2] == val) ||
            (arr[2][0] == val) && (arr[2][1] == val) && (arr[2][2] == val) ||
            (arr[0][0] == val) && (arr[1][0] == val) && (arr[2][0] == val) ||
            (arr[0][1] == val) && (arr[1][1] == val) && (arr[2][1] == val) ||
            (arr[0][2] == val) && (arr[1][2] == val) && (arr[2][2] == val)

    )
    {
            flag =1;
    }

        return flag;
}

//calculate of path cost

int* getPathCost(int player)
{
    // int cost[]={0, 0, 0, 0, 0, 0, 0, 0};
    //             0  1  2  3  4  5  6  7
    int *cost=(int *)(malloc(8*sizeof(int)));

    //initialize path cost
    for(int i=0; i<8; i++)
        cost[i]=0;

    //horizontal path
    for(int k=0; k<3; k++)
    {
        for(int i=0; i<3; i++)
        {
            if(arr[k][i] == player)
            {
                cost[k]++;
            }
        }
    }

    // vartical path
    for(int k=0; k<3; k++)
    {
        for(int i=0; i<3; i++)
        {
            if(arr[i][k] == player)
            {
                cost[k+3]++;
            }
        }
    }

    // princple diagonal 
    for(int i=0; i<3; i++)
    {
        if(arr[i][i] == player)
        {
            cost[6]++;
        }
    }

    // other diagonal
    for(int i=0; i<3; i++)
    {
        if(arr[2-i][i] == player)
        {
            cost[7]++;
        }
    }

    return cost;
}

void updateCell(int pos, int player)
{
    arr[(pos-1)/3][(pos-1)%3]=player;
        
}

//smart mode ----> Player(O -1) Vs Computer(X 0);
void smartMode(int player)
{
    int pos;
    //enter valid posion by user
    printf("\nPlayer 1, Enter Marking Place : ");
    scanf("%d", &pos);

    if((pos<1) || (pos>9) || (!isvalidPosition(pos)))
    {
        return;
    }

    updateCell(pos, -1);

    int *costO=getPathCost(-1);


    for(int i=0; i<8; i++)
    {
        if(costO[i] == 3)
        {
            printf("\nPlayer 1 won !!!");
            printf("\n\n\n\n");
            printf("\n#####################################################################");
            printf("\n\n");   
            return;
        }
    }

    player=0;// smart computer turn

    // smart computer turn  --> oppose to win
    int flag=0;
    for(int i=0; i<8; i++)
    {
        if(costO[i] == 2)
        {
            pos=checkValidPath(i);
            if(pos !=-1 )
            {
                updateCell(pos, player);// update cell for smart computer
                flag=1;
                break;
            }
        }
    }
    if(!flag)
    {
        // smart computer turn  --> play to win
        int *costX=getPathCost(player);

        for(int i=2; i>=0; i--)// start from maximum cost
        {
            int updateFlag=0;
            for(int j=0; j<8; j++)
            {
                if(costX[j] == i)
                {
                    pos=checkValidPath(j);
                    if(pos !=-1 )
                    {
                        updateCell(pos, player);// update cell for smart computer
                        updateFlag=1;
                        break;
                    }
                }
            }

            if(updateFlag)
            {
                return;
            }

        }

    }
    

} 


////evil mode ----> Player(O -1) Vs evil Computer(X 0);
void evilMode(int player)
{
    int pos;
    //enter valid position by user
    printf("\nPlayer 1, Enter Marking Place : ");
    scanf("%d", &pos);

    if((pos<1) || (pos>9) || (!isvalidPosition(pos)))
    {
        return;
    }

    updateCell(pos, -1);

    int *costO=getPathCost(-1);


    for(int i=0; i<8; i++)
    {
        if(costO[i] == 3)
        {
            printf("\nPlayer 1 won !!!");
            printf("\n\n\n\n");
            printf("\n#####################################################################");
            printf("\n\n");   
            return;
        }
    }

    player=0;// evil computer turn

    // evil computer turn  --> oppose to win strictly
    int flag=0, count=0;
    for(int i=0; i<8; i++)
    {
        if(costO[i] == 2)
        {
            pos=checkValidPath(i);
            if(pos !=-1 && (count<2))
            {
                updateCell(pos, player);// update cell for evil computer
                count++;
                flag=1;

                // break;
            }
        }
    }
    if(!flag)
    {
        // smart computer turn  --> play to win
        int *costX=getPathCost(player);

        for(int i=2; i>=0; i--)// start from maximum cost
        {
            int updateFlag=0;
            for(int j=0; j<8; j++)
            {
                if(costO[j] == i)
                {
                    pos=checkValidPath(j);
                    if(pos !=-1 )
                    {
                        updateCell(pos, player);// update cell for smart computer
                        updateFlag=1;
                        break;
                    }
                }
            }

            if(updateFlag)
            {
                return;
            }

        }

    }
    

}

////player mode ----> Player 1(O -1) Vs Player 2(X 0);
void playerMode(int *player)
{
    int pos;
    //enter valid position by Player 1
    if(*player == -1)
        printf("\nPlayer O, Enter Marking Place : ");
    else
        printf("\nPlayer X, Enter Marking Place : ");
    scanf("%d", &pos);

    if((pos<1) || (pos>9) || (!isvalidPosition(pos)))
    {
        return;
    }

    updateCell(pos, *player); 
    
    if(*player == -1)
       *player=0;
    else
        *player=-1;

}




