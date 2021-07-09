#include <stdio.h>

char result[3]={'W','T','L'};

int main()
{
    double information[3][3]={};
    int max_index[3]={};

    double max = 0,odd;
    for(int i=0;i<3;i++){
        double max = 0;
        for(int j=0;j<3;j++){
            scanf("%lf",&odd);
            information[i][j] = odd;
            if(odd>max)
            {
                max = odd;
                max_index[i]=j;
            }
        }
    }

    double profit = 1;
    for(int i=0;i<3;i++){
        printf("%c ",result[max_index[i]]);
        profit=profit*information[i][max_index[i]];
    }
    profit = (profit*0.65-1)*2;
    printf("%.2f\n",profit);


    return 0;
}
