//Question:- 1286 Iterator for Combination
(https://leetcode.com/problems/iterator-for-combination/)
//Difficulty Level: Medium but According to me if you know how to generate all the combination then it's Easy
//Pre-requisite: Solve first How to generate all the combination of a string


//Time Complexity:- O(N*2^N)
//Space Complexity:- O(number of combination of length N)
vector<string>res;//to store all combination of  length n of string str
    int ptr;
    void findCombinations(string& str,int i,string temp,int n)
    {
        if(temp.size()==n)
        {
            res.push_back(temp);
            return ;
        }
     //for every char we have two option -> whether we can choose it or we can skip it
        for(int j=i;j<str.size();j++)
        {
            temp.push_back(str[j]);//op1
            findCombinations(str,j+1,temp,n);//call for next
            temp.pop_back();//skip
        }
    }
    void combinations(string& s,int n)
    {
         findCombinations(s,0,"",n);
    }

CombinationIterator(string s, int n) {
        combinations(s,n);
        ptr=0;
    }
    
    string next() {
        return res[ptr++];
    }
    
    bool hasNext() {
     return ptr<res.size();   
    }

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */