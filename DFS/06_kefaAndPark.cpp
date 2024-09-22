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
void addEdge(int src, int dest, bool isBiDir = true) {
    adjList[src].push_back(dest);
    if(isBiDir){
        adjList[dest].push_back(src);
    }
}

vector<int> hasCat;

int countRestorent(int root, int &k , int catFounds){
    if(hasCat[root] == 1) catFounds++;
    else catFounds = 0;
    if(catFounds > k) return 0;
    if(adjList[root].size() == 1 && root != 1) return 1;
    if(st.count(root)) return 0;
    st.insert(root);
    int ans = 0;
    for(auto& neigh : adjList[root]){
        ans += countRestorent(neigh, k, catFounds);
    }
    st.erase(root);
    return ans;
}


void solve() {
    int n,k;
    cin>>n>>k;
    adjList.clear();
    adjList.resize(n+1,list<int> ());
    hasCat.clear();
    hasCat.reserve(n+1);
    for(int i = 1; i <= n; i++){
        cin>>hasCat[i];
    }
    for(int i = 1 ; i < n; i++){
        int src, des;
        cin>>src>>des;
        addEdge(src, des, true);
    }

    // for(auto &ele : adjList){
    //     for(auto & neigh : ele) cout<<neigh<<" ";
    //     cout
    // }
    cout<<countRestorent(1, k, 0)<<endl;

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