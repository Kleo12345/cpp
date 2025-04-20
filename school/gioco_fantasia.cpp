#include <iostream>
#include <cstdlib>

using namespace std;
class Die{
    int superior_side;
    public:
    Die(int side=0){
        superior_side = side;
    }
        Die(Die &cop){
        superior_side = cop.superior_side;
            if (superior_side==6){
                cop.superior_side = 1;
            }else{
                cop.superior_side +=1;
            }
    }
    int roll(){
        superior_side = 1+(rand() % 6);
        return superior_side;
    }
};
class weapon{
    char tipo;
    int danno;
    public:
    weapon(){
        danno = 5+(rand()%5);
    }
    int getdanno(){
        return danno;
    }
    void gettipo(char w){
        tipo=w;
    }
};

class persona{
    int vita;
    int forza;
    weapon hunger;
    public:
    persona(){
        vita = 51+(rand()%50);
        forza = 0; 
    }
    int gethunger(){
        return hunger.getdanno();
    }
    void getweapon(char z){
        hunger.gettipo(z);
    }
    void assegnavita(int v){
        vita=v;
    }
    int getvita(){
        return vita;
    }
    int getforza(Die f){
        forza=f.roll();
        forza += f.roll();
        return forza;
    }
    void fight(persona kleanth,persona bidox){
        kleanth.getweapon('s');
        Die kl;
        bidox.getweapon('l');
        kleanth.getforza(kl);
        int somma1=forza+hunger.getdanno();
        int somma2=bidox.getforza(kl)+bidox.gethunger();
        if(somma1>somma2){
            if(somma1-somma2<kleanth.gethunger()){            
            bidox.assegnavita(bidox.getvita()-(somma1-somma2));
            }else{bidox.assegnavita(bidox.getvita()-kleanth.gethunger());}
        }else if (somma1<somma2){
            if(somma2-somma1<kleanth.gethunger()){            
            kleanth.assegnavita(kleanth.getvita()-(somma2-somma1));
            }else{
                kleanth.assegnavita(kleanth.getvita()-bidox.gethunger());
            }           
        }
    }
};
int main(){
    srand(time(0));  
    persona kleanth;
    persona bidox;
    persona mario;
    kleanth.fight(kleanth,mario);
    bidox.fight(kleanth,bidox);
    mario.fight(bidox,mario);
    if(mario.getvita()<bidox.getvita()){
        if(bidox.getvita()>kleanth.getvita()){
            cout <<"Bidox is the boss " << bidox.getvita()<< endl;
            if(kleanth.getvita()>mario.getvita()){
                cout <<"Kleanth is the Lord " << kleanth.getvita() << endl;
                cout << "Mario is a feudal " <<mario.getvita()<< endl;
            }
            else{
                cout <<"Mario is the Lord " << mario.getvita()<< endl;
                cout << "Kleanth is a feudal " << kleanth.getvita()<< endl;
            }
        }
    }
    if(mario.getvita()>bidox.getvita()){
        if(mario.getvita()>kleanth.getvita()){
            cout <<"Mario is the boss " << mario.getvita()<< endl;
            if(kleanth.getvita()>bidox.getvita()){
                cout <<"Kleanth is the Lord " << kleanth.getvita()<< endl;
                cout << "Bidox is a feudal " << bidox.getvita()<< endl;
            }
            else{
                cout <<"Bidox is the Lord " << bidox.getvita()<< endl;
                cout << "Kleanth is a feudal " << kleanth.getvita()<< endl;
            }
        }
    }
    if(mario.getvita()<kleanth.getvita()){
        if(bidox.getvita()<kleanth.getvita()){
            cout <<"Kleanth is the boss "<< kleanth.getvita() << endl;
            if(bidox.getvita()>mario.getvita()){
                cout <<"Bidox is the Lord " << bidox.getvita()<< endl;
                cout << "Mario is a feudal " << mario.getvita()<< endl;
            }
            else{
                cout <<"Mario is the Lord " << mario.getvita()<< endl;
                cout << "Bidox is a feudal " << bidox.getvita()<<endl;
            }
        }
    }
}
