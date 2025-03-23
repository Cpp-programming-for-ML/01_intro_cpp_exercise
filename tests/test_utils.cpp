#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include "../src/utils.cpp"

using namespace std;

// Test matrix multplication
void test_matrix_multiplication(){
    twod_array A = {{1.0,2.0,3.0},
                 {4.0,5.0,6.0}};
    twod_array B = {{1.0,0.0,1.0},
                 {0.0,1.0,1.0},
                 {1.0,1.0,0.0}};
    twod_array C = {{4.0,5.0,3.0},
                 {10.0,11.0,9.0}};
    twod_array res = matmul(A, B);
    assert(compare(res, C));
    A = {{0.1,-0.4,-0.9},
         {0.5,1.4,-1.5},
         {-0.2,1.0,-0.9},
         {1.1,-0.5,0.1}};
    B = {{0.6,0.1,0.9,-0.6,-0.2},
         {-0.1,-0.5,0.6,0.4,-0.2},
         {1.3,0.9,1.2,0.9,2.1}};
    C = {{-1.07,-0.60,-1.23,-1.03,-1.83},
         {-1.79,-2.00,-0.51,-1.09,-3.53},
         {-1.39,-1.33,-0.66,-0.29,-2.05},
         {0.84,0.45,0.81,-0.77,0.09}};
    res = matmul(A, B);
    assert(compare(res, C));
}

// Test matrix addition
void test_matrix_addition(){
    twod_array A = {{1.0,2.0,3.0},
                 {4.0,5.0,6.0}};
    twod_array B = {{1.0,0.0,1.0},
                 {0.0,1.0,1.0},
                 {1.0,1.0,0.0}};
    try{
        twod_array res = matadd(A, B);
    }
    catch(runtime_error){
        assert(true);
    }
    A = {{1.0,2.0},
         {4.0,5.0}};
    B = {{1.0,0.0},
         {0.0,1.0}};
    twod_array C = {{2.0,2.0},
                    {4.0,6.0}};
    twod_array res = matadd(A, B);
    assert(compare(res, C));
}

// Test matrix subtraction
void test_matrix_subtraction(){
    twod_array A = {{1.0,2.0,3.0},
                 {4.0,5.0,6.0}};
    twod_array B = {{1.0,0.0,1.0},
                 {0.0,1.0,1.0},
                 {1.0,1.0,0.0}};
    try{
        twod_array res = matsub(A, B);
    }
    catch(runtime_error){
        assert(true);
    }
    A = {{1.0,2.0},
         {4.0,5.0}};
    B = {{1.0,0.0},
         {0.0,1.0}};
    twod_array C = {{0.0,2.0},
                    {4.0,4.0}};
    twod_array res = matsub(A, B);
    assert(compare(res, C));
}

// Test power of matrix (element-wise)
void test_matrix_power(){
    twod_array A = {{1.0, 2.0},
                    {4.0, 5.0}};
    twod_array C = {{1.0, 4.0},
                    {16.0, 25.0}};
    twod_array res = matpow(A, 2);
    assert(compare(res, C));
    C = {{1.0, 8.0},
         {64.0, 125.0}};
    res = matpow(A, 3);
    assert(compare(res, C));
}

// Test sum of all elements in matrix
void test_matrix_sum(){
    twod_array A = {{1.0, 2.0},
                    {4.0, 5.0}};
    double C = 12.0;
    double res = matsum(A);
    assert(res==C);
    A = {{0.1,-0.4,-0.9},
         {0.5,1.4,-1.5},
         {-0.2,1.0,-0.9},
         {1.1,-0.5,0.1}};
    C = -0.2;
    res = matsum(A);
    assert(abs(res-C)<1e-10);
}

// Test transpose of matrix
void test_matrix_transpose(){
    twod_array A = {{1.0, 2.0},
                    {4.0, 5.0}};
    twod_array C = {{1.0, 4.0},
                    {2.0, 5.0}};
    twod_array res = mattranspose(A);
    A = {{0.1,-0.4,-0.9},
         {0.5,1.4,-1.5},
         {-0.2,1.0,-0.9},
         {1.1,-0.5,0.1}};
    C = {{0.1, 0.5, -0.2, 1.1},
         {-0.4, 1.4, 1.0, -0.5},
         {-0.9, -1.5, -0.9, 0.1}};
    res = mattranspose(A);
    assert(compare(res, C));
}

// Test matrix hadamard product.
void test_hadamard_product(){
    twod_array A = {{1.0, 2.0},
                    {4.0, 5.0}};
    twod_array B = {{11.0, 7.0},
                    {4.0, 9.0}};
    twod_array C = {{11.0, 14.0},
                    {16.0, 45.0}};
    twod_array res = hadamard_product(A, B);
    assert(compare(res, C));
}

int main(){
    test_matrix_multiplication();
    test_matrix_addition();
    test_matrix_subtraction();
    test_matrix_power();
    test_matrix_sum();
    test_matrix_transpose();
    test_hadamard_product();
    return 0;
}