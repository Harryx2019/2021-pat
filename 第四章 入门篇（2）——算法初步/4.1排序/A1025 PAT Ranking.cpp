#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct student
{
    string registration_number;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
} student;

bool cmp(student s1,student s2)
{
    if(s1.score!=s2.score)
        return s1.score>s2.score;
    return strcmp(s1.registration_number.c_str(),s2.registration_number.c_str())<0;
}

int main()
{
    int n;
    cin>>n;

    vector<student> students;

    int local_students_num[n+1]= {0};
    int i,j;
    for(i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        local_students_num[i]=k;

        vector<student> local_students;
        for(j=0; j<k; j++)
        {
            student stu;
            stu.location_number=i;

            string registration_number;
            cin>>registration_number;
            stu.registration_number = registration_number;

            int score;
            cin>>score;
            stu.score = score;

            local_students.push_back(stu);
        }

        sort(local_students.begin(),local_students.end(),cmp);

        //区域排名
        int r=1;
        for(j=0; j<k; j++)
        {
            if(j>0&&local_students[j].score!=local_students[j-1].score)
                r = j+1;
            local_students[j].local_rank=r;
            students.push_back(local_students[j]);
        }
    }
    //整体排名
    int sum=0;
    for(i=1;i<=n;i++)
        sum+=local_students_num[i];

    cout<<sum<<endl;
    sort(students.begin(),students.end(),cmp);
    int r=1;
    for(i=0; i<sum; i++)
    {
        if(i>0&&students[i].score!=students[i-1].score)
            r = i+1;
        students[i].final_rank=r;
        cout<<students[i].registration_number<<" "<<students[i].final_rank<<" "<<students[i].location_number<<" "<<students[i].local_rank<<endl;
    }

    return 0;
}
