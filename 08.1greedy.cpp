#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n1 = g.size();
    int n2 = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int r=0,l=0;
    while (l<n2 && r<n1)
    {
        if(g[r]<=s[l]){
            r++;
        }
        l++;
    }
    return r;
}

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    //sort(bills.begin(), bills.end());
    for(int i = 0 ;i < bills.size(); i++){
        if(bills[i]==5) five ++;
        else if(bills[i] ==10){
            if(five){
                five--;
                ten++;
            }else{
                return false;
            }
        } else {
            if(ten && five){
                five--;
                ten--;
            }else if(five>=3){
                five -=3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int sjf(vector<int>& q){
    sort(q.begin(), q.end());
    int t = 0, w= 0;
    for(int i = 0 ;i < q.size(); i++){
        w += t;
        t +=q[i];
    }
    return w/q.size();
}

bool jump1(vector<int>& p){
    int maximum = 0;
    for(int i = 0 ; i<p.size() ; i++){
        if( maximum<i) return false;
        maximum = max(maximum, i+p[i]);
    }
    return true;
}

// int jump2(vector<int>& p){
//     int count = 0 , maximum = 0;
//     for(int i = 0,left = 0 ;i < p.size(); i++, left--){
//         maximum = max(maximum, p[i]);
//         if(left==0 && i!=p.size()-1){
//             left = maximum;
//             maximum = 0;
//             count+=1;
//         }
//     }
//     return count;
// }

int jump2(vector<int>& nums){
    int jump = 0, farthest = 0, n = nums.size();
    int r = 0 , l = 0;
    while (r< n-1)
    {   
        farthest = 0;
        cout<<nums[l]<<endl;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i+nums[i]);
        }
        l = r+1;
        r =  farthest;
        jump +=1;
    }
    return jump;
}

struct Data {
    int start;
    int end;
    int pos;
};

int activity(vector<int>& s, vector<int>& e, int n ){
    vector<Data> arr(n);
    for(int i = 0 ; i< n ;i ++){
        arr[i].start = s[i];
        arr[i].end = e[i];
        arr[i].pos = i+1;
    }
    sort(arr.begin(), arr.end(), [](Data a, Data b){
        if (a.end != b.end) return a.end < b.end;
        if (a.start != b.start) return a.start < b.start;
        return a.pos < b.pos;
    });
    vector<int> standings;
    int count = 1, finish = arr[0].end;
    standings.push_back(arr[0].pos);
    for(int i = 1 ;i < n ;i ++){
        if(arr[i].start > finish){
            count++;
            finish= arr[i].end;
            standings.push_back(arr[i].pos);
        }
    }
    return count;  // alternately return the standings vector if asked for the order
}

int spanningTreePrim(vector<vector<vector<int>>> adj, int V){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> p;
    vector<int> vis(V,0);
    p.push({0,0});
    int sum = 0;
    while (!p.empty()) 
    {
        pair<int, int> a = p.top();
        p.pop(); 
        int node = a.second;
        int wt = a.first;
        if(vis[node] == 1)continue;
        vis[node] =1;
        sum+=wt;
        for (vector<int> it : adj[node]){ 
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode]) {
                p.push({edW, adjNode}); 
			}
        }
    } 
    return sum;
}


int main() {
    auto start = high_resolution_clock::now();

    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 2, 2}
    };

    vector<vector<vector<int>>> adj(V);

    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    int mstCost = spanningTreePrim(adj, V);
    cout << "Total weight of MST: " << mstCost << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}