#include <stdio.h>

int a[101]= {0};

int gcd(int m,int n)
{
    int temp;
    while(n!=0)
    {
        temp=n;
        n=m%n;
        m=temp;
    }
    return m;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j,p;
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    m=m%n;
    int pre,last;
    int t=gcd(n,m);
    for(i=0; i<t; i++)
    {
        p=i;
        pre = a[p];
        for(j=1; j<=n/t; j++)
        {
            p=(p+m)%n;
            last = a[p];

            a[p] = pre;
            pre = last;
        }
    }
    for(i=0; i<n-1; i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[i]);
}
