#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(0);


vector<list<int>> adjList;

void addEdge(int src, int dest, bool isBiDir = true) {
    adjList[src].push_back(dest);
    if(isBiDir){
        adjList[dest].push_back(src);
    }
}

void traversal(){
    for(int i = 0 ; i < adjList.size(); i++){
        if(i == 0) continue;
        cout<<i<<" -> ";
        for(auto& ele : adjList[i]){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}

int totalPaths(int src, int des, unordered_set<int> &st, vector<int> &temp){

    if(src == des){
        temp.push_back(des);
        for(auto& ele : temp) cout<<ele<<" ";
        cout<<endl;
        temp.pop_back();
        return 1;
    }
    if(st.count(src)) return 0;
    temp.push_back(src);

    st.insert(src);
    int ans = 0;
    for(auto& child : adjList[src]){
        ans += totalPaths(child, des, st, temp);
    }
    st.erase(src);
    temp.pop_back();
    return ans;

}

int ShortestPath(int src, int des){
    queue<pair<int,int>> q;
    q.push({src,0});
    unordered_set<int> st;
    while(q.size()){
        int src = q.front().first;
        int wt = q.front().second;
        q.pop();
        if(src == des){
            return wt;
        }
        st.insert(src);
        for(auto& child : adjList[src]){
            if(st.count(child)) continue;
            q.push({child, wt+1});
        }
    }
    return -1;

}

void solve() {
    int n = 7;
    vector<vector<int>> edges = {{1,2},{1,4},{2,3},{5,6},{5,7}, {4,3}, {6,7}, {2,5}};
    adjList.clear();
    adjList.resize(n+1, list<int>());
    for(auto& ele : edges) addEdge(ele[0], ele[1]);
    // traversal();
    unordered_set<int> st;
    vector<int> temp;
    // cout<<totalPaths(1, 7, st, temp);
    cout<<ShortestPath(1,7);
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