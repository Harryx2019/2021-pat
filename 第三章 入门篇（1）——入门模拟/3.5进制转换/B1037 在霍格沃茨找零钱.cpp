#include <stdio.h>

int changeToKnut(int Galleon,int Sickle,int Knut)
{
    return (Galleon*17+Sickle)*29+Knut;
}

int main()
{
    int Galleon1,Sickle1,Knut1;
    int Galleon2,Sickle2,Knut2;

    scanf("%d.%d.%d",&Galleon1,&Sickle1,&Knut1);
    scanf("%d.%d.%d",&Galleon2,&Sickle2,&Knut2);

    Knut1 = changeToKnut(Galleon1,Sickle1,Knut1);
    Knut2 = changeToKnut(Galleon2,Sickle2,Knut2);

    int Knut = Knut2 - Knut1;
    if(Knut<0)
    {
        printf("-");
        Knut = -Knut;
    }
    int Sickle = Knut/29;
    Knut = Knut%29;
    int Galleon = Sickle/17;
    Sickle = Sickle%17;
    printf("%d.%d.%d\n",Galleon,Sickle,Knut);

    return 0;
}
