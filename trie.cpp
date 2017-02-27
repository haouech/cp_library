#include <bits/stdc++.h>
using namespace std;
const int MAX = 300009;
char pat[MAX];

struct node{
	bool leaf;
	vector<int> adj;
	node(){
		leaf = 0;
		adj.resize(26,-1);
	}
};
vector<node> trie;

void insert(char* s){
	int cur = 0;
	for(int i=0;s[i]!='\0';i++){
		if(trie[cur].adj[ s[i]-'a' ]==-1){
			trie[cur].adj[ s[i]-'a' ] = trie.size();
			trie.push_back(node());
		}
		cur = trie[cur].adj[ s[i]-'a' ];
	}
	trie[cur].leaf = 1;
}

string P;

void print(int cur){
	if(trie[cur].leaf)
		cout << P << endl;
	for(int i=0;i<26;i++){
		if(trie[cur].adj[i]!=-1){
			P += char(i+'a');
			print(trie[cur].adj[i]);
			P.resize(P.size()-1);
		}
	}
}

int main()
{
    int k;
    while(scanf("%d\n",&k)>=1){
		trie.clear();
		trie.push_back(node());
		while(k--){
			scanf("%s",pat);
			insert(pat);
		}
		P = "";
		print(0);
    }
    return 0;
}
