#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <random>

using namespace std;
const int N = 10000000;

class VecSOA {
public:
    float* x;
    float* y;
    float* z;

    VecSOA() {
        x = new float[N];
        y = new float[N];
        z = new float[N];
    }
};

int main() {
    float foo = 0;
    int tests = 30;

    VecSOA* vecSOA = new VecSOA();

    for (int i = 0; i < N; i++) {
        vecSOA -> x[i] = rand();
        vecSOA -> y[i] = rand();
        vecSOA -> z[i] = rand();
    }

    for (int i = 0; i < tests; i++) {
        float sumX, sumY, sumZ;
        sumX = sumY = sumZ = 0;

        for (int j = 0; j < N; j++) {
            sumX += vecSOA -> x[j];
            sumY += vecSOA -> y[j];
            sumZ += vecSOA -> z[j];
        }

        foo += sumX + sumY + sumZ;
    }

    return 0;
}