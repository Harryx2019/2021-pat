#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date
{
    int hour,minute,second;
} date;

typedef struct personInfo
{
    char Id_number[16];
    date Sign_in_time;
    date Sign_out_time;
} personInfo,*personLink;

bool Earlier(date date1,date date2)
{
    if(date1.hour<date2.hour)
        return true;
    else if(date1.hour==date2.hour && date1.minute<date2.minute)
        return true;
    else if(date1.hour==date2.hour && date1.minute==date2.minute && date1.second<date2.second)
        return true;
    else
        return false;
}

bool Later(date date1,date date2)
{
    if(date1.hour>date2.hour)
        return true;
    else if(date1.hour==date2.hour && date1.minute>date2.minute)
        return true;
    else if(date1.hour==date2.hour && date1.minute==date2.minute && date1.second>date2.second)
        return true;
    else
        return false;
}

int main()
{
    int m;
    scanf("%d",&m);
    personLink persons = (personLink)malloc(sizeof(personInfo)*m);

    char Id_number[16];
    int hour,minute,second;
    for(int i=0; i<m; i++)
    {
        scanf("%s",Id_number);
        strcpy(persons[i].Id_number,Id_number);

        scanf("%d:%d:%d",&hour,&minute,&second);
        persons[i].Sign_in_time.hour = hour;
        persons[i].Sign_in_time.minute = minute;
        persons[i].Sign_in_time.second = second;

        scanf("%d:%d:%d",&hour,&minute,&second);
        persons[i].Sign_out_time.hour = hour;
        persons[i].Sign_out_time.minute = minute;
        persons[i].Sign_out_time.second = second;
    }

    //寻找最早Sign_out_time
    date Min_sign_in_time = persons[0].Sign_in_time;
    int min_index = 0;

    date Max_sign_out_time = persons[0].Sign_out_time;
    int max_index = 0;
    for(int i=1; i<m; i++)
    {
        if(Earlier(persons[i].Sign_in_time,Min_sign_in_time))
        {
            min_index = i;
            Min_sign_in_time = persons[i].Sign_in_time;
        }
        if(Later(persons[i].Sign_out_time,Max_sign_out_time))
        {
            max_index = i;
            Max_sign_out_time = persons[i].Sign_out_time;
        }
    }

    printf("%s %s\n",persons[min_index].Id_number,persons[max_index].Id_number);

    return 0;
}
