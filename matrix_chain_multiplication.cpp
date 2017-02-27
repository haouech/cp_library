 1 #include<iostream>
 2 using namespace std;
 3 //P as the matrix chain, p[0], p[1] represents the first matrix, p[1], p[2] represents the second matrix, length is the length of the p
 4 //So if there are six matrix, length=7 matrix, m as storage optimal results, t as storage optimal results route
 5 //Two dimensional matrix
 6 void MatrixChainOrder(int *p,int (*m)[10],int (*t)[10],int length)
 7 {
 8     int n=length-1;
 9     int i,j,k,q,num=0;
10     //A[i][i]Only one matrix multiplication, so the number 0, M[i][i]=0;
11     for(i=1;i<length;i++)
12     {
13         m[i][i]=0;
14     }
15     //I represents the matrix chain length, i=2 says how to divide the two matrix multiplication when
16     for(i=2;i<=n;i++)
17     {
18         //J j from the matrix of the I matrix to partition is optimal
19         for(j=1;j<=n-i+1;j++)
20         {
21             //K j from the I number of a matrix is k, from J to K to I between them a matrix partition
22             k=j+i-1;
23             //m[j][k]The optimal results from J to K using the optimal partitioning the storage
24             m[j][k]=0x7fffffff;
25             //Q is between J to k-1 number, purpose is divided by Q for exploratory matrix between K to j to, 
26             //In order to find the best partition, this is an ergodic test. 
27             for(q=j;q<=k-1;q++)
28             {
29                 num=m[j][q]+m[q+1][k]+p[j-1]*p[q]*p[k];
30                 if(num<m[j][k])
31                 {
32                     m[j][k]=num;
33                     t[j][k]=q;
34                 }
35             }
36         }
37     }
38 }
39 void PrintAnswer(int(*t)[10],int i,int j)
40 {
41     if(i==j)
42     {
43         cout<<"A"<<i;
44     }
45     else
46     {
47         cout<<"(";
48         PrintAnswer(t,i,t[i][j]);
49         PrintAnswer(t,t[i][j]+1,j);
50         cout<<")";
51     }
52 
53 }
54 int main()
55 {
56     int p[7]={30,35,15,5,10,20,25};
57     int m[10][10],t[10][10];
58     MatrixChainOrder(p,m,t,7);
59     MatrixChainOrder(p,m,t,7);
60     PrintAnswer(t,1,6);
61     cout<<endl;
62     return 0;
63 }
