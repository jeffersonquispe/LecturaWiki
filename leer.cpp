#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <string>
#include <locale.h>
#include <windows.h>

using namespace std;
 
string Lower(string s){
	int len=s.length();

	for (int i = 0; i < len; ++i)
	{
		if(s[i]>='A' && s[i] <='Z'){

			s[i]=(s[i] + 32);
		}
	}
	return s;
}

int main () {

 setlocale(LC_ALL, "spanish");	
 setlocale(LC_CTYPE, "Spanish");
 ifstream ficheroEntrada;
 string frase;
 int i=0;
 vector <string> textInFile(999999);
 

 ficheroEntrada.open ("raw/spanishText_10000_15000");
 while(!ficheroEntrada.eof()){  

 	getline(ficheroEntrada, frase);
 	
 	if(frase =="</doc>"){	
 		continue;
 	}
 	if(frase =="ENDOFARTICLE."){
 		i++;	
 		continue;
 	}
 	if(frase !="ENDOFARTICLE." && frase !="</doc>"){
 		textInFile[i] =textInFile[i] + frase;
 		continue;		
 	}
 	
 }
 for (int i = 0; i < 100; ++i)
 {
 	textInFile[i]=Lower(textInFile[i]);
 	cout << "Frase leida: " << textInFile[i] << endl;	
 }

 ficheroEntrada.close();
 return 0;
}