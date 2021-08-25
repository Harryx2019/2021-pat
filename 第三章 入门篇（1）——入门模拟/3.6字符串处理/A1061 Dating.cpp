#include <string>
#include <iostream>
using namespace std;

string day[7]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
    string strs[4];
    int i;
    for(i=0; i<4; i++)
        cin>>strs[i];

    for(i=0; i<strs[0].length()&&i<strs[1].length(); i++)
    {
        if(strs[0][i]==strs[1][i]&&strs[0][i]>='A'&&strs[0][i]<='G')
        {
            cout<<day[strs[0][i]-'A']<<" ";
            break;
        }
    }

    for(i++; i<strs[0].length()&&i<strs[1].length(); i++)
    {
        if(strs[0][i]==strs[1][i])
        {
            if(strs[0][i]>='0'&&strs[0][i]<='9')
            {
                printf("%02d:",strs[0][i]-'0');
                break;
            }
            if(strs[0][i]>='A'&&strs[0][i]<='N')
            {
                printf("%d:",strs[0][i]-'A'+10);
                break;
            }
        }
    }

    for(i=0; i<strs[2].length()&&i<strs[3].length(); i++)
    {
        if(strs[2][i]==strs[3][i])
        {
            if((strs[2][i]>='a'&&strs[2][i]<='z')||(strs[2][i]>='A'&&strs[2][i]<='Z'))
            {
                printf("%02d\n",i);
                break;
            }
        }
    }
    return 0;
}
