#include <bits/stdc++.h>

using namespace std;

int T ;
int tab[12][12] ;
int dp[15][2050];



int solve(int pos,int state){
    if(state == 2047)return 0;
    if(pos==11) return -1000000;
    if(dp[pos][state] != -1)return dp[pos][state] ;
    int ans = -10000000 ;
    for(int i = 0 ; i < 11 ; i++){
        if( (state &  (1<<i)) == 0 && tab[pos][i]>0){
            ans = max(ans ,tab[pos][i] + solve( pos +1 , state | (1<< i) ) ) ;
        }
    }
    return dp[pos][state] = ans ;
}

int main()
{

//    freopen("test.in" ,"r" ,stdin) ;
    cin >> T ;
    for(int cases = 1 ; cases <= T ; cases++){

    memset(dp ,-1 , sizeof dp ) ;


      for(int i = 0 ; i < 11 ; i++){
        for(int j = 0 ; j < 11 ; j++){
         cin >> tab[i][j] ;
        }
      }

    cout << solve(0,0) << endl;

    }
    return 0;
}

