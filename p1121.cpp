#include <iostream>
#include <vector>
#include <algorithm>

#define PII pair < int, int >

using namespace std ;

/**ifstream cin ("in.in") ;
ofstream cout ("out.out") ;**/

int n, S ;
long long v[100005] ;

int main()
{

    long long left, right, sum, ans ;
    bool changed ;

    while (cin >> n >> S)
    {

        for (int i = 0; i < n; ++i) {
            cin >> v[i] ;
        }

        left = right = 0 ;
        sum = v[0] ;
        ans = (1 << 30) ;
        changed = false ;

        while (right < n)
        {

            if (sum >= S)
            {

                if (right - left + 1 < ans)
                    ans = right - left + 1, changed = true ;

            }

            if (sum >= S)
                sum -= v[left], left ++ ;

            if (sum < S) {
                right ++ ;
                if (right < n)
                    sum += v[right] ;
            }

        }

        if (changed)
            cout << ans << '\n' ;

        else
            cout << 0 << '\n' ;

    }

    return 0 ;

}
