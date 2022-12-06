#include "Pedido.hpp"
#include "Livro.hpp"
#include "ExcecoesPedido.hpp"
#include <bits/stdc++.h>
using namespace std;

void Pedido::adicionarLivro(Livro &livro)
{
    this->_livrosSalvos.push_back(livro);
}

float Pedido::calcularValorCompra()
{
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    double valorTotalCompra;
    for (vector<Livro>::iterator it = _livrosSalvos.begin();
         it != _livrosSalvos.end(); it++)
    {
        valorTotalCompra += it->getPrecoVenda();
    }
    return valorTotalCompra;
}
float Pedido::calcularLucroCompra()
{
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    double lucroCompra;
    double precoCompra;
    for (vector<Livro>::iterator it = _livrosSalvos.begin();
         it != _livrosSalvos.end(); it++)
    {
        precoCompra += it->getPrecoCusto();
    }
    lucroCompra = this->calcularValorCompra() - precoCompra;
    return lucroCompra;
}

void Pedido::gerarBoleto(Pedido *pedido)
{
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    for (vector<Livro>::iterator it = pedido->_livrosSalvos.begin();
         it != pedido->_livrosSalvos.end(); it++)
    {
        cout << "Título: " << it->getTituloLivro() << endl;
        cout << "Preço: R$" << it->getPrecoVenda() << endl;
    }

    cout << "Valor total da compra: R$" << pedido->calcularValorCompra() << endl;
}

void Pedido::removerLivro(int codigo)
{
    for (vector<Livro>::iterator it = _livrosSalvos.begin();
         it != _livrosSalvos.end(); it++)
    {
        if (it->getCodigoLivro() == codigo)
        {
            this->_livrosSalvos.erase(it);
            break;
        }
        else
        {
            cout << "Este código não consta na sua lista de pedidos" << endl;
        }
    }
}
