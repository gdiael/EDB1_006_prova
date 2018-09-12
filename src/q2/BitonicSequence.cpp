#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int findBase(vector<int> v, int left, int right)
{
	int m = (left+right)/2;

	int mid = v.at(m);
	// como exite a possibilidade da entrada estar vazia no lado crescente ou decrescente
	// temos de verificar se m é o indice do primeiro ou do ultimo elemento
	// nesses dois casos o indice calculado para o elemento posterior ou anterior
	// podem estar fora do vetor
	// caso "m" seja 0 significa que não há lista de elementos decrescente e o algoritmo
	// convergiu para o primeiro elemento. Caso "m" seja "size-1" significa que o algoritmo
	// convergiu para o ultimo elemento, e não há lista de elementos do lado crescente
	// OBS: aqui também foi provida uma conversão explícita de m para o tipo unsigned int
	if((m == 0) || ((unsigned)m == v.size() -1))
	{
		// nesse caso retornaremos mid, pois trata-se do menor elemento do vetor
		// não importa se o grupo que está faltando seja o de elementos crescentes ou decrescentes
		return m;
	};

	int midPrev = v.at(m-1);
	int midNext = v.at(m+1);

	if(midPrev > mid && midNext > mid)
		return m;
	else if(midPrev > mid)
		return findBase(v, m+1, right);
	else
		return findBase(v, left, m-1);
}

int testCounter = 0;

void test(vector<int> v, int expectedIndex)
{
	std::cout << "\tINÍCIO: Teste " << ++testCounter << endl;	
	
	int r = findBase(v, 0, v.size()-1);

	std::cout << "Entrada: (abaixo, impressos índice:valor)\n\t{" << std::endl;

	int counter = 0;
	for( int i : v )
		std::cout << counter++ << ":" << i << ", ";
	std::cout << "}\n";	

	
	std::cout << "\nSaída:" << std::endl;
	if( v[r] != v[expectedIndex] )
		std::cout << "\tResultado esperado era " << expectedIndex << ", mas retornou " << r << endl;
	else
		std::cout << "\tResultado correto, índice esperado == retornado: " << r << endl;	

	std::cout << "\tFIM: Teste " << testCounter << endl << endl;	
}

int main(void)
{
	int s = 50;

	// entradas
	vector<int> v1(s), v2(s), v3(s);	
	for(int i = 0; i < s; i++)
	{
		v1[i] = i < s / 2 ? s-i : i; // decrescente + crescente
		v2[i] = i; // crescente
		v3[i] = s-i; // decrescente		
	}

	// testes
	test(v1, s/2); // v1 tem uma sequência inicial decrescente, depois outra sequência crescente
	test(v2, 0); // v2 tem uma sequência inicial decresente vazia, depois uma sequência crescente
	test(v3, s-1); // v3 tem uma sequência inicial descrescente, depois uma sequência crescente vazia

	return 0;
}
