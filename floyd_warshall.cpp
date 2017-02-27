condition : 	

Floyd–Warshall algorithm is an algorithm for finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles). A single execution of the algorithm will find the lengths (summed weights) of the shortest paths between all pairs of vertices, though it does not return details of the paths themselves.



#include <bits/stdc++.h>
using namespace std;

void floyds(int b[][7])
{
    int i, j, k;
    for (k = 0; k < 7; k++)
    {
        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 7; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < 7; i++)
    {
        cout<<"nMinimum Cost With Respect to Node:"<<i<<endl;
        for (j = 0; j < 7; j++)
        {
            cout<<b[i][j]<<"t";
        }
    }
}
int main()
{
        int b[7][7];
        cout<<"ENTER VALUES OF ADJACENCY MATRIXnn";
        for (int i = 0; i < 7; i++)
        {
                cout<<"enter values for "<<(i+1)<<" row"<<endl;
                for (int j = 0; j < 7; j++)
                cin>>b[i][j];
        }
        floyds(b);
        return 0;
}
