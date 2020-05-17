//
//  main.cpp
//  GetOffer-13
//
//  Created by liweiye on 2020/5/17.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// dfs
class Solution_DFS {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n));
        int ans = dfs(0, 0, m, n, k, visited);
        return ans;
    }

private:
    int sums(int x) {
        int sums = 0;
        while (x != 0) {
            sums += x % 10;
            x = x / 10;
        }
        return sums;
    }

    int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= m || j >= n || sums(i) + sums(j) > k || visited[i][j] == true) {
            return 0;
        }
        visited[i][j] = true;
        return 1 + dfs(i, j + 1, m, n, k, visited) + dfs(i, j - 1, m, n, k, visited)
        + dfs(i + 1, j, m, n, k, visited) + dfs(i - 1, j, m, n, k, visited);
    }
};

// bfs
class Solution_BFS {
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int, int> > Q;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int> > vis(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 2; i++) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || sums(tx) + sums(ty) > k) continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return 0;
    }

private:
    int sums(int x) {
        int sums = 0;
        while (x != 0) {
            sums += x % 10;
            x = x / 10;
        }
        return sums;
    }
};

// 递推
class Solution_Ditui {
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j == 0) || sums(i) + sums(j) > k) continue;
                // 边界判断
                if (i - 1 >= 0) vis[i][j] |= vis[i - 1][j];
                if (j - 1 >= 0) vis[i][j] |= vis[i][j - 1];
                ans += vis[i][j];
             }
        }
        return ans;
    }
private:
    int sums(int x) {
        int sums = 0;
        while (x != 0) {
            sums += x % 10;
            x = x / 10;
        }
        return sums;
    }
};

int main(int argc, const char * argv[]) {
    Solution_Ditui solution1;
    int ans = solution1.movingCount(16, 8, 4);
    cout << ans << endl;
}
