#include <iostream>

#include <iostream>
#include <vector>

#include "Livro.hpp"
#include "Pedido.hpp"


using namespace std;

int main()
{
    vector<Livro> livros;
    Livro a1("Aloha","Antoine de Saint-Exupéry","Infantil",29.99,4,4,15.00);
    Livro a2("O Pequeno Príncipe","Antoine de Saint-Exupéry","Infantil",29.99,5,5,15.00);
 
    livros.push_back(a1);
    livros.push_back(a2);
    Pedido teste(livros);
    
    teste.gerarBoleto(&teste);
    Pedido teste2;
   teste2.gerarBoleto(&teste2);
   teste.removerLivro(4);
   teste.gerarBoleto(&teste);
    Livro a("O Pequeno Príncipe","Antoine de Saint-Exupéry","Infantil",29.99,001,3,15.00);
    string nome(a.getTituloLivro());
    
    cout<< nome << endl;
    

    return 0;
}

