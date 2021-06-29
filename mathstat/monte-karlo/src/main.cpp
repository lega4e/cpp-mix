#include <cstdio>
#include <random>


using namespace std;

constexpr int const REPEATS = 100'000'000;
default_random_engine dre(time(0));





// main
int main( int argc, char *argv[] )
{
	double x, y;
	int got = 0;
	uniform_real_distribution<double> dis(-1.0, 1.0);

	for (int i = 0; i < REPEATS; ++i)
	{
		x = dis(dre), y = dis(dre);
		if (x*x + y*y < 1.0)
			++got;
	}

	double const s = 4.0 * got / REPEATS;
	printf("S = %.5lf, repeats: %i\n", s, REPEATS);


	return 0;
}





// end
