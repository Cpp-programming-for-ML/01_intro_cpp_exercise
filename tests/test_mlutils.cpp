#include <iostream>
#include <cmath>
#include <cassert>
#include "../src/mlutils.cpp"

using namespace std;

// Test sigmoid activation
void test_sigmoid(){
    twod_array A = {{1.0,0.6,0.79},
                 {15.9,-22.65,49.99},
                 {3.3,0.15,0.001}};
    twod_array C = {{0.731058579,0.645656306,0.687831331},
                 {0.999999876,0.00000000,1.00000},
                 {0.964428811,0.53742984,0.50025}};
    twod_array res = sigmoid(A);
    assert(compare(res, C));
    A = {{0.22644879, -1.63332347, -0.9685243 ,  1.69784809, -0.00929561, -0.37249256,  1.52719364},
         {-0.95115955,  0.89759245,  0.19628412,  1.59546508,  1.87519907, -0.55765492, -0.09360188},
         {-0.88576706,  1.36174854, -0.36843331, -0.6757256 ,  0.04689628, 0.2896207 ,  0.11614733},
         {-0.81194634, -1.04492248,  0.32547885, -1.2322984 , -1.55543396, 1.16224973, -1.93042923}};
    C = {{0.55637151, 0.16337559, 0.27517474, 0.84525347, 0.49767611, 0.40793887, 0.82159534},
         {0.27865169, 0.7104545 , 0.54891409, 0.83138361, 0.86705871, 0.36409024, 0.47661660},
         {0.29198413, 0.79604373, 0.40891964, 0.33721597, 0.51172192, 0.57190327, 0.52900423},
         {0.3074759 , 0.26020132, 0.58065891, 0.22577941, 0.17430282, 0.76174126, 0.12670308}};
    res = sigmoid(A);
    assert(compare(res, C));
}

// Test mse cost function
void test_cost(){
    twod_array gt = {{-1.34472803, -0.68036661,  0.50162227},
                     { 0.21238899,  0.44488505, -1.11385444},
                     {-0.01984596,  1.07825466, -0.60315014}};
    twod_array h = {{-1.67613501, -1.03342832, -0.97615712},
                    { 1.98773623, -0.62693144, -0.21888114},
                    { 2.2245095 , -0.31431578,  0.37511461}};
    double c = 7.7266632;
    double res = cost(gt, h);
    cout << abs(res-c)<< endl;
    assert(abs(res-c)<1e-7);
}

int main(){
    test_sigmoid();
    test_cost();
    return 0;
}