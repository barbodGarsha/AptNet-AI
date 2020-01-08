#include "AptNet.h"

// counts the indexes in a layer scheme
int scheme_index_counter(std::string scheme)
{
	int n = 0;
	int len = scheme.length();
	for (int i = 1; i < len; i++) { if (scheme[i] == ',') { n++; } }
	return ++n;
}


// reads the indexes in a layer scheme
int read_scheme_index(std::string scheme, int* counter)
{
	std::string num = "";
	int len = scheme.length();
	for (int i = *counter; i < len; i++)
	{
		if (scheme[i] == ',')
		{
			*counter = ++i;
			return std::stoi(num);	
		}
		num += scheme[i];
		if (i == (len - 1))
		{
			*counter = ++i;
			return std::stoi(num);
		}
	}
}