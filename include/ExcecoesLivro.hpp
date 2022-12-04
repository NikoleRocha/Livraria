#ifndef EXCECOES_LIVRO_H
#define EXCECOES_LIVRO_H

#include <exception>

class ExcecoesLivro : public std::exception
{
  public:
    virtual const char *what() const throw() = 0;
};

class TituloInvalido : public ExcecoesLivro
{
public:
  virtual const char *what() const throw()
  {
    return "O título nao pode ficar em branco.";
  }
};

class AutorInvalido : public ExcecoesLivro
{
public:
  virtual const char *what() const throw()
  {
    return "O nome do autor do livro nao pode ficar em branco.";
  }
};

class GeneroInvalido : public ExcecoesLivro
{
public:
  virtual const char *what() const throw()
  {
    return "O gênero nao pode ficar em branco.";
  }
};

class CodigoInvalido : public ExcecoesLivro
{
public:
  virtual const char *what() const throw()
  {
    return "Código Inválido.";
  }
};

class QuantidadeInvalida : public ExcecoesLivro
{
public:
  virtual const char *what() const throw()
  {
    return "Quantidade inválida de livros";
  }
};

class CustoInvalido : public ExcecoesLivro
{
public:
  virtual const char *what() const throw()
  {
    return "Valor de custo inválido";
  }
};

class PrecoInvalido : public ExcecoesLivro
{
public:
  virtual const char *what() const throw()
  {
    return "Valor de venda inválido";
  }
};

#endif