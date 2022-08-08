#include <iostream>

using namespace std ;

/**ifstream cin ("in.in") ;
ofstream cout ("out.out") ;**/

int tests, points ;
char table[14][14] ;
bool isblack, iswhite ;
int dx[] = {1,-1,0,0} ;
int dy[] = {0,0,1,-1} ;

bool isintable (int x, int y)
{

    return (x >= 0 && y >= 0 && x < 9 && y < 9) ;

}

void dfs (int x, int y)
{

    int newx, newy ;

    points ++ ;
    table[x][y] = '!' ;

    for (int i = 0; i < 4; ++i) {
        newx = x + dx[i], newy = y + dy[i] ;

        if (isintable(newx, newy)) {
            if (table[newx][newy] == '.')
                dfs(newx, newy);

            else if (table[newx][newy] == 'X')
                isblack = true ;

            else if (table[newx][newy] == 'O')
                iswhite = true ;

        }

    }

}

int main()
{

    int white, black ;

    cin >> tests ;

    while (tests)
    {

        white = black = 0 ;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {

                cin >> table[i][j] ;
                if (table[i][j] == 'X')
                    black ++ ;

                else if (table[i][j] == 'O')
                    white ++ ;
            }

        }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (table[i][j] == '.')
                {

                    points = 0 ;
                    isblack = iswhite = false ;
                    dfs(i, j) ;

                    if (iswhite == isblack)
                        continue;

                    if (iswhite)
                        white += points ;

                    else
                        black += points ;

                }

            }

        }

        cout << "Black " << black << ' ' << "White " << white << '\n' ;

        tests -- ;

    }

    return 0 ;

}
