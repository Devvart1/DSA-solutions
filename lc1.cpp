/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   void makeGraph(unordered_map<int, vector<int>> &adj, TreeNode*par, TreeNode*child) {



      adj[par->val].push_back(child->val);
      adj[child->val].push_back(par->val);

      if (child->left) {
         makeGraph(adj, child, child->left);
      }
      if (child->right) {
         makeGraph(adj, child, child->right);
      }
   }
   vector<int> distK(TreeNode* root, TreeNode* target, int k) {

      unordered_map<int, vector<int>> adj;
      if (root->left)
         makeGraph(adj, root, root->left);
      if (root->right)
         makeGraph(adj, root, root->right);


      // for (auto x : adj) {
      //    cout << x.first << "->";
      //    for (auto y : x.second) {
      //       cout << y << " ";
      //    }
      //    cout << endl;
      // }
      set<int> vis;
      queue<int>q;
      vector<int> ans;
      q.push(root->val);
      int level = 1;
      while (q.size())
      {
         int sije = q.size();

         while (sije--) {
            int cur = q.front();
            vis.insert(cur);
            q.pop();
            for (int x : adj[cur]) {
               if (vis.find(x) == end())
                  q.push_back(x);
            }
            if (level == k) {
               ans.push_back(cur);
            }
         }
         level++;

      }
      return ans;
   }
};