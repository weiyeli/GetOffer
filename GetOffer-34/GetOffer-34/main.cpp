//
//  main.cpp
//  GetOffer-34
//
//  Created by liweiye on 2020/6/2.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> vec;
        preorderTraversal(root, sum, vec);
        return res;
    }

    void preorderTraversal(TreeNode* root, int sum, vector<int>& vec) {
        if (root == nullptr) return;
        vec.push_back(root->val);
        int currentSum = sum - root->val;
        if (currentSum == 0 && root->left == nullptr && root->right == nullptr)
            res.push_back(vec);
        preorderTraversal(root->left, currentSum, vec);
        preorderTraversal(root->right, currentSum, vec);
        vec.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
