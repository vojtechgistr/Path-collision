#include <vector>
#include "main.h"

static bool ccw(const std::pair<int, int>& A, const std::pair<int, int>& B, const std::pair<int, int>& C) {
    return (C.second - A.second) * (B.first - A.first) > (B.second - A.second) * (C.first - A.first);
}

std::pair<int, int> intersectionCoords(const std::pair<int, int> &A, const std::pair<int, int> &B, const std::pair<int, int> &C, const std::pair<int, int> &D)
{
    //  A1   A2    B1  B2   C1  C2      D1  D2
    // { -2, 2 }, { 4, 2 }, { 3, -3 }, { 3, 4 }

    if ((A.first != B.first && A.second != B.second)
        || (C.first != D.first && C.second != D.second)
        || (!(ccw(A, C, D) != ccw(B, C, D) && ccw(A, B, C) != ccw(A, B, D))))
        return std::make_pair(INT_MAX, INT_MAX);

    // Line AB represented as a1*x + b1*y = c1
    int a1 = B.second - A.second;
    int b1 = A.first - B.first;
    int c1 = a1 * A.first + b1 * A.second;

    // Line CD represented as a2*x + b2*y = c2
    int a2 = D.second - C.second;
    int b2 = C.first - D.first;
    int c2 = a2 * C.first + b2 * C.second;

    int determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        // if lines are on themselves
        if (A.first == C.first) {               // vertical    

            if (C.second < A.second && B.second < D.second) // if line is inherit
                return std::make_pair(A.first, A.second);

            else if (C.second <= B.second)         // upper line
                return std::make_pair(C.first, C.second);

            else if (D.second <= B.second)      // bottom line
                return std::make_pair(D.first, D.second);

        }
        else if (A.second == C.second) {        // horizontal    --

            if (C.first < A.first && B.first < D.first)     // if line is inherit
                return std::make_pair(A.first, A.second);

            else if (C.first <= B.first)         // upper line
                return std::make_pair(C.first, C.second);

            else if (D.first <= B.first)        // bottom line
                return std::make_pair(D.first, D.second);

        }
        
        return std::make_pair(INT_MAX, INT_MAX);
    }
    else {
        int x = (b2 * c1 - b1 * c2) / determinant;
        int y = (a1 * c2 - a2 * c1) / determinant;

        if(((A.first <= x && x <= B.first) || (B.first <= x && x <= A.first))
            && ((A.second <= y && y <= B.second) || (B.second <= y && y <= A.second)))
            return std::make_pair(x, y);

        return std::make_pair(INT_MAX, INT_MAX);
    }
}