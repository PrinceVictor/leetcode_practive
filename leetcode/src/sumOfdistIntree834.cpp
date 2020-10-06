//
// Created by victor on 2020/10/6.
//

#include "sumOfdistIntree.h"

namespace SumofDistinTree{

vector<vector<int>> edges_(){
    return {{0,1}, {0,2}, {2,3}, {2,4}, {2,5}};
}

int N_(){
    return 6;
}

void dfs(vector<vector<int>>& graph,
         vector<int>& subsum, vector<int>& count, vector<int>& ans,
         int u, int root){
    subsum[u] = 0;
    count[u] = 1;
    for(auto &v : graph[u]){
        if(v == root) continue;
        dfs(graph, subsum, count, ans, v, u);
        subsum[u]+= subsum[v]+count[v];
        count[u]+=count[v];
    }
}

void dfs2(vector<vector<int>>& graph,
          vector<int>& subsum, vector<int>& count, vector<int>& ans,
          int u, int root){
    ans[u] = subsum[u];
    for(auto &v : graph[u]){
        if(v==root) continue;
        int sum_u = subsum[u], sum_v = subsum[v];
        int cnt_u = count[u], cnt_v = count[v];

        subsum[u] -= subsum[v] + count[v];
        count[u] -= count[v];
        subsum[v] += subsum[u] + count[u];
        count[v] += count[u];

        dfs2(graph, subsum, count, ans, v, u);

        subsum[u] = sum_u, subsum[v] = sum_v;
        count[u] = cnt_u, count[v] = cnt_v;
    }

}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>> edges) {
    vector<int> ans(N);
    vector<vector<int>> graph(N);
    vector<int> subsum(N);
    vector<int> count(N);

    for(auto& it: edges){
        graph[it[0]].emplace_back(it[1]);
        graph[it[1]].emplace_back(it[0]);
    }
    dfs(graph, subsum, count, ans, 0, -1);
    dfs2(graph, subsum, count, ans, 0, -1);

    for(auto it: ans){
        printf("%d\t", it);
    }
    printf("\n%d\n", ans.size());

    return ans;
}

}