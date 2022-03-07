#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int SIZE = 1005;
int n, a[SIZE][SIZE], m, vis[SIZE][SIZE];
int dy1[] = {1, 1, 0, -1, -1};
int dx1[]  ={0, 1, 1, 1, 0};
int dx2[] = {0, -1, -1, -1, 0};
int dy2[] = {-1, -1, 0, 1, 1};
int id2[] = {4, 3, 2, 1, 0};
int id1[] = {0, 7, 6, 5, 4};
struct point{
    int x, y;
}s, t;
bool avai(int x, int y){
    return (x >= 1 && x <= n && y >=1 && y <= m);
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++){
        cin >> a[i][j];
        if(a[i][j] == 0) continue;
        if(s.x == 0) s = {i, j};
        t = {i, j};
    }
    int x =  s.x, y = s.y;
    vector<int> ans;
    while(x != t.x || y != t.y){
        int id, nx, ny;
        //cout << x << " " << y << endl;
        for(int i = 0; i < 5; i++){
            nx = x + dx1[i];
            ny = y + dy1[i];
            id = i;
            if(!avai(nx, ny) || vis[nx][ny]) continue;
            if(a[nx][ny] == 1)break;
        }
        ans.push_back(id1[id]);
        x = nx, y = ny;
        vis[x][y] = 1;
    }
    //cout << x << " " << y << endl;
    //for(auto j: ans) cout << j;
    //cout << endl;
    while(x != s.x || y != s.y){
        int id, nx, ny;
        //cout << x << " " << y << endl;
        for(int i = 0; i < 5; i++){
            nx = x + dx2[i];
            ny = y + dy2[i];
            id = i;
            if(nx == s.x && ny == s.y){
                x = nx, y = ny;
                break;
            }
            if(!avai(nx, ny) || vis[nx][ny]) continue;
            if(a[nx][ny] == 1)break;
        }
        ans.push_back(id2[id]);
        x = nx, y = ny;
        vis[x][y] = 1;
    }
    for(auto j: ans) cout << j;
    cout << endl;
    return 0;

}
/*
3 3
0 0 1
1 1 1
1 1 1


6 7
0 0 0 0 0 0 0
0 0 1 1 1 0 0
0 1 1 1 1 0 0
0 0 1 1 1 1 0
0 0 0 1 1 1 0
0 0 0 0 0 0 0
*/
