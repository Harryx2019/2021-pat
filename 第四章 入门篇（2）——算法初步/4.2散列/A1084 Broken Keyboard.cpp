#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;

    char hashTableofCh[81];
    int hashTable[81]={0};
    int k=0;

    int i,j;
    int len=str1.size();
    for(i=0; i<len; i++)
    {
        char ch = str1[i];
        if(ch>='a'&&ch<='z')
            ch='A'+(ch-'a');
        if(k==0)
        {
            hashTableofCh[k]=ch;
            hashTable[k]=1;
            k++;
        }
        else
        {
            for(j=0; j<k; j++)
            {
                if(hashTableofCh[j]==ch)
                {
                    hashTable[j]++;
                    break;
                }
            }
            if(j==k)
            {
                hashTableofCh[k]=ch;
                hashTable[k]=1;
                k++;
            }
        }
    }

    len=str2.size();
    for(i=0; i<len; i++)
    {
        char ch = str2[i];
        if(ch>='a'&&ch<='z')
            ch='A'+(ch-'a');
        for(j=0; j<k; j++)
        {
            if(hashTableofCh[j]==ch)
            {
                hashTable[j]--;
                break;
            }
        }
    }

    for(i=0; i<k; i++)
    {
        if(hashTable[i]!=0)
            printf("%c",hashTableofCh[i]);
    }


    return 0;
}

/*2021.8.11考虑是否可以用map键值对*/
