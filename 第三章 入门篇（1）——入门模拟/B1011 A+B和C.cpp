#include <stdio.h>
//#include <limits.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i=1;
    while(i<=T){
        long long A,B,C;
        scanf("%lld %lld %lld",&A,&B,&C);
        if(A+B>C){
            printf("Case #%d: true\n",i);
        }else{
            printf("Case #%d: false\n",i);
        }
        i++;
    }
    return 0;
}
