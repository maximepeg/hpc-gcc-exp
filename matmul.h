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

// Multiplying two matrices:
//
// R[nrowsA][pcolsB] = A[nrowsA][mcolsA] x B[mcolsA][pcolsB]

#ifndef MATMUL_H_INCLUDED
#define MATMUL_H_INCLUDED

// Datatype for matrices
#ifdef _INT_
typedef int basetype;
#define labelelem    "ints"
#define printdata(t) printf("%i", t);
#elif _DOUBLE_
typedef double basetype;
#define labelelem    "doubles"
#define printdata(t) printf("%lf", t);
#else
typedef float basetype;       // DEFAULT
#define labelelem    "floats"
#define printdata(t) printf("%f", t);
#endif

void matmul(const unsigned int nrowsA, const unsigned int mcolsA,
            const unsigned int pcolsB, const basetype arrayA[],
            const basetype arrayB[], basetype arrayR[]);

void matmul_alt(const unsigned int nrowsA, const unsigned int mcolsA,
                const unsigned int pcolsB, const basetype arrayA[][mcolsA],
                const basetype arrayB[][pcolsB], basetype arrayR[][pcolsB]);

#endif
