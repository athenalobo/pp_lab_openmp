//estimate the value of pi=4|k=0->infinity((-1)^k)/(2k+1)
//remove loop carried dependancy

#include<math.h>
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

#define infinity 1000000

int main(int argc, char *argv[])
{
  //serial
  double pi=0;
  double start=omp_get_wtime();
  for(int k=0;k<infinity;k++)
    {
      pi+= pow(-1,k)/(2*k+1);
    }
  pi=4*pi;
  double end=omp_get_wtime();
  double time=end-start;
  printf("In serial, value of pi is %lf in time %lf",pi,time);

  //parallel
  pi=0;
  start=omp_get_wtime();
  int size=omp_get_num_threads();
  double thread[size];
  #pragma omp parallel
  {
    for(int k=0;k<infinity;k++)
      {
        int t=omp_get_thread_num();
        thread[t]+= pow(-1,k)/(2*k+1);
      }
    for(int i=0;i<size;i++)
      {
        pi+=thread[i];
      }
    pi=4*pi;
    end=omp_get_wtime();
    }
    time=end-start;
    printf("In parallel, value of pi is %lf in time %lf",pi,time);
    
  
  
  return 0;
  
}
