//Question : - All Path From Source to Target(https://leetcode.com/problems/all-paths-from-source-to-target/)
//Difficulty :- Medium
//Pre-requisites : - BFS or DFS Traversal
/*
To solve this question I created two arrays visited and ans, when we reached at target node we push visited in ans.
else we will traverse in each node connected to current node and call to next dfs  for adjacents  node.
*/

      vector<vector<int>>res;//to store result
      vector<int>path;
      int target;
     void dfs(vector<vector<int>>&graph,int node=0)
     { 
         path.push_back(node);
         if(node==target) res.push_back(path);
         else
         {
             for(auto it : graph[node])
                 dfs(graph,it);
         }
         path.pop_back();//backtrack
     }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            target=graph.size()-1;
            dfs(graph);
        return res;
    }
    