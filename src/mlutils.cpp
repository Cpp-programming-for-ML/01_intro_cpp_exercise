#include <iostream>
#include <vector>
#include "./utils.cpp"

using namespace std;

twod_array sigmoid(twod_array matrix){
    // TODO: Implemet sigmoid activation.
    return matrix;
}

double cost(twod_array gt, twod_array h){
    //TODO: Compute mse loss
    return 0.0;
}

void compute_gradients(twod_array w_2, twod_array w_1, twod_array bias, twod_array x, twod_array y, 
    twod_array& grad_w2, twod_array& grad_w1, twod_array& grad_bias){
    twod_array h_0 = matadd(matmul(w_1, x), bias);
    twod_array sigm_h_0 = sigmoid(h_0);
    twod_array h1 = matmul(w_2, sigm_h_0);
    twod_array p = matsub(y, h1);
    
    grad_w2 = matmul(p, mattranspose(sigm_h_0));
    grad_w2 = ele_product(grad_w2, -1.0);

    twod_array sigm_deriv = hadamard_product(sigm_h_0, ele_subtract(sigm_h_0, -1.0));
    twod_array p1 = matmul(mattranspose(w_2), p);
    twod_array deriv_interim = hadamard_product(p1, sigm_deriv);
    grad_w1 = matmul(deriv_interim, mattranspose(x));
    grad_w1 = ele_product(grad_w1, -1.0);
    grad_bias = ele_product(deriv_interim, -1.0);
}