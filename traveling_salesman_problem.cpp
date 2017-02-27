#include <stdio.h>
#include<limits.h>
#define size 10 //maximum 10 cities
#define min(a,b) a>b?b:a
#define sizePOW 1024 // 2^10
//Space complexity: O(n * 2^n)
//Time complexity: O(n^2 * 2^n)
int n,npow,g[size][sizePOW],p[size][sizePOW],adj[size][size];
int compute(int start,int set)
{	int masked,mask,result=INT_MAX,temp,i;//result stores the minimum 
	if(g[start][set]!=-1)//memoization DP top-down,check for repeated subproblem
		return g[start][set];
	for(i=0;i<n;i++)
		{	//npow-1 because we always exclude "home" vertex from our set
			mask=(npow-1)-(1<<i);//remove ith vertex from this set
			masked=set&mask;
			if(masked!=set)//in case same set is generated(because ith vertex was not present in the set
                                      // hence we get the same set on removal) eg 12&13=12
			{	
				temp=adj[start][i]+compute(i,masked);//compute the removed set
				if(temp<result)
					result=temp,p[start][set]=i;//removing ith vertex gave us minimum
			}
		}
		return g[start][set]=result;//return minimum
}
void getpath(int start,int set)
{
	if(p[start][set]==-1) return;//reached null set
	int x=p[start][set];
	int mask=(npow-1)-(1<<x);
	int masked=set&mask;//remove p from set
	printf("%d ",x);
	getpath(x,masked);
}
void TSP()
{	int i,j;
	//g(i,S) is length of shortest path starting at i visiting all vertices in S and ending at 1
	for(i=0;i<n;i++)
		for(j=0;j<npow;j++) 
				g[i][j]=p[i][j]=-1; 
	for(i=0;i<n;i++)g[i][0]=adj[i][0];//g(i,nullset)= direct edge between (i,1)
	int result=compute(0,npow-2);//npow-2 to exclude our "home" vertex
	printf("Tour cost:%d\n",result);
	printf("Tour path:\n0 ");
	getpath(0,npow-2);
	printf("0\n");
}
int main(void) {
	int i,j;
	printf("Enter number of cities\n");
	scanf("%d",&n);
	npow=(int)pow(2,n);//bit number required to represent all possible sets
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&adj[i][j]);
	TSP();
	return 0;
}
