//  dtnorm usage example.

#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <time.h>
#include "dtnorm.h"

int main(void) {
    double      a=1, b=2;       // Truncation interval is (a,b)
    double      mu = 0;         // Mean
    double      sigma = 1;      // Standard deviation
    int         nreps = 1000;   // Number of random variates to generate
    gsl_rng    *rng = gsl_rng_alloc(gsl_rng_taus);
    gsl_rng_set(rng, (unsigned long) time(NULL));
    int i;
    double x;

    for(i=0; i < nreps; ++i) {
        x = dtnorm(mu, sigma, a, b, rng);
        printf("%lf\n", x);
    }


    gsl_rng_free(rng);

    return 0;
}
