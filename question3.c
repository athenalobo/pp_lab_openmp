// divide the iterations into chunks of 2 for each thread

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int iterns = 8, i, itern = 1;
#pragma omp parallel for schedule(static, 2)

  for (i = 0; i < iterns; i++) {
    int t = omp_get_thread_num();
    itern += 1;
    itern = itern % 2;
    printf("Thread %d: iteration %d -- %d\n", t, itern + 1, i);
  }
}
