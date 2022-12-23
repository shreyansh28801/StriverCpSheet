#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(abs(nums[i])) != mp.end())
            {
                // cout<<"\n insA "<<nums[i];
                mp.find(abs(nums[i]))->second.push_back(nums[i]);
            }
            else
            {
                // cout<<"\n insB "<<nums[i];
                vector<int> v;
                v.push_back(nums[i]);
                // mp.find(abs(nums[i]))->second = v
                mp[abs(nums[i])]=v;
            }
        }
        sort(mp.begin()->second.begin(),mp.begin()->second.end());
        // cout<<"mp s"<<mp.size();
        // for (auto i = mp.begin(); i != mp.end(); i++)
        // {
        //     cout<<"\nfor i->f "<<i->first<<"  : ";
        //     for (int j = 0; j < i->second.size(); j++)
        //     {
        //         cout<<" "<<i->second[j];
        //     }
            
        // }




        // map<int ,vector<int>> mp;
       
        // for(int i=0;i<nums.size();i++){
            
        //     if(mp.find(s)!=mp.end()) {
        //         cout<<"\ngjhghjg A  "<<i;
        //         mp.find(s)->second.push_back(strs[i]);
        //     }
        //     else{ cout<<"\ngjhghjg B  "<<i;
        //         vector<string> vs;
        //         vs.push_back(strs[i]);
        //          ump[s]=vs;
        //     }
        // }
        
        return mp.begin()->second[mp.begin()->second.size()-1];
    }
};

int main()
{
    Solution o;
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    cout<<o.findClosestNumber(nums);
    

    return 0;
}