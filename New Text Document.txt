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

// Recursive
// Time Complexity : O(2^N)
// Space Complexity : O(N)
int findNthFibonacci(int n){
	if(n == 1 || n == 0) return n;
	return fib(n-1) + fib(n-2);
}

int main(){
	// Non-Recursive
	// Time Complexity : O(N)
	// Space Complexity : O(1) or O(constant)
	int n;
	cout << "Enter the Number of Fibonacci required: ";
	cin >> n;
	cout << nline;
	int curr_num = 0, next_num = 1, temp;

	for(int i=1;i<n;i++){
		temp = curr_num;
		curr_num = next_num;
		next_num = temp + curr_num;
	}

	cout << "The Nth Fibonacci Number is: " << curr_num << nline;

return 0;
}