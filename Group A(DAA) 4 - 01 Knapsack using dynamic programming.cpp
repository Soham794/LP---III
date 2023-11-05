/*Soham Belokar*/
#include <bits/stdc++.h>

using namespace std;
 
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define space " "
#define pb push_back
#define mp make_pair
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print_time() cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC  << " mS\n";
#define _test_cases int _TEST; cin >> _TEST; while(_TEST--)

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

// Recursive method using memoization (Top-Down approach)
// Without Memoization:
// Time Complexity : O(2^N)
// Space Complexity : O(N) // recursion stack
// With Memoization:
// Time Complexity : O(N*W)
// Space Complexity : O(N)
// Auxiliary Space Complexity : O(N*W) // dp table

int knapsack01(vector<vector<int>> &dp, vector<pair<int,int>> &items, int curr, int weight, int profit){
	
	
	if(curr < 0) return 0;

	if(dp[curr][weight] != -1) return dp[curr][weight];

	if(weight < items[curr].first) return dp[curr][weight] = knapsack01(dp, items, curr-1, weight, profit);

	return dp[curr][weight] = max(items[curr].second + knapsack01(dp, items, curr-1, weight-items[curr].first, profit+items[curr].second),
		knapsack01(dp, items, curr-1, weight, profit));

}



int main(){	

	// Non-Recursive method using Tabulation (Bottom-Up approach)
	// Time Complexity : O(N)
	// Space Complexity : O(N*W)
	// Auxiliary Space Complexity : O(N*W) // dp table

	int n;
	cout << "Enter the total number of items: ";
	cin >> n;
	cout << nline;

	int mx_weight;
	cout << "Enter the maximum weight of the Knapsack: ";
	cin >> mx_weight;
	cout << nline;

	vector<pair<int,int>> items(n);
	cout << "Enter the weight of the items: ";
	for(int i=0;i<n;i++) cin >> items[i].first;
	cout << nline;
	
	cout << "Enter the profit of the items: ";
	for(int i=0;i<n;i++) cin >> items[i].second;
	cout << nline;

	vector<vector<int>> dp(n+1, vector<int>(mx_weight+1));

	for(int i=0;i<=n;i++){
		for(int w=0;w<=mx_weight;w++){
			if(w==0 || i==0){
				dp[i][w] = 0;
			}
			else if(items[i-1].first <= w){
				dp[i][w] = max(items[i-1].second + dp[i-1][w-items[i-1].first], dp[i-1][w]);
			}
			else{
				dp[i][w] = dp[i-1][w];
			}
		}
	}

	cout << dp[n][mx_weight];

	// Space Optimized approach
	// Space Compelxity : O(max_weight)
	// Auxiliary Space Complexity : O(max_weight) // dp table
	// vector<int> dp1(mx_weight+1, 0);
	// for(int i=1;i<=n;i++){
	// 	for(int w=mx_weight;w>=0;w--){
	// 		if(items[i-1].first <= w){
	// 			dp1[w] = max(dp1[w], dp1[w-items[i-1].first]+items[i-1].second);
	// 		}
	// 	}
	// }

	// cout << dp1[mx_weight];


return 0;
}