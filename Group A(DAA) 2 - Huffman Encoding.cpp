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

struct node{
	int freq;
	string ch;
	node *left = NULL;
	node *right = NULL;

	Node(string str, int count){
		freq = count;
		ch = str;
	}

	void displayHuffmanCode(string str){
		if(left) left->displayHuffmanCode(str+'0');
		if(right) right->displayHuffmanCode(str+'1');
		if(left && right){
			cout << ch << " ==> " << str << nline;
		}
		return;
	}

}

void display_nodes(vector<node*> arr){
	for(auto i: arr){
		cout << i->ch << "-" << i->freq << "\t";
	}
	cout << nline;
}

bool compare(node *a, node *b){
	return a->freq < b->freq;
}

int main(){
	
	int n;
	cout << "Enter the number of characters: ";
	cin >> n;
	cout << nline;

	vector<pair<string, int>> char_freq;
	cout << "Enter the characters: ";
    for(int i=0;i<n;i++) cin >> char_freq[i].first;
    cout << nline;

	for(int i=0;i<n;i++) cin >> char_freq[i].second;
	cout << nline;

    vector<node*> nodes;
	for(auto i: char_freq){
		node newNode = new Node(i.first, i.second);
		nodes.push_back(newNode);
	}

    
	while(nodes.size() > 1){
		sort(nodes.begin(), nodes.end(), compare);
		display_nodes(nodes);
		node *left = nodes[0];
		node *right = nodes[1];
		node *newNode = new node(left->ch+right->ch, left->freq+right->freq);
		newNode->left = left;
		newNode->right = right;
		nodes.erase(nodes.begin(), nodes.begin() + 2);
		nodes.push_back(newNode);
	}

    nodes[0]->displayHuffmanCode("");

return 0;
}