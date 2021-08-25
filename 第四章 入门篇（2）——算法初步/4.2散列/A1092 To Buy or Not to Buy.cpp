#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;

    int hashTable[130]= {0};
    int i;
    int len=str1.size();
    for(i=0; i<len; i++)
    {
        char ch=str1[i];
        hashTable[ch]++;
    }

    int flag=0;
    len=str2.size();
    for(i=0; i<len; i++)
    {
        char ch=str2[i];
        hashTable[ch]--;
        if(hashTable[ch]<0)
            flag=1;
    }

    int sum=0;
    if(flag)
    {
        printf("No ");
        for(i=0; i<130; i++)
        {
            if(hashTable[i]<0)
                sum+=hashTable[i];
        }
        printf("%d\n",-sum);
    }
    else
    {
        printf("Yes ");
        for(i=0; i<130; i++)
        {
            sum+=hashTable[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
