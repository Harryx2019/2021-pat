#include <iostream>
#include <string>

using namespace std;

long long inf = (1LL << 63)-1;

long long numberOfDecimal(string n,long long radix,long long max)
{
    long long result=0;
    int len=n.size();
    char ch;
    for(int i=0;i<len;i++)
    {
        ch=n[i];
        if(ch>='0'&&ch<='9')
            result=result*radix+(ch-'0');
        if(ch>='a'&&ch<='z')
            result=result*radix+(ch-'a'+10);
        if(result<0||result>max)
            return -1;
    }
    return result;
}

long long binarySearch(long long n,string x,long long low,long long high)
{
    //寻找k进制数x，使得x=n
    long long k=-1;
    /*基数上届为int最大值*/
    long long mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        long long tmp = numberOfDecimal(x,mid,n);
        if(tmp==n)
            return mid;
        else if(tmp>n||tmp<0)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int findLargestDigit(string n)
{
    int ans=-1,tmp;
    int len=n.size();
    char ch;
    for(int i=0;i<len;i++)
    {
        ch=n[i];
        if(ch>='0'&&ch<='9')
            tmp=ch-'0';
        if(ch>='a'&&ch<='z')
            tmp=ch-'a'+10;
        if(tmp>ans)
            ans=tmp;
    }
    return ans+1;
}

int main()
{
    string n1,n2;
    int tag,radix;

    cin>>n1;
    cin>>n2;
    scanf("%d %d",&tag,&radix);

    string x;
    long long n;
    if(tag==1)
    {
        x=n2;
        n=numberOfDecimal(n1,radix,inf);
    }
    else
    {
        x=n1;
        n=numberOfDecimal(n2,radix,inf);
    }

    long long k=-1;
    long long low=findLargestDigit(x);
    long long high=max(low,n)+1;
    k=binarySearch(n,x,low,high);

    if(k==-1)
        printf("Impossible");
    else
        printf("%d",k);

    return 0;
}
