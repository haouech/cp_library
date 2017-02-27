    #include <bits/stdc++.h>
    using namespace std;
    const int N = 8;
    int arr[N] = { 5,25,6,11,5,4,7,8 };
    int M[N];
    int prev[N];
    int Mem[N];

    int lis(){
    	int L = 0;
    	for(int i=0;i<N;i++){
    		int idx = lower_bound(M,M+L,arr[i]) - M;
    		M[idx] = arr[i];
    		Mem[idx] = i;
    		if(idx==L)
    			L++;
    		if(idx==0) prev[i] = -1;
    		else prev[i] = Mem[idx-1];
    	}
    	return L;
    }



    int main() {
    	int len = lis();
    	cout << len << endl;
    	for(int i=0;i<N;i++)
    		cout << prev[i] << " ";
    	return 0;
    }
