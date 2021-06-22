#include <cstring>
#include <iostream>
#include <sstream>


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
	string ifname, ofname;

	FILE *ifile = stdin;
	FILE *ofile = stdout;



	// flag handling
	char mode = 'h';
	for (int i = 1; i < argc; ++i)
	{
		if (!strcmp("-h", argv[i]) || !strcmp("--hex", argv[i]))
			mode = 'h';
		else if (!strcmp("-b", argv[i]) || !strcmp("--bin", argv[i]))
			mode = 'b';
		else if (!strcmp("-i", argv[i]) || argv[i][0] != '-')
		{
			if (argv[i][0] == '-')
			{
				++i;
				if (i >= argc)
				{
					fprintf(stderr, "Error: require input file name for option -i\n");
					return 1;
				}
			}

			ifname = argv[i];
		}
		else if (!strcmp("-o", argv[i]))
		{
			++i;
			if (i >= argc)
			{
				fprintf(stderr, "Error: require input file name for option -i\n");
				return 1;
			}

			ofname = argv[i];
		}
		else
		{
			fprintf(stderr, "Error: unknown flag %s\n", argv[i]);
			return 1;
		}
	}



	// converting
	if (!ifname.empty())
	{
		ifile = fopen(ifname.c_str(), "r");
		if (!ifile)
		{
			fprintf(stderr, "Error: can't open file %s\n", ifname.c_str());
			return 1;
		}
	}

	int c = 0;
	int ch;
	stringstream out;
	while ((ch = getc(ifile)) != EOF)
	{
		if (mode == 'h')
			out << hexval(ch / 16) << hexval(ch % 16) << ' ';
		else
			out << binval(ch) << " ";

		++c;
		if(c % 4 == 0)
			out << '\n';
	}

	if (ifile != stdin)
		fclose(ifile);



	// writing
	if (!ofname.empty())
	{
		ofile = fopen(ofname.c_str(), "w");
		if (!ofile)
		{
			fprintf(stderr, "Error: can't open file %s\n", ofname.c_str());
			return 1;
		}
	}

	fprintf(ofile, "%s", out.str().c_str());

	if (ofile != stdout)
		fclose(ofile);



	return 0;
}





// end
