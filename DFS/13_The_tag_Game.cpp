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

vector<list<int>> adj;
void addEdges(int src, int des){
    adj[src].push_back(des);
    adj[des].push_back(src);
}
vector<int> reachedByA;
unordered_set<int> st;
void dfs(int src , int dis){
    if(st.count(src)) return;
    st.insert(src);
    reachedByA[src] = dis;
    for(auto child : adj[src]){
        dfs(child, dis+1);
    }
}
int ans = 0;
void countMax(int src, int des){
    if(st.count(src)) return;
    st.insert(src);
    if(des < reachedByA[src]) ans = max(ans, 2*reachedByA[src]);
    for(auto child : adj[src]){
        countMax(child, des+1);
    }
}

void solve() {
    adj.clear();
    int n,b;
    cin>>n>>b;
    adj.resize(n+1);
    reachedByA.clear();
    reachedByA.resize(n+1,0);
    for(int i = 1 ; i < n; i++){
        int src, des;
        cin>>src>>des;
        addEdges(src,des);
    }
    st.clear();
    dfs(1,0);
    st.clear();
    countMax(b,0);
    cout<<ans;
    
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