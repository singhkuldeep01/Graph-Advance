#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define MOD 1000000007
#define F first
#define S second
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}

vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &visited){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] == 1 || grid[i][j] == '#'){
        return;
    }
    visited[i][j] = 1;
    for(int k = 0 ; k < dir.size(); k++){
        int newI = i + dir[k][0];
        int newJ = j + dir[k][1];
        dfs(newI, newJ, grid, visited);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0 ;j < m; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> visited(n, vector<int>(m,0));
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0;j < m; j++){
            if(grid[i][j] == '.' && visited[i][j] == 0){
                dfs(i, j, grid, visited);
                ans++;
            }
        }  
    }
    cout<<ans;
}

int64_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}