#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int ansPrint(vector<int>& v,int target)
{
    if(target == 0)
    {
        return 0;
    }
    if(target < 0)
    {
        return INT_MAX;
    }
    int ans;
    int mini = INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        ans = ansPrint(v,target-v[i]);
        if(ans != INT_MAX)
        mini = min(mini,ans+1);
    }
    return mini;
}
int main()
{
    vector<int>v{1,2};
    int target = 5;
    int ans = ansPrint(v,target);
    cout<<ans;
    return 0;
}