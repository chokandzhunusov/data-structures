/*
    Given a `height`, you have to find the number of `Nodes`:

        min Nodes:
            n = h + 1

        max Nodes:
            Geometric Progression Series:
                                                    k+1
                           2     3           k   a(r    - 1)
                a + ar + ar  + ar  + ... + ar  = ----------
                                                   r - 1

                                                   h+1
                                                = 2    - 1 (to find max num of Nodes)

        Number of Nodes in BT:
                             n+1
            (h + 1) <= n <= 2   - 1




    Given a number of `nodes`, you have to find the `Height`:

        min Height:
            h = log (n+1) - 1
                   2

        max Height:
            h = n - 1

        Height of BT:
            log (n+1) - 1 <= h <= (n - 1)
               2
            =============================
            O(logn)                 O(n)
*/


int main()
{

}
