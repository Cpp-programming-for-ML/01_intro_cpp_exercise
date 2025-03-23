#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include "./mlutils.cpp"

using namespace std;

/**
 * Network forward pass.
 * 
 * Forward pass function is given by y = W2(sigmoid(W1x+b))
 * 
 * @param w1 dense weight matrix 1 of shape (10, 200)
 * @param w2 dense weight matrix 2 of shape (200, 10)
 * @param b bias vector for weight matrix 1 of shape (10, 1)
 * @param x input of shape (200, 1)
 * @return network prediction output
 */
twod_array network(twod_array w1, twod_array w2, twod_array b, twod_array x){
    // TODO: Implement forward pass
}

int main(){
    // Hyperparameters
    int input_neurons = 200;
    int output_neurons = 200;
    int hidden_neurons = 10;
    double lr = 0.01;
    int epochs = 150;
    
    // Read input data (noise and ground truth)
    twod_array y_noise(input_neurons, vector<double>(1));
    twod_array y(input_neurons, vector<double>(1));
    read_cosine(y_noise, y);

    twod_array y_hat;
    double loss_val;

    // TODO: Declare and intialise parameters
    // TODO: Declare gradients

    for(int epoch=0; epoch<epochs; epoch++){
        // TODO: Forward pass
        // TODO: Compute cost and gradients
        // TODO: Update parameters using SGD
        cout << "Epoch: " << epoch << " Loss: " << loss_val << endl;
    }
    // TODO: Get network predictions on y_noise and assign to y_hat variable.
    write_cosine(y_hat);
    return 0;
}