#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include "./mlutils.cpp"

using namespace std;

twod_array network(twod_array w1, twod_array w2, twod_array b, twod_array x){
    twod_array h0 = sigmoid(matadd(matmul(w1, x), b));
    twod_array h1 = matmul(w2, h0);
    return h1;
}

int main(){
    double lr = 0.01;
    int epochs = 150;
    twod_array y_hat;
    double loss_val;
    vector<double> gradients;
    twod_array W1(10, vector<double>(200));
    twod_array W2(200, vector<double>(10));
    twod_array bias(10, vector<double>(1));
    twod_array grad_w1(10, vector<double>(200)); 
    twod_array grad_w2(200, vector<double>(10)); 
    twod_array grad_bias(10, vector<double>(1)); 
    twod_array y_noise(200, vector<double>(1));
    twod_array y(200, vector<double>(1));

    read_cosine(y_noise, y);

    initialise_weights(W1);
    initialise_weights(W2);
    initialise_weights(bias);

    for(int epoch=0; epoch<epochs; epoch++){
        y_hat = network(W1, W2, bias, y_noise);
        loss_val = cost(y, y_hat);
        compute_gradients(W2, W1, bias, y_noise, y, grad_w2, grad_w1, grad_bias);
        W2 = matadd(W2, ele_product(ele_product(grad_w2, lr), -1.0));
        W1 = matadd(W1, ele_product(ele_product(grad_w1, lr), -1.0));
        bias = matadd(bias, ele_product(ele_product(grad_bias, lr), -1.0));
        cout << "Epoch: " << epoch << " Loss: " << loss_val << endl;
    }
    y_hat = network(W1, W2, bias, y_noise);
    write_cosine(y_hat);
    return 0;
}