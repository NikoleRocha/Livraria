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

void Livro::buscarInformacoesLivro(string _tituloLivro){
    if(this->tituloLivro==_tituloLivro){
       cout<<"Preço: R$"<<precoVenda<<endl;
        cout<<"Quantidade disponível: "<<quantidadeLivro<<endl;
    }else{
         cout<<"Livro Indisponível no momento" << endl;
    }
}

void Livro::filtroCategoria(string _categoria){
    if(this->generoLivro==_categoria){
      this->exibirLivro();
    }else{
         cout<<"Categoria não encontrada" << endl;
    }
}

void Livro::filtroCodigo(int _codigo){
    if(this->codigoLivro==_codigo){
      this->exibirLivro();
    }else{
         cout<<"Livro não identificado" << endl;
    }
}

void Livro::filtroTitulo(string _titulo){
    if(this->tituloLivro==_titulo){
      this->exibirLivro();
    }else{
         cout<<"Título não encontrado" << endl;
    }
}

double Livro::getPrecoVenda()
        {
       
            return precoVenda;
        }

string Livro::getTituloLivro(){
return tituloLivro;
}