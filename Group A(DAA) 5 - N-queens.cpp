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

void print_board(vector<vector<int>> &board, int n){
	char c = 'X';
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(board[row][col] == 1) c = 'Q';
			else c = 'X';
			cout << c << " ";
		}
		cout << nline;
	}
}

bool safe(vector<vector<int>> &board, int n, int row, int col){

	for(int i=row;i>=0;i--){
		if(board[i][col] == 1) return false;
	}

	for(int i=row, j=col; i>=0&&j>=0; i--,j--){
		if(board[i][j] == 1) return false;
	}

	for(int i=row, j=col; i>=0&&j<n; i--,j++){
		if(board[i][j] == 1) return false;
	}

	return true;
}

bool solve_nqueen(vector<vector<int>> &board, int row, int n){

	if(row == n) return true;

	for(int col=0;col<n;col++){
		if(safe(board, n, row, col)){
			board[row][col] = 1;
			if(!solve_nqueen(board, row+1, n)) board[row][col] = 0;
			else return true;
		}
	}

	return false;
}


int main(){
	

	int n;
	cout << "Enter the size of board: ";
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));

	if(solve_nqueen(board, 0, n)){
		cout << "The arrangement of the n-queens is as followed: " << nline;
		print_board(board, n);
	} 
	else cout << "No solution exists for this board" << nline;


return 0;
}