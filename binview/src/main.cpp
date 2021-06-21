#include <cstring>
#include <iostream>


using namespace std;





// functions
char hexval(int i)
{
	if(i < 10)
		return '0' + i;
	return 'a' + (i - 10);
}

string binval(uint8_t one)
{
	string res;
	res.resize(8);
	for (int i = 0; i < 8; ++i)
		res[i] = one & (1 << (7-i)) ? '1' : '0';
	return res.substr(0, 4) + "'" + res.substr(4);
}





// main
int main( int argc, char *argv[] )
{
	char mode = 'h';

	for (int i = 1; i < argc; ++i)
	{
		if (!strcmp("-h", argv[i]) || !strcmp("--hex", argv[i]))
			mode = 'h';
		else if (!strcmp("-b", argv[i]) || !strcmp("--bin", argv[i]))
			mode = 'b';
	}

	int c = 0;
	uint8_t ch;
	while(cin.read((char *)&ch, 1))
	{
		if (mode == 'h')
			printf("%c%c ", hexval(ch / 16), hexval(ch % 16));
		else
			printf("%s ", binval(ch).c_str());

		++c;
		if(c % 4 == 0)
			putchar('\n');
	}



	return 0;
}





// end
