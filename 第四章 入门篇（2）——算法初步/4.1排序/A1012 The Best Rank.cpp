#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct student
{
    int index;//序号
    char id[7];
    int grade[4];
}student;

char course[4]={'A','C','M','E'};
int now;

bool cmp(student s1,student s2)
{
    return s1.grade[now]>s2.grade[now];
}

int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    //n个学生
    student studentsOfSort[n];
    student students[n];
    //n个学生四个排名
    int rankOfAll[n][4];

    char id[7];
    int a,c,m,e;
    for(int i=0;i<n;i++)
    {
        scanf("%s",id);
        scanf("%d %d %d",&c,&m,&e);
        a=round((c+m+e)/3.0)+0.5;

        students[i].index=i;
        strcpy(students[i].id,id);
        students[i].grade[0]=a;
        students[i].grade[1]=c;
        students[i].grade[2]=m;
        students[i].grade[3]=e;

        studentsOfSort[i].index=i;
        strcpy(studentsOfSort[i].id,id);
        studentsOfSort[i].grade[0]=a;
        studentsOfSort[i].grade[1]=c;
        studentsOfSort[i].grade[2]=m;
        studentsOfSort[i].grade[3]=e;
    }
    //四类排序
    for(now=0;now<4;now++)
    {
        sort(studentsOfSort,studentsOfSort+n,cmp);
        int r=1;
        for(int i=0;i<n;i++)
        {
            if(i>0&&studentsOfSort[i].grade[now]!=studentsOfSort[i-1].grade[now])
                r = i+1;
            rankOfAll[studentsOfSort[i].index][now]=r;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",rankOfAll[i][j]);
        }
        printf("\n");
    }

    int i,j,k;
    for(i=0;i<t;i++)
    {
        scanf("%s",id);
        for(j=0;j<n;j++)
        {
            if(strcmp(students[j].id,id)==0)
                break;
        }
        if(j==n)
            printf("N/A\n");
        else
        {
            int method=0;
            for(k=0;k<4;k++)
            {
                if(rankOfAll[j][k]<rankOfAll[j][method])
                    method=k;
            }
            printf("%d %c\n",rankOfAll[j][method],course[method]);
        }
    }


    return 0;
}

/*超时
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef struct student
{
    char id[6];
    int C,M,E,A;
    int rank;

    bool operator == (const student &stu)
    {
        return strcmp(this->id,stu.id)==0;
    }
} student;

bool cmpOfA(student s1,student s2)
{
    if(s1.A!=s2.A)
        return s1.A>s2.A;
    return strcmp(s1.id,s2.id)<0;
}

bool cmpOfC(student s1,student s2)
{
    if(s1.C!=s2.C)
        return s1.C>s2.C;
    return strcmp(s1.id,s2.id)<0;
}

bool cmpOfM(student s1,student s2)
{
    if(s1.M!=s2.M)
        return s1.M>s2.M;
    return strcmp(s1.id,s2.id)<0;
}

bool cmpOfE(student s1,student s2)
{
    if(s1.E!=s2.E)
        return s1.E>s2.E;
    return strcmp(s1.id,s2.id)<0;
}

int main()
{
    int n,t;
    cin>>n>>t;

    int i;
    char id[7];
    int C,M,E,A;
    vector<student> studentsOfA;
    vector<student> studentsOfC;
    vector<student> studentsOfM;
    vector<student> studentsOfE;
    for(i=0; i<n; i++)
    {
        scanf("%s",id);
        scanf("%d %d %d",&C,&M,&E);
        A=(C+M+E)/3;

        student stu;
        strcpy(stu.id,id);
        stu.C=C;
        stu.M=M;
        stu.E=E;
        stu.A=A;

        studentsOfA.push_back(stu);
        studentsOfC.push_back(stu);
        studentsOfM.push_back(stu);
        studentsOfE.push_back(stu);
    }
    n=studentsOfA.size();
    sort(studentsOfA.begin(),studentsOfA.end(),cmpOfA);
    int r=1;
    for(i=0; i<n; i++)
    {
        if(i>0&&studentsOfA[i].A!=studentsOfA[i-1].A)
            r = i+1;
        studentsOfA[i].rank=r;
    }

    sort(studentsOfC.begin(),studentsOfC.end(),cmpOfC);
    r=1;
    for(i=0; i<n; i++)
    {
        if(i>0&&studentsOfC[i].A!=studentsOfC[i-1].A)
            r = i+1;
        studentsOfC[i].rank=r;
    }

    sort(studentsOfM.begin(),studentsOfM.end(),cmpOfM);
    r=1;
    for(i=0; i<n; i++)
    {
        if(i>0&&studentsOfM[i].A!=studentsOfM[i-1].A)
            r = i+1;
        studentsOfM[i].rank=r;
    }

    sort(studentsOfE.begin(),studentsOfE.end(),cmpOfE);
    r=1;
    for(i=0; i<n; i++)
    {
        if(i>0&&studentsOfE[i].A!=studentsOfE[i-1].A)
            r = i+1;
        studentsOfE[i].rank=r;
    }

    vector<student>::iterator p;
    for(i=0; i<t; i++)
    {
        scanf("%s",id);
        student stu;
        strcpy(stu.id,id);
        p=find(studentsOfA.begin(),studentsOfA.end(),stu);
        if(p==studentsOfA.end())
        {
            printf("N/A\n");
            continue;
        }
        int min=p->rank;
        char method='A';
        p=find(studentsOfC.begin(),studentsOfC.end(),stu);
        if(p->rank<min)
        {
            min=p->rank;
            method='C';
        }

        p=find(studentsOfM.begin(),studentsOfM.end(),stu);
        if(p->rank<min)
        {
            min=p->rank;
            method='M';
        }

        p=find(studentsOfE.begin(),studentsOfE.end(),stu);
        if(p->rank<min)
        {
            min=p->rank;
            method='E';
        }
        printf("%d %c\n",min,method);
    }

    return 0;
}*/
