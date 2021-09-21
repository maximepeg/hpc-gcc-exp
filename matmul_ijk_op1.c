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

//  IJK version with a minimal optimization effort

void matmul(const unsigned int nrowsA, const unsigned int mcolsA,
            const unsigned int pcolsB, const basetype arrayA[],
            const basetype arrayB[], basetype arrayR[])
{
  unsigned int i, j, k;
  basetype *R = arrayR;
  const basetype *A = arrayA;

  for(i = 0; i < nrowsA; i++) {

    for(j = 0; j < pcolsB; j++) {
      const basetype *B = arrayB + j;
      basetype result = 0;

      for(k = 0; k < mcolsA; k++)
        result += A[k] * B[k*pcolsB];

      R[j] = result;
    }

    A += mcolsA;
    R += pcolsB;
  }
}
