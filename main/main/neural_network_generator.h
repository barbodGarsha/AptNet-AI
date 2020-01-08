#pragma once

class TrainingSmaple
{
public:
	MatrixXf inputs;
	MatrixXf outputs;
};

class NeuralNet
{
public:
	
	NeuralNet(std::string layers_scheme);
	NeuralNet();

	void set_activations_funtions(std::string activation_functions_scheme);
	
	void set_inputs(MatrixXf inputs);
	
	void feedforward();

	void set_training_samples(TrainingSmaple samples[], int size);

	/* TODO1 : is_ready we should know if our Neural Network has everything it needs for the training
			   however it works we will handle it in the Error handling for now we use this to build the basic of checking system			
	*/
	int is_ready();

	/*
	get functions
	TODO2 : if it's needed we use them
	int get_input_index();
	int* get_hidden_index();
	int get_output_index();

	MatrixXf get_input_values();
	MatrixXf* get_hidden_values();
	MatrixXf get_output_values();

	uint32_t get_training_samples_n();*/

	//--------------------------------
	//TODO2 : these might need to be private
	int input_index;
	int* hidden_index;
	int output_index;

	MatrixXf input_values;
	MatrixXf* hidden_values;
	MatrixXf output_values;

	MatrixXf* raw_values;

	uint32_t training_samples_n;

	TrainingSmaple* training_samples;

	int* activations_functions;

	int hidden_layers_len;

	MatrixXf* weights;
	MatrixXf* biases;
	//----------------------------
private:
	//TODO1 : is_ready (for now it's always ready lol)
	int ready = 1;

	void generate_weights();
	void generate_biases();

};
