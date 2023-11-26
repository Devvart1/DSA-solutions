
class Solution {
public:
   class State {
   public:
      int keys, i, j;

      State(int keys, int i , int j) {
         this->keys = keys;
         this->i = i;
         this->j = j;

      }
   };
   bool isValid(int i , int j , vector<string>& grid) {

      if (i >= 0 and j >= 0 and j < grid[0].size() and i < grid.size() ) {
         return true;
      }
      return false;
   }
   int dx[4][4] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};

   int shortestPathAllKeys(vector<string>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      int si;
      int sj;
      int TotKeys = 0;
      for (int i = 0; i < n; ++i) {

         for (int j = 0; j < m; ++j) {
            char c = grid[i][j];

            if (c >= 'a' and c <= 'f')TotKeys++;

            if (grid[i][j] == '@')
            {
               si = i;
               sj = j;
            }
         }
      }


      State state(0, si, sj);

      queue<State> q;
      set<string> visited;

      visited.insert(to_string(0) + " " + to_string(si) + " " + to_string(sj));

      q.push(state);
      int ans = 0;

      while (q.size()) {
         int sije = q.size();
         while (sije--) {
            auto cur = q.front();


            if (cur.keys == (1 << TotKeys) - 1) return ans;

            int i = cur.i;
            int j = cur.j;
            ans++;

            q.pop();

            int curKey = cur.keys;
            for (int k = 0; k < 4; k++) {

               int _i = i + dx[k][0];
               int _j = j + dx[k][1];

               char c = grid[_i][_j];

               if (isValid(i, j, grid)) {
                  if (c == '#')continue;

                  if (c >= 'a' and c <= 'f') {
                     curKey |= (1 << (c - 'a'));
                  }
                  if (c >= 'A' anf c <= 'F' and ((curKey >> (c - 'A')) & 1) == 0)continue;

                  if (!visited.find(to_string(curKey) + " " + to_string(_i) + " " + to_string(_j))) {

                     visited.find(to_string(curKey) + " " + to_string(_i) + " " + to_string(_j));

                     q.push(new State(curKey, _i, _j));
                  }


               }

            }
         }
         ans++;

      }
      if (key != 0)
         return -1;
      return ans;

   }
};