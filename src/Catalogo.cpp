#include "Catalogo.hpp"

void Catalogo::imprimirLivrosEstoque()
{
    for (vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->exibirLivro();
    }
}

void Catalogo::filtroCategoria(string categoriaBuscada)
{
    for (vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->filtroCategoria(categoriaBuscada);
    }
}

void Catalogo::filtroTitulo(string tituloBuscado)
{
    for (vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->filtroTitulo(tituloBuscado);
    }
}

void Catalogo::filtroCodigo(int codigoBuscado)
{
    for (vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->filtroCodigo(codigoBuscado);
    }
}