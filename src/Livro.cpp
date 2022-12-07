#include "Livro.hpp"
#include "ExcecoesLivro.hpp"

/**
 * @brief Construtor do objeto Livro. Lança exceções caso um valor inválido seja inserido
 *
 * @param _tituloLivro Titulo a ser atribuido ao livro
 * @param _autorLivro Autor do livro
 * @param _generoLivro Gênero/categoria do livro
 * @param _precoVenda Preço o qual vai ser vendido
 * @param _codigoLivro Código atribuído ao livro
 * @param _quantidadeLivro Quantido de livros disponíveis para venda
 * @param _precoCusto Preço de custo do livro
 */

Livro::Livro(std::string _tituloLivro, std::string _autorLivro, std::string _generoLivro, float _precoVenda, int _codigoLivro, int _quantidadeLivro, float _precoCusto)
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

/**
 * @brief Printa as informações referentes ao livro
 *
 */

void Livro::exibirLivro()
{
    std::cout << "Título: " << tituloLivro << std::endl;
    std::cout << "Autor: " << autorLivro << std::endl;
    std::cout << "Gênero: " << generoLivro << std::endl;
    std::cout << "Preço: R$" << precoVenda << std::endl;
    std::cout << "Código: " << codigoLivro << std::endl;
    std::cout << "Quantidade disponível: " << quantidadeLivro << std::endl;
}

/**
 * @brief Exibe o preço e aquantidade de um livro procurado através de seu título, caso ele exista
 *
 * @param _tituloLivro Titulo do livro o qual se busca as informações
 */

void Livro::buscarInformacoesLivro(std::string _tituloLivro)
{
    if (this->tituloLivro == _tituloLivro)
    {
        std::cout << "Preço: R$" << precoVenda << std::endl;
        std::cout << "Quantidade disponível: " << quantidadeLivro << std::endl;
    }
    else
    {
        std::cout << "Livro Indisponível no momento" << std::endl;
    }
}

/**
 * @brief Exibe as informações de livros petencentes a categoria buscada
 *
 * @param _categoria Categoria do livro 
 */

void Livro::filtroCategoria(std::string _categoria)
{
    if (this->generoLivro == _categoria)
        this->exibirLivro();
}

/**
 * @brief Exibe as informações de um livro procurado através de seu código, caso ele conste no catálogo
 *
 * @param _codigo Código do livro o qual se busca as informações
 */

void Livro::filtroCodigo(int _codigo)
{
    if (this->codigoLivro == _codigo)
        this->exibirLivro();
}

/**
 * @brief Exibe as informações de um livro procurado através de seu título, caso ele exista
 *
 * @param _tituloLivro Titulo do livro o qual se busca as informações
 */

void Livro::filtroTitulo(std::string _titulo)
{
    if (this->tituloLivro == _titulo)
        this->exibirLivro();
}

/**
 * @brief Get responsável pelo preço de venda do livro
 * 
 * @return double Retorna o preço de venda do livro
 */

double Livro::getPrecoVenda()
{

    return precoVenda;
}

/**
 * @brief Get responsável pelo titulo do livro
 * 
 * @return std::string Retorna o titulo do livro
 */

std::string Livro::getTituloLivro()
{
    return this->tituloLivro;
}

/**
 * @brief Get responsável pelo codigo do livro
 * 
 * @return int Retorna o codigo do livro
 */

int Livro::getCodigoLivro()
{
    return this->codigoLivro;
}

/**
 * @brief Get responsável pela quantidade de livros disponiveis
 * 
 * @return int Retorna a quantidade de livros disponíveis
 */

int Livro::getQuantidadeLivro()
{
    return this->quantidadeLivro;
}

/**
 * @brief Set responsável pela quantidade de livros disponiveis
 * 
 * @param _quantidade Quantidade de livros que vai ser disponibilizada
 */

void Livro::setQuantidadeLivro(int _quantidade)
{
    this->quantidadeLivro = _quantidade;
}

/**
 * @brief Get responsável pelo preço de custo do livro
 * 
 * @return double Retorna o preço de custo do livro
 */

double Livro::getPrecoCusto()
{
    return this->precoCusto;
}