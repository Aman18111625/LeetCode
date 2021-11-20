//Question :- Harming Distance(https://leetcode.com/problems/hamming-distance/)
//Difficulty: Easy
//Pre-requisite: How bit operation works 

  /*
    //approach-1 using Xor operator if ith bit is set in both then x^y for ith bit ==0 and if not set then x^y ==1 such that we can get different bit in x^y ,now simply count number of set bit x^y
    int hammingDistance(int x, int y) {
        int res=0;
        int num=x^y;
        while(num)
        {
            res+=(num%2);
            num>>=1;
        }
        return res;
    }
    */
    //approach-2
    //x%2!=y%2 it means ith bit is not set for x or y 
    int hammingDistance(int x, int y){
        int res=0;
        while(x and y)
        {
            res+=(x%2!=y%2);
            x>>=1,y>>=1;
        }
        while(x)
        {
            res+=(x%2);
            x>>=1;
        }
        while(y)
        {
            res+=(y%2);
            y>>=1;
        }
        return res;
    }