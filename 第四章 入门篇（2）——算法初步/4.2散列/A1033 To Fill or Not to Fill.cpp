#include <iostream>
#include <algorithm>

using namespace std;

const int INF=100000000;

typedef struct station
{
    double price;
    double distance;
} station;

bool cmp(station s1,station s2)
{
    return s1.distance<s2.distance;
}

int main()
{
    double Cmax,D,Davg;
    int N;
    scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&N);

    station stations[N+1];
    int i;
    for(i=0; i<N; i++)
        scanf("%lf %lf",&stations[i].price,&stations[i].distance);
    //设置终点为距离为D，单价为0的站点
    stations[N].price=0;
    stations[N].distance=D;

    sort(stations,stations+N+1,cmp);

    if(stations[0].distance!=0)
    {
        printf("The maximum travel distance = 0.00\n");
    }
    else
    {
        int now=0;
        //当前油量，加满油能到达的最远距离
        double nowTank=0,MAXDistance=Cmax*Davg;
        //油费
        double ans=0;

        while(now<N)
        {
            //从当前站点选择能到达的站点中第一个小于当前单价的站点
            //若没有则选择最小单价的站点
            int k=-1;
            double minPrice = INF;
            for(i=now+1;i<=N&&stations[i].distance-stations[now].distance<=MAXDistance;i++)
            {
                if(stations[i].price<minPrice)
                {
                    k=i;
                    minPrice=stations[i].price;
                    if(minPrice<stations[now].price)
                        break;
                }
            }
            if(k==-1)
                break;//满油状态下无法找到站点，结束循环
            double need = (stations[k].distance - stations[now].distance)/Davg;
            if(minPrice<stations[now].price)
            {
                //找到第一个小于当前站点单价的站点，只买足够到该站点的油
                if(nowTank<need)
                {
                    ans+=(need-nowTank)*stations[now].price;
                    nowTank = 0;
                }
                else{
                    nowTank-=need;
                }
            }
            else
            {
                //在当前站点加满油到下一个最小单价油的站点
                ans+=(Cmax-nowTank)*stations[now].price;
                nowTank=Cmax-need;
            }
            now=k;
        }
        if(now==N)
            printf("%.2f\n",ans);
        else
            printf("The maximum travel distance = %.2f\n",stations[now].distance+MAXDistance);
    }


    return 0;
}
