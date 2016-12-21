//  Example for using rtnorm
//
// This code was translated by Alan R. Rogers into C, based on the C++
// original written by G. Dolle and V. Mazet, which is available at
// http://miv.u-strasbg.fr/mazet/rtnorm/rtnormCpp.zip
//  
//  Copyright (C) 2012 Guillaume Dollé, Vincent Mazet (LSIIT,
//  CNRS/Université de Strasbourg)  
//  Licence: GNU General Public License Version 2
//  see http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
//
//  Depends: LibGSL
//  OS: Unix based system

#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#include "dtnorm.h"

void test(int nreps, double mu, double sigma, double a, double b, gsl_rng *rng);

void test(int nreps, double mu, double sigma, double a, double b, gsl_rng *rng) {
    int i;
    double min = HUGE_VAL;
    double max = -HUGE_VAL;
    double x;
    for(i=0; i < nreps; ++i) {
        x = dtnorm(mu, sigma, a, b, rng);
        min = fmin(min, x);
        max = fmax(max, x);
    }
    assert(min >= a);
    assert(max <= b);
}

int main(void) {
    double      a;              // Left bound
    double      b;              // Right bound
    double      mu = 2;         // Mean
    double      sigma = 3;      // Standard deviation
    int         nreps = 1e6;    // Number of random variates to generate

    gsl_rng    *rng = gsl_rng_alloc(gsl_rng_taus);
    gsl_rng_set(rng, (unsigned long) time(NULL));

    a = 1.0;
    b = 1.5;
    test(nreps, mu, sigma, a*sigma, b*sigma, rng);

    printf("dtnorm OK\n");

    gsl_rng_free(rng);

    return 0;
}
