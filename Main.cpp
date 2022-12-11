#include <iostream>
#include <string>
#include <fstream>
#include "Tabela.h"
#include "Cifrador.h"
#include "Solver.h"

int main(int argc, char *argv[]) {

  std::string mensagem;
  std::string chave;
  std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";

  std::string criptografia = "", auxiliar;

  std::fstream arquivo;
  arquivo.open(argv[1], std::ios::in);

  if(!arquivo) {
    std::cout << "arquivo nao existe!" << std::endl;
  }else {
    while(getline(arquivo, auxiliar)) criptografia += auxiliar + "\n";

    arquivo.close();
  }

  std::cout << "insira a mensagem a ser cifrada: ";
  std::cin >> mensagem;
  std::cout << "insira a chave: ";
  std::cin >> chave;
  std::cout << mensagem.size();
  // depois perguntar se ele quer dar o proprio alfabeto

  Tabela tab(alfabeto);

  std::string cript = tab.coder(mensagem, chave);
  std::string volta = tab.decoder(cript, chave);

  std::cout << "A sua mensagem criptografada eh " << std::endl;
  std::cout << cript << std::endl;
  std::cout << "A sua mensagem descriptografada eh " << std::endl;
  std::cout << volta << std::endl;

  Solver s(alfabeto);
  s.solve(cript);
  
}
