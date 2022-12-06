#ifndef LIVRO_H
#define LIVRO_H
#include <string>
#include <iostream>
using namespace std;

class Livro{
    protected:
        string tituloLivro;
        string autorLivro;
        string generoLivro;
        int codigoLivro;
        int quantidadeLivro;
        double precoCusto;
        double precoVenda;
    public:
        Livro(string _tituloLivro, string _autorLivro, string _generoLivro, float _precoVenda, int _codigoLivro, int _quantidadeLivro, float _precoCusto);
        Livro();
        void exibirLivro();
        void buscarInformacoesLivro(string _tituloLivro);
        void filtroCategoria(string _categoria);
        void filtroTitulo(string _titulo);
        void filtroCodigo(int _codigo);
        double getPrecoVenda();
        double getPrecoCusto();
        string getTituloLivro();
        int getCodigoLivro();
        int getQuantidadeLivro();
        void setQuantidadeLivro(int _quantidade);
};

#endif