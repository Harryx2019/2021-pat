#include <stdio.h>

int main()
{
    long long a = 9223372036854775807, b = -9223372036854775808;
    printf("%lld\n",b-1);

    /*long long a,b,c;
    int t,i=1;
    scanf("%d",&t);
    while(i<=t){
        scanf("%lld %lld %lld",&a,&b,&c);
        long long res = a+b;
        bool flag;
        if(a>0&&b>0&&res<0)
            flag = true;
        else if(a<0&&b<0&&res>=0)
            flag = false;
        else if(res>c)
            flag = true;
        else
            flag = false;
        if(flag)
            printf("Case #%d: true\n",i);
        else
            printf("Case #%d: false\n",i);
        i++;
    }*/

    return 0;
}
