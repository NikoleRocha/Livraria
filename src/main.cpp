#include <iostream>

#include "Endereco.hpp"

using namespace std;

int main()
{
    Endereco A = Endereco("deu","bug", "no", "sistema", "nobre");
    A.imprimir_endereco();
    return 0;
}
