#include <fstream>
#include <vector>
#include <stdexcept>
#include <random>
#include <cmath>

using namespace std;
typedef vector<vector<double>> twod_array; // Special data type to store arrays.

/**
 * Read input noisy cosine and ground truth cosine
 * 
 * @param noise_data parameter to hold noisy data (pass by reference)
 * @param gt parameter to hold ground truth data (pass by reference)
 */
void read_cosine(twod_array& noise_data, twod_array& gt){
    // Read noisy cosine data for input
    ifstream fp;
    fp.open("../data/noise_cosine.txt");
    if (!fp.is_open())
        throw runtime_error("Invalid file");

    double value;
    int index = 0;
    while (fp >> value){
        noise_data[index][0] = double(value);
        index++;
    }
    fp.close();
    // Read ground truth data
    fp.open("../data/cosine.txt");
    if (!fp.is_open())
        throw runtime_error("Invalid file");

    double gt_val;
    index = 0;
    while (fp >> gt_val){
        gt[index][0] = double(gt_val);
        index++;
    }
    fp.close();
}

/**
 * Write cosine fit to txt file.
 * 
 * @param y_fit parameter holding fit data (pass by reference)
 */
void write_cosine(twod_array& y_fit){
    ofstream fp("./fit.txt");
    if (!fp.is_open())
        throw runtime_error("Invalid file");

    for (int i=0; i<y_fit.size(); i++)
        fp << y_fit[i][0] << "\n";
    fp.close();
}

/**
 * Generate random number of double type.
 * 
 * @return random number
 */
double genrate_random_double(){
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> gen(0, 1);
    return gen(mt);
}

/**
 * Initialise weight from random numbers
 * 
 * @param weight_mat matrix to be initialised (pass by reference)
 */
void initialise_weights(twod_array& weight_mat){
    int rows = weight_mat.size();
    int cols =  weight_mat[0].size();
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++){
            weight_mat[i][j] = genrate_random_double();
        }
    }
}

/**
 * Multiply two matrices.
 * 
 * Raises error if matrices cannot be multplied.
 * 
 * @param A first matrix
 * @param B second matrix
 * @return multiplied matrix
 */
twod_array matmul(twod_array A, twod_array B){
    int Ar = A.size();
    int Ac = A[0].size();
    int Br = B.size();
    int Bc = B[0].size();
    if (Ac != Br)
        throw runtime_error("Columns of A not equals rows of B");
    
    twod_array C(Ar, vector<double>(Bc));
    // TODO: Compute matrix multplication
    return C;
}

/**
 * Add two matrices
 * 
 * Raises error if matrices are different shapes.
 * 
 * @param A first matrix
 * @param B second matrix
 * @return added matrix
 */
twod_array matadd(twod_array A, twod_array B){
    int Ar = A.size();
    int Ac = A[0].size();
    int Br = B.size();
    int Bc = B[0].size();
    if ((Ar != Br) || (Ac != Bc))
        throw runtime_error("Two matrices should be of same shape");
    twod_array C(Ar, vector<double>(Ac));
    // TODO: Compute matrix addition
    return C;
}

/**
 * Subtract two matrices
 * 
 * Raises error if matrices are different shapes.
 * 
 * @param A first matrix
 * @param B second matrix
 * @return subtracted matrix
 */
twod_array matsub(twod_array A, twod_array B){
    int Ar = A.size();
    int Ac = A[0].size();
    int Br = B.size();
    int Bc = B[0].size();
    if ((Ar != Br) || (Ac != Bc))
        throw runtime_error("Two matrices should be of same shape");
    twod_array C(Ar, vector<double>(Ac));
    // TODO: Compute matrix subtraction
    return C;
}

/**
 * Power of matrix (element wise).
 * 
 * @param A first matrix
 * @param p int with requried power
 * @return matrix power
 */
twod_array matpow(twod_array A, int p){
    int Ar = A.size();
    int Ac = A[0].size();
    twod_array C(Ar, vector<double>(Ac));
    // TODO: Compute power 'p' of matrix per each element.
    return C;
}

/**
 * Element sum in matrix.
 * 
 * @param A input matrix
 * @return variable cotnaining sum of all matrix elements
 */
double matsum(twod_array A){
    int Ar = A.size();
    int Ac = A[0].size();
    double sum_val = 0.0;
    // TODO: Compute sum of all elements in the matrix.
    return sum_val;
}

/**
 * Compute matrix transpose.
 * 
 * @param A input matrix
 * @return transposed matrix
 */
twod_array mattranspose(twod_array A){
    int Ar = A.size();
    int Ac = A[0].size();
    twod_array A_t(Ac, vector<double>(Ar));
    // TODO: Compute transpose of the matrix.
    return A_t;
}

/**
 * Compute matrix hadamard (element-wise) product.
 * 
 * @param A first matrix
 * @param B second matrix
 * @return hadamard product
 */
twod_array hadamard_product(twod_array A, twod_array B){
    int Ar = A.size();
    int Ac = A[0].size();
    int Br = B.size();
    int Bc = B[0].size();
    if ((Ar != Br) || (Ac != Bc))
        throw runtime_error("Two matrices should be of same shape");
    twod_array C(Ar, vector<double>(Ac));
    // TODO: Compute element wise product of the matrices.
    return C;
}

/**
 * Subtract specific scalar. 
 * 
 * Particularly used in gradient computation for sigmoid.
 * 
 * @param A input matrix
 * @param B scalar to remove
 * @return resultant matrix
 */
twod_array ele_subtract(twod_array A, double B){
    int Ar = A.size();
    int Ac = A[0].size();
    twod_array C(Ar, vector<double>(Ac));
    for (int i=0; i<Ar; i++){
        for (int j=0; j<Ac; j++){
            C[i][j] = B-A[i][j];
        }
    }
    return C;
}

/**
 * Multiply scalar to individual element in matrix.
 * 
 * @param A input matrix
 * @param B scalar to multiply
 * @return resultant matrix
 */
twod_array ele_product(twod_array A, double B){
    int Ar = A.size();
    int Ac = A[0].size();
    twod_array C(Ar, vector<double>(Ac));
    for (int i=0; i<Ar; i++){
        for (int j=0; j<Ac; j++){
            C[i][j] = B*A[i][j];
        }
    }
    return C;
}

/**
 * Compare two matrices (element-wise).
 * 
 * @param A first matrix
 * @param B second matrix
 * @return boolean 
 */
bool compare(twod_array& A, twod_array& B){
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (abs(A[i][j] - B[i][j]) > 1e-8) { 
                return false;
            }
        }
    }
    return true;
}
