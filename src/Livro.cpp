#include "Livro.hpp"

Livro::Livro(string _tituloLivro, string _autorLivro, string _generoLivro, float _precoVenda, int _codigoLivro, int _quantidadeLivro, float _precoCusto){
    this->tituloLivro=_tituloLivro;
    this->autorLivro=_autorLivro;
    this->generoLivro=_generoLivro;
    this->precoVenda=_precoVenda;
    this->codigoLivro=_codigoLivro;
    this->quantidadeLivro=_quantidadeLivro;
    this->precoCusto=_precoCusto;
}

void Livro::exibirLivro(){
    cout<<"Título: "<<tituloLivro<<endl;
    cout<<"Autor: "<<autorLivro<<endl;
    cout<<"Gênero: "<<generoLivro<<endl;
    cout<<"Preço: R$"<<precoVenda<<endl;
    cout<<"Código: "<<codigoLivro<<endl;
    cout<<"Quantidade disponível: "<<quantidadeLivro<<endl;
}

bool Livro::buscaLivroTitulo(string _tituloLivro){
    if(this->tituloLivro==_tituloLivro){
        return 1;
    }else{
        return 0;
    }
}