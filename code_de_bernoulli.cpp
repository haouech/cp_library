This program takes as inpout two long integers : 1 <= n <= 10^9 and 1 <= k <= 10^6 , and it generates the Sum :

Sum{i=1..n}(i^k)%M


#include <stdio.h>
#define M 1000000007
int n,k,i,c,d;
long long y,z,u,v,r,f;

int F(long long a,int b){
    for (f=1;b;b>>=1,a=a*a%M){if (b&1)f=f*a%M;}
    return f;
}


int main()
{
    cin >> n >> k ;
    if (n<=++k){for(i=1;i<=n;i++)r+=F(i,k-1);}
    else{
        for (u=v=1;i<=k;i++){u=(u*(n-i))%M;if (i)v=((v*-i)%M+M)%M;}
        for (i=0,c=1,d=k;i<=k;i++,c++,d--){
            z=(z+F(i,k-1))%M;
            y=u*z%M*F(n-i,M-2)%M*F(v,M-2)%M;
            v=v*c%M*F(d,M-2)%M;
            if(i&1)y=M-y;r+=y;
        }
    }
    if (!--k&&n>1)r--;
    cout << r%M << endl;
}
