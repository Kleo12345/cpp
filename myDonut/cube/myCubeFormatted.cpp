#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

                           int screenWidth = 100; int screenHeight = 80; float K2 = 100; float K1 = 50;
                           float cubeWidth = 20; float resolution = 0.2; bool LUMINOSITY  = true; float
                           rotatedX, rotatedY, rotatedZ, ooz; int xP, yP;std::vector<char>b(screenWidth
                           * screenHeight, ' '); std::vector<int> c(screenWidth * screenHeight, 33);std
                           ::vector<float>zBuffer(screenWidth*screenHeight,0);const float pi=3.14159265
                           ; float A = 0.0; float B = 0.0; float C = 0.0; void plotPlane(float x, float
                           y, float z, char ch){ rotatedX = y*(sin(A)*sin(B)*cos(C)+cos(A)*sin(C))+ z *
                           (sin(A)*sin(C)-cos(A)*sin(B)*cos(C))+x*cos(B)*cos(C); rotatedY = y*(cos(A) *
                           cos(C)-sin(A)*sin(B)*sin(C))+z*(cos(A)*sin(B)*sin(C)+sin(A)*cos(C))-x*cos(B)
                           *sin(C); rotatedZ = -y*sin(A)*cos(B)+z*cos(A)*cos(B)+x*sin(B) + K2; ooz= 1 /
                           rotatedZ; int xP = int (screenWidth / 2 + K1 * ooz * rotatedX * 2); int yP =
                           int(screenHeight / 2 - K1 * ooz * rotatedY); int position =xP+yP*screenWidth
                           ; float tmpColor = 33; if (LUMINOSITY){ x = 0; y = 0; z = 0; if(ch == '@'){z
                           = 1;} else if(ch == '#'){z = -1;} else if(ch == '$'){y = -1;} else if (ch ==
                           'o'){y = 1;} else if(ch == '*'){x = -1;}else if(ch == '&'){x = 1;}float lumY
                           =y*(cos(A)*cos(C)-sin(A)*sin(B)*sin(C))+z*(cos(A)*sin(B)*sin(C)+sin(A)*cos(C
                           ))-x*cos(B)*sin(C);float lumZ= -y * sin(A) *cos(B)+z*cos(A)*cos(B)+x*sin(B);
                           float lum = -1*(lumY-lumZ); if (lum<0){ lum = 0; } int luminance_index = lum
                           * 8;ch = ".,-~:;=!*#$@"[luminance_index >0?luminance_index:0];}if(position>=
                           0 && position < screenWidth *screenHeight){if(ooz>zBuffer[position]){zBuffer
                           [position] = ooz; b[position] = ch; c[position] = tmpColor; } } } int main()
                           { std::cout << "\x1b[2J"; while(true){std::fill(b.begin(),b.end(),' ');std::
                           fill(zBuffer.begin(), zBuffer.end(), 0); std::fill(c.begin(),c.end(),33);for
                           (float i = -cubeWidth; i < cubeWidth; i +=resolution){for(float j=-cubeWidth
                           ; j < cubeWidth; j += resolution) { plotPlane(i, j,-cubeWidth,'@');plotPlane
                           (i, j, cubeWidth, '#');plotPlane(i,cubeWidth,j,'$'); plotPlane(i, -cubeWidth
                           , j, 'o'); plotPlane(cubeWidth, i, j, '*'); plotPlane(-cubeWidth, i, j,'&');
                           } } std::cout << "\x1b[H"; for (int k = 0; k<screenWidth * screenHeight;++k)
                           { std::cout.put(k % screenWidth ? b[k] : '\n'); } A += 0.1; B += 0.1;C+=0.2;
                           std:: this_thread :: sleep_for(std::chrono::milliseconds(50)); } return 0; }