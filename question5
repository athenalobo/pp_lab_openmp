//print prime numbers from 1 to n in serial and parallel

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int prime(int x)
{
  for(int i=2;i<=x/2;i++)
    {
      if(x%i==0)
        return 0;
    }
  return 1;
}
void serialprime(int n)
{
  int i=2;
  while(i<=n)
    {
      if(prime(i)!=0)
      {
        printf("%d\n",i);
      }
      i++;
    }
}
void parallelprime(int n)
{
  int i=2;
  #pragma omp parallel
  while(i<=n)
    {
      if(prime(i)!=0)
      {
        printf("%d\n",i);
      }
      #pragma omp atomic
      i++;
    }
}

int main(int argc, char* argv[])
{
  int n=20;
  double start=omp_get_wtime();
  serialprime(n);
  double end=omp_get_wtime();
  printf("Time taken in serial=%lf",end-start);
  start=omp_get_wtime();
  parallelprime(n);
  end=omp_get_wtime();
  printf("Time taken in paralle;=%lf", end-start);
}
