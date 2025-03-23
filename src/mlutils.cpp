#include <iostream>
#include <vector>
#include "./utils.cpp"

using namespace std;

/**
 * Sigmoid function.
 * 
 *                                                                      1
 * Compute sigmoid activation function (element-wise) using formula -----------
 *                                                                  1 + exp(-x)
 * @param matrix input matrix
 * @return sigmoid activated matrix    
 */
twod_array sigmoid(twod_array matrix){
    // TODO: Implemet sigmoid activation.
    return matrix;
}

/**
 * MSE Loss
 * 
 * Compute MSE loss as 0.5*sum((gt-h)^2)
 * 
 * @param gt ground truth
 * @param h network predictions
 * @return scalar of double type with loss value
 */
double cost(twod_array gt, twod_array h){
    // TODO: Compute mse loss
    return 0.0;
}

/**
 * Compute gradients
 * 
 * @param w_2 dense weight matrix 2
 * @param w_1 dense wegiht matrix 1
 * @param bias bias for w_1
 * @param x input
 * @param y ground truth
 * @param grad_w2 gradient for w_2 (pass by reference)
 * @param grad_w1 gradient for w_1 (pass by reference)
 * @param grad_bias gradient for bias (pass by reference)
 */
void compute_gradients(twod_array w_2, twod_array w_1, twod_array bias, twod_array x, twod_array y,
    twod_array& grad_w2, twod_array& grad_w1, twod_array& grad_bias){
    // TODO: Compute gradients
}
