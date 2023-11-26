

#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define int long long
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int32_t t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(list <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

//mex and increments
vector<int> Lps(string s) {
	int i = 1;
	int len = 0;
	int n = s.size();

	vector<int> lps(n, 0);

	while (i < n) {
		if (s[i] == s[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len > 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
vector<int> lps(string s) {
	int i , j, n;
	n = s.size();
	vector<int> lps_array(n, 0);
	i = 0;
	j = 1;

	while (j < n) {

		if (s[i] == s[j]) {
			lps_array[j] = i + 1;
			i++;
			j++;

		}
		else {

			if (i != 0) {
				i = lps_array[i - 1];
			}
			else
			{
				lps_array[i] = 0;
				j++;
			}



		}

	}

	return lps_array;
}
vector<int> KMP(string text, string pattern) {

	vector<int> lps_array = Lps(pattern);
	debug(lps_array)
	int i = 0;
	int j = 0;
	vector<int> ans;

	while (i < text.size() && j < pattern.size()) {
		if (text[i] == pattern[j]) {

			if (j == pattern.size() - 1) {
				ans.push_back(i - j);
				cout << i - j << " ";
				i++;

				j = lps_array[j];
			}
			else {
				i++;
				j++;
			}

		} else {
			if (j != 0) {
				j = lps_array[j - 1];
			} else {
				i++;
			}
		}
	}

	return ans;
}

void KMP()
{

	string text, pat;
	cin >> text >> pat;
	ll n = text.size();
	ll m = pat.size();
	// finding lps array of pattern
	vector<ll>lps_array = Lps(pat);
	int i, j;
	// for (ll i = 0; i < m; i++)
	// 	//cout << lps_array[i] << " ";
	// 	//cout << "\n";
	i = 0;
	j = 0;
	vector<ll>ans;
	while (i < n)
	{
		debug(i)

		if (text[i] == pat[j])
		{
			if (j == m - 1)
			{
				cout << i - j << " ";
				i++;
				j = lps_array[j];
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			while (j > 0 && text[i] != pat[j])
			{
				j = lps_array[j - 1];
			}
			if (pat[j] != text[i])
			{
				i++;
			}
		}
	}
	return;
}
void solve() {

	int tc = 0 , T  ;
	cin >> T;

	while (++tc <= T) {
		debug(tc)

		// string text, patt;
		// cin >> text >> patt;
		// vector<int> ans;
		// ans = KMP(text, patt);
		// for (auto x : ans)cout << x << " ";

		KMP();

		cout << endl;
	}
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	fastio();
	auto start1 = high_resolution_clock::now();
	solve() ;
	auto stop1 = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop1 - start1);

#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif

	return 0;

}


