#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;

    int flag1=0;//正负标志
    if(str[0]=='+')
        flag1=1;

    int i=1,num=0;
    string str_fra;
    while(str[i]!='E')
    {
        i++;
        num++;
    }

    str_fra=str.substr(1,num);

    i++;
    int flag2=0;//指数正负标志
    if(str[i]=='+')
        flag2=1;

    i++;
    string str_exp = str.substr(i,str.length()-i);

    int exp=0;
    for(i=0; i<str_exp.length(); i++)
        exp=exp*10+(str_exp[i]-'0');

    if(!flag2)
    {
        //小数点左移
        str_fra.erase(1,1);
        for(i=0; i<exp; i++)
            str_fra.insert(0,"0");
        str_fra.insert(1,".");
    }
    else
    {
        int fra_num = str_fra.length()-2;
        str_fra.erase(1,1);
        if(exp>=fra_num)
        {
            for(i=0; i<exp-fra_num; i++)
                str_fra+="0";
        }
        else
           str_fra.insert(1+exp,".");
    }

    if(!flag1)
        cout<<'-';
    cout<<str_fra<<endl;


    return 0;
}
