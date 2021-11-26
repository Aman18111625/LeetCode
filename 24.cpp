//Question : Interval List Intersections(https://leetcode.com/problems/interval-list-intersections/)
//Difficulty Level: Medium
//Pre-requisite : how to find intersection 

//Time Complexity :- O(N+M) where N->length of first list and M->length of second list
//Space Complexity:- O(1) I'm not considering  store result in vector as a extra space

vector<vector<int>>intervalIntersection(vector<vector<int>>&f,vector<vector<int>>&s)
{
      vector<vector<int>>res; //to store results
    int n=f.size();//size of first list
    int m=s.size();//size of second list
    if(n==0 or m==0) return res; //if anyone is zero then intersection is not possible
    int i=0,j=0;
    while(i<n and j<m)
    {
        int l=max(f[i][0],s[j][0]); 
        int u=min(f[i][1],s[j][1]);
         if(l<=u) res.push_back({l,u}); //it means ->intersection 
         if(f[i][1] <= s[j][1])   i++;
          else j++;
    }   
  return res;
}