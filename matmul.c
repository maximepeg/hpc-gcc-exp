// Different CPU implementations of matrix multiplication.
// Written in 2020 by Emilio J. Padrón <emilioj at udc.gal>
//
// To the extent possible under law, the author have dedicated all
// copyright and related and neighboring rights to this software to
// the public domain worldwide. This software is distributed without
// any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.

#include <stdio.h>
#include "stuff.h"
#include "matmul.h"

const int N = 1024; // Default elements per row and col: NxN matrix

int main(int argc, char *argv[])
{
  resnfo start, end;
  timenfo time;

  // Parameters

  // 0: Elements per row and per column (default: N)
  unsigned int n = (argc > 1)?atoi (argv[1]):N;

  // Matrices size
  unsigned int numBytes = n * n * sizeof(basetype);

  // Allocate and init matrices (32-byte aligned addresses for AVX2)
  // About aligned memory allocation:
  // https://stackoverflow.com/questions/32612881/why-use-mm-malloc-as-opposed-to-aligned-malloc-alligned-alloc-or-posix-mem
  // C11 alt.: void * aligned_alloc (size_t alignment, size_t size)
  // POSIX alt.: int posix_memalign (void **memptr, size_t alignment, size_t size)
  // Intel's used here: void* _mm_malloc (int size, int align)
  //                    void _mm_free (void *p)

  timestamp(&start);
  basetype *vectorA = (basetype *) malloc(numBytes);
  basetype *vectorB = (basetype *) malloc(numBytes);
  basetype *vectorR = (basetype *) malloc(numBytes);
  //  basetype *vectorA = (basetype *) _mm_malloc (numBytes, 32);
  //  basetype *vectorB = (basetype *) _mm_malloc (numBytes, 32);
  //  basetype *vectorR = (basetype *) _mm_malloc (numBytes, 32);
  populating_arrays(vectorA, vectorB, vectorR, n*n);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrices allocation and initialiation (%ux%u %s)\n\n", n, n, labelelem);

  timestamp(&start);
  matmul(n, n, n, vectorA, vectorB, vectorR);
  timestamp(&end);

  get_walltime(start, end, &time);
  printtime(time);
  printf(" -> Matrix product: %s\n", argv[0]);

  basetype check = check_result(vectorR, n*n);
  printf("%29s", "Check: "); printdata(check); printf("\n\n");

  char *md5check = md5((unsigned char *) vectorR, n*n*sizeof(basetype));
  printf("%28s %s\n\n", "MD5:", md5check);
  free(md5check);

  free(vectorA);
  free(vectorB);
  free(vectorR);
  //  _mm_free(vectorA);
  //  _mm_free(vectorB);
  //  _mm_free(vectorR);

  return(0);
}
