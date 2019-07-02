#include <stdio.h>
#include <omp.h>
#include <time.h>


#define INTERVALS 1000000000000

int main() {
//c
double start, stop;
long int i, j;
double n_1, x, pi;

n_1 = 1.0 / INTERVALS;
pi = 0.0;

start = omp_get_wtime();


#pragma omp parallel for reduction(+:pi)
for(i = 0; i < INTERVALS; i++)  {
x = n_1 *((double)i - 0.5);
pi += 4.0 / (1.0 + x * x);
}
pi *= n_1;
stop = omp_get_wtime();
printf("Elapsed Time: %lf sec.\n", (stop - start));
printf("PI = %.30lf\n", pi);
return 0;
}
