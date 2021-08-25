#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string userName[n];
    string password[n];

    int modified[n]= {0};
    int i,j,k=0;
    int num=0;
    for(i=0; i<n; i++)
    {
        cin>>userName[i];
        cin>>password[i];

        int flag=0;
        int length = password[i].length();
        for(j=0; j<length; j++)
        {
            char ch=password[i][j];
            if(!flag&&(ch=='1'||ch=='l'||ch=='0'||ch=='O'))
            {
                flag=1;
                num++;
                modified[k]=i;
                k++;
            }
            switch(ch)
            {
            case '1':
                password[i][j]='@';
                break;
            case 'l':
                password[i][j]='L';
                break;
            case '0':
                password[i][j]='%';
                break;
            case 'O':
                password[i][j]='o';
                break;
            }
        }
    }

    if(num==0)
    {
        if(n>1)
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
        else
            cout<<"There is "<<n<<" account and no account is modified"<<endl;
    }
    else
    {
        cout<<num<<endl;
        for(i=0;i<num;i++)
            cout<<userName[modified[i]]<<" "<<password[modified[i]]<<endl;
    }

    return 0;

}
