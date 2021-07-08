#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char num[17];
    int seat1,seat2;
}stuInfo;

int main()
{
    int n;
    scanf("%d",&n);

    stuInfo *info = (stuInfo*)malloc(sizeof(stuInfo)*n);
    char num[17];
    int seat1,seat2;
    for(int i=0;i<n;i++)
    {
        scanf("%s",&num);
        scanf("%d %d",&seat1,&seat2);
        strcpy(info[i].num,num);
        info[i].seat1 = seat1;
        info[i].seat2 = seat2;
    }

    int m;
    scanf("%d",&m);
    int seat;
    for(int i=0;i<m;i++){
        scanf("%d",&seat);
        for(int j=0;j<n;j++){
            if(info[j].seat1 == seat){
                printf("%s %d\n",info[j].num,info[j].seat2);
                break;
            }
        }
    }

    return 0;
}
