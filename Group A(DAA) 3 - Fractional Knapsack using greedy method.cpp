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

bool compare(pair<int,int> a, pair<int,int> b){
	double profit_weight1 = (double)a.second/(double)a.first;
	double profit_weight2 = (double)b.second/(double)b.first;
	if(profit_weight2 == profit_weight1) return a.first < b.first;
	return profit_weight1 > profit_weight2;
}

int main(){	

	// Fractional Knapsack using greedy method
	// Time Complexity : O(N Log(N)) // becuase of sorting
	// Space Complexity : O(N)
	// Auxiliary Space : O(1) or O(constant)
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

	sort(items.begin(), items.end(), compare);

	for(int i=0;i<n;i++){
		cout << items[i].first << " " << items[i].second << nline;
	}

	double final_profit = 0;

	for(int i=0;i<n;i++){
		if(items[i].first <= mx_weight){
			mx_weight -= items[i].first;
			final_profit += items[i].second;
		}
		else{
			final_profit += items[i].second * ((double)mx_weight/(double)items[i].first);
			mx_weight = 0;
			break;
		}
	}

	cout << "The maximum profit obtained is: " << final_profit << nline;

return 0;
}