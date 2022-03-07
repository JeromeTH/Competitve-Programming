#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, M;
const int SIZE = 1005;
int a[SIZE], deg[SIZE], blk[SIZE], num[SIZE], cnt, vis[SIZE];
vector<int> g[SIZE];
void dfs(int u){
    vis[u] = 1;
    blk[u] = cnt;
    num[cnt] ++;
    for(auto j: g[u]){
        if(vis[j]) continue;
        dfs(j);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = 1; j <= n; j++){
            int c; cin >> c;
            if(c== 1){
                deg[i] ++;
                g[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt ++;
            dfs(i);
        }
    }
    //for(int i = 1; i <= n; i++) cout << blk[i] << " ";
    //cout << endl;
    int ans = 0;
    for(int i= 1; i <= n; i++){
        if(deg[i] == num[blk[i]] - 1){
            ans += a[i];
            ans %= M;
            num[blk[i]] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
5
19
9 2 1 0 0 0
17 1 2 1 1 1
7 0 1 2 0 0
2 0 1 0 2 0
11 0 1 0 0 2


5
23
13 2 1 0 0 0
21 1 2 1 0 0
8 0 1 2 0 0
6 0 0 0 2 1
6 0 0 0 1 2

*/
