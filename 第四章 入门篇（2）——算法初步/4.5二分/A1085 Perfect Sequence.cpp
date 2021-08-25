/*双指针法*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,p;
    scanf("%d %d",&n,&p);

    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);

    int i=0,j=0,count=0;
    long long x;
    while(i<n&&j<n)
    {
        while(j<n&&a[j]<=(long long)a[i]*p)
        {
            count=max(count,j-i+1);
            j++;
        }
        i++;
    }
    printf("%d",count);

    return 0;
}

/*#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int numbers[],int n,int i,long long x)
{
    if(numbers[n-1]<=x)
        return n-1;
    int left=i+1,right=n-1,mid;
    while(left<right)
    {
        mid = left + (right-left)/2;
        if(numbers[mid]<=x)
            left=mid+1;
        else
            right=mid;
    }
    return left;
}

int main()
{
    int n,p;
    scanf("%d %d",&n,&p);

    int numbers[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&numbers[i]);
    sort(numbers,numbers+n);

    int max=1;
    for(i=0;i<n;i++)
    {
        long long x = numbers[i] * p;
        int j=binarySearch(numbers,n,i,x);
        if(j-i>max)
            max=j-i;
    }
    printf("%d\n",max);

    return 0;
}*/
