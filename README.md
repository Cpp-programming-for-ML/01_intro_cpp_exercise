# Exercise Denoise Cosine
The goal of this exercise is to implement a multilayer dense neuralnetwork from scratch using C++.
Specifically, you will implement gradient descent and use it to learn a cosine function.
- First, take a look and understand array datatype defined in `line 8` in `src/utils.cpp`.
- Further now, code the linear algebra operations such as matrix multplication, addition, subtraction, hadamard (element-wise) product, matrix elements sum, transpose, and matrix power (element-wise) in `src/utils.cpp`.
- You can check your implementation of functions in `src/utils.cpp` by running tests with following commands
```bash
cd <exercise_folder>/tests
g++ -o test_utils_executable test_utils.cpp
./test_utils_executable
```
- If you see no output by running the executable, this means the implementation is right.
- Navigate to `src/mlutils.cpp` and code `sigmoid` activation function as first step.
```math
\sigma(x) = \frac{1}{1 + e^{-x}}
```
- In next step, given ground truth and predictions, compute Mean Square Error (MSE) in `cost` function as follows
```math
MSE = \frac{1}{2}\sum(y-h)^2
```
- Similarly you can test your implementation of `src/mlutils.cpp` by executing `test_mlutils.cpp`.
- Navigate to `src/denoise_cosine.cpp` with the above custom datatype, declare $W_1, W_2, bias$ variables and intialise the weights using the corresponding initialisation function in `src/utils.cpp`. Similarly declare the gradient variables.
- Code the forward pass in `network` function in `src/denoise_cosine.cpp` and call this forward pass in main function training followed by above implemented loss function.
- As a next step, derive the gradients for each variable and implement in `compute_gradients` function in `src/mlutils.cpp`. Note: `compute_gradients` function needs the above declared gradient variables as arguments and they are pass by reference, so no return type is necessary. 
- As a final training step implement the gradient descent step using the following formula.
```math
W_{new} = W_{old} - lr*\nabla W_{old}
```
- Finally compute the network predictions and assign it to `y_hat` variable. Now you can run the C++ program by runnig the following commands
```bash
cd <exercise_folder>/src
g++ -o denoise_executable denoise_cosing.cpp
./denoise_executable
```
- Finally, to check our cosine fit, you need to run the following commands
```bash
cd <exercise_folder>/src
python plot.py
```