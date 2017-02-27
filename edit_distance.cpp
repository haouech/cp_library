#include <bits/stdc++.h>

using namespace std;
int T ;
int dp[2016][2016] ;
string s1,s2;


int main()
{
    cin >> T ;

    for(int cases = 1 ; cases <= T ; cases++){

    memset(dp , 0 , sizeof dp);

    cin >> s1 >> s2 ;
    
    for(int i = 0 ; i < max(s1.size() ,s2.size()) ; i++){dp[i][0] = dp[0][i] = i ;}

    for(int i = 1 ; i <= s1.size() ; i++){
        for(int j = 1 ; j <= s2.size() ; j++){
         if(s1[i-1] == s2[j-1] ){
         dp[i][j] = dp[i-1][j-1] ;
         }
         else{
         dp[i][j] = min(dp[i][j-1] , min(dp[i-1][j]  ,dp[i-1][j-1]  )) + 1 ;
         }

        }

    }

    cout << dp[s1.size()][s2.size()] << endl;
    }
        return 0;
}
