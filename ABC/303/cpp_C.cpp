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
    ll N, M, H, K;
    string S;

    cin >> N >> M >> H >> K;
    cin >> S;
    ll x, y;
    // vector<ll> xs, ys;
    map<pair<ll, ll>, bool> xyOK;

    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y;
        // xs.push_back(x);
        // ys.push_back(y);
        xyOK[make_pair(x, y)] = true;
        
    }

    ll nx = 0, ny = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (H <= 0)
        {
            cout << "No" << endl;
            return 0;
        }
        H--;
        if (S[i] == 'R')
        {
            nx += 1;
        }
        else if (S[i] == 'L')
        {
            nx -= 1;
        }
        else if (S[i] == 'U')
        {
            ny += 1;
        }
        else
        {
            ny -= 1;
        }

        if (H < K)
        {
            if (xyOK[make_pair(nx, ny)])
            {
                xyOK[make_pair(nx, ny)] = false;
                H = K;
            }
        }
    }
    cout << "Yes" << endl;
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
