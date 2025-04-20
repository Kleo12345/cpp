#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

int screenWidth = 120; // Width of console
int screenHeight = 80; // Height of console
float K2 = 100; // Distance from the viewer
float K1 = 50; // Horizontal projection scale factor
float cubeWidth = 25;
float resolution = 0.2;
bool LUMINOSITY = false;
bool COLORS = false;

float rotatedX, rotatedY, rotatedZ, ooz;
int xP, yP;

std::vector<char> b(screenWidth * screenHeight, ' ');
std::vector<int> c(screenWidth * screenHeight, 33);
std::vector<float> zBuffer(screenWidth * screenHeight, 0);

const float pi = 3.14159265;

float A = 0.0;
float B = 0.0;
float C = 0.0;

void SetColor(int colorCode){std::cout << "\x1B[" << colorCode << "m";}

void ResetColor(){std::cout << "\033[0m";}

void plotPlane(float x, float y, float z, char ch){
    rotatedX = y*(sin(A)*sin(B)*cos(C)+cos(A)*sin(C))+z*(sin(A)*sin(C)-cos(A)*sin(B)*cos(C))+x*cos(B)*cos(C);
    rotatedY = y*(cos(A)*cos(C)-sin(A)*sin(B)*sin(C))+z*(cos(A)*sin(B)*sin(C)+sin(A)*cos(C))-x*cos(B)*sin(C);
    rotatedZ = -y*sin(A)*cos(B)+z*cos(A)*cos(B)+x*sin(B) + K2;

    ooz = 1 / rotatedZ;

    int xP = int(screenWidth / 2 + K1 * ooz * rotatedX * 2);
    int yP = int(screenHeight / 2 - K1 * ooz * rotatedY);

    int position = xP + yP * screenWidth;
    float tmpColor = 33;

    if(COLORS){
        if(ch == '@'){ tmpColor = 32;}
        else if(ch == '#'){tmpColor = 31;}
        else if(ch == '$'){tmpColor = 34;}
        else if(ch == 'o'){tmpColor = 35;}
        else if(ch == '*'){tmpColor = 36;}
        else if(ch == '&'){tmpColor = 37;}
    }

    if (LUMINOSITY){
        x = 0;
        y = 0;
        z = 0;

        // Pretty Way
        if(ch == '@'){z = 1/1.6259; y = (-1/0.78)/1.6259;}
        else if(ch == '#'){z = -1/1.6259; y = (-1/0.78)/1.6259;}
        else if(ch == '*'){x = -1;}
        else if(ch == '&'){x = 1;}
        else if(ch == 'o'){y = 1;}

        // Correct Way
        // if(ch == '@'){z = 1/1.6259; y = (-1/0.78)/1.6259;}
        // else if(ch == '#'){z = -1/1.6259; y = (-1/0.78)/1.6259;}
        // else if(ch == '*'){x = -1/1.6259; y = (-1/0.78)/1.6259;}
        // else if(ch == '&'){x = 1/1.6259; y = (-1/0.78)/1.6259;}
        // else if(ch == 'o'){y = 1;}

        float lumY = y*(cos(A)*cos(C)-sin(A)*sin(B)*sin(C))+z*(cos(A)*sin(B)*sin(C)+sin(A)*cos(C))-x*cos(B)*sin(C);
        float lumZ =  -y*sin(A)*cos(B)+z*cos(A)*cos(B)+x*sin(B);
        float lum = (-lumY-lumZ);
        if (lum<0){
            lum = 0;
        }
        int luminance_index = lum * 8;
        ch = ".,-~:;=!*#$@"[luminance_index > 0 ? luminance_index : 0];
    }

    if (position >= 0 && position < screenWidth * screenHeight) {
        if (ooz > zBuffer[position]) {
            zBuffer[position] = ooz;
            b[position] = ch;
            c[position] = tmpColor;
        }
    }
}


int main() {
    std::cout << "\x1b[2J";
    
    bool loop = true;
    bool runOnce = false;

    while(loop){
        std::fill(b.begin(), b.end(), ' ');
        std::fill(zBuffer.begin(), zBuffer.end(), 0);
        std::fill(c.begin(), c.end(), 33);

        for (float i = -cubeWidth; i < cubeWidth; i += resolution) {
            for (float j = -cubeWidth; j < cubeWidth; j += resolution) {

                if (j >= 0 && j >= abs(i)) {
                    plotPlane(i, ((-1/0.78)*j)+0, j, '@');
                }
                else if(j < 0 && j <= -abs(i)){
                    plotPlane(i, ((1/0.78)*j)+0, j, '#');
                }

                if(i >= 0 && i >= abs(j)){
                    plotPlane(i, ((-1/0.78)*i)+0, j, '&');
                }
                else if(i < 0 && i <= -abs(j)){
                    plotPlane(i, ((1/0.78)*i)+0, j, '*');
                }
                // plotPlane(i, -cubeWidth, j, 'o');
            }
        }

        std::cout << "\x1b[H";
        for (int k = 0; k < screenWidth * screenHeight; ++k) {
            if (COLORS){
                SetColor(c[k]);
            }

            std::cout.put(k % screenWidth ? b[k] : '\n');
            if (COLORS){
                ResetColor();
            }
        }

        // Update rotation angles
        // A += 0.3;
        B += 0.1;
        // C += 0.1;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        if (runOnce){
            loop = false;
        }
    }

    return 0;
}
