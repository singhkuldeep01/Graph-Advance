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

vector<list<pair<int,int>>> adj;
void addEdge(int src, int des, int wt){
    adj[src].push_back({des,wt});
    adj[des].push_back({src,wt});
}

unordered_set<int> st;
vector<int> dp;
int dfs(int src){
    st.insert(src);
    int ans = 0;
    for(auto& child : adj[src]){
        if(st.count(child.first)) continue;
        ans = max(ans,dfs(child.first)+child.second);
    }
    return  dp[src] = ans;
}

void solve() {
    int n;
    dp.clear();
    adj.clear();
    cin>>n;
    dp.assign(n,-1);
    adj.resize(n);
    for(int i = 0 ; i < n ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        addEdge(a,b,c);
    }
    cout<<dfs(0);
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