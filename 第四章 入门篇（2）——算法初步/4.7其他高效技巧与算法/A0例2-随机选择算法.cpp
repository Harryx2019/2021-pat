/*求一个数列第2/n大的数*/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
const int maxn=100010;
int A[maxn],n;

//选取随机主元，对区间[left,right]进行划分
int randPartition(int A[],int left,int right){
    //生成[left,right]内的随机数
    int p=(round(1.0*rand()/RAND_MAX*(right-left)+left);
    swap(A[p],A[left]);

    int temp=A[left];
    while(left<right){
        while(left<right && A[right]>temp) right--;
        A[left] = A[right];
        while(left<right && A[left]<=temp) left++;
        A[right] = A[left];
    }
    A[left]=temp;
    return left;
}

//随机选择算法，从A[left,right]中找到第K大的数，并进行划分
void randSelect(int A[],int left,int right,int K){
    if(left == right) return;
    int p = randPartition(A,left,right);
    int M = p-left+1;
    if(K==M)
        return;
    else if(M>K)
        return randSelect(A,left,p-1,K);
    else
        return randSelect(A,p+1,right,K-M);
}

int main()
{
    srand((unsigned)time(NULL));
    int sum=0,sum1=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        sum+=A[i];
    }
    randSelect(A,0,n-1,n/2);//寻找第n/2大的数,并进行切分
    for(int i=0;i<n/2;i++)
        sum1+=A[i];
    printf("%d",(sum-sum1)-sum1);
    return 0;
}
