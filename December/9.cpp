//Question : Jump Game III(https://leetcode.com/problems/jump-game-iii/)
//Difficulty : Medium
//Pre-requisites: BFS, DFS

   //Approach-1
   //BFS
  //Time-Complexity :O(N) 
  //Space-Complexity:-O(N)(using queue)+O(N)(using vector)
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        if(arr[start]==0) return true;
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(start);
        vis[start]=true;
        while(!q.empty())
        {
          int curr=q.front();q.pop();
          if(arr[curr]==0) return true;
          int temp=curr+arr[curr];
          if(temp<n && !vis[temp])
          {
              q.push(temp);
              vis[temp]=true;
          }
            temp=curr-arr[curr];
            if(temp>=0 && !vis[temp])
            {
                q.push(temp);
                vis[temp]=true;
            }
        }
        return false;
    }
    
//Approach-2 
//DFS
//Time-Complexity: O(N)
//Space-Complexity: O(N) (stack space because of recursion)
     bool canReach(vector<int>& arr, int start){
        if(arr[start]==0) return true;
        int new_index1=start+arr[start];
        int new_index2=start-arr[start];
        arr[start]=-1; // for marking visited
        if(new_index1<arr.size() && arr[new_index1]!=-1 && canReach(arr,new_index1)) return true;
        if(new_index2>=0 && arr[new_index2]!=-1 && canReach(arr,new_index2))  return true;
        return false;
     }