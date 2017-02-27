#include <bits/stdc++.h>

using namespace std;

int dp [2][2000001];

int main()
{

    int k,n;
    scanf("%d %d",&k,&n);
    int v[n],w[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",v+i,w+i);

    }
    if(!n)
    {
        cout<<0;
        return 0;
    }


    for(int i=0;i<=k;i++)
    {
        if(i<w[0])dp[0][i]=0;else dp[0][i]=v[0];
    }


    bool jb=1;
    for(int j=1;j<n;j++)
    {

        for(int i=0;i<=k;i++)
        {
            if(i<=w[j])dp[jb][i]=dp[!jb][i];
            else
            {
                dp[jb][i]=max(dp[!jb][i],v[j]+dp[!jb][i-w[j]]);
            }
        }
        jb=!jb;
    }

    cout<<dp[!jb][k];




    return 0;
}
