for execution:

1) gedit ath.c

2) gcc -fopenmp ath.c 
   gcc -lm -fopenmp ath.c

3) export OMP_NUM_THREADS=8

4) ./a.out
