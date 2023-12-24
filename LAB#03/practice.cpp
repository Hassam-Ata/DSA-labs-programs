#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    map<int,int>count;
     int maxi=-1;
    int ans1=-1;
    int mini=v.size();
    int ans2=-1;

    for(int i=0;i<v.size();i++)
    {
        count[v[i]]++;
    }
   
    for(auto i:count)
    {
        if(i.second>maxi)
        {
            maxi=i.second;
            ans1=i.first;
        }
        if (i.second<mini)
        {
            mini=i.second;
            ans2=i.first;


        }
        

    }
    
    return {ans1,ans2};



    
}
int main()
{
    vector<int>v={1,2,2,2,2,3,3,3,4};
    vector<int>result=getFrequencies(v);
    for (int i = 0; i < result.size(); i++)
    {
        /* code */
        cout<<result[i]<<" ";
    }
    
    
    return 0;
}

