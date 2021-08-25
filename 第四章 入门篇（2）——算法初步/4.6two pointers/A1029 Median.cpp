#include <stdio.h>

const int INF = 0x7ffffff;

int main()
{
    int n1,n2;
    scanf("%d",&n1);
    int a[n1+1];
    for(int i=0; i<n1; i++)
        scanf("%d",&a[i]);

    scanf("%d",&n2);
    int b[n2+1];
    for(int i=0; i<n2; i++)
        scanf("%d",&b[i]);
    a[n1]=b[n2]=INF;

    //long long c[n1+n2];
    int i=0,j=0,k=0,mid=(n1+n2-1)/2;
    //long long k=0,mid=(n1+n2-1)/2;
    while(k<mid)
    {
        if(a[i]<b[j])
            i++;
        else
            j++;
        k++;
    }
    if(a[i]<b[j])
        printf("%d",a[i]);
    else
        printf("%d",b[j]);
    /*if(k!=mid)
    {
        while(i<n1)
        {
            c[k]=a[i++];
            if(k==mid)
            {
                printf("%lld",c[k]);
                break;
            }
            k++;
        }
        while(j<n2)
        {
            c[k]=b[j++];
            if(k==mid)
            {
                printf("%lld",c[k]);
                break;
            }
            k++;
        }
    }*/


    return 0;
}
