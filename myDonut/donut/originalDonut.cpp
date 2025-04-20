#include <iostream>
#include <string.h>
#include <math.h>
#include <unistd.h>
using namespace std;

int main() {
    system("clear");
    float A = 0, B = 0;
    float phi, theta;
    int k;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
    for(;;) {
        memset(b,32,1760);
        memset(z,0,7040);
        for(theta=0; theta < 6.28; theta += 0.07) {
            for(phi=0; phi < 6.28; phi += 0.02) {
                float c = sin(phi);
                float d = cos(theta);
                float e = sin(A);
                float f = sin(theta);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (sin(phi) * (cos(theta) + 2) * sin(A) + sin(theta) * cos(A) + 5); // 1/z
                float l = cos(phi);
                float m = cos(B);
                float n = sin(B);
                float t = sin(phi) * (cos(theta) + 2) * cos(A) - sin(theta) * sin(A);
                
                int x = 40 + 30 * D * (cos(phi) * (cos(theta) + 2) * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004; // 0.00004;
            B += 0.00002; //0.00002;
        }
        //std::cout << "A:" << A;
        //std::cout << "B:" << B;

        usleep(30000);
    }
    return 0;
}