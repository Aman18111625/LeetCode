//Question : Maximal Rectangle(https://leetcode.com/problems/maximal-rectangle/)
//Difficulty : Hard
//Pre-requistes : Maximum Area Of Histogram 
//I'll Recommend to watch aditya verma solution ,i have already solved this question.

//Code is too long but if you'll understand then it's simple to write
//Time Complexity: O(N*M)
//Space Complexity : O(N)+O(N) (using 2 stack)
//Find Next Smaller Element to Left
vector<int> NSL(vector<int>&arr)
{
       vector<int>ans;
        stack<pair<int,int>>st;
        int pseudoIndex=-1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty()) ans.push_back(pseudoIndex);
            else if(!st.empty() and st.top().first<arr[i])
                ans.push_back(st.top().second);
            else //if(!st.empty() and st.top().first>=arr[i])
            {
                while(!st.empty() and st.top().first>=arr[i]) st.pop();
                if(st.empty()) ans.push_back(pseudoIndex);
                else ans.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
        return ans;
 }
    
//Find Next Smaller Element to Right    
vector<int> NSR(vector<int>&arr)
{
       vector<int>ans;
        stack<pair<int,int>>st;
         int n=arr.size();
        int pseudoIndex=n; 
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) ans.push_back(pseudoIndex);
            else if(!st.empty() and st.top().first<arr[i])
                ans.push_back(st.top().second);
            else //if(!st.empty() and st.top().first>=arr[i])
            {
                while(!st.empty() and st.top().first>=arr[i]) st.pop();
                if(st.empty()) ans.push_back(pseudoIndex);
                else ans.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
 }
    
//Maximum area of histogram
 int MAH(vector<int>&arr)
 {
        vector<int>left=NSL(arr);
        vector<int>right=NSR(arr);
        int width;
        int maxi=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            width=right[i]-left[i]-1;
            maxi=max(maxi,width*arr[i]);
        }
        return maxi;
 }

//main function
int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
         int m=mat[0].size();
        if(m==0) return 0;
          vector<int>arr;
        for(int j=0;j<m;j++)
            arr.push_back(mat[0][j]-'0');
        
        int maxi=MAH(arr);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(mat[i][j]=='0')
                   arr[j]=0;
                else 
                    arr[j]+=(mat[i][j]-'0');
            }
            maxi=max(maxi,MAH(arr));
        }
        return maxi;
}

