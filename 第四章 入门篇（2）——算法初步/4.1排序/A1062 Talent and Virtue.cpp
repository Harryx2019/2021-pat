#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct people
{
    string ID_Number;
    int Virtue_Grade;
    int Talent_Grade;
    int Sum_Grade;
    int flag;
} people;

bool cmp(people p1,people p2)
{
    if(p1.flag != p2.flag)
        return p1.flag<p2.flag;
    int sum1 = p1.Sum_Grade;
    int sum2 = p2.Sum_Grade;
    if(sum1!=sum2)
        return sum1>sum2;
    else
    {
        if(p1.Virtue_Grade!=p2.Virtue_Grade)
            return p1.Virtue_Grade>p2.Virtue_Grade;
    }
    return strcmp(p1.ID_Number.c_str(),p2.ID_Number.c_str())<0;
}

int main()
{
    int n,L,H;
    scanf("%d %d %d",&n,&L,&H);

    //最终名单
    vector<people> res_peoples;
    /*//圣人
    vector<people> sage_peoples;
    //君子
    vector<people> nobelman_peoples;
    //愚人
    vector<people> foolMan_peoples;
    //小人
    vector<people> smallMan_peopels;*/

    int i;
    string ID_Number;
    int Virtue_Grade;
    int Talent_Grade;
    int Sum_Grade;
    for(i=0; i<n; i++)
    {
        people p;
        cin>>ID_Number;
        scanf("%d %d",&Virtue_Grade,&Talent_Grade);
        Sum_Grade = Virtue_Grade+Talent_Grade;

        //分数是否达标
        if(Virtue_Grade<L||Talent_Grade<L)
            continue;

        p.ID_Number=ID_Number;
        p.Virtue_Grade=Virtue_Grade;
        p.Talent_Grade=Talent_Grade;
        p.Sum_Grade=Sum_Grade;
        //圣人
        if(Virtue_Grade>=H && Talent_Grade>=H)
            p.flag=1;
        //君子
        else if(Virtue_Grade>=H && Talent_Grade<H)
            p.flag=2;
        //愚人
        else if(Virtue_Grade>=Talent_Grade)
            p.flag=3;
        //小人
        else
            p.flag=4;

        res_peoples.push_back(p);
    }
    sort(res_peoples.begin(),res_peoples.end(),cmp);

    n=res_peoples.size();
    cout<<n<<endl;
    for(i=0; i<n; i++)
        cout<<res_peoples[i].ID_Number<<" "<<res_peoples[i].Virtue_Grade<<" "<<res_peoples[i].Talent_Grade<<endl;

    return 0;
}

/*2021.8.5 改进想法：将四个vector改为数组*/

/*2021.8.6 修改代码：结构体添加flag分类标签 根据分类进行排序*/
