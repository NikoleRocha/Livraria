#include "Livro.hpp"
#include "ExcecoesLivro.hpp"

Livro::Livro(string _tituloLivro, string _autorLivro, string _generoLivro, float _precoVenda, int _codigoLivro, int _quantidadeLivro, float _precoCusto)
{
    this->tituloLivro = _tituloLivro;
    this->autorLivro = _autorLivro;
    this->generoLivro = _generoLivro;
    this->precoVenda = _precoVenda;
    this->codigoLivro = _codigoLivro;
    this->quantidadeLivro = _quantidadeLivro;
    this->precoCusto = _precoCusto;

    if (this->tituloLivro.empty())
    {
        throw TituloInvalido();
    }
    else if (this->codigoLivro < 0)
    {
        throw CodigoInvalido();
    }
    else if (this->autorLivro.empty())
    {
        throw AutorInvalido();
    }
    else if (this->generoLivro.empty())
    {
        throw GeneroInvalido();
    }
    else if (this->precoVenda < 0)
    {
        throw CustoInvalido();
    }
    else if (this->precoCusto < 0)
    {
        throw PrecoInvalido();
    }
    else if (this->quantidadeLivro < 0)
    {
        throw QuantidadeInvalida();
    }
}

Livro::Livro()
{
    this->tituloLivro = "Indefinido";
    this->autorLivro = "Indefinido";
    this->generoLivro = "Indefinido";
    this->precoVenda = 0;
    this->codigoLivro = 0;
    this->quantidadeLivro = 0;
    this->precoCusto = 0;
}

void Livro::exibirLivro()
{
    cout << "Título: " << tituloLivro << endl;
    cout << "Autor: " << autorLivro << endl;
    cout << "Gênero: " << generoLivro << endl;
    cout << "Preço: R$" << precoVenda << endl;
    cout << "Código: " << codigoLivro << endl;
    cout << "Quantidade disponível: " << quantidadeLivro << endl;
}

void Livro::buscarInformacoesLivro(string _tituloLivro)
{
    if (this->tituloLivro == _tituloLivro)
    {
        cout << "Preço: R$" << precoVenda << endl;
        cout << "Quantidade disponível: " << quantidadeLivro << endl;
    }
    else
    {
        cout << "Livro Indisponível no momento" << endl;
    }
}

void Livro::filtroCategoria(string _categoria)
{
    if (this->generoLivro == _categoria)
        this->exibirLivro();
}

void Livro::filtroCodigo(int _codigo)
{
    if (this->codigoLivro == _codigo)
        this->exibirLivro();
}

void Livro::filtroTitulo(string _titulo)
{
    if (this->tituloLivro == _titulo)
        this->exibirLivro();
}

double Livro::getPrecoVenda()
{

    return precoVenda;
}

string Livro::getTituloLivro()
{
    return this->tituloLivro;
}

int Livro::getCodigoLivro()
{
    return this->codigoLivro;
}
int Livro::getQuantidadeLivro()
{
    return this->quantidadeLivro;
}
void Livro::setQuantidadeLivro(int _quantidade)
{
    this->quantidadeLivro = _quantidade;
}
double Livro::getPrecoCusto()
{
    return this->precoCusto;
}