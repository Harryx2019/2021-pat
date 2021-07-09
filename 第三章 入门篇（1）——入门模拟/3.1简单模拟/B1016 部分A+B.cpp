#include <stdio.h>
//#include <limits.h>
int main()
{
    long long A,B,Pa=0,Pb=0;
    int Da,Db;
    scanf("%lld %d %lld %d",&A,&Da,&B,&Db);
    while(A){
        if(A%10==Da){
            Pa = Pa*10+Da;
        }
        A/=10;
    }
    while(B){
        if(B%10==Db){
            Pb = Pb*10+Db;
        }
        B/=10;
    }
    printf("%lld\n",Pa+Pb);
    return 0;
}
