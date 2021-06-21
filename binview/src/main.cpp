#include <iostream>


using namespace std;





// functions
char val(int i)
{
	if(i < 10)
		return '0' + i;
	return 'a' + (i - 10);
}





// main
int main( int argc, char *argv[] )
{
	int c = 0;
	int ch;

	while((ch = getchar()) != EOF)
	{
		printf("%c%c ", val(ch / 16), val(ch % 16));
		++c;
		if(c % 4 == 0)
			printf("\n");
	}



	return 0;
}





// end
