#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <random>

using namespace std;

class Vec {
public:
    float x;
    float y;
    float z;
};

int main() {
    float foo = 0;
    int tests = 30;

    const int N = 10000000;

    Vec* vecs = new Vec[N];

    for (int i = 0; i < N; i++) {
        vecs[i].x = rand();
        vecs[i].y = rand();
        vecs[i].z = rand();
    }

    for (int i = 0; i < tests; i++) {
        float sumX, sumY, sumZ;
        sumX = sumY = sumZ = 0;

        for (int j = 0; j < N; j++) {
            sumX += vecs[j].x;
            sumY += vecs[j].y;
            sumZ += vecs[j].z;
        }

        foo += sumX + sumY + sumZ;
    }

    return 0;
}