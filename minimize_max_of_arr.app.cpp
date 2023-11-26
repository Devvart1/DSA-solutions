class Solution {
public:

    bool isMaxPossible1(vector<int> nums, int maxInt) {
        //forward iteration approach
        //not correct(just works lol)

        int n = nums.size() ;
        vector<long long int> numsll(n) ;
        for (int i = 0  ; i < n ; i++) {
            numsll[i] = nums[i] ;
        }

        if (numsll[0] > maxInt) {
            return false ;
        }

        for (int i = 1 ; i < n ; i++) {

            long long int maxDecrement = maxInt - numsll[i - 1] ;
            long long int decrement = maxDecrement ; //just works but shouldnt hehe ;)

            numsll[i] -= decrement ;

            if (numsll[i] > maxInt) {
                return false;
            }

        }

        return true ;
    }

    bool isMaxPossible2(vector<int> &nums, int maxInt) {
        //backward iteration approach
        int n = nums.size() ;
        vector<long long int> numsll(n) ;

        for (int i = 0 ; i < n  ; i++) {
            numsll[i] = nums[i] ;
        }


        for (int i = n - 1 ; i > 0  ; i--) {

            long long int decrement = numsll[i] - maxInt ;

            numsll[i - 1] += decrement > 0 ? decrement : 0 ;
        }

        return numsll[0] <= maxInt ;
    }

    bool isMaxPossible(vector<int>&nums, int maxInt) {
        //prefix Sum approach

        long long int sum = 0 ;
        int n = nums.size() ;

        for (int i = 0  ; i < n ; i++) {
            sum += nums[i] ;

            if (sum > (long long int)(i + 1)*maxInt) {
                return false ;
            }
        }

        return true ;
    }



    int minimizeArrayValue(vector<int>& nums) {

        int n = nums.size() ;
        long long int sum = 0 , maxElement = 0 ;

        for (int i = 0 ; i < n ; i++) {
            sum += nums[i];
            maxElement = maxElement > nums[i] ? maxElement : nums[i] ;
        }

        int start = sum / n , end = maxElement , ans = end;

        while (start <= end) {
            int mid = (start + end) / 2;

            bool isMaxPossible = isMaxPossible1(nums, mid) ;

            if (isMaxPossible) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1 ;
            }
        }

        return ans ;

    }
};