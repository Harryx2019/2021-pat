#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*n);
    int *dif = (int *)malloc(sizeof(int)*n);
    dif[0]=0;

    int i;
    int sum=0;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        //解决超时
        dif[i]=sum;//dif[i]表示顺时针方向从0到i+1的距离
    }

    int m;
    scanf("%d",&m);

    int start,end;
    int distance;
    while(m)
    {
        //distance=0; 优化
        scanf("%d %d",&start,&end);
        if(start>end)
            swap(start,end);

        distance = dif[end-1] - dif[start-1];
        printf("%d\n",min(distance,sum-distance));

        m--;
    }

    return 0;
}
