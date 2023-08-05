#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

int find(int parent[], int i){
	if(parent[i] == i) return i;
	return find(parent, parent[i]);
}

void _union(int parent[], int rank[], int u, int v){
	int up=find(parent,u);
	int vp=find(parent,v);
	if(rank[vp]<rank[up]){
    	rank[up]+=rank[vp];
    	parent[vp]=up;
	} else {
    	parent[up]=vp;
    	rank[vp]+=rank[up];
	}
}

int kargerAlgorithmForMinCut(vector<pair<int, int> >& edges, int parent[], int rank[], int n){
	int m=edges.size();
	while(n>2){
    	int i=rand()%m;
    	int u=edges[i].first;
    	int v=edges[i].second;
    	int uparent=find(parent, u);
    	int vparent=find(parent, v);
    	if(uparent==vparent) continue;
    	_union(parent, rank, u, v);
    	n--;
	}
	int ans=0;
	// cout<<n<<endl;
	for(int i=0; i<4;i++) cout<<parent[i]<<" ";
	for(pair<int, int>p : edges){
    	if(find(parent, p.first)!=find(parent, p.second)) {ans++;cout<<p.first<<"->"<<p.second<<endl;}
	}
	return ans/2;
}

int main() {
	srand(time(NULL));
	int n;
	cin>>n;
	vector<pair<int, int> > edges;
	vector<vector<int> > g(n, vector<int>(n, 0));
	int parent[n], rank[n];
	for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
        	cin>>g[i][j];
        	if(g[i][j] == 1) edges.push_back(make_pair(i, j));
    	}
    	parent[i]=i;
    	rank[i]=1;
	}
	for(int i=0;i<n;i++) cout<<parent[i]<<" ";
	cout<<endl;
    
	int ans=INT_MAX;
	// for(int i=0; i<10; i++)
    	ans=min(ans, kargerAlgorithmForMinCut(edges, parent, rank, n));
	cout<<endl<<ans;
    return 0;
}
/*
input:
4
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0
*/
