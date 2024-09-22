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
void dfs(int root, vector<int> & inDeg){
    if(st.count(root) || inDeg[root] > 0) return;
    cout<<root<<" ";
    st.insert(root);
    for(auto& neighbours : adjList[root]){
        inDeg[neighbours]--;
        if(inDeg[neighbours] == 0) dfs(neighbours, inDeg);
    }
}
void solve() {
    int n = 10;
    adjList.clear();
    adjList.resize(n);
    vector<vector<int>> edjes =  {{0,1},{0,2},{1,4},{1,3},{1,2},{3,5},{5,6},{5,7},{5,8},{7,8},{8,9}};
    for(auto& ele : edjes) addEdge(ele[0], ele[1], false);
    vector<int> inDeg(n,0);
    for(int i = 0 ; i < n; i++){
        for(auto& neigh : adjList[i]){
            inDeg[neigh]++;
        }
    }
    int src = 0;
    for(auto & ele : inDeg){
        if(ele == 0 && !st.count(ele)){
            dfs(ele, inDeg);
        }
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