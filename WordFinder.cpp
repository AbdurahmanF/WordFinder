#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "proizvodi.csv";
    ifstream input;

    input.open("proizvodi.csv");

    if (!input.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string rijecKojuTrazimo;
    int brojac=0;
    cout << "Enter the word to search for: ";
    cin >> rijecKojuTrazimo;
    
    string trenutnaRijec;
    char ch;

    while (input.get(ch)) {
     if (isalnum(ch)) {
     	trenutnaRijec +=ch;
            
        }
        else{
        	if(trenutnaRijec==rijecKojuTrazimo){
        		brojac++;
			}
        	trenutnaRijec.clear();
		}
    }
    if(trenutnaRijec==rijecKojuTrazimo){
    	brojac++;
	}
	
	input.close();
	
	if(brojac>0){
		cout<<"Rijec '"<<rijecKojuTrazimo<<"' je nadena "<<brojac<<" puta u fajlu!"<<endl;
	}
	else{
		cout<<"Rijec '"<<rijecKojuTrazimo<<"' nije nadena  u fajlu!"<<endl;
	}

    return 0;
}
