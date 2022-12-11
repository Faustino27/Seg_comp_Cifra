#include <iostream>
#include <string>
#include <fstream>
#include "Tabela.h"
#include "Cifrador.h"
#include "Solver.h"

void parse(std::string& criptografia, std::string alfabeto) {
  std::string s;
  for(auto it: criptografia)
    if(alfabeto.find(it) != std::string::npos) 
      s += it;

  criptografia = s;
}

void mask(std::string& mask, std::string alfabeto) {
  std::string s;
  for(auto it: mask) {
    if(alfabeto.find(it) != std::string::npos)
      s += 'A';
    else
      s += it;
  }

  mask = s;
}

void use_mask(std::string& cript, std::string& mask) {

  int idx = 0;
  for(int i = 0; i < mask.size(); i++) {
    if(mask[i] == 'A') mask[i] = cript[idx++];
  } 

  cript = mask;

}

void solve(std::string arq, std::string alfabeto) {

  std::string criptografia = "", auxiliar, mascara;

  std::fstream arquivo;
  arquivo.open(arq, std::ios::in);

  if(!arquivo) {
    std::cout << "arquivo nao existe!" << std::endl;
  }else {
    while(getline(arquivo, auxiliar)) criptografia += auxiliar + "\n";
    arquivo.close();

    mascara = criptografia;
  }

  parse(criptografia, alfabeto);
  mask(mascara, alfabeto);

  std::cout << "essa eh a mensagem criptografada apos retirar os caracteres fora do alfabeto" << std::endl;
  std::cout << criptografia << std::endl;
  std::cout << "essa eh a mensagem com mascara" << std::endl;
  std::cout << mascara << std::endl;

  // usar aqui o decrypt/solver
  // a mensagem codificada esta guardada na variavel criptografia

  use_mask(criptografia, mascara);

  std::cout << "essa eh a mensagem apos colocar na mascara" << std::endl;
  std::cout << criptografia << std::endl;

}

int main(int argc, char *argv[]) {

  std::string mensagem;
  std::string chave;
  std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";

  // descomente a linha debaixo para descriptar sem a chave
  // solve(argv[1], alfabeto);

  /*
  std::cout << "insira a mensagem a ser cifrada: ";
  std::cin >> mensagem;
  std::cout << "insira a chave: ";
  std::cin >> chave;
  std::cout << mensagem.size();
  // depois perguntar se ele quer dar o proprio alfabeto
  */
  Tabela tab(alfabeto);

  std::string cript = solve(argv[1], alfabeto);//tab.coder(mensagem, chave);
  /*
  std::string volta = tab.decoder(cript, chave);

  std::cout << "A sua mensagem criptografada eh " << std::endl;
  std::cout << cript << std::endl;
  std::cout << "A sua mensagem descriptografada eh " << std::endl;
  std::cout << volta << std::endl;
  */

  Solver s(alfabeto, cript);
  auto a = s.testeKeysize();
  for(auto it: a) std::cout << it << ' '; std::cout << std::endl;
//  s.solve(cript);
  
}
