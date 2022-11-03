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
        double precoVenda;
        int codigoLivro;
        int quantidadeLivro;
        double precoCusto;
    public:
        Livro(string _tituloLivro, string _autorLivro, string _generoLivro, float _precoVenda, int _codigoLivro, int _quantidadeLivro, float _precoCusto);
        void exibirLivro();
        bool buscaLivroTitulo(string _tituloLivro);
    
};


#endif