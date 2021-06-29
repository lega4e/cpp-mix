#include <cmath>
#include <iostream>


using namespace std;

typedef uint64_t ullong;

constexpr int const DIGNUM = 64;





ullong _current_random_number = 5938493402381934021 * time(0);

ullong rnd()
{
	ullong const a =
		(_current_random_number << (DIGNUM / 4)) |
		(_current_random_number >> (DIGNUM / 4 * 3));

	ullong const b =
		(_current_random_number >> (DIGNUM / 4)) |
		(_current_random_number << (DIGNUM / 4 * 3));

	_current_random_number = a + b;
	return _current_random_number;
}





// main
int main( int argc, char *argv[] )
{
	cout << "seed: " << _current_random_number << '\n';
	for (int i = 0; i < 10; ++i)
		cout << rnd() << '\n';

	return 0;
}





// end
