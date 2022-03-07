#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
const int SIZE = 2000;
int dp[SIZE][SIZE], vis[SIZE][SIZE];
int n, a[SIZE];
int f(int l, int r){
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = 1;
    if(l == r || (l + 1) %n == r) return dp[l][r] =0;

    for(int i = (l + 1) %n; i!= r; i = (i + 1) %n){
        dp[l][r] = max(dp[l][r], f(l, i) + f(i, r) + a[l] * a[r]);
    }
    return dp[l][r];
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int l = i %n;
        int r = (i - 1) %n;
        int ma = max(a[l], a[r]);
        ans = max(ans, f(l, r)  + ma * ma + ma);
    }
    cout << ans << endl;

}
