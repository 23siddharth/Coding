/*
Leave no Witnesses
Let B be a binary string of length N.
The integer X is said to be a witness for B if the following condition holds:
• Consider two arrays S1 and S2, initially both empty.
• For each index i (1 < i< N),
	 If Bi = 0, append (X & i) to S1.
Here, & represents the bitwise AND operation.
	 If Bi = 1, append (X | i) to Sz.
Here, represents the bitwise OR operation.
• In the end, if S1 ^ S2 = D holds, i.e. S1 and S have no common elements, then X is said to be a witness for B.

For example, consider B = 010.
• X = 1 is a witness for this string, because S1 = [1 & 1, 1 & 3] = [1, 1], and S2 =
[1 | 2] = [3] are disjoint.
• X = 2 is not a witness for this string, because S1 = [2 & 1, 2 & 3] = [0, 2], and
S2 = 12 | 2] = 2] are not disjoint (they both contain the element 2).
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<int>st;
    for(int x=1; x<=2e5; x<<=1)
    {
        st.insert(x);
        if(n-x==0)
        {
            cout << -1 << endl;
            return;
        }
    }
    
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(st.find(i)!=st.end())
        {
            cnt+=(s[i-1]=='0');
        }
        else if(s[i-1]=='1')
        {
            int add=i^(i|(i+1));
            if(i+add>n)
                cnt++;
        }
    }
    
    cout << cnt << endl;
}
int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
