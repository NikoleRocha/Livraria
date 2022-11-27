#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Livro.hpp"

class Pedido : public Livro{
    std::vector<Livro> _livrosSalvos;
    float _valorTotalCompra;
    public:
        void removerLivro(string tituloLivro);
        void adicionarLivro(Livro &livro);
        float calcularValorCompra();
        void gerarBoleto(Pedido* pedido);
        int getIndex(vector<Livro> livros, Livro livroBuscado);

};

#endif
