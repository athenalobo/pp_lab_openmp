//sum of first 100 integers using omp critical

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  int sum=0;
  #pragma omp parallel for
  for(int i=1;i<=100;i++)
    {
      #pragma omp critical
      sum=sum+i;
      
    }
  printf("%d", sum);
  return 0;
  
}
