#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int SIZE = 3e6 + 5;
int cnt = 0, n,ans;
unordered_map<int, int> g[SIZE];
int t[SIZE], fa[SIZE];
int solve(vector<int> v){
    int cur = 1;
    int f = 0;
    int res = 0;
    for(int i =0; i < v.size(); i++){
        if(g[cur][v[i]] == 0){
            if(f == 0){
                res -= i * t[cur];
                //cout << i << " " << cur << " " << t[cur] << endl;
                f = 1;
            }
            g[cur][v[i]] = ++cnt;
            fa[cnt] = cur;
            cur = cnt;
        }else{
            cur = g[cur][v[i]];
        }
    }
    if(f == 0){
        res -= v.size() * t[cur];
    }
    while(cur != fa[cur]){
        t[cur] ++;
        cur=  fa[cur];
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    cnt ++;
    fa[1] =1;
    for(int i = 0; i < n; i++){
        vector<int> v;
        int p; cin >> p;
        for(int j = 0; j < p; j++){
            int x; cin >> x;
            v.push_back(x);
        }
        int d = solve(v);
        //cout << v.size() * v.size() << " " << d << endl;
        ans += v.size() * v.size() + d;
    }
    cout << ans << endl;
    return 0;
}

/*
5
5 1 2 3 4 5
5 1 2 5 4 3
5 4 2 3 4 5
6 1 2 3 5 6 7
4 1 2 3 6
*/
