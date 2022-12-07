#include "Pedido.hpp"
#include "Livro.hpp"
#include "ExcecoesPedido.hpp"
#include <bits/stdc++.h>

/**
 * @brief Adiciona livro na lista de pedido do usuário
 *
 * @param livro Livro do catalogo a ser adicionado
 */

void Pedido::adicionarLivro(Livro &livro)
{
    this->_livrosSalvos.push_back(livro);
}

/**
 * @brief Calcula o valor total da compra, sendo a soma do preço de venda todos os livros adicionados ao pedido, caso não tenha
 * nenhum livro adicionado ao pedido lança exceção
 * 
 * @return float Retorna o valor total da compra
 */

float Pedido::calcularValorCompra()
{
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    double valorTotalCompra;
    for (std::vector<Livro>::iterator it = _livrosSalvos.begin();
         it != _livrosSalvos.end(); it++)
    {
        valorTotalCompra += it->getPrecoVenda();
    }
    return valorTotalCompra;
}

/**
 * @brief Calcula o valor de lucro que o administrador terá sobre a venda, e lança execeção caso nenhum livro tenha sido 
 * adicionado ao pedido
 * 
 * @return float Retorna o valor de lucro da compra
 */

float Pedido::calcularLucroCompra()
{
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    double lucroCompra;
    double precoCompra;
    for (std::vector<Livro>::iterator it = _livrosSalvos.begin();
         it != _livrosSalvos.end(); it++)
    {
        precoCompra += it->getPrecoCusto();
    }
    lucroCompra = this->calcularValorCompra() - precoCompra;
    return lucroCompra;
}

/**
 * @brief Exibe todas as informações acerca do pedido a ser finalizado e lança exceção caso não haja nenhum livro adicionado
 * no pedido
 *
 * @param pedido Pedido do cliente que vai ser finalizado
 */

void Pedido::gerarBoleto(Pedido *pedido)
{
    if (this->_livrosSalvos.empty())
    {
        throw NenhumLivroAdicionado();
    }
    for (std::vector<Livro>::iterator it = pedido->_livrosSalvos.begin();
         it != pedido->_livrosSalvos.end(); it++)
    {
        std::cout << "Título: " << it->getTituloLivro() << std::endl;
        std::cout << "Preço: R$" << it->getPrecoVenda() << std::endl;
    }

    std::cout << "Valor total da compra: R$" << pedido->calcularValorCompra() << std::endl;
}

/**
 * @brief Permite que o cliente remova do seu pedido um livro através do seu código
 *
 * @param codigo Código do livro a ser removido
 */

void Pedido::removerLivro(int codigo)
{
    for (std::vector<Livro>::iterator it = _livrosSalvos.begin();
         it != _livrosSalvos.end(); it++)
    {
        if (it->getCodigoLivro() == codigo)
        {
            this->_livrosSalvos.erase(it);
            break;
        }
        else
        {
            std::cout << "Este código não consta na sua lista de pedidos" << std::endl;
        }
    }
}
