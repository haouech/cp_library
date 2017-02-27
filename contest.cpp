RQ : in a spanning tree ther's at most (n-1) edges .


longest increasing subsequence : 

int tab[MAX_N] ; // remplissage du tableau
    int liste[MAX_N] ; liste[0] = 1 ;
    int res = 1 ;
    for(int i = 1 ; i < MAX_N ; i++){
         int ans = 1 ;
        for(int j = 0 ; j < i ; j++){
            if(tab[i] >= tab[j] )ans = max(ans , 1 + liste[j] ) ;
        }
        liste[i] = ans ;
        res = max(res , ans) ;
    }
    cout << res << endl;



coin change : 

Solution: Use these Complete Search recurrences:

1. coin(0) = 0 // 0 coin to produce 0 cent
2. coin(< 0) = INVALID → (in practice, we just return a large positive value)
3. coin(value) = 1 + min(coin(value - coinValue[i])) ∀i ∈ [0..N-1] , The answer is in coin(V).

Maximum sum :

One possible DP solution is to turn this n x n array into an n x n sum array where arr[i][j]
no longer contains its own value, but the sum of all items within sub-rectangle (0, 0) to (i, j). 
This can easily be done on-the-fly when reading the input and still O(n 2 ).

scanf("%d", &n);
for (int i = 0; i < n; i++) for (int j = 0 ; j < n ; j++){
scanf("%d", &arr[i][j]);
if (i > 0) arr[i][j] += arr[i - 1][j] ;   // if possible, add values from top
if (j > 0) arr[i][j] += arr[i][j - 1] ;   // if possible, add values from left
if (i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1] ;  // to avoid double count
} // inclusion-exclusion principle

then we do this ==> 

maxSubRect = -127*100*100; // lowest possible value for this problem

for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coord
for (int k = i; k < n; k++) for (int l = j; l < n; l++) { // end coord
subRect = arr[k][l]; // this is sum of all items from (0, 0) to (k, l): O(1)
if (i > 0) subRect -= arr[i - 1][l]; // O(1)
if (j > 0) subRect -= arr[k][j - 1]; // O(1)
if (i > 0 && j > 0) subRect += arr[i - 1][j - 1]; // inclusion-exclusion: O(1)

maxSubRect = max(maxSubRect, subRect);
}



dijkstra ( shortest path ) , lorsque le graph est définie par vector<vector<int > > ,,,  :

    #define INT_MAX 1e9+7   
   
    struct edge { int to, length; };
        
    int dijkstra(const vector< vector<edge> > &graph, int source, int target) {
        vector<int> min_distance( graph.size(), INT_MAX );
        min_distance[ source ] = 0;
        set< pair<int,int> > active_vertices;
        active_vertices.insert( {0,source} );
            
        while (!active_vertices.empty()) {
            int where = active_vertices.begin()->second;
            if (where == target) return min_distance[where];
            active_vertices.erase( active_vertices.begin() );
            for (auto edge : graph[where]) 
                if (min_distance[edge.to] > min_distance[where] + edge.length) {
                    active_vertices.erase( { min_distance[edge.to], edge.to } );
                    min_distance[edge.to] = min_distance[where] + edge.length;
                    active_vertices.insert( { min_distance[edge.to], edge.to } );
                }
        }

        return INT_MAX;
    }



kruskal ( MST ) ; principe ::

input : a connected undirected graph with edge weights 
outouts : a minimum spanning tree defined by the edges

for all u du graph : makeset( u ) ;

X = { } ;

sort the edges by weight . 

for all edges of E in increasing order of weight : 
  if find(u) <> find(v) ==>  add {u,v} to X , union(u,v) ;

  
int find(int i){ 
	if(parent[i] == i)return i ; 
        else {  return parent[i] = find( parent[i] ) ; }  
}

int union(int i,int j){
   parent[i] = parent[j] ;
}








