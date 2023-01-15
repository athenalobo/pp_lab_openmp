// Progarm to sort an array using merge sort in parallel and serial. Record the
// time taken for each and return the difference.

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int mid, int h) {
  int i, j, k;
  int n1 = mid - 1 + l;
  int n2 = h - mid;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = a[mid + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void sortSerial(int a[], int l, int h) {
  if (l < h) {
    int mid = l + (h - l) / 2;
    sortSerial(a, l, mid);
    sortSerial(a, mid + 1, h);
    merge(a, l, mid, h);
  }
}

void sortParallel(int a[], int l, int h) {
  if (l < h) {
    int mid = l + (h - l) / 2;
#pragma omp parallel sections
    {
#pragma omp section
      sortParallel(a, l, mid);
#pragma omp section
      sortParallel(a, mid + 1, h);
    }
  }
}

int main(int argc, char *argv[]) {
  int *a,num=20;
  a=(int*)malloc(sizeof(int)*num);
  printf("Array before sorting:");
  for (int i = 0; i < 20; i++) {
    a[i] = rand() % 100;
    printf("%d", a[i]);
  }

  double start = omp_get_wtime();
  sortSerial(a, 0, 19);
  double end = omp_get_wtime();
  double val = end - start;
  printf("Time taken for serial:%f", val);

  start = omp_get_wtime();
  sortParallel(a, 0, 19);
  end = omp_get_wtime();
  val = end - start;
  printf("Time taken for parallell:%f", val);

  printf("Array after sorting:\n");
  for (int i = 0; i < 20; i++) {
    printf("%d\n", a[i]);
  }
}
