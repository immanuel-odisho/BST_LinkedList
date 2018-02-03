#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

unsigned long primeGap(const mpz_t a, const mpz_t b)
{
	mpz_t x,c,gap,max,next;
	mpz_init(x);
	mpz_init(gap);
	mpz_init(c);
	mpz_init(max);
	mpz_set_ui(max,0);
	mpz_init(next);



	if (mpz_probab_prime_p(a,15) == 1 || mpz_probab_prime_p(a,15) == 2)
	{

		mpz_set(x,a);
		mpz_set(c,a);
		mpz_nextprime(next,x);

		while (mpz_cmp(b,next) >= 0)
		{
		
			mpz_nextprime(x,x);
			mpz_nextprime(next,x);
			mpz_sub(gap,x,c);
			mpz_set(c,x);

			if (mpz_cmp(gap,max) >= 0)
			{
				mpz_set(max,gap);
			}			
		}

	}

	else
	{	
		mpz_nextprime(x,a);
		mpz_nextprime(c,a);
		mpz_nextprime(next,x);

		while (mpz_cmp(b,next) >= 0)
		{
			
			mpz_nextprime(x,x);
			mpz_nextprime(next,x);
			mpz_sub(gap,x,c);
			mpz_set(c,x);

			if (mpz_cmp(gap,max) >= 0)
			{
				mpz_set(max,gap);
			}			
		}


	}

int final;

final = mpz_get_ui(max);
return final;

}