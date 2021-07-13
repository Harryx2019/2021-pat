#include <stdio.h>

long long changeToKnut(long long Galleon,int Sickle,int Knut)
{
    long long ans = (Galleon*17+Sickle)*29+Knut;
    return ans;
}

int main()
{
    int Galleon1,Sickle1,Knut1;
    int Galleon2,Sickle2,Knut2;

    scanf("%d.%d.%d",&Galleon1,&Sickle1,&Knut1);
    scanf("%d.%d.%d",&Galleon2,&Sickle2,&Knut2);

    long long k1,k2;
    //18分答案
    k1 = changeToKnut(Galleon1,Sickle1,Knut1);
    k2 = changeToKnut(Galleon2,Sickle2,Knut2);

    long long Knut = k1 + k2;
    int Sickle = Knut/29;
    Knut = Knut%29;

    int Galleon = Sickle/17;
    Sickle = Sickle%17;
    printf("%d.%d.%lld\n",Galleon,Sickle,Knut);

    return 0;
}
