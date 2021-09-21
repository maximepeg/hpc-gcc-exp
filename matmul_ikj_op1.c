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

// ikj version: j in inner loop improves locality (i.e. exploits cache lines)

void matmul(const unsigned int nrowsA, const unsigned int mcolsA,
            const unsigned int pcolsB, const basetype arrayA[],
            const basetype arrayB[], basetype arrayR[])
{
  unsigned int i, j, k, ii, kk, iik;

  for(i = 0; i < nrowsA; i++) {
    ii = i*mcolsA;

    for(k = 0; k < mcolsA; k++) {
      kk = k*pcolsB;
      iik = ii+k;

      for(j = 0; j < pcolsB; j++)
        // Computation
    }
  }
}
