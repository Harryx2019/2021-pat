#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char str[81];
    cin.getline(str,81);

    char result[40][80];

    int len = strlen(str);
    int j=0,k=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]!=' '){
            result[j][k]=str[i];
            k++;
        }
        else{
            result[j][k]='\0';
            j++;
            k=0;
        }
    }
    result[j][k]='\0';

    for(int i=j;i>0;i--)
        printf("%s ",result[i]);
    printf("%s\n",result[0]);

    return 0;
}
