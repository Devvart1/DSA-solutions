void func(ll ind, vector<ll>&arr, ll curr_sum)
{
    if (ind == (ll)(arr.size()))
    {
        dp[ind][curr_sum] = 1;
        return;
    }
    if (dp[ind][curr_sum] != -1)
    {
        return;
    }
    dp[ind][curr_sum] = 1;
    // if i dont pick it
    func(ind + 1, arr, curr_sum);
    // if i pick it
    func(ind + 1, arr, curr_sum + arr[ind]);
}
ll sum = 0;
for (ll i = 0; i < n; i++)
    cin >> arr[i], sum += arr[i];
if (sum % 2)
{
    cout << "-1\n";
}
else {
    bool flag = false;
    memset(dp, sizeof dp, -1);
    func(0, arr, sum, flag, 0);
    for (ll i = 0; i <= n; i++)
    {
        if (dp[i][sum / 2] != -1)
        {
            flag = true;
        }
    }
    cout << flag << "\n";
}