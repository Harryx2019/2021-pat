#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[11];
    char no[11];
    int score;
}stuInfo;

int main()
{
    int n;
    scanf("%d",&n);

    char name[11];
    char no[11];
    int score;

    stuInfo *stuLink = (stuInfo*)malloc(sizeof(stuInfo)*n);

    int max_score,min_score;
    int max_index = -1,min_index = -1;
    if(n!=0){
        //输入第一个学生信息
        scanf("%s",name);
        scanf("%s",no);
        scanf("%d",&score);
        strcpy(stuLink[0].name,name);
        strcpy(stuLink[0].no,no);
        stuLink[0].score = score;

        max_score =score;
        min_score = score;
        max_index = 0;
        min_index = 0;
    }
    for(int i=1;i<n;i++){
        scanf("%s",name);
        scanf("%s",no);
        scanf("%d",&score);

        strcpy(stuLink[i].name,name);
        strcpy(stuLink[i].no,no);
        stuLink[i].score = score;

        if(score>max_score){
            max_score = score;
            max_index = i;
        }
        if(score<min_score){
            min_score = score;
            min_index = i;
        }
    }

    printf("%s %s\n",stuLink[max_index].name,stuLink[max_index].no);
    printf("%s %s\n",stuLink[min_index].name,stuLink[min_index].no);

    return 0;
}
