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
void addEdge(int src, int des, bool isBiDir = true){
    adjList[src].push_back(des);
    if(isBiDir) adjList[des].push_back(src);
}
unordered_set<int> st;
bool haveCycle(int root){
    if(st.count(root)) return true;
    st.insert(root);
    bool ans = false;
    for(auto& neigh : adjList[root]){
        ans = ans || haveCycle(neigh);
    }
    st.erase(root);
    return ans;
}
void solve() {
    int n = 10;
    adjList.clear();
    adjList.assign(n, list<int>());
    vector<vector<int>> edges =  {{0,1},{0,2},{1,4},{1,3},{1,2},{3,5},{5,6},{5,7},{5,8},{7,8},{8,9}};      
    for(auto& ele : edges) addEdge(ele[0], ele[1], false);
    if(haveCycle(0)){
        cout<<"YES graph have cycle";
    }else{
        cout<<"NO graph does not have cycle";
    }
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