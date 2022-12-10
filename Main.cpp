#include <iostream>
#include <string>
#include "Tabela.h"
#include "Cifrador.h"
#include "Solver.h"

int main() {
  std::string mensagem;
  std::string chave;
  std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";

  std::cout << "hello cifra!" << std::endl;

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
