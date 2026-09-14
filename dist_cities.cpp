#include <bits/stdc++.h>
using namespace std;

void solve(){
    int R;
    cin >> R;

    map<int, vector<pair<int,int>>> g;
    set<int> vis;

    while(R--){
        int src, dest, dist;
        cin >> src >> dest >> dist;

        g[src].push_back({dest, dist});
        g[dest].push_back({src, dist});
    }

    int st, end;
    cin >> st >> end;

    // {distance, city}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, st});

    while(!pq.empty()){
        auto [currdist, city] = pq.top();
        pq.pop();

        if(vis.find(city) == vis.end()){
            vis.insert(city);

            if(city == end){
                cout << currdist;
                return;
            }

            for(auto [oc, ocd] : g[city]){
                if(vis.find(oc) == vis.end()){
                    pq.push({currdist + ocd, oc});
                }
            }
        }
    }

    cout << -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
