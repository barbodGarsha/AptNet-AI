#pragma once

class NeuralNet
{
public:
	
	NeuralNet(std::string layers_scheme);
	NeuralNet();

	void set_activations_funtions(std::string activation_functions_scheme);
	
private:
	int input_index;
	int* hidden_index;
	int output_index;

	MatrixXf input_values;
	MatrixXf* hidden_values;
	MatrixXf output_values;

	MatrixXf* raw_values;

	int* activations_functions;

	int hidden_layers_len;

	MatrixXf* weights;
	MatrixXf* biases;


	void generate_weights();
	void generate_biases();

};
