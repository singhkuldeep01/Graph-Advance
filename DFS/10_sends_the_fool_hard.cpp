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

vector<vector<pair<int,int>>> adj;
vector<vector<int>> dp_true, dp_false;
int k;

void addEdge(int src, int des, int wt){
    adj[src].push_back({des,wt});
    adj[des].push_back({src,wt});
}

void dfs(int v, int parent) {
    vector<int> child_true;
    for(auto& child : adj[v]) {
        if(child.first != parent) {
            dfs(child.first, v);
            child_true.push_back(dp_true[child.first][1] + child.second);
        }
    }
    sort(child_true.rbegin(), child_true.rend());
    
    int sum_true = 0;
    for(int i = 0; i < min((int)child_true.size(), k); i++) {
        sum_true += child_true[i];
    }
    dp_true[v][1] = sum_true;
    
    int max_false = 0;
    for(int i = 0; i < child_true.size(); i++) {
        int current_false = sum_true;
        if(i < k) {
            current_false -= child_true[i];
        }
        current_false += dp_false[adj[v][i].first][0];
        max_false = max(max_false, current_false);
    }
    dp_false[v][0] = max_false;

    // Debugging output
    cout << "Node: " << v << ", dp_true: " << dp_true[v][1] << ", dp_false: " << dp_false[v][0] << endl;
}

void solve() {
    int n;
    cin >> n >> k;
    adj.clear();
    adj.resize(n);
    dp_true.assign(n, vector<int>(2, 0));
    dp_false.assign(n, vector<int>(2, 0));
    
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    
    dfs(0, -1);
    cout << dp_false[0][0] << endl;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}