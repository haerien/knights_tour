#include <stdio.h>

int control(int startingX, int startingY);

int sleep();
int system();

int x[8]={2,1,-1,-2,-2,-1,1,2};
int y[8]={-1,-2,-2,-1,1,2,2,1};

int board[8][8]={   {2,3,4,4,4,4,3,2},
                    {3,4,6,6,6,6,4,3},
                    {4,6,8,8,8,8,6,4},
                    {4,6,8,8,8,8,6,4},
                    {4,6,8,8,8,8,6,4},
                    {4,6,8,8,8,8,6,4},
                    {3,4,6,6,6,6,4,3},
                    {2,3,4,4,4,4,3,2} };



int main()
{
    int count=0;
    int startingX=-1,startingY=-1;

    control(startingX,startingY);

    printf("\nEnter starting position(X Y): ");
    scanf("%d %d",&startingX,&startingY);

    int currentX=startingX;
    int currentY=startingY;
    board[currentX][currentY]=0;

    system("cls");

    while (count<64)
    {
        int minPos=-1;
        int minNum=9;
        
        for (int i=0;i<8;i++)
        {
            if (currentX+x[i]<=7 && currentY+y[i]<=7 && currentX+x[i]>=0 && currentY+y[i]>=0)
            {
                if (board[currentX+x[i]][currentY+y[i]]!=0)
                {

                    if (board[currentX+x[i]][currentY+y[i]]<minNum)
                    {
                        minNum=board[currentX+x[i]][currentY+y[i]];
                        minPos=i;
                    }
                }
            }
        }
        if (minPos!=-1)
        {
            currentX+=x[minPos];
            currentY+=y[minPos];
            board[currentX][currentY]=0;
            count+=1;
            
            control(startingX,startingY);
            system("cls");
                
        }
        else
            break;
    }

    control(startingX,startingY);
    printf("Moved %d times\n\n",count);
    printf("Last position: (%d,%d)",currentX,currentY);

    return 0;

}

int control(int startingX, int startingY)
{
    if (startingX!=-1 && startingY!=-1)
    {
        printf("Starting position: (%d,%d)\n",startingX,startingY);
        printf("Knight's movement:\n");
    }

    printf("0   1   2   3   4   5   6   7\n\n");
    for (int i=0; i<8; i++)
    {   
        
        for (int j=0; j<8; j++)
        {
            if (board[i][j]==0)
                printf("X   ");
            else
                printf("_   ");
        }
        printf("  %d",i);
        printf("\n\n");
    }
}
