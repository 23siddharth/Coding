#include<bits/stdc++.h>
using namespace std;
#define int long long int
//mask
// _ _ _{_ _ _ _ _ 
// _ _ _}# _ _ _ _
int n, m;
int dp[12][12][1<<12];
int rec(int x, int y, int mask)
{
    //pruning
    if(y==m)
        return rec(x+1, 0, mask);
    //basecase;
    if(x==n)
    {
        if( mask==((1<<m)-1) )
            return 1;
        return 0;
    }
    if(dp[x][y][mask]!=-1)
        return dp[x][y][mask];
    int ans=0;
    if( (mask&(1<<(m-1)))==0  )
        ans=rec(x, y+1, (mask<<1)|1);
    else
    {
        if((mask&1)==0 && y>0)
        {
            int newmask= (((mask|1)<<1)&((1<<m)-1))|1;
            ans=rec(x, y+1, newmask);
        }
        int newmask=(mask<<1)&((1<<m)-1);
        ans+=rec(x, y+1, newmask);
    }
    return dp[x][y][mask]=ans;

}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        int mask=(1<<m)-1;
        cout << rec(0, 0, mask) << endl;
    }
}
