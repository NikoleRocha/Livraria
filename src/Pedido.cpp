#include "Pedido.hpp"
#include <bits/stdc++.h>
using namespace std;

void Pedido::removerLivro(string tituloLivro){
    int auxIndex = 0;
 for (vector<Livro>::iterator it = _livrosSalvos.begin();
it != _livrosSalvos.end(); it++) {
if(it->getTituloLivro() == tituloLivro){
    auxIndex = getIndex(_livrosSalvos, *it);
}
}
if(auxIndex!=-1){
_livrosSalvos.erase(_livrosSalvos.begin()+ auxIndex);
}else{
    cout<<"O livro não consta na sua lista de pedidos"<<endl;
} 

}

void Pedido::adicionarLivro(Livro &livro){
     if (this->_livrosSalvos.empty())
    {
        this->_livrosSalvos.push_back(livro);
        return;
    }
    this->_livrosSalvos.push_back(livro);
}

float Pedido::calcularValorCompra(){
    for (vector<Livro>::iterator it = _livrosSalvos.begin();
it != _livrosSalvos.end(); it++) {
_valorTotalCompra += it->getPrecoVenda();
}
}

void Pedido::gerarBoleto(Pedido* pedido){
    for (vector<Livro>::iterator it = pedido->_livrosSalvos.begin();
it != pedido->_livrosSalvos.end(); it++) {
 cout<<"Título: "<<it->getTituloLivro()<<endl;
    cout<<"Preço: R$"<<it->getPrecoVenda()<<endl;
}
   
    cout<<"Valor total da compra: R$"<<_valorTotalCompra<<endl;

}

int Pedido::getIndex(vector<Livro> livros, Livro livroBuscado){
    auto it = find(livros.begin(), livros.end(), livroBuscado);
  
    // If element was found
    if (it != livros.end()) 
    {
      
        // calculating the index
        // of K
        int index = it - livros.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}