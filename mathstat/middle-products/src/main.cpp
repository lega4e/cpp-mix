#include <cmath>
#include <iostream>


using namespace std;

typedef long long llong;

constexpr llong const DIGNUM    = 6;
constexpr llong const DIGNUMPOW = pow(10, DIGNUM);
constexpr llong const DIGNUMDIV = pow(10, DIGNUM/2);


llong _current_random_number  = time(0) % DIGNUMPOW;
llong _previous_random_number = time(0) % DIGNUMPOW;

llong rnd()
{
	_previous_random_number *= _current_random_number;
	_previous_random_number /= DIGNUMDIV;
	_previous_random_number %= DIGNUMPOW;
	swap(_previous_random_number, _current_random_number);
	return _current_random_number;
}




// main
int main( int argc, char *argv[] )
{
	printf("seed: %Li\n", _current_random_number);
	for (int i = 0; i < 10; ++i)
		printf("%Li\n", rnd());

	return 0;
}





// end
