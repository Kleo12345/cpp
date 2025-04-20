#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>
#include <random>
#include <vector>

int screenWidth = 100; // Width of console
int screenHeight = 80; // Height of console
float theta_spacing = 0.01;
float phi_spacing = 0.01;
float R1 = 1; // Smaller circle radius
float R2 = 2; // Larger circle radius
float K2 = 5; // Distance from the viewer
float K1 = 50; // Horizontal projection scale factor

const float pi = 3.14159265;

float A = 0.0;
float B = 0.0;

// Srinkles
float thicknessTheta = 0.1;
float thicknessPhi = 0.1;
float midPoint = (3*pi)/2;
int numberSprinkles = 200;

void SetColor(int colorCode){std::cout << "\x1B[" << colorCode << "m";}

void ResetColor(){std::cout << "\033[0m";}


int main() {
    std::cout << "\x1b[2J";
    
    bool loop = true;
    bool runOnce = false;

    std::vector<int> colorsSprinkles;
    colorsSprinkles.push_back(31);
    colorsSprinkles.push_back(32);
    colorsSprinkles.push_back(33);
    colorsSprinkles.push_back(36);

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(-1.5, 1.5);
    std::uniform_int_distribution<> distribution2(0, colorsSprinkles.size() - 1);


    std::vector<float> randTheta(numberSprinkles, midPoint);
    std::vector<int> randThetaColor(numberSprinkles, 36);
    float random_number = 0;
    int random_numberColor = 0;

    for(int i=0; i < numberSprinkles; i++) {
        random_number = distribution(generator);
        random_numberColor = colorsSprinkles[distribution2(generator)];
        randTheta[i] += random_number;
        randThetaColor[i] = random_numberColor;
    }

    while(loop){
        
        std::vector<char> b(screenWidth * screenHeight, ' ');
        std::vector<int> c(screenWidth * screenHeight, 33);
        std::vector<float> zBuffer(screenWidth * screenHeight, 0);

        // Render Donut
        for (float theta=0; theta < 2*pi; theta += theta_spacing) {
            for(float phi=0; phi < 2*pi; phi += phi_spacing) {
                // Math 3D coordinates
                float x = (R2+R1*cos(theta))*(cos(B)*cos(phi)+sin(A)*sin(B)*sin(phi))-R1*sin(theta)*cos(A)*sin(B);
                float y = (R2+R1*cos(theta))*(sin(B)*cos(phi)-sin(A)*cos(B)*sin(phi))+R1*sin(theta)*cos(A)*cos(B); // COSINUS DE B NO DE SINO ESTE ES EL ERROR GILIPOLLAS
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

                        if (theta > pi+0.2*cos(phi*5) && theta < 2*pi-0.2*cos(phi*5)){
                            // Change color of character
                            c[position] = 95;

                            // Generate Sparkles
                            int count = 0;
                            for(float phi2=0; phi2 <= 2*pi; phi2 += (2*pi)/numberSprinkles) {
                                //std::cout << phi2 << "\n";
                                if ((theta < randTheta[count]+thicknessTheta && theta > randTheta[count]-thicknessTheta)  && (phi > phi2 && phi < phi2+thicknessPhi)){
                                    c[position] = randThetaColor[count];
                                }
                                count++;
                            }
                            //std::cout << "\n";
                            
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
