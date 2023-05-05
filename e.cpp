/*

e) You will be given a list coin denominations that you can use to tender change to your customers, find the most optimum way to tender the exact change to your customers,
 the optimum is when you use the least number of coins

Example:
input : [1 2 5 8 10]
input : 7 (change to be given)
Ans : [2,5]


Explain all the scenarios in better words and simpler to understand format compared to explanation available in the link below:
Explain what is a greedy algorithm and how dynamic programming helps in this case.

Bonus question

given a number N, remove one digit and print the largest possible number.

Eg :  Why is the above solution part of a greedy algorithm?

*/


/*
Solution:

In this implementation, we return a pair of integers consisting of a vector of the coins used to calculate the sum and the minimum number of coins needed, respectively. To keep track of the coins that were used to construct each value in the dp vector, we establish another vector called usedCoins.

We determine in the inner loop whether the current coin denomination yields less coins than the current value of dp[i]. If so, we update both usedCoins[i] and dp[i].

The coinsUsed vector is created by iterating backwards from sum and adding each coin denomination to the vector using a while loop after the dp and usedCoins vectors have been calculated.

The fewestCoins function is then called in the main function, and it is checked to see if it returns -1, which indicates that the total cannot be calculated using the provided coin denominations. If it is not zero, we print the minimal number of coins necessary as well as the coins that were used to calculate the total.

*/

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> fewestCoins(vector<int>& coins, int sum) {
    vector<int> dp(sum+1, INT_MAX);
    vector<int> usedCoins(sum+1, -1);
    dp[0] = 0;
    
    for (int coin : coins) {
        for (int i = coin; i <= sum; i++) {
            if (dp[i-coin] != INT_MAX && dp[i] > dp[i-coin] + 1) {
                dp[i] = dp[i-coin] + 1;
                usedCoins[i] = coin;
            }
        }
    }
    
    if (dp[sum] == INT_MAX) {
        return make_pair(-1, vector<int>());
    } else {
        vector<int> coinsUsed;
        int currentSum = sum;
        while (currentSum > 0) {
            coinsUsed.push_back(usedCoins[currentSum]);
            currentSum -= usedCoins[currentSum];
        }
        return make_pair(dp[sum], coinsUsed);
    }
}

int main() {
    vector<int> coins = {1, 2, 5, 8, 10};
    int sum = 7;
    auto result = fewestCoins(coins, sum);
    if (result.first == -1) {
        cout << "Sum cannot be constructed using the given coin denominations." << endl;
    } else {
        cout << "Minimum number of coins required: " << result.first << endl;
        cout << "Coins used: ";
        for (int coin : result.second) {
            cout << coin << " ";
        }
        cout << endl;
    }
    return 0;
}