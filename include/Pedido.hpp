#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Livro.hpp"

class Pedido : public Livro{
    std::vector<Livro> _livrosSalvos;
    public:
        Pedido(std::vector<Livro> _livrosSalvos);
        Pedido();
        void removerLivro(int codigo);
        void adicionarLivro(Livro &livro);
        float calcularValorCompra();
        void gerarBoleto(Pedido* pedido);

};

#endif
