#include "AptNet.h"

int scheme_index_counter(std::string scheme)
{
	int n = 0;
	int len = scheme.length();
	for (int i = 1; i < len; i++) { if (scheme[i] == ',') { n++; } }
	return ++n;
}