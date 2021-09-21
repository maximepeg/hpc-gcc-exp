// Matrix multiplication
//
// R[nrowsA][pcolsB] = A[nrowsA][mcolsA] x B[mcolsA][pcolsB]
//

#include "matmul.h"

/* IJK

          j                   j
        k + + + +           k + + + +
          + + + +           k + + + +
          + + + +           k + + + +
  k       + + + +     k k k k + + + +
i * * * * o         i * * * * o
  * * * *             * * * *
  * * * *             * * * *
  * * * *             * * * *

i
 j
  k
   c[i][j] += a[i][k] * b[k][j]
*/

//  Naive version: just an ijk easier for programmer

void matmul(const unsigned int nrowsA, const unsigned int mcolsA,
            const unsigned int pcolsB, const basetype arrayA[],
            const basetype arrayB[], basetype arrayR[])
{
  unsigned int i, j, k;

  for(i = 0; i < nrowsA; i++)
    for(j = 0; j < pcolsB; j++)
      for(k = 0; k < mcolsA; k++)
        arrayR[i*mcolsA+j] += arrayA[i*mcolsA+k] * arrayB[k*pcolsB+j];
}
