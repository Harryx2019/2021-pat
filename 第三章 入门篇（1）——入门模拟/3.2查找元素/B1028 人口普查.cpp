//16分答案
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct peopleInfo
{
    char name[6];
    int year,month,day;
}peopleInfo;


bool Judge(int year,int month,int day)
{
    if(year>2014)
        return false;
    if(year==2014 && month>9)
        return false;
    if(year==2014 && month==9 && day>6)
        return false;
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);

    peopleInfo *peopleLink = (peopleInfo*)malloc(sizeof(peopleInfo)*n);

    char name[6];
    int year,month,day;
    int count = 0;
    int old;
    int max=-1,max_index=-1;
    int min=201,min_index=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",name);
        strcpy(peopleLink[i].name,name);
        scanf("%d/%d/%d",&year,&month,&day);
        peopleLink[i].year=year;
        peopleLink[i].month=month;
        peopleLink[i].day=day;
        if(Judge(year,month,day)){
            old = 2014 - year;
            if(month>9 || (month==9&&day>6))
                old--;
            if(month<9 || (month==9&&day<6))
                old++;
            if(old<=200)
            {
                count++;
                if(old>=max)
                {
                    max=old;
                    max_index = i;
                }
                if(old<=min)
                {
                    min=old;
                    min_index = i;
                }
            }
        }
    }

    if(count==0){
        printf("0\n");
    }
    else{
        printf("%d %s %s\n",count,peopleLink[max_index].name,peopleLink[min_index].name);
    }

    return 0;
}

//满分答案
#include<stdio.h>

int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	struct birth{
		char name[6];
		int y;
		int m;
		int d;
	}a,max,min;

	max.y=2014;max.m=9;max.d=7;
	min.y=1814;max.m=9;max.d=5;
	for(int i = 0;i<n;i++){
		scanf("%s %d/%d/%d",&a.name,&a.y,&a.m,&a.d);
		cnt++;
		if(a.y>2014||(a.y==2014&&a.m>9)||(a.y==2014&&a.m==9&&a.d>6)||a.y<1814||(a.y==1814&&a.m<9)||(a.y==1814&&a.m==9&&a.d<6)){
			cnt--;
			continue;
		}
		if(a.y<max.y||(a.y==max.y&&a.m<max.m)||(a.y==max.y&&a.m==max.m&&a.d<max.d)){
			max=a;
		}
		if(a.y>min.y||(a.y==min.y&&a.m>min.m)||(a.y==min.y&&a.m==min.m&&a.d>min.d)){
			min=a;
		}
	}
	printf("%d",cnt);
	if(cnt!=0){
		printf(" %s %s",max.name,min.name);
	}

	return 0;
 }


