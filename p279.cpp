///#include <fstream>
#include "iostream"
#include <algorithm>

using namespace std ;

/**ifstream cin ("in.in") ;
ofstream cout ("out.out") ;**/

int t ;

void HammingDistance (string q, int string_size, int h_dist)
{

    if (q.size() == string_size)
    {

        if (!h_dist)
            cout << q << '\n' ;

        return;

    }

    HammingDistance(q + '0', string_size, h_dist) ;
    HammingDistance(q + '1', string_size, h_dist - 1) ;

}

int main()
{

    int n, target ;

    cin >> t ;

    while (t --) {
        cin >> n >> target ;

        string q ;

        HammingDistance(q, n, target) ;

        if (t)
            cout << '\n' ;

    }

    return 0 ;

}
