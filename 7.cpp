//Questions: Multiply Strings (https://leetcode.com/problems/multiply-strings/)
//Difficulty Level : Medium
//Pre-requisites: Add Two Number ,Plus One and simple math

    string multiply(string num1, string num2) {
        // if anyone or both are zero then multiplication will be zero. 
        if(num1=="0" or num2=="0") return "0"; 
        
        int l1=num1.size();
        int l2=num2.size();
        
        vector<int>res(l1+l2); //MaxLen of multiplication will be l1+l2
        
        int i=l2-1; 
        int pf=0; //power factor
        while(i>=0)
        {
              int j=l1-1;
              int ival=num2[i]-'0';
               i--;
              int k=res.size()-1-pf;
              int carry=0;
             while(j>=0 or carry!=0)
             {
                 int jval=j>=0?num1[j]-'0':0;
                  j--;
                 int prod=ival*jval+carry+res[k];
                 res[k]=prod%10;
                 carry=prod/10;
                 k--;
             }
            pf++;
        }
        //skip leading zeros
        i=0;
        while(res[i]==0) i++;
        
        string ans="";
         for(;i<res.size();i++)
              ans+=to_string(res[i]);
        
        return ans;
}

