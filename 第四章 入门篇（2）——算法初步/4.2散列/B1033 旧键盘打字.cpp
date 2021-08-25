#include <iostream>
#include <string>
using namespace std;

int main()
{
    int hashTable[130]= {0};
    int flag=0;//上档键

    string str1;
    cin>>str1;
    string str2;
    cin>>str2;

    int len=str1.size();
    int i;
    for(i=0; i<len; i++)
    {
        char ch=str1[i];
        if(ch=='+')
            flag=1;
        hashTable[ch]=1;
        if(ch>='A'&&ch<='Z')
        {
            ch='a'+(ch-'A');
            hashTable[ch]=1;
        }
    }

    len=str2.size();
    for(i=0; i<len; i++)
    {
        char ch=str2[i];
        if(flag&&ch>='A'&&ch<='Z')
            continue;
        if(hashTable[ch]==0)
            printf("%c",ch);
    }
    printf("\n");

    return 0;
}
