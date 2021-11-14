//Question:- Daily Temperatures
//Difficulty: Medium but I feel like it's a easy question but we need to just understand the question
//Pre-requisite:- how stack works

//Time Complexity:- O(N) //iterate given array 
//Space Complexity:- O(N)//using extra space as stack

 vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
       vector<int>ans(n,0);//resultant array
        stack<int>st;//to store temp so that we can get how many temp are less than or equal
        for(int i=0;i<n;i++)
        {
              while (!st.empty() and temp[st.top()] < temp[i]) //if stack is empty and temp of top is less than ith index temp then run while loop 
              {
	   int j = st.top(); st.pop();
	   ans[j] = i - j;
            }
            st.push(i);//push index in stack
        }
        return ans;
    }

