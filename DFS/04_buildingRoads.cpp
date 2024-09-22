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
vector<list<int>> adjList;
unordered_set<int> st;
void connectedComponents(int root){
    if(st.count(root)) return;
    st.insert(root);
    for(auto& neigh : adjList[root]){
        connectedComponents(neigh);
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    adjList.clear();
    adjList.resize(n+1);
    for(int i = 0;i < m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int count = 0;
    vector<vector<int>> ans;
    int prev = 0;
    for(int i = 1; i <= n; i++){
        if(!st.count(i)){
            count++;
            connectedComponents(i);
            if(prev != 0){
                ans.push_back({prev , i});
            }
            prev = i;
        }
    }
    cout<<(count-1)<<endl;
    for(auto & ele : ans) cout<<ele[0]<<" "<<ele[1]<<endl;
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}