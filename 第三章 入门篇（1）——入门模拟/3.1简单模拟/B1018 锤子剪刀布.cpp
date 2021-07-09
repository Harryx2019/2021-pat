#include <stdio.h>
#include <stdlib.h>

char game[3]={'B','C','J'};
int result[3][3]={
    {0,1,-1},
    {-1,0,1},
    {1,-1,0}
};

int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    char ch1,ch2;
    int a,b;
    int gesture[2][3]={0};
    int score[2][3]={0};
    while(n!=0){
        ch1=getchar();
        getchar();
        ch2=getchar();
        getchar();
        if(ch1=='B')
            a=0;
        else if(ch1=='C')
            a=1;
        else
            a=2;

        if(ch2=='B')
            b=0;
        else if(ch2=='C')
            b=1;
        else
            b=2;

        if(result[a][b]==1){
            //甲胜利
            score[0][0]++;
            score[1][2]++;
            gesture[0][a]++;
        }else if(result[a][b]==-1){
            //乙胜利
            score[1][0]++;
            score[0][2]++;
            gesture[1][b]++;
        }else{
            score[0][1]++;
            score[1][1]++;
        }
        n--;
    }
    int i;
    for(i=0;i<2;i++){
        for(int j=0;j<3;j++){
            if(j==2){
                printf("%d",score[i][j]);
                break;
            }
            printf("%d ",score[i][j]);
        }
        printf("\n");
    }
    int maxa=0,maxb=0;
    int max1=gesture[0][0],max2=gesture[1][0];
    for(i=1;i<3;i++){
        if(gesture[0][i]>max1)
        {
            max1 = gesture[0][i];
            maxa=i;
        }
        if(gesture[1][i]>max2)
        {
            max2 = gesture[1][i];
            maxb=i;
        }
    }
    printf("%c %c\n",game[maxa],game[maxb]);
    return 0;
}
