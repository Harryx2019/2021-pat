#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int coins[n];
    for(int i=0;i<n;i++)
        scanf("%d",&coins[i]);
    sort(coins,coins+n);

    //双指针法
    int i=0,j=n-1;
    while(i<j)
    {
        if(coins[i]+coins[j]==m)
        {
            printf("%d %d",coins[i],coins[j]);
            break;
        }
        else if(coins[i]+coins[j]>m)
            j--;
        else
            i++;
    }
    if(i==j)
        printf("No Solution");

    return 0;
}
