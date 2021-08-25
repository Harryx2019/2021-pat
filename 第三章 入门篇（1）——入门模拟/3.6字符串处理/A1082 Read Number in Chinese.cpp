#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

char number[10][5]= {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char unit[3][5]= {"Qian","Bai","Shi"};

int main()
{
    int n;
    scanf("%d",&n);

    if(n<0)
    {
        n=-n;
        printf("Fu ");
    }

    //numPart[0]:最后四位
    //numPart[1]:中间四位
    //numPart[2]:最高位
    int numPart[3]= {0};
    int i=0;
    while(n!=0)
    {
        numPart[i]=n%10000;
        i++;
        n=n/10000;
    }

    if(numPart[2]!=0)
        printf("%s Yi",number[numPart[2]]);

    //cout<<endl;

    string numberOfChinese[2];
    int numberOfPart[2][4]= {0};
    for(i=0; i<2; i++)
    {
        n=numPart[i];
        int j=0;
        while(n!=0)
        {
            numberOfPart[i][j]=n%10;
            n=n/10;
            j++;
        }

        int flag=0,flagOfZero=0;
        for(j=3; j>0; j--)
        {
            if(numberOfPart[i][j]!=0)
            {
                if(!flag)
                    flag=1;
                else
                    numberOfChinese[i]+=" ";
                numberOfChinese[i]+=number[numberOfPart[i][j]];
                numberOfChinese[i]+=" ";
                numberOfChinese[i]+=unit[3-j];
            }
            else
            {
                if(flag&&!flagOfZero)
                {
                    for(int k=j-1; k>=0; k--)
                    {
                        if(numberOfPart[i][k]!=0)
                        {
                            numberOfChinese[i]+=" ";
                            numberOfChinese[i]+="ling";
                            flagOfZero = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(numberOfPart[i][j]!=0)
        {
            if(flag)
                numberOfChinese[i]+=" ";
            numberOfChinese[i]+=number[numberOfPart[i][j]];
        }
        //cout<<numberOfChinese[i]<<endl;
    }

    //增加零的中文输出
    if(numPart[2]!=0)
    {
        if(numPart[1]!=0)
        {
            cout<<" ";
            for(int j=3; j>=0; j--)
            {
                if(numberOfPart[1][j]==0)
                {
                    cout<<"ling";
                    cout<<" ";
                    break;
                }
                else
                    break;
            }
            cout<<numberOfChinese[1];
            cout<<" "<<"Wan";
            if(numPart[0]!=0)
            {
                cout<<" ";
                for(int j=3; j>=0; j--)
                {
                    if(numberOfPart[0][j]==0)
                    {
                        cout<<"ling";
                        cout<<" ";
                        break;
                    }
                    else
                        break;
                }
                cout<<numberOfChinese[0];
            }
        }
        else
        {
            if(numPart[0]!=0)
            {
                cout<<" ";
                cout<<"ling";
                cout<<" ";
                cout<<numberOfChinese[0];
            }
        }
    }
    else
    {
        if(numPart[1]!=0)
        {
            cout<<numberOfChinese[1];
            cout<<" "<<"Wan";
            if(numPart[0]!=0)
            {
                cout<<" ";
                for(int j=3; j>=0; j--)
                {
                    if(numberOfPart[0][j]==0)
                    {
                        cout<<"ling";
                        cout<<" ";
                        break;
                    }
                    else
                        break;
                }
                cout<<numberOfChinese[0];
            }
        }
        else
        {
            if(numPart[0]!=0)
                cout<<numberOfChinese[0];
            else
                cout<<"ling";
        }
    }

    return 0;
}
