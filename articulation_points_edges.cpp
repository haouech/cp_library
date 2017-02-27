#include <iostream>
#include <vector>


using namespace std;


vector<vector<int>> graph ;
vector<bool> vis ;
vector<int> low ,num ,parent;
int rtime ;


void DFS(int src)
{

vis[src]=true ;
low[src]=num[src]=++rtime ;

int nchild =0,v ;

for(int i=0 ; i<graph[src].size();i++)
{v= graph[src][i] ;
if(!vis[v])
{nchild++;
parent[v]=src;
DFS(v) ;
low[src]=min(low[src],low[v]) ;


}
		else if(vis[v] && v!=parent[src])
			low[src]=min(low[src],num[v]);
	}

			if((parent[src]==-1 && nchild>1)||(parent[src]!=-1 && low[v]>=num[src]))
            cout<<src<<" ";//Adding the articulation points. How are they repeated?



}



int main()
{
    int n , m;
    cin>>n>>m ;
    graph.clear();
    graph.resize(n);
    vis.clear();
    vis.resize(n,false);

    low.clear();
    low.resize(n);
    num.clear();
    num.resize(n);
    parent.clear();
    parent.resize(n);

    for(int i=0 ; i<n ; i++)
    {parent[i]=-1 ; num[i]=1e9 ; low[i]=1e9 ;}

    while(m--)
    {int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    }



/**Articulation Point

    rtime=0;//The time for each cycle of DFS

	for(int i=0;i<n;i++)
		if(!vis[i])//Vertex not discoverdd
			DFS(i); **/



/**Bridges
    for(int i=0 ; i<n ;i++)
    {for(int j=0 ;j<graph[i].size();j++)
    {if (num[i]<low[graph[i][j]]) {cout<<i<<"--"<<graph[i][j]<<endl;}}}**/

    return 0;
}

