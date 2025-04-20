#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

                                     int screenWidth=100; int
                                screenHeight=80;float theta_spacin
                             =0.01;float phi_spacing = 0.01; float R1
                          = 1; float R2 = 2; float K2 = 5; float K1 =50;
                        const float pi = 3.14159265; float A = pi/2; float
                      B = 0.0; int main() { std::cout<<"\x1b[2J";while(true)
                    { std::vector<char> b(screenWidth *screenHeight,' ');std::
                   vector<int>c(screenWidth*screenHeight,33);std::vector<float>
                 zBuffer (screenWidth * screenHeight, 0);float cosA=cos(A);float
                cosB = cos(B); float sinA = sin(A); float sinB = sin(B); for(float
                theta=0;theta<2*pi;theta+= theta_spacin){float cosTheta=cos(theta);
               float sinTheta = sin(theta); float a1 = R1*sinTheta*cosA; float a2 =
              R2+R1*cosTheta; float a3 = R1*sinA*sinTheta; for(float phi=0; phi < 2*
              pi; phi += phi_spacing) { float        cosPhi = cos(phi); float sinPhi
             = sin(phi); float x = (a2)*(               cosB*cosPhi+sinA*sinB*sinPhi)
             -a1*sinB; float y = (a2)* (                  sinB*cosPhi-sinA*cosB*sinPhi)
             +a1*cosB; float z=K2+cosA*                    (a2)*sinPhi+a3; float ooz=
             1/z;int xP=int(screenWidth                    / 2 + K1 * ooz * x);int yP
             = int(screenHeight / 2 -                      K1 * ooz *y*0.5);float lum 
             = (cosPhi*cosTheta *sinB-                     cosA*cosTheta*sinPhi-sinA*
             sinTheta  +  cosB * (cosA*                   sinTheta- cosTheta * sinA *
             sinPhi)); if (lum<0){lum =                 0; } int position = xP + yP * 
              screenWidth; if ( position >= 0        &&  position  <  screenWidth  *
              screenHeight) { if (ooz > zBuffer[position]) { zBuffer[position] = ooz
              ;int luminance_index=lum*8;b[position] =".,-~:;=!*#$@"[luminance_index 
               > 0 ? luminance_index : 0]; if (theta > pi+0.2*cos(phi*5) && theta < 
               2*pi-0.2*cos(phi*5)){ c[position] = 95; } } }}}std::cout<<"\x1b[H";
                for (int k = 0; k  <  screenWidth  *  screenHeight; ++k )  { std::
                cout.put ( k % screenWidth ? b[k] : '\n') ; } A += 0.1 ; B += 0.1;
                  std::this_thread::sleep_for(std::chrono::milliseconds(50));} }
                   /*Shit I think I left too much space for the donut.I made it
                    too freaking big. Well it is what it is.I'm definitely not   
                      gonna start again, this took AGES.Alright I guess that    
                        's it. Now I'm just gonna write some random char-
                          acters to make it look like nothing happened..
                             ~::===!!!!!!****************!!!!!!===::-
                                ***---- Made by GREEN CODE ---***
                                     ==!!!************!!!==*/                                                               
