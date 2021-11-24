//Question : Largest Component Size by Common Factor(https://leetcode.com/problems/largest-component-size-by-common-factor/)
//Difficulty : Hard
//Pre-requisite : Disjoint Set
It's a really hard problem if we try to solve this problem using graph i mean first build graph then find size of largest connected component
it will give us TLE because of constraints.

//Disjoin Set
//Time Complexity :=> O(N * sqrt(max(arr[i])). SC:=> O(N)
//The idea is that for every number we find and link all of its factors to a unique parent number. Then simply count the numbers which has the given parent and output the maximum such frequency.

   int find(int x,vector<int>&parents)
     {
         if(parents[x]==-1) return x;
         return parents[x]=find(parents[x],parents);
     }
     
     void Union(int x,int y,vector<int>&parents)
     {
         int xp=find(x,parents);
         int yp=find(y,parents);
         if(xp!=yp) parents[yp]=xp;
     }

    int largestComponentSize(vector<int>& nums) {
        vector<int>parents(1000001,-1);
        unordered_map<int,int>mpp;
        int ans=0;
     for(int x:nums)
     {
        for(int i=2;i*i<=x;++i)
            if(x%i==0)
            {
                Union(i,x,parents);
                Union(x,x/i,parents);
            }
     }
    for(int x:nums)
        ans=max(ans,++mpp[find(x,parents)]);
    return ans;
    }