#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// No. of Subarray(s) with sum = 0

ll _ss0(vector<ll>a)
{
    ll n=a.size();
    map<ll, ll> mp;
    mp[0]=1;
    ll sum=0;
    ll mx=0;
    for(int i=0; i<n; i++)
    {
        sum+=a[i];
        if(mp.find(sum)!=mp.end())
        {
            mx+=mp[sum];
        }
        mp[sum]++;
    }
    return mx;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    cout << _ss0(a);
}
