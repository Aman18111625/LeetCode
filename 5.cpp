//Question : Arranging Coins(https://leetcode.com/problems/arranging-coins/)
//Difficulty Level : Easy
//Pre-requisites:- knowledge of loop

int arrangeCoins(int n) {
        if(n<=2) return 1;
       int num=n,cnt=0,i=1;
           do{
            num -= i;
            cnt++;
        }while(num > i++ );
        return cnt;
 }