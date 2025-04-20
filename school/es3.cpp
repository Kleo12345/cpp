#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (){
    vector<char>teams;
    vector <int> years;    
    int year = 1900;
    char team;
    int co = 0;
    char c;
    cout << "Give me the team you are searching for " << endl;
    cin >> team ;
    for (int i = 0; i <= 5 ; i++){
        cout << "Give me the team you want to add" << endl;
        cin >> c;
        teams.push_back(c);
    }
    years.push_back(1999);
    years.push_back(1932);
    years.push_back(1976);
    years.push_back(1989);
    years.push_back(2016);
    for (int i = 0; i < teams.size(); i++){
        if ( teams[i] == team){
            cout << "Your team is " << teams[i] << endl;
            cout << "Your team has won in this year :" << years[i] << endl;
            co = 1;
            break;
        }
    }
    if (co == 0){
        cout << "Your team is not in our list of teams " << endl;
    }
    return 0;
}