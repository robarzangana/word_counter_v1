#include "metod.h"

string cout_word(string document){
    string text, c_word, doc;
    doc = "ord.txt";
    ifstream file(document);
    ofstream output;
    output.open(doc);
    
    //Deklarera map och iterator
    map<string, int> word_count;
    map<string, int>::iterator it;
	
    //Lagra ord i word_count och sorterar bort oönskade tecken
    while(file.peek() != EOF){
        file >> text;
        for(int i=0; i !=text.length(); i++){
            switch(text.at(i)){
                case '|' : case '`' : case ':' : case '*' : case ';' : case 39 : case '?' : case '.' : 
                case  ',' : case ')' : case '(' : case '"' : case '-' : case '!' : case '=' : case '1' :
                 case '2' : case '3' : case '4' : case '5' : case '6' : case '7' : case '8' : case '9' :
		 case '0' : case ' ' :
                    c_word += "";
                     break;
                default:
                    c_word += tolower(text.at(i));
                    break;
            }
        }
        //Kontrollerar om strängen är tom, lägg inte till då till word_count
	    if(c_word == "")
		    c_word = "";
	    else{
        	++word_count[c_word];
        	c_word = "";
	    }
    }
    //Sortera efter fallande ordning
    vector<pair<string,int>> vec(word_count.begin(), word_count.end());

    sort(vec.begin(), vec.end(), [](auto a, auto b) {
        return a.second > b.second;
    });

    //Skriver ut vec till output källa.
    for(auto a : vec)
        output << a.second << " " << a.first << endl;
    cout << "Done!" << endl;
    return doc;
}
