#include "AptNet.h"

// TODO: handle errors NOTE: later with error_handler.cpp/.h
/*
	Input Layer |  Hidden Layer | Output Layer
				|				|
				|    *	   *	|
		*		|    *	   *	|	* ----> each '*' represents a Neuron in our Neural Network
		*		|    *	   *	|	*
				|    *	   *	|

	a layer scheme structure is like : "I,H1,H2,...,Hn,O"
	- I is the number of Nuerons in the Input Layer
	- Hx is the number of Neurons in the Hidden Layer number x (you can have as many as you want
	- O in the number of Neurons in the Output Layer
	the layer scheme which makes the Neural Network up there looks like this : "2,4,4,5"
	
	NeuralNet::NeuralNet(std::string layer_scheme) reads the layer_scheme and creates the Neural Network.
*/
NeuralNet::NeuralNet(std::string layer_scheme)
{
	int n = scheme_index_counter(layer_scheme);
	hidden_layers_len = n - 2;
	int counter = 0;
	hidden_index = new int[hidden_layers_len];
	input_index = read_scheme_index(layer_scheme, &counter);
	for (int i = 0; i < hidden_layers_len; i++)
	{
		hidden_index[i] = read_scheme_index(layer_scheme, &counter);
	}
	output_index = read_scheme_index(layer_scheme, &counter);
	hidden_values = new MatrixXf[hidden_layers_len];

	generate_weights();
	generate_biases();



	raw_values = new MatrixXf[hidden_layers_len + 1];
}

NeuralNet::NeuralNet() {}

//TO DO2: the whole activation functions system needs to e rewritten but for now it works and we go with it
void NeuralNet::set_activations_funtions(std::string activation_functions_scheme)
{
	activations_functions = new int[hidden_layers_len + 1];
	std::string num = "";
	for (int j = 0; j < hidden_layers_len + 1; j++)
	{
		num = "";
		for (uint16_t i = 0; i < activation_functions_scheme.length(); i++)
		{
			if (activation_functions_scheme[i] == ',')
			{
				activations_functions[j] = std::stoi(num);
				activation_functions_scheme[i] = ' ';
				break;
			}
			num += activation_functions_scheme[i];
			activation_functions_scheme[i] = ' ';
		}
	}
}

/* here an array of MatrixXf will be defined which will contain the values of all the weights in our Neural Network.
   every Matrix in this array is defined given to the amount of neurons in each layer
   the amount of neurons are stored in:
										MatrixXf input_values
										MatrixXf* hidden_values
										MatrixXf output_values
	which are set in the NeuralNet::NeuralNet(std::string layer_scheme) function 
*/
void NeuralNet::generate_weights()
{
	weights = new MatrixXf[hidden_layers_len + 1];

	
	if (hidden_layers_len != 0)
	{
		weights[0] = MatrixXf::Random(input_index, hidden_index[0]);
		if (hidden_layers_len > 1)
		{
			for (int i = 0; i < hidden_layers_len - 1; i++)
			{
				weights[i + 1] = MatrixXf::Random(hidden_index[i], hidden_index[i + 1]);
			}
			weights[hidden_layers_len] = MatrixXf::Random(hidden_index[hidden_layers_len - 1], output_index);
		}
		else
		{
			weights[hidden_layers_len] = MatrixXf::Random(hidden_index[hidden_layers_len - 1], output_index);
		}
	}
	else
	{
		weights[0] = MatrixXf::Random(input_index, output_index);
	}

}

/* here an array of MatrixXf will be defined which will contain the values of all the biases in our Neural Network.
   every Matrix in this array is defined given to the amount of neurons in each layer
   the amount of neurons are stored in:
										MatrixXf input_values
										MatrixXf* hidden_values
										MatrixXf output_values
	which are set in the NeuralNet::NeuralNet(std::string layer_scheme) function
*/
void NeuralNet::generate_biases()
{
	biases = new MatrixXf[hidden_layers_len + 1];
	for (int i = 0; i < hidden_layers_len; i++)
	{
		biases[i] = MatrixXf::Random(1, hidden_index[i]);
	}
	biases[hidden_layers_len] = MatrixXf::Random(1, output_index);
}
