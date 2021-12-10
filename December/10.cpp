//Question : Domino and Tromino Tiling (https://leetcode.com/problems/domino-and-tromino-tiling/)
//Difficulty: Medium
//Pre-requisites : Tiling with M*1 board (it will help you to clear basic)

/*
Idea:
In any iteration, our empty slots in the board can look in two ways:
Either it's a full rectangle or it's a rectangle with one more square sticking out.

We define two functions:
dp[i] = The number of ways to fill a full rectangle in the size of i * 2.
t[i] = The number of ways to fill a rectangle of size i * 2 + one square sticking out.

dp[i]:
We have a rectangle.
We have 3 options:

put one domino vertically on the side, leaving us with a full rectangle of size i-1 - dp[i-1].
put two dominoes on the side, leaving us with a full rectangle of size i-2 - dp[i-2].
Put a tromino on the side - leaving us with a rectangle of size i-2 plus another sticking out square - t[i-2].
There are two directions to put the tromino, so we have 2 * t[i-2].
Conclusion - dp[i] = dp[i-1] + dp[1-2] + 2 * t[i-2].

t[i]:
We have a rectangle with a square sticking out, it doesn't matter if on the top row or bottom.
We have two options:

Put a domino horizontally in the sticking out square, leaving us again with a sticking out square on the other row - t[i-1].
Put a tromino completing the extra square, leaving us with a full rectangle - D[i-1].
Conclusion - t[i] = t[i-1] + dp[i-1].
*/

Time Complexity: O(n)
Space Complexity: O(n)

int numTilings(int n) {
        if(n<3) return n;
        long long mod = 1e9 + 7;
        vector<long long> dp(n+1, 0), t(n+1, 0);
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        t[0] = 0, t[1] = 1, t[2] = 2;   
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + 2*t[i-2]) % mod;
            t[i] = (t[i-1] + dp[i-1]) % mod;
        }
        return dp[n];
}