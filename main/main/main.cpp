#include "AptNet.h"

int main()
{
	//anything that is written in here for now is for test
	NeuralNet nt;
	nt = NeuralNet::NeuralNet("2,4,1,5");
	nt.set_activations_funtions("0,0,0");
	
	system("pause");
	return 0;
}