#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

int screenWidth = 100; // Width of console
int screenHeight = 80; // Height of console
float theta_spacing = 0.01;
float phi_spacing = 0.01;
float R1 = 1; // Smaller circle radius
float R2 = 2; // Larger circle radius
float K2 = 5; // Distance from the viewer
float K1 = 50; // Horizontal projection scale factor
bool COLORS = true;

const float pi = 3.14159265;

float A = 0.0;
float B = 0.0;

void SetColor(int colorCode){std::cout << "\x1B[" << colorCode << "m";}

void ResetColor(){std::cout << "\033[0m";}


int main() {
    std::cout << "\x1b[2J";
    
    bool loop = true;
    bool runOnce = false;

    while(loop){
        
        std::vector<char> b(screenWidth * screenHeight, ' ');
        std::vector<int> c(screenWidth * screenHeight, 33);
        std::vector<float> zBuffer(screenWidth * screenHeight, 0);

        // Render Donut
        for (float theta=0; theta < 2*pi; theta += theta_spacing) {
            for(float phi=0; phi < 2*pi; phi += phi_spacing) {
                // Math 3D coordinates
                float x = (R2+R1*cos(theta))*(cos(B)*cos(phi)+sin(A)*sin(B)*sin(phi))-R1*sin(theta)*cos(A)*sin(B);
                float y = (R2+R1*cos(theta))*(sin(B)*cos(phi)-sin(A)*cos(B)*sin(phi))+R1*sin(theta)*cos(A)*cos(B);
                float z = K2 + cos(A)*(R2+R1*cos(theta))*sin(phi)+R1*sin(A)*sin(theta);
                float ooz = 1 / z;
                
                // 2D Projection coordinates
                int xP = int(screenWidth / 2 + K1 * ooz * x);
                int yP = int(screenHeight / 2 - K1 * ooz * y*0.5);

                // Calculate luminance
                float lum = (cos(phi)*cos(theta)*sin(B)-cos(A)*cos(theta)*sin(phi)-sin(A)*sin(theta)+cos(B)*(cos(A)*sin(theta)-cos(theta)*sin(A)*sin(phi))); //(0,1,-1)
                //lum = -cos(A)*cos(theta)*sin(phi)-sin(A)*sin(theta); // (0,0,-1)

                if (lum<0){
                    lum = 0;
                }
                // Check with z-buffer
                int position = xP + yP * screenWidth;

                //c[position] = 0;
                if (position >= 0 && position < screenWidth * screenHeight) {
                    if (ooz > zBuffer[position]) {
                        zBuffer[position] = ooz;
                        int luminance_index = lum * 8; // Scale luminance value to index ASCII chars
                        b[position] = ".,-~:;=!*#$@"[luminance_index > 0 ? luminance_index : 0]; //".,-~:;=!*#$@"[lumIdx];

                        if (theta > pi+0.2*cos(phi*5) && theta < 2*pi-0.2*cos(phi*5) && COLORS){
                            // Change color of character
                            c[position] = 95;
                        }
                    }
                }
            }
        }

        std::cout << "\x1b[H";
        for (int k = 0; k < screenWidth * screenHeight; ++k) {
            SetColor(c[k]);
            std::cout.put(k % screenWidth ? b[k] : '\n');
            ResetColor();
        }

        // Update rotation angles
        A += 0.1;
        B += 0.1;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        if (runOnce){
            loop = false;
        }
    }

    return 0;
}
