#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long ll;
#define size_t ll
#define double long double
#define all(obj) (obj).begin(), (obj).end()
const double PI = 3.141592653589793;
const ll INF = 1e18, MOD = 1000000007;
template <class T>
inline bool chmax(T &a, T b);
template <class T>
inline bool chmin(T &a, T b);
ll roundup(ll a, ll b); // 切り上げ
ll comb(ll n, ll r);    // nCr 組み合わせ
template <class T>
ll my_lower_bound(vector<T> &vec, T key);

// ==================================================================== //

int main()
{
    ll x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;

    vector<ll> capon(s.size() + 5);
    vector<ll> capoff(s.size() + 5);

    if (s[0] == 'a')
    {
        capoff[0] = x;
        capon[0] = z + y;
    }
    else
    {
        capoff[0] = y;
        capon[0] = z + x;
    }

    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            capoff[i] = min(capoff[i - 1] + x, capon[i - 1] + z + x);
            capon[i] = min(capoff[i - 1] + z + y, capon[i - 1] + y);
        }
        else
        {
            capoff[i] = min(capoff[i - 1] + y, capon[i - 1] + z + y);
            capon[i] = min(capoff[i - 1] + z + x, capon[i - 1] + x);
        }
    }
    cout << min(capoff[s.size() - 1], capon[s.size() - 1]) << endl;
    // for (size_t i = 0; i < s.size(); i++)
    // {
    //     cout << capoff[i] << ' ';
    // }
    // cout << endl;
    // for (size_t i = 0; i < s.size(); i++)
    // {
    //     cout << capon[i] << ' ';
    // }
    // cout << endl;

    return 0;
}

// ==================================================================== //

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

ll roundup(ll a, ll b)
{
    return ((a + b - 1) / b);
}

ll comb(ll n, ll r)
{
    if (r < 1 || n < r)
        return 0;
    double ans = 1.0;
    for (size_t i = 1; i <= r; i++)
        ans *= (double)(n - i + 1) / (double)(i);
    return (ll)ans;
}

template <class T>
ll my_lower_bound(vector<T> &vec, T key)
{
    auto it = lower_bound(all(vec), key);
    return (it - vec.begin());
}
