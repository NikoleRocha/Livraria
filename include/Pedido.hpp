#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Livro.hpp"

class Pedido : public Livro
{
public:
    std::vector<Livro> _livrosSalvos;
    void removerLivro(int codigo);
    void adicionarLivro(Livro &livro);
    float calcularValorCompra();
    float calcularLucroCompra();
    void gerarBoleto(Pedido *pedido);
};

#endif
