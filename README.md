# dtnorm

Random samples from a doubly-truncated Normal distribution. In other
words, a Normal distribution truncated to a finite interval.

I started with the [C++
code](http://miv.u-strasbg.fr/mazet/rtnorm/rtnormCpp.zip) of G. Dolle
and V Mazet, which implements Chopin's algorithm for sampling from the
doubly-truncated Normal distribution. My C translation of their code
is available [on github](https://github.com/alanrogers/rtnormC). I
then did numerical experiments with various algorithms, and discovered
that other algorithms work better in some regions of parameter space.

The code in this repository combines 4 algorithms:

1. Rejection sampling with a Gaussian proposal distribution

2. Rejection sampling with an exponential proposal distribution.

3. [Chopin's algorithm](https://arxiv.org/abs/1201.6140), as implemented by
   Dolle and Mazet.

4. [Robert's algorithm](https://arxiv.org/abs/0907.4010)

Each of these algorithms is used in a different region of parameter space.

The dtnorm function is in src/dtnorm.h, src/dtnorm_data.h, and
src/dtnorm.c. For a usage example, see test/example.c. A unit test is
in test/xdtnorm.c.

To compile and run the example:

	cd test
	make example
	./example

To compile and run the unit test

	cd test
	make xdtnorm
	./xdtnorm

The unit test takes a single optional argument, `-v`, which will
provide verbose output.


