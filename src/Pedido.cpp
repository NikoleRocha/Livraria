#include "Pedido.hpp"
#include "Livro.hpp"
#include "ExcecoesPedido.hpp"
#include <bits/stdc++.h>
using namespace std;

Pedido::Pedido(std::vector<Livro> _livrosSalvos):
_livrosSalvos(_livrosSalvos){
   
}
Pedido::Pedido():
_livrosSalvos(_livrosSalvos){
   
}

void Pedido::adicionarLivro(Livro &livro){
     if (this->_livrosSalvos.empty())
    {
        this->_livrosSalvos.push_back(livro);
    }
    this->_livrosSalvos.push_back(livro);
}

float Pedido::calcularValorCompra(){
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    double valorTotalCompra;
    for (vector<Livro>::iterator it = _livrosSalvos.begin();
it != _livrosSalvos.end(); it++) {
valorTotalCompra += it->getPrecoVenda();

}
return valorTotalCompra;
}

void Pedido::gerarBoleto(Pedido* pedido){
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    for (vector<Livro>::iterator it = pedido->_livrosSalvos.begin();
it != pedido->_livrosSalvos.end(); it++) {
 cout<<"Título: "<<it->getTituloLivro()<<endl;
    cout<<"Preço: R$"<<it->getPrecoVenda()<<endl;
}
   
    cout<<"Valor total da compra: R$"<<pedido->calcularValorCompra()<<endl;

}

void Pedido::removerLivro(int codigo){
 for (vector<Livro>::iterator it = _livrosSalvos.begin();
it != _livrosSalvos.end(); it++) {
    cout<< it->getCodigoLivro() << endl;
if(it->getCodigoLivro() == codigo){
    _livrosSalvos.erase(it);
}else{
    cout<<"Este código não consta na sua lista de pedidos"<<endl;
} 
}
}