class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        // int i=0;
        // while(i<32){
        //     if(n&(1<<i))
        //         ans++;
        //     i++;
        // }
        // while(n>0){
        //     n=n&(n-1); // in every iteration, unseting the right most set bit
        //     ans++;
        // }
        // while(n){
        //     ans+=n%2;
        //     n/=2;
        // }

        // return ans;
        return __builtin_popcount(n);
    }
};