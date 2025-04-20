#include <iostream>

using namespace std;

class Television{
    private:
    bool onOrOff ;
    int volume ;
    int channel ;
    bool silence ;

    public:
    Television(){
        onOrOff = false;
        volume = 0;
        channel = 1;
        silence = false;
    }
    bool turnOnOff(bool onOrOff) {
        return onOrOff;
    }
    int channelNext(int channel){
        return channel;
    }
    int channelPrev(int channel){
        return channel;
    }
    int turnUpVolume(int volume){
        return volume;
    }
    int turnDownVolume(int volume){
        return volume;
    }
    int SetChannel(int channel, int c){
        return c;
    }
    void printStatus(int channel, int volume, bool silence){
        cout << "Channel: " << channel << endl;
        cout << "Volume: " << volume << endl;
        cout << "Silence: " << silence << endl;
    }
}

int main() {
    Television tv;
    tv.turnOnOff(true);
    tv.printStatus(tv.SetChannel(10, tv.channelNext(10)), tv.turnUpVolume(5), tv.silence);
    tv.turnOnOff(false);
    return 0;
}
