#include <stdio.h>

const int INF = 0x3fffffff;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    int leftMax[n],rightMin[n];
    leftMax[0]=0;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>leftMax[i-1])
            leftMax[i]=a[i-1];
        else
            leftMax[i]=leftMax[i-1];
    }

    rightMin[n-1]=INF;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i+1]<rightMin[i+1])
            rightMin[i]=a[i+1];
        else
            rightMin[i]=rightMin[i+1];
    }

    int count=0,ans[n];
    for(int i=0;i<n;i++)
    {
        if(leftMax[i]<a[i]&&rightMin[i]>a[i])
        {
            ans[count]=a[i];
            count++;
        }
    }
    printf("%d\n",count);
    if(count>0)
    {
        printf("%d",ans[0]);
        for(int i=1;i<count;i++)
            printf(" %d",ans[i]);
    }
    else
        printf("\n");

    return 0;
}

/*暴力超时
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    int i,j,k;
    int count=0,ans[n];
    for(i=0; i<n; i++)
    {
        int flag=1;
        int pivot=a[i];
        for(j=0; j<i; j++)
        {
            if(a[j]>pivot)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            for(k=n-1; k>i; k--)
            {
                if(a[k]<pivot)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
        {
            ans[count]=pivot;
            count++;
        }
    }
    printf("%d\n",count);
    printf("%d",ans[0]);
    for(i=1;i<count;i++)
        printf(" %d",ans[i]);

    return 0;
}
*/
