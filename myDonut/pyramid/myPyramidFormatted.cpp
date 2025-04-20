#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

                                                                                  int
                                                                                width =
                                                                              120;int hei
                                                                            = 80; float K2= 
                                                                          100; float K1 = 50;
                                                                        float cubeWidth  = 25 ;
                                                                      float resolution = 0.2;bool
                                                                    LUMINOSITY=false;float rotatedX
                                                                  , rotatedY,rotatedZ,ooz;int xP, yP;
                                                                std::vector<char> b ( width * hei, ' ')
                                                              ; std::vector<int> c(width* hei, 33); std::
                                                            vector<float> zBuffer ( width * hei, 0 ); const 
                                                          float pi = 3.14159265; float A = 0.0; float B = 0.0
                                                        ; float C = 0.0; void plotPlane (float x, float y,float
                                                      z, char ch ) { rotatedX = y * ( sin(A)*sin(B)*cos(C)+cos(A)
                                                    * sin(C) ) + z * ( sin(A) * sin(C) - cos(A) * sin(B) * cos(C))+
                                                  x * cos(B) * cos(C); rotatedY = y * ( cos(A) *cos(C) -sin(A)*sin(B)
                                                * sin(C) ) + z * ( cos(A) * sin(B) * sin(C) + sin(A) * cos(C))-x*cos(B)
                                              * sin(C); rotatedZ = -y * sin(A) * cos(B) + z * cos(A) * cos(B) + x *sin(B)
                                            + K2; ooz = 1 / rotatedZ; int xP = int ( width / 2 + K1 * ooz * rotatedX * 2 );
                                          int yP = int ( hei / 2 - K1 * ooz * rotatedY ); int position = xP + yP *width;float
                                        tmpColor = 33; if ( LUMINOSITY ){ x = 0; y = 0; z = 0; if( ch == '@' ) { z = 1 /1.6259;
                                      y = (-1/0.78) / 1.6259; } else if( ch == '#' ) { z = -1/1.6259; y = (-1/0.78)/1.6259;} else
                                    if( ch == '*' ) { x = -1; } else if( ch == '&' ) { x = 1; } else if( ch == 'o' ){ y = 1; }float
                                  lumY = y * ( cos(A) * cos(C) - sin(A) * sin(B) * sin(C) ) + z * ( cos(A) * sin(B) * sin(C) + sin(A)
                                * cos(C) ) - x * cos(B) * sin(C) ; float lumZ =  -y * sin(A) * cos(B) + z * cos(A) * cos(B) + x *sin(B)
                              ; float lum = ( -lumY -lumZ ); if ( lum < 0 ){ lum = 0; } int luminance_index = lum * 8; ch= ".,-~:;=!*#$@"
                            [ luminance_index > 0 ? luminance_index : 0 ]; } if ( position >= 0 && position < width * hei){if(ooz > zBuffer
                          [position] ) { zBuffer [position] = ooz; b [position] = ch; c [position] = tmpColor; } } } int main() { std::cout<< 
                        "\x1b[2J"; while( true){ std::fill ( b.begin( ), b.end( ), ' '); std::fill ( zBuffer.begin(),zBuffer.end(),0);std::fill
                      ( c.begin( ), c.end( ), 33); for ( float i = -cubeWidth; i <cubeWidth; i += resolution) {for(float j=-cubeWidth;j<cubeWidth
                    ; j += resolution) { if ( j >= 0 && j >= abs( i ) ) { plotPlane( i, ( ( -1 / 0.78 ) * j ) + 0, j, '@'); } else if( j < 0 && j<=
                  -abs( i ) ) { plotPlane( i, ( ( 1 / 0.78 ) * j ) + 0, j, '#'); } if( i >= 0 && i >= abs( j ) ) { plotPlane( i, ( ( -1 / 0.78 ) * i)
                + 0, j, '&'); } else if( i < 0 && i <= -abs( j ) ) { plotPlane( i, ( ( 1 / 0.78 ) * i ) + 0, j, '*'); } } } std::cout<<"\x1b[H";for(int
              k = 0; k < width*hei;++k){std::cout.put(k%width ? b[k] : '\n' ); } B += 0.1; std::this_thread::sleep_for( std::chrono::milliseconds(50));}}

