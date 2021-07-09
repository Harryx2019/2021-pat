#include <stdio.h>

int score_sum[100010]={};

int main()
{
    int n;
    scanf("%d",&n);

    int index,score;
    int max_index=-1,max=-1;
    for(int i=0;i<n;i++){
        scanf("%d %d",&index,&score);
        score_sum[index]+=score;

        if(score_sum[index]>max){
            max_index=index;
            max = score_sum[index];
        }
    }
    printf("%d %d\n",max_index,max);

    return 0;
}
