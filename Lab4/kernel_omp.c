#include <omp.h>

#include "kernel.h"

void kernel_omp(int *input, int *ref, int64_t rows, int64_t cols, int penalty) {
    const int BLOCK_SIZE = 64;
    #pragma omp parallel
    {
    for (int xx = 1; xx < rows - BLOCK_SIZE + 1; xx += BLOCK_SIZE) {
        #pragma omp for
        for (int y = 1; y < xx + 1; y += BLOCK_SIZE) {
            int x = xx - y + 1;
            int xbound = x + BLOCK_SIZE;
            int ybound = y + BLOCK_SIZE;
            for (int i = x; i < xbound; i++) {
                for (int j = y; j < ybound; j += 4) {
                    int64_t idx = i * cols + j;

                    int64_t idxNW = idx - cols - 1;
                    int64_t idxN = idx - cols;
                    int64_t idxW = idx - 1;
                    int r = ref[idx];
                    int inputNW = input[idxNW];
                    int inputW = input[idxW];
                    int inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);

                    idx++;
                    idxNW = idx - cols - 1;
                    idxN = idx - cols;
                    idxW = idx - 1;
                    r = ref[idx];
                    inputNW = input[idxNW];
                    inputW = input[idxW];
                    inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);

                    idx++;
                    idxNW = idx - cols - 1;
                    idxN = idx - cols;
                    idxW = idx - 1;
                    r = ref[idx];
                    inputNW = input[idxNW];
                    inputW = input[idxW];
                    inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);

                    idx++;
                    idxNW = idx - cols - 1;
                    idxN = idx - cols;
                    idxW = idx - 1;
                    r = ref[idx];
                    inputNW = input[idxNW];
                    inputW = input[idxW];
                    inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);
                }
            }
        }
    }
    const int rowlimit = rows - BLOCK_SIZE;
    for (int yy = 1 + BLOCK_SIZE; yy < cols - BLOCK_SIZE + 1; yy += BLOCK_SIZE) {
        #pragma omp for
        for (int x = rowlimit; x > yy - 1; x -= BLOCK_SIZE) {
            int y = rowlimit - x + yy;
            int xbound = x + BLOCK_SIZE;
            int ybound = y + BLOCK_SIZE;
            for (int i = x; i < xbound; i++) {
                for (int j = y; j < ybound; j += 4) {
                    int64_t idx = i * cols + j;

                    int64_t idxNW = idx - cols - 1;
                    int64_t idxN = idx - cols;
                    int64_t idxW = idx - 1;
                    int r = ref[idx];
                    int inputNW = input[idxNW];
                    int inputW = input[idxW];
                    int inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);

                    idx++;
                    idxNW = idx - cols - 1;
                    idxN = idx - cols;
                    idxW = idx - 1;
                    r = ref[idx];
                    inputNW = input[idxNW];
                    inputW = input[idxW];
                    inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);

                    idx++;
                    idxNW = idx - cols - 1;
                    idxN = idx - cols;
                    idxW = idx - 1;
                    r = ref[idx];
                    inputNW = input[idxNW];
                    inputW = input[idxW];
                    inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);

                    idx++;
                    idxNW = idx - cols - 1;
                    idxN = idx - cols;
                    idxW = idx - 1;
                    r = ref[idx];
                    inputNW = input[idxNW];
                    inputW = input[idxW];
                    inputN = input[idxN];
                    input[idx] = maximum(inputNW + r, inputW - penalty, inputN - penalty);
                }
            }
        }
    }
    }
}
