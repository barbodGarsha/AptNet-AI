#include "AptNet.h"

// TODO: handle errors NOTE: later with error_handler.cpp/.h
NeuralNet::NeuralNet(std::string layer_scheme)
{
	//TO DO1: setting the setup values with layer_scheme - they are needed in generate_weights() and generate_biases()

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
