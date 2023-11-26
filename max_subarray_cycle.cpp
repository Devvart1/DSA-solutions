class Solution {
public:

  int kadane(vector<int> v)
  {
    int n = v.size();
    int newmax = v[0]
                 sum = 0;
    i = 0;

    while (i < n) {

      sum += v[i];

      newmax = max(newmax, sum);
      if (sum < 0)
        sum = 0;

      i++;



    }
    return newmax;

  }
  int maxSubarraySumCircular(vector<int>& v) {
    int n = v.size();



    int raw_sum = 0;
    int kadan = kadane(v);

    for (int i = 0; i < n; ++i)
    {
      v[i] *= -1;
      cout << v[i] << " ";

    }
    for (int x : v)
    {
      raw_sum += x;


    }


    int neg_kadane = kadane(v);
    if (raw_sum + neg_kadane == 0)
      return kadan;


    return max(raw_sum + neg_kadane ,  kadan);
  }
};