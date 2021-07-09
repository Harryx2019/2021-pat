#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct personInfo
{
    char name[11];
    char gender;
    char ID[11];
    int grade;
    struct personInfo *next;
} studentInfo,*studentLink;

int main()
{
    //男生链表
    studentLink maleStu = (studentLink)malloc(sizeof(studentInfo));
    maleStu->next = NULL;
    studentInfo *maleStuTail = maleStu;
    //女生链表
    studentLink femaleStu = (studentLink)malloc(sizeof(studentInfo));
    femaleStu->next = NULL;
    studentInfo *femaleStuTail = femaleStu;

    int n;
    scanf("%d",&n);

    char name[11];
    char gender;
    char ID[11];
    int grade;
    for(int i=0; i<n; i++)
    {
        scanf("%s",name);
        getchar();
        scanf("%c",&gender);
        scanf("%s",ID);
        scanf("%d",&grade);

        studentInfo *p = (studentInfo*)malloc(sizeof(studentInfo));
        strcpy(p->name,name);
        p->gender = gender;
        strcpy(p->ID,ID);
        p->grade = grade;
        p->next = NULL;

        if(gender == 'M')
        {
            maleStuTail->next = p;
            maleStuTail=p;
        }
        else
        {
            femaleStuTail->next = p;
            femaleStuTail=p;
        }
    }

    bool flag1=true,flag2=true;
    //查找女生最高分
    studentInfo *p = femaleStu->next;
    studentInfo *maxFemale = (studentInfo*)malloc(sizeof(studentInfo));
    maxFemale->gender = 'F';
    maxFemale->grade = 0;
    if(p==NULL)
    {
        flag1 = false;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->grade > maxFemale->grade)
            {
                strcpy(maxFemale->name,p->name);
                strcpy(maxFemale->ID,p->ID);
                maxFemale->grade = p->grade;
            }
            p=p->next;
        }
    }

    //查找男生最低分
    p = maleStu->next;
    studentInfo *minMale = (studentInfo*)malloc(sizeof(studentInfo));
    minMale->gender = 'M';
    minMale->grade = 100;
    if(p==NULL)
    {
        flag2 = false;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->grade < minMale->grade)
            {
                strcpy(minMale->name,p->name);
                strcpy(minMale->ID,p->ID);
                minMale->grade = p->grade;
            }
            p=p->next;
        }
    }

    if(flag1)
        printf("%s %s\n",maxFemale->name,maxFemale->ID);
    else
        printf("Absent\n");

    if(flag2)
        printf("%s %s\n",minMale->name,minMale->ID);
    else
        printf("Absent\n");

    if(flag1&&flag2)
        printf("%d\n",maxFemale->grade-minMale->grade);
    else
        printf("NA\n");


    return 0;
}
