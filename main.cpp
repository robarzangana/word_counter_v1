/*
Namn: Robar Zangana
Datum: 11/12/18
Kurs: Introduktion till programmering i C++
Labboration: Laboration fem
*/
#include "metod.h"
//hitchhikersguide.txt
int main(){
    string doc, rader;
    int row;
    
    //Anropar count_word
    doc = cout_word("hitchhikersguide.txt");
    ifstream file(doc);

    cout << "Hur många rader vill du se?" << endl;
    cin >> row;
    
    //Skriver ut rader från doc
    for(int i = 0; i<row; i++){
    	getline(file, rader);
	    cout << rader << endl;
    }
    return 0;
}