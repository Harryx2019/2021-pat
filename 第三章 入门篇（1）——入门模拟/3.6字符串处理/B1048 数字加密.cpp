#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //此题在第一遍未得全分：当b的长度小于a的长度时，
    //依然需要按照每位为0进行计算，并非简单将a进行拼接
    string a,b;
    cin>>a;
    cin>>b;

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    string c;

    int n1 = a.length();
    int n2 = b.length();
    int n = n1>n2?n1:n2;

    int i;
    for(i=0; i<n; i++)
    {
        int numA = i<n1?a[i]-'0':0;
        int numB = i<n2?b[i]-'0':0;
        if(i%2!=0)
        {
            int f = numB-numA;
            if(f<0)
                f+=10;
            char ch = f+'0';
            c+=ch;
        }
        else
        {
            int f = numA+numB;
            f = f%13;
            if(f<10)
            {
                char ch = f+'0';
                c+=ch;
            }
            else if(f==10)
                c+='J';
            else if(f==11)
                c+='Q';
            else if(f==12)
                c+='K';
        }
    }
    reverse(c.begin(),c.end());
    cout<<c<<endl;

    return 0;

}
