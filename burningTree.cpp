//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
   void makeGraph(unordered_map<int, vector<int>> &adj, Node*par, Node*child) {

      adj[par->data].push_back(child->data);
      adj[child->data].push_back(par->data);

      if (child->left) {
         makeGraph(adj, child, child->left);
      }
      if (child->right) {
         makeGraph(adj, child, child->right);
      }
   }
   int minTime(Node* root, int target)
   {
      unordered_map<int, vector<int>>adj;
      if (root->left)
         makeGraph(adj, root, rot->left);
      if (root->right)
         makeGraph(adj, root, root->right);



      set<int> vis;
      queue<int>q;

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
         }
         level++;

      }
      return level;
      // Your code goes here
   }
};