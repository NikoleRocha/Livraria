#ifndef CATALOGO_H
#define CATALOGO_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Livro.hpp"

class Catalogo : public Livro{
    std::vector<Livro> livrosEstoque;
    public:
    void imprimirLivrosEstoque();
    void filtroCategoria(string categoriaBuscada);
    void filtroTitulo(string tituloBuscado);
    void filtroCodigo(int codigoBuscado);

};

#endif
