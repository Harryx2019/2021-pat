#include <cstdio>
#include <algorithm>
using namespace std;

bool cmpDown(int a,int b)
{
    return a>b;
}

void to_array(int n,int num[])
{
    for(int i=0;i<4;i++)
    {
        num[i]=n%10;
        n/=10;
    }
}

int to_number(int num[])
{
    int sum=0;
    for(int i=0;i<4;i++)
    {
        sum=sum*10+num[i];
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    int MAX,MIN;
    int num[5];
    while(1)
    {
        to_array(n,num);
        sort(num,num+4);
        MIN=to_number(num);
        sort(num,num+4,cmpDown);
        MAX=to_number(num);
        n=MAX-MIN;
        printf("%04d - %04d = %04d\n",MAX,MIN,n);
        if(n==0||n==6174)
            break;
    }
    return 0;
}

/*18分答案
int main()
{
    int n;
    scanf("%d",&n);
    int temp=n;
    int num1[5],num2[5];

    int len=0;
    int num;
    while(temp!=0)
    {
        num=temp%10;
        num1[len]=num;
        num2[len]=num;
        temp/=10;
        len++;
    }

    int i,flag=1;
    num=num1[0];
    for(i=1; i<len; i++)
    {
        if(num1[i]==num)
            flag++;
    }
    if(flag==4)
        printf("%04d - %04d = 0000",n,n);
    else
    {
        flag=0;
        do
        {
            sort(num1,num1+4,cmpDown);
            sort(num2,num2+4);
            int n1=0,n2=0;
            for(i=0; i<4; i++)
            {
                n1=n1*10+num1[i];
                n2=n2*10+num2[i];
            }
            n=n1-n2;
            temp=n;
            if(!flag)
            {
                printf("%04d - %04d = %04d",n1,n2,n);
                flag=1;
            }
            else
                printf("\n%04d - %04d = %04d",n1,n2,n);
            len=0;
            while(temp!=0)
            {
                num=temp%10;
                num1[len]=num;
                num2[len]=num;
                temp/=10;
                len++;
            }
        }
        while(n!=6174);
    }

    return 0;
}
*/
