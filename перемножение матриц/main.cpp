
#include "optimization.h"
int main() {
    unsigned long long n = readInt<unsigned long long>();
    unsigned long long s = readInt<unsigned long long>();
    unsigned long long a[n][n];
    unsigned long long b[n][n];
    unsigned long long c[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j]=readInt<unsigned long long>();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j][i]=readInt<unsigned long long>();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[j][k];
                if (c[i][j] >= s * s)
                    c[i][j] -= s * s;
            }
            c[i][j] = c[i][j] % s;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            writeInt<unsigned long long>(c[i][j]);
            writeChar(' ');
        }
        writeChar('\n');
    }

}