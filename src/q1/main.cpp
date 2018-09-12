#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string char2string(char s)
{
	string ss;
	ss.assign(&s);
	return ss;
}

string aux(string s, int pos)
{
	string letra = "" + s[pos];
	cout << pos << " | " << letra << endl;
	if(pos == 0){
		return letra;
	}else{
		return letra + aux(s,pos-1);
	};
}

string revert(string s)
{
	// TO-DO Implementar esta função
	
	// Dica: Dada uma string s, para saber o seu tamanho (quantidade de caracteres), basta usar o méotod size()
	// Ex.:  size = s.size();

	// Dica: Para concatenar duas strings, basta usar o operador '+'
	// Ex.: 
	// umaString = "a"
	// outraString = "b";
	// str = umaString + "X" + outraString;
	int size = s.size();
	if(size == 0){
		return s;
	};
	return aux(s,size-1);
}

int main(void)
{
	assert( "" == revert("") );
	assert( "A" == revert("A") );
	assert( "AB" == revert("BA") );
	assert( "ABCDEfgh" == revert("hgfEDCBA") );
	assert( "EDB" == revert("BDE") );
	assert( "ARARA" == revert("ARARA") );
	assert( revert(revert("lkjhg")) == "lkjhg");
	std::cout << "All tests passed!" << std::endl;
	return 0;
}
