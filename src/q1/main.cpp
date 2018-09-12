#include <cassert>
#include <iostream>
#include <string>

using namespace std;

string revertRec(string s, int pos)
{
	// criamos uma nova string, com o "char" exitente na posição "pos"
	string letra(1, s[pos]);
	// quando pos chegar no valor 0, estamos no primeiro caractere
	// então retorne ele
	if(pos == 0){
		return letra;
	}else{
		// caso contrário, retorne a concatenação do caractere em "pos"
		// com o caractere em "pos -1"
		return letra + revertRec(s, pos -1);
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

	// inicio da resposta
	// o salvamos o tamanho da string para que ela seja percorrida
	int size = s.size();
	// se a string tiver menos de dois caracteres, não há reversa, então retorne a string
	if(size < 2){
		return s;
	};
	// para calcular a string reversa percorremos os indices em ordem decrescente
	// iniciando no indice "size-1" o ultimo
	return revertRec(s,size-1);
}

int main(void)
{
	// a função main foi fornecida pelo professor, para as verificações
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
