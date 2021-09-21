// Matrix multiplication
//
// R[nrowsA][pcolsB] = A[nrowsA][mcolsA] x B[mcolsA][pcolsB]
//

#include "matmul.h"

/* IKJ

          j                   j j j j
        k + + + +           k + + + +
          + + + +             + + + +
          + + + +             + + + +
  k       + + + +     k       + + + +
i * * * * o         i * * * * o o o o
  * * * *             * * * *
  * * * *             * * * *
  * * * *             * * * *

i
 k
  j
   c[i][j] += a[i][k] * b[k][j]
*/

// ikj version with a minimal optimization effort

void matmul(const unsigned int nrowsA, const unsigned int mcolsA,
            const unsigned int pcolsB, const basetype arrayA[],
            const basetype arrayB[], basetype arrayR[])
{
  unsigned int i, j, k;
  basetype *R = arrayR;
  const basetype *A = arrayA;

  for(i = 0; i < nrowsA; i++) {
    const basetype *B = arrayB;

    for(k = 0; k < mcolsA; k++) {

      for(j = 0; j < pcolsB; j++)
        // Computation

      B += pcolsB;
    }

    A += mcolsA;
    R += mcolsA;
  }
}
