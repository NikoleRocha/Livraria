CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=program

BUILD_DIR    = ./build
SRC_DIR    = ./src
INCLUDE_DIR  = ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Administrador.o ${BUILD_DIR}/Catalogo.o ${BUILD_DIR}/CLiente.o ${BUILD_DIR}/Endereco.o ${BUILD_DIR}/Livro.o ${BUILD_DIR}/Pedido.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Administrador.o: ${INCLUDE_DIR}/Administrador.hpp ${SRC_DIR}/Administrador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Administrador.cpp -o ${BUILD_DIR}/Administrador.o

${BUILD_DIR}/Catalogo.o: ${INCLUDE_DIR}/Catalogo.hpp ${SRC_DIR}/Catalogo.cpp 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Catalogo.cpp -o ${BUILD_DIR}/Catalogo.o

${BUILD_DIR}/Cliente.o: ${INCLUDE_DIR}/Cliente.hpp ${SRC_DIR}/Cliente.cpp 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/Endereco.o: ${INCLUDE_DIR}/Endereco.hpp ${SRC_DIR}/Endereco.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Endereco.cpp -o ${BUILD_DIR}/Endereco.o

${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/Usuario.hpp ${SRC_DIR}/Usuario.cpp 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Usuario.cpp -o ${BUILD_DIR}/Usuario.o

${BUILD_DIR}/Livro.o: ${INCLUDE_DIR}/Livro.hpp ${SRC_DIR}/Livro.cpp ${INCLUDE_DIR}/ExcecoesLivro.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Livro.cpp -o ${BUILD_DIR}/Livro.o

${BUILD_DIR}/Pedido.o: ${INCLUDE_DIR}/Pedido.hpp ${SRC_DIR}/Pedido.cpp ${INCLUDE_DIR}/ExcecoesPedido.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Pedido.cpp -o ${BUILD_DIR}/Pedido.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Administrador.hpp ${INCLUDE_DIR}/Catalogo.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/Endereco.hpp ${INCLUDE_DIR}/Usuario.hpp ${INCLUDE_DIR}/Livro.hpp ${INCLUDE_DIR}/Pedido.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/* 