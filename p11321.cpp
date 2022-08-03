#include <fstream>
#include <vector>
#include <algorithm>

#define PII pair < int, int >

using namespace std ;

ifstream cin ("in.in") ;
ofstream cout ("out.out") ;

int n, m ;
vector < PII > v ;

bool compare (PII a, PII b)
{

    if (a.second != b.second)
        return a.second < b.second ;

    if (a.first % 2 == 1)
    {

        if (b.first % 2 == 1)
            return a.first > b.first ;

        return true ;

    }

    if (b.first % 2 == 1)
    {

        return false ;

    }

    return a.first < b.first ;

}

int main()
{

    int x ;

    cin >> n >> m ;

    for (int i = 0; i < n; ++i) {
        cin >> x ;
        v.emplace_back(x, x % m) ;
    }

    cin >> x >> x ;

    sort (v.begin(), v.end(), compare) ;

    cout << n << ' ' << m << '\n' ;

    for (auto i : v)
        cout << i.first << '\n' ;

    cout << 0 << ' ' << 0 << '\n' ;

    return 0 ;

}
