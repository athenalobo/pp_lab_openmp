for execution:

gedit ath.c

gcc -fopenmp ath.c 
gcc -lm -fopenmp ath.c

export OMP_NUM_THREADS=8

./a.out
