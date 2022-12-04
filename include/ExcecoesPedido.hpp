#ifndef EXCECOES_PEDIDO_H
#define EXCECOES_PEDIDO_H

#include <exception>

class ExcecoesPedido : public std::exception
{
  public:
    virtual const char *what() const throw() = 0;
};

class NenhumLivroAdicionado : public ExcecoesPedido
{
  public:
    virtual const char *what() const throw()
    {
      return "Nao foi adicionado nenhum livro na sua lista de pedidos.";
    }
};

#endif