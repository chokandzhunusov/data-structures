/*

    UNLABELED TREE:
        Catalan Number Formula: for defining how many BT can be made for given N:
                   2n to Cn
            T(n) = --------
                     n+1

                   2*5 to C5        10*9*8*7*6
            T(5) = ---------    =   ----------  =   42
                       6            5*4*3*2*1
                                    ----------
                                         6


             Can be also written like this:
                       n
                T(n) = E  T(i-1)*T(n-i)
                      i=1


    LABELED TREE:
        For defining how many BT can be made for given N:
                  2n to Cn
            T(n) = -------- * n!
                     n+1

                  |______|   |_|
               (shapes part) (filling part, one shape can have `n!` num ways)


*/


int main()
{

}

