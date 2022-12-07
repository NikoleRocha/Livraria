#include "Catalogo.hpp"

/**
 * @brief Printa os livros que constam no catálogo
 *
 */

void Catalogo::imprimirLivrosEstoque()
{
    for (std::vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->exibirLivro();
    }
}

/**
 * @brief Filtra e exibe os livros conforme a categoria buscada
 *
 * @param  categoriaBuscada Categoria de livro que se busca
 */

void Catalogo::filtroCategoria(std::string categoriaBuscada)
{
    for (std::vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->filtroCategoria(categoriaBuscada);
    }
}

/**
 * @brief Filtra e exibe os livros conforme o titulo buscado
 *
 * @param  tituloBuscado Titulo do livro que se busca
 */

void Catalogo::filtroTitulo(std::string tituloBuscado)
{
    for (std::vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->filtroTitulo(tituloBuscado);
    }
}

/**
 * @brief Filtra e exibe o livro conforme o código buscado
 *
 * @param  codigoBuscado Código do livro que se busca 
 */

void Catalogo::filtroCodigo(int codigoBuscado)
{
    for (std::vector<Livro>::iterator it = livrosEstoque.begin();
         it != livrosEstoque.end(); it++)
    {
        it->filtroCodigo(codigoBuscado);
    }
}