#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int hashTable[101]={0};
    int i;
    int score;
    for(i=0;i<n;i++)
    {
        scanf("%d",&score);
        hashTable[score]++;
    }

    int k;
    scanf("%d",&k);

    scanf("%d",&score);
    printf("%d",hashTable[score]);
    for(i=1;i<k;i++)
    {
        scanf("%d",&score);
        printf(" %d",hashTable[score]);
    }
    return 0;
}
