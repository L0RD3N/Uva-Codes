///#include <fstream>
#include "iostream"
#include <algorithm>
#include "vector"
#include <cmath>

using namespace std ;

/**ifstream cin ("in.in") ;
ofstream cout ("out.out") ;**/

int t, n, ans ;
vector < int > d ;

bool check (int x)
{

    if (sqrt(x) == floor(sqrt(x)))
        return true ;

    return false ;

}

void Probing (vector < int > digits, int position)
{

    int experiment ;

    if (position == 4)
        return;

    if (!position) {
        for (int i = 1; i < 10; ++i) {
            digits[position] = i ;
            experiment = 0 ;

            for (int digit : digits) {
                experiment = experiment * 10 + digit ;
            }

            //cout << position << ' ' << experiment << ' ' << check(experiment) << '\n' ;

            if (experiment != n)
                if (check(experiment))
                    ans ++ ;

        }

    }

    else if (position < 5)
    {

        for (int i = 0; i < 10; ++i) {

            for (int j = 0; j < d.size(); ++j) {
                digits[j] = d[j] ;
            }

            digits[position] = i ;
            experiment = 0 ;

            for (int digit : digits) {
                experiment = experiment * 10 + digit ;
            }

            if (experiment != n)
                if (check(experiment))
                    ans ++ ;

        }

    }

    Probing(digits, position + 1) ;

}

int main()
{

    cin >> t ;

    for (int tt = 0; tt < t; ++tt) {
        cin >> n ;

        d.clear() ;
        ans = 0 ;
        int nn = n ;

        while (nn)
            d.emplace_back(nn % 10), nn /= 10 ;

        reverse(d.begin(), d.end()) ;
        Probing(d, 0) ;

        cout << "Case " << tt + 1 << ": " << ans << '\n' ;

    }

    return 0 ;

}
