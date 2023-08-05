/*
Input 
6
0 16 13 0 0 0
0 0 10 12 0 0
0 4 0 0 14 0
0 0 9 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0
Output
23
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

bool bfs(vector<vector<int> >& rg, int source, int sink, vector<int>& parent){
	queue<int> q;
	vector<bool> visited(rg.size(), false);
	visited[source]=true;
	q.push(source);
	parent.at(source)=-1;
	while(!q.empty()){
    	int u=q.front();
    	q.pop();
    	for(int v=0; v<rg.size(); v++){
        	if(v==sink && rg[u][v]>0 && !visited[v]){
            	parent[sink]=u;
            	return true;
        	}
        	if(rg[u][v]>0 && !visited[v]){
            	visited[v]=true;
            	parent[v]=u;
            	q.push(v);
        	}
    	}
	}
	return false;
}

int fordFlukerson(vector<vector<int> >& g, int source, int sink){
	vector<vector<int> > rg=g;
	vector<int> parent(rg.size(),-1);
	int maxFlow=0;
	while(bfs(rg, source, sink, parent)){
    	int bottleNeckCapacity=INT_MAX;
    	for(int v=sink; v!=source; v=parent[v]){
        	bottleNeckCapacity=min(rg[parent[v]][v], bottleNeckCapacity);
    	}
    	for(int v=sink; v!=source; v=parent[v]){
        	rg[parent[v]][v]-=bottleNeckCapacity;
        	rg[v][parent[v]]+=bottleNeckCapacity;
    	}
    	maxFlow+=bottleNeckCapacity;
	}
	return maxFlow;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > g(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
        	cin>>g[i][j];
    	}
    }
    cout<<fordFlukerson(g, 0, n-1);
    return 0;
}
