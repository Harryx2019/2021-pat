#include <cstdio>
#include <cmath>

/*排列数-回溯法 解决n皇后问题*/

using namespace std;
//总共合法的方案数
int count=0;

const int maxn = 11;
int n,P[maxn],hashTable[maxn]={false};

void generateP(int index)
{
    if(index == n+1)
    {
        count++;
        for(int i=1;i<=n;i++)
            printf("%d ",P[i]);
        printf("\n");
        return;
    }
    //第x行
    for(int x=1;x<=n;x++)
    {
        if(hashTable[x]==false)
        {
            bool flag = true;
            //剪枝-回溯
            for(int pre=1;pre<index;pre++)
            {
                if(abs(index-pre)==abs(x-P[pre]))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                P[index]=x;
                hashTable[x]=true;
                generateP(index+1);
                hashTable[x]=false;
            }
        }
    }
}

int main()
{
    n = 8;
    generateP(1);
    printf("%d\n",count);
    return 0;
}
