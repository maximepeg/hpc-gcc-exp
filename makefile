TARGETS = matmul_ijk matmul_ijk_op1 matmul_ijk_op2

CC = gcc

reportflags.gcc = -fopt-info-optall-optimized
reportflags.icc = -qopt-report-phase=vec

O = -O3 -march=native
#CFLAGS = $(O) $(reportflags.$(CC)) -Wall -Wextra
CFLAGS = $(O) -Wall -Wextra

all: $(TARGETS)

matmul_ijk: matmul.o matmul_ijk.o stuff.o

matmul_ijk_op1: matmul.o matmul_ijk_op1.o stuff.o

matmul_ijk_op2: matmul.o matmul_ijk_op2.o stuff.o

matmul_ikj: matmul.o matmul_ikj.o stuff.o

matmul_ikj_op1: matmul.o matmul_ikj_op1.o stuff.o

matmul_ikj_op2: matmul.o matmul_ikj_op2.o stuff.o

matmul_ikj_op2op: matmul.o matmul_ikj_op2op.o stuff.o

OBJS = ${TARGETS:=.o}

clean:
	rm -f ${OBJS} *.s *~

cleanall: clean
	rm -f $(TARGETS) *.o
