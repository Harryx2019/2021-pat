#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000007;

int main()
{
    string str;
    cin>>str;

    int n=str.size();
    int leftNumP[n]={0};

    int i;
    for(i=0;i<n;i++)
    {
        if(i>0)
            leftNumP[i]=leftNumP[i-1];
        if(str[i]=='P')
            leftNumP[i]++;
    }

    int ans=0;
    int rightNumT=0;
    for(i=n-1;i>=0;i--)
    {
        if(str[i]=='T')
            rightNumT++;
        else if(str[i]=='A')
            ans=(ans+leftNumP[i]*rightNumT)%MOD;
    }

    printf("%d",ans);
    return 0;
}
