#include <cstdio>
#include <algorithm>
using namespace std;

void merge(int a[],int L1,int R1,int L2,int R2)
{
    int i=L1,j=L2;
    int temp[R2-L1+1],index=0;
    while(i<=R1&&j<=R2)
    {
        if(a[i]<=a[j])
            temp[index++]=a[i++];
        else
            temp[index++]=a[j++];
    }
    while(i<=R1)
        temp[index++]=a[i++];
    while(j<=R2)
        temp[index++]=a[j++];
    for(i=0; i<index; i++)
        a[L1+i]=temp[i];
}

int main()
{
    int n;
    scanf("%d",&n);

    int a[n+1],temp[n+1],b[n+1];
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        temp[i]=a[i];
    }
    for(int i=1; i<=n; i++)
        scanf("%d",&b[i]);

    int i,j,k;

    int flag=0;
    //插入排序
    for(i=1; i<=n; i++)
    {
        for(j=i; j>1; j--)
        {
            if(temp[j]<temp[j-1])
            {
                int t=temp[j];
                temp[j]=temp[j-1];
                temp[j-1]=t;
            }
            else
                break;
        }
        if(flag)
        {
            printf("Insertion Sort\n");
            printf("%d",temp[1]);
            for(int k=2; k<=n; k++)
                printf(" %d",temp[k]);
            break;
        }
        for(k=1; k<=n; k++)
        {
            if(b[k]!=temp[k])
                break;
        }
        if(k>n)
            flag=1;
    }

    if(!flag)
    {
        //归并排序
        int flag2=0;
        printf("Merge Sort\n");
        for(i=1; i<=n; i++)
            temp[i]=a[i];

        for(int step=2; step/2<=n; step*=2)
        {
            for(i=1; i<=n; i+=step)
            {
                //int mid=i+step/2-1;
                //if(mid+1<=n)
                //    merge(temp,i,mid,mid+1,min(i+step-1,n));
                sort(temp+i,temp+min(i+step,n+1));
            }
            if(flag2)
            {
                printf("%d",temp[1]);
                for(i=2; i<=n; i++)
                    printf(" %d",temp[i]);
                break;
            }
            for(i=1; i<=n; i++)
            {
                if(b[i]!=temp[i])
                    break;
            }
            if(i>n)
                flag2=1;
        }
    }

    return 0;
}
