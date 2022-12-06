#ifndef CATALOGO_H
#define CATALOGO_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Livro.hpp"

class Catalogo : public Livro
{
public:
    std::vector<Livro> livrosEstoque;
    void imprimirLivrosEstoque();
    void filtroCategoria(string categoriaBuscada);
    void filtroTitulo(string tituloBuscado);
    void filtroCodigo(int codigoBuscado);
};

#endif