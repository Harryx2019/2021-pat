#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct record
{
    string customer_name;
    int month,day,hour,minute;
    string label;
} record;

bool cmp(record r1,record r2)
{
    if(r1.customer_name!=r2.customer_name)
        return r1.customer_name<r2.customer_name;
    else if(r1.day!=r2.day)
        return r1.day<r2.day;
    else if(r1.hour!=r2.hour)
        return r1.hour<r2.hour;
    else if(r1.minute!=r2.minute)
        return r1.minute<r2.minute;
    else
        return r1.label=="on-line";
}

int main()
{
    int charge[24];
    int i,j;
    for(i=0; i<24; i++)
        scanf("%d",&charge[i]);

    int n;
    scanf("%d",&n);

    record records[n];

    string customer_name;
    int month,day,hour,minute;
    string label;
    for(i=0; i<n; i++)
    {
        cin>>customer_name;
        scanf("%d:%d:%d:%d",&month,&day,&hour,&minute);
        cin>>label;

        records[i].customer_name=customer_name;
        records[i].month=month;
        records[i].day=day;
        records[i].hour=hour;
        records[i].minute=minute;
        records[i].label=label;
    }

    sort(records,records+n,cmp);

    vector<vector<record>> recordsOfCustomers;

    i=0;
    while(i<n)
    {
        customer_name = records[i].customer_name;
        vector<record> recordsOfCustomer;
        while(records[i].customer_name==customer_name)
            recordsOfCustomer.push_back(records[i++]);

        recordsOfCustomers.push_back(recordsOfCustomer);
    }
    int customerNum = 0;
    if(recordsOfCustomers.size()!=0)
        customerNum = recordsOfCustomers.size();
    for(i=0; i<customerNum; i++)
    {
        //flag标志 该用户是否有有效通话记录
        int flag=0;
        float total=0;
        int recordsNum=recordsOfCustomers[i].size();
        for(j=0; j<recordsNum; j++)
        {
            if(recordsOfCustomers[i][j].label == "off-line")
                continue;
            if(j<recordsNum-1)
            {
                if(recordsOfCustomers[i][j+1].label != "off-line")
                    continue;
                else
                {
                    //配对成功
                    if(!flag)
                    {
                        //该用户是否有效通话记录 修改flag=1
                        cout<<recordsOfCustomers[i][0].customer_name<<" ";
                        printf("%02d\n",month);
                        flag=1;
                    }
                    record record1=recordsOfCustomers[i][j];
                    record record2=recordsOfCustomers[i][j+1];
                    int day1=record1.day,hour1=record1.hour,minute1=record1.minute;
                    int day2=record2.day,hour2=record2.hour,minute2=record2.minute;
                    printf("%02d:%02d:%02d ",day1,hour1,minute1);
                    printf("%02d:%02d:%02d ",day2,hour2,minute2);


                    int minute;
                    int sumMinute=0;
                    float amount=0;
                    while(day1<day2)
                    {
                        while(hour1<24)
                        {
                            minute=60-minute1;
                            sumMinute+=minute;
                            amount+=charge[hour1]*minute;

                            minute1=0;
                            hour1++;
                        }
                        day1++;
                        hour1=0;
                    }
                    while(hour1<hour2)
                    {
                        minute=60-minute1;
                        sumMinute+=minute;
                        amount+=charge[hour1]*minute;

                        minute1=0;
                        hour1++;
                    }
                    minute=minute2-minute1;
                    sumMinute+=minute;
                    amount+=charge[hour1]*minute;

                    amount=amount/100;
                    total+=amount;

                    printf("%d $%.2f\n",sumMinute,amount);
                }
            }
        }
        //该用户是否有效通话记录 才输出总金额
        if(flag)
            printf("Total amount: $%.2f\n",total);
    }

    return 0;
}
