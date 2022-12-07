//print n fibonacci numbers

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
  int a=0,b=1,t;
  #pragma omp parallel for schedule(static, 2)
  for(int i=0;i<n;i++)
    {
      t=a+b;
      a=b;
      b=t;
    }
  return a;
}

int main(int argc, char* argv)
{
  double start=omp_get_wtime();
  int n=20;
  #pragma omp parallel for
  for(int i=0;i<n;i++)
    {
      int t=omp_get_thread_num();
      printf("thread: %d, fib(%d) = %d\n", t, i, fib(i));
    }
  double end=omp_get_wtime();
  printf("total time=%lf", end-start);
  
}

