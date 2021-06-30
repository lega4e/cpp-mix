#include <iostream>


using namespace std;





// LCG
constexpr int const _M = 8;
constexpr int const _K = 5;
constexpr int const _B = 3;

int _currandnum = 0;


int rnd()
{
	return (_currandnum = (_currandnum * _K + _B) % _M);
}





// main
int main( int argc, char *argv[] )
{
	for (int i = 0; i < 9; ++i)
		cout << rnd() << '\n';
	cout << flush;

	return 0;
}





// end
