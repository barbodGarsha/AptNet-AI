#include "AptNet.h"

int main()
{
	//anything that is written in here for now is for test
	NeuralNet nt;
	nt = NeuralNet::NeuralNet("2,4,1,5");
	nt.set_activations_funtions("0,0,0");
	std::cout << nt.input_index << std::endl;
	std::cout << nt.hidden_index[0] << std::endl;
	std::cout << nt.hidden_index[1] << std::endl;
	std::cout << nt.output_index << std::endl;
	MatrixXf i = MatrixXf(1, 2);
	i(0, 0) = 1;
	i(0, 1) = 0;
	nt.set_inputs(i);
	nt.feedforward();
	std::cout << std::endl;
	std::cout << nt.input_values << std::endl;

	std::cout << std::endl;
	std::cout << nt.hidden_values[0] << std::endl;

	std::cout << std::endl;
	std::cout << nt.hidden_values[1] << std::endl;

	std::cout << std::endl;
	std::cout << nt.output_values << std::endl;
	system("pause");
	return 0;
}