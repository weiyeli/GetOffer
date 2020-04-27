//
//  main.cpp
//  GetOffer-38
//
//  Created by liweiye on 2020/4/26.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        if (s.size() <= 0) return res;
        if (s.size() == 1) {
            res.push_back(s);
            return res;
        }
        dfs(s, 0);
        return res;
    }

private:
    // 以pos开头的字符串input的全排列
    void dfs(string& s, int pos) {
        if (pos >= s.size()) {
            res.push_back(s);
            return;
        }
        // 从自身开始，依次把每一个元素放在pos这个位置上
        for (int i = pos; i < s.size(); ++i) {
            if (hasRedundantElement(s, pos, i)) continue;
            swap(s[i], s[pos]);
            dfs(s, pos + 1);
            swap(s[pos], s[i]);
        }
    }

    bool hasRedundantElement(string& s, int start, int end) {
        for (int i = start; i < end; i++) {
            if (s[i] == s[end]) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> res = s.permutation("aabb");
    for (auto i: res) {
        cout << i << endl;
    }
}
