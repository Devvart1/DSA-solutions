class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
        // string s=to_string(x);
        // int j=s.size()-1;
        // int i=0;
        // while(i<j){
        //     if(s[i]!=s[j])return false;
        //     i++;
        //     j--;
        // }
        // return true;
        long long int rev = 0;
        int temp = x;
        while (temp) {
            //  cout<<"x="<<x<<endl;
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        // cout<<x<<endl;
        // cout<<rev<<endl;
        // cout<<(rev==x);
        return rev == x;
    }
};