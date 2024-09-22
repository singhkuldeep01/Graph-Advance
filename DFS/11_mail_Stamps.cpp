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

unordered_map<int,list<int>>adj;
unordered_map<int,int> degree;
vector<int> ans;
void addEdges(int src , int des){
    adj[src].push_back(des);
    adj[des].push_back(src);
    degree[src]++;
    degree[des]++;
}

int checkRoot(){
    for(auto& ele : degree){
        if(ele.second == 1){
            return ele.first;
        }
    }
}

unordered_set<int> st;
void dfs(int src){
    if(st.count(src)) return;
    ans.push_back(src);
    st.insert(src);
    for(auto &child : adj[src]){
        dfs(child);
    }
}

void solve() {
    int n;
    cin>>n;
    adj.clear();
    for(int i = 0; i < n; i++){
        int src, des;
        cin>>src>>des;
        addEdges(src, des);
    }
    int src = checkRoot();
    checkRoot();
    dfs(src);
    for(auto& ele : ans) cout<<ele<<" ";
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