//Question : Nth Magical Number (https://leetcode.com/problems/nth-magical-number/)
//Difficulty : Hard but i think if you have already solved ugly number's all version than it's very easy to get idea about the solution
//Pre-requisites: Basic Math & Binary Search

//Time- Complexity : O(logn)
//Space-Complexity: O(n)
  /*
    To find if position of x, in the sequence of numbers divisble by either A or B can denoted by,
	position = (x/A + x/B - x/lcm)
    we know that lcm of A & B -> lcm = (A*B)/__gcd(A,B)
Example:
	Consider A=2, B=5. Find the position of 15 in this sequence?
		gcd = 1;
		lcm = (2*5)/gcd   = 10
	then postion of 15,
				2 , 4 , 5 , 6 , 8 , 10 , 12 , 14 , 15
				i.e. 9th position
	by the formula,
				= 15/2 + 15/5 - 15/10= 7+3-1=9
    */

   const int mod=1e9+7;
    int gcd(int a,int b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
    
    int lcm(int a,int b)
    {
        return (a*b)/gcd(a,b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long low,high,mid,target,lcmOfAB;
        lcmOfAB=lcm(a,b);
        low=1;
        high=1e17;
        while(low<high)
        {
            mid=low+(high-low)/2;
            target=(mid/a)+(mid/b)-(mid/lcmOfAB);
            /*
              mid/a => number those who are divisible by a
              mid/b => number those who are divisible by b
              mid/(lcmOfAB) => number those who are divisible by a & b both,so they count twice 
            */
            if(target<n) low=mid+1;
            else high=mid;
        }
        return high%mod;
    }