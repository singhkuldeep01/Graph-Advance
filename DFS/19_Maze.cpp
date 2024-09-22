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
vector<vector<int>> visited;
void dfs(vector<vector<char>>& matrix , int i , int j , int &k){
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || visited[i][j] || matrix[i][j] == '#') return;
    visited[i][j] = 1;
    dfs(matrix, i+1, j , k);
    dfs(matrix, i-1, j , k);
    dfs(matrix, i, j+1, k);
    dfs(matrix, i, j-1, k);
    if(k) matrix[i][j] = 'X', k--;

}

void solve() {
    int r, c, k;
    cin>>r>>c>>k;
    vector<vector<char>> matrix;
    visited.clear();
    visited.resize(r, vector<int>(c, 0));
    for(int i = 0 ; i < r ; i++){
        vector<char> temp;
        for(int j = 0 ; j < c ; j++){
            char x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if(matrix[i][j] == '.' && k){
                dfs(matrix, i, j, k);
            }
        }
        if(!k) break;
    }
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

int32_t main()
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