#ifndef UTILS_H
#define UTILS_H

#include "network.h"
#include "sparse_representation.hpp"

void cudaCheckErr();
void cublasCheckError(cublasStatus_t stat);
void cusparseCheckError(cusparseStatus_t stat);

void print_vector(float *vec, int len);
void print_matrix(float *mat, int n_rows, int ncols);
void print_bsr_matrix(BSR &mat);
void print_csr_matrix(CSR &mat);
void print_sparse_vector(SparseVector vec);

MLP load_mlp(const char *path, int n_inputs, int n_hidden1, int n_hidden2, int n_outputs);
void load_mnist_data(float *mnist_data);
void load_mnist_labels(unsigned char *mnist_labels);

SparseVector dense_to_SparseVector(float *values, unsigned int len, unsigned int gpu);
CSR get_random_projection(unsigned int nrows, unsigned int ncols, float s, unsigned int gpu);
BSR dense_to_BSR(float *mat, unsigned int nrows, unsigned int ncols, unsigned int block_size);

#endif /* !UTILS_H */
