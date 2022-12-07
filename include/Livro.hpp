#ifndef LIVRO_H
#define LIVRO_H
#include <string>
#include <iostream>

class Livro
{
protected:
    std::string tituloLivro;
    std::string autorLivro;
    std::string generoLivro;
    int codigoLivro;
    int quantidadeLivro;
    double precoCusto;
    double precoVenda;

public:
    Livro(std::string _tituloLivro, std::string _autorLivro, std::string _generoLivro, float _precoVenda, int _codigoLivro, int _quantidadeLivro, float _precoCusto);
    Livro();
    void exibirLivro();
    void buscarInformacoesLivro(std::string _tituloLivro);
    void filtroCategoria(std::string _categoria);
    void filtroTitulo(std::string _titulo);
    void filtroCodigo(int _codigo);
    double getPrecoVenda();
    double getPrecoCusto();
    std::string getTituloLivro();
    int getCodigoLivro();
    int getQuantidadeLivro();
    void setQuantidadeLivro(int _quantidade);
};

#endif