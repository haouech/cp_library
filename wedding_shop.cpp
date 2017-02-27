/* wedding shop */

int shop(int money, int g){
if (money < 0) return -1000000000; // order of >1 base cases is important
if (g == C) return M - money; // money can’t be <0 if we reach this line
int &ans = memo[money][g];
// remember the memory address
if (ans != -1) return ans;
for (int model = 1; model <= price[g][0]; model++)
ans = max(ans, shop(money - price[g][model], g + 1));
return ans;
// ans (or memo[money][g]) is directly updated
}


/* A Naive Recursive C++ program to count derangements  */
A Derangement is a permutation of n elements, such that no element appears in its original position. 
For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.

Given a number n, find total number of Derangements of a set of n elements.

countDer(n) = (n-1)*[countDer(n-1) + countDer(n-2)] ;

/* 	  */
