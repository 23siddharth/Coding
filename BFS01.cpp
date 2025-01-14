#include <bits/stdc++.h>
using namespace std;


/*
This time you are given a directed graph, so there is no certainty that there exists a path from source to destination.
So we are asked to find the min no of reversals required.
So we tactfully treated the reversals as edges with weight of 1
** Remember level is the dist from the source.
** And the normal edges had no weights.
** Thus the level of destination gives the min no of reversed edges we used to reach it from source.
Since the queue maintains elements upto 2 levels, we can push in elements in the first level after pushing some in the second level using deque.
Thus we avoid visited array in this can to allow for a level decrease if possible.
Each child's level is changed at max 2 times.
Time complexity is still O( V + 2*E )... which we write as O(V+E)
Also notice the space complexity is reduced by V (vis array of V size)

*/

const int N=1e5+10;
int INF=1e9+10;
vector<pair<int,int>> G[N];
vector<int> lev(N, INF);

int s=1,n=1;
int bfs01()
{
    deque<int> q;
    lev[s]=0;
    q.push_back(s);

    while(!q.empty())
    {
        int par=q.front();
        q.pop_front();
        for(auto childpair : G[par])
        {
            int child=childpair.first, wt=childpair.second;
            if(lev[par] + wt < lev[child])
            {
                lev[child]=lev[par]+wt;
                if(wt==0)
                    q.push_front(child);
                else
                    q.push_back(child);
            }
        }
    }
    return lev[n];
}
int main()
{
    int v, e;
    cin >> v >> e;
    while(e--)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back({y,0});
        G[y].push_back({x,1});
    }
    s=1; n=v;
    cout << bfs01() << endl;
}
