///#include <fstream>
#include "iostream"
#include <vector>
#include <algorithm>

#define PII pair < int, int >

using namespace std ;

/**ifstream cin ("in.in") ;
ofstream cout ("out.out") ;**/

int t, n ;

int main()
{

    int previous, current, start, end ;

    cin >> t ;

    for (int i = 0 ; i < t ; i ++)
        {

            cin >> n ;

            previous = 0 ;
            start = end = 1 ;


            for (int j = 0 ; j < n ; j ++)
                {


                    cin >> current ;

                    if (previous > current)
                        start = end + 1 ;

                    else if (previous < current)
                        end = start + 1 ;

                    previous = current ;

                }

            if (start > end)
                cout << end << '\n' ;

            else
                cout << start << '\n' ;

        }

    return 0 ;

}
