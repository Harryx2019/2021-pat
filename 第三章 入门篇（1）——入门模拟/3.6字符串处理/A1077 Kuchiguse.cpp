#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    getchar();
    char words[n][260];
    int len[n]= {0};

    int i,j;
    int maxLen = 0;
    for(i=0; i<n; i++)
    {
        cin.getline(words[i],260);
        len[i]=strlen(words[i]);
        if(len[i]>maxLen)
            maxLen = len[i];
    }

    string Kuchiguse;
    int flag=0;
    for(i=0; i<maxLen; i++)
    {
        char ch = words[0][len[0]-1-i];
        for(j=1; j<n; j++)
        {
            if(words[j][len[j]-1-i]!=ch)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
        else
            Kuchiguse+=ch;
    }

    if(!Kuchiguse.length())
        cout<<"nai"<<endl;
    else
    {
        reverse(Kuchiguse.begin(),Kuchiguse.end());
        cout<<Kuchiguse<<endl;
    }


    return 0;
}
