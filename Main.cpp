#include <iostream>
#include <string>
#include <fstream>
#include "Tabela.h"
#include "Solver.h"



//remove os espacos do input e pontuacao
void parse(std::string& criptografia, std::string alfabeto) {
  std::string s;
  for(auto it: criptografia)
    if(alfabeto.find(it) != std::string::npos) 
      s += it;

  criptografia = s;
}

//Cria uma mascara para podermos juntarmos o texto com o parse e remover potuacao e caracteres especiais e os adiconarmos depois
void mask(std::string& mask, std::string alfabeto) {
  std::string s="";
  for(auto it: mask) {
    if(alfabeto.find(it) != std::string::npos)
      s += 'A';
    else
      s += it;
  }

  mask = s;
}
//usa a mascara criada anteiormente para recolocar os espaços e pontuacao
void use_mask(std::string& cript, std::string mask) {

  int idx = 0;
  for(int i = 0; i < (int)mask.size(); i++) {
    if(mask[i] == 'A') mask[i] = cript[idx++];
  } 

  cript = mask;

}

void solve(std::string arq, std::string alfabeto) {

  std::string criptografia = "", auxiliar, mascara;

  std::fstream arquivo;
  arquivo.open(arq, std::ios::in);

  if(!arquivo) {
    std::cout << "O arquivo nao existe!" << std::endl;
  }else {
    while(getline(arquivo, auxiliar)) criptografia += auxiliar + "\n";
    arquivo.close();
    criptografia = 
    mascara = criptografia;
  }

  parse(criptografia, alfabeto);
  mask(mascara, alfabeto);

  // usar aqui o decrypt/solver
  // a mensagem codificada esta guardada na variavel criptografia
  Solver solver(alfabeto, criptografia, 100, 1);
  std::vector<std::pair<std::string, std::string>> res = solver.solve();

  for(auto [key, msg] : res){
    use_mask(msg, mascara);
    std::cout << "o algoritmo encontrou essa chave " << key  << std::endl;
    std::cout <<"essa eh a mensagem apos colocar na mascara e ser quebrada sem a chave\n" << msg << "\n\n\n\n";
  }

}


void criptografa(std::string alfabeto){
  std::string arq = "";
  std::string chave = "";
  std::string auxiliar = "";
  std::string mascara = "";
  std::string criptografia = "";

  std::cout << "Digite o nome do arquivo:\n";
  std::cin >> arq;
  std::cout << "Digite a chave a ser utilizada para cifrar:\n";
  std::cin >> chave;

  std::fstream arquivo;
  arquivo.open(arq, std::ios::in);

  parse(chave, alfabeto);
  int tChave = chave.size();

  if(!arquivo) {
    std::cout << "O arquivo nao existe!\n\nFechando o programa..." << std::endl;
  }else if(tChave <=  0){
    std::cout << "Chave invalida!\n\nFechando o programa..." << std::endl;
  }else {
    while(getline(arquivo, auxiliar)) criptografia += auxiliar + "\n";
    arquivo.close();
    mascara = criptografia;
  }
  parse(criptografia, alfabeto);
  mask(mascara, alfabeto);

  Tabela tab(alfabeto);
  
  std::string mensagem = tab.coder(criptografia, chave);

  use_mask(mensagem, mascara);

  std::cout << "A mensagem cifrada eh:\n" << mensagem << "\n\n -->>Fechando programa...\n";

  return; 
}

void descriptografa(std::string alfabeto){
  std::string arq = "";
  std::string chave = "";
  std::string auxiliar = "";
  std::string mascara = "";
  std::string criptografia = "";

  std::cout << "Digite o nome do arquivo:\n";
  std::cin >> arq;
  std::cout << "Digite a chave a ser utilizada para decifrar:\n";
  std::cin >> chave;

  std::fstream arquivo;
  arquivo.open(arq, std::ios::in);

  parse(chave, alfabeto);
  int tChave = chave.size();

  if(!arquivo) {
    std::cout << "O arquivo nao existe!\n\nFechando o programa..." << std::endl;
  }else if(tChave <=  0){
    std::cout << "Chave invalida!\n\nFechando o programa..." << std::endl;
  }else {
    while(getline(arquivo, auxiliar)) criptografia += auxiliar + "\n";
    arquivo.close();
    mascara = criptografia;
  }
  parse(criptografia, alfabeto);
  mask(mascara, alfabeto);

  Tabela tab(alfabeto);
  
  std::string mensagem = tab.decoder(criptografia, chave);

  use_mask(mensagem, mascara);

  std::cout << "A mensagem decifrada eh:\n" << mensagem << "\n\n -->>Fechando programa...\n";

  return; 

}

void quebra(std::string alfabeto){
  std::string arq = "";
  std::string chaves = "";
  std::string auxiliar = "";
  std::string mascara = "";
  std::string criptografia = "";

  std::cout << "Digite o nome do arquivo:\n";
  std::cin >> arq;
  std::cout << "Até quantas chaves possiveis deseja que o programa mostre?:\n";
  std::cin >> chaves;

  std::fstream arquivo;
  arquivo.open(arq, std::ios::in);
  int tChave = 0;

  try{
    tChave = std::stoi(chaves);
  }catch(std::exception& ex){
    std::cout << "\n\n\n\nATENCAO o valor digitado para a quantidade de chaves nao eh um numero e por isso usará o padrão de 3\n\n\n\n";
    tChave = 3;
  }

  if(!arquivo) {
    std::cout << "O arquivo nao existe!\n\nFechando o programa..." << std::endl;
  }else {
    while(getline(arquivo, auxiliar)) criptografia += auxiliar + "\n";
    arquivo.close();
    mascara = criptografia;
  }
  parse(criptografia, alfabeto);
  mask(mascara, alfabeto);

  Solver solver(alfabeto, criptografia, 100, 1);
  std::vector<std::pair<std::string, std::string>> res = solver.solve(tChave);

  std::string quebraLinha = "#####################################################################";
  for(auto [key, msg] : res){
    use_mask(msg, mascara);
    std::cout << "O algoritmo encontrou a chave: " << key  << std::endl;
    std::cout <<"Essa eh a mensagem apos ser quebrada coma chave encontrada:\n\n" << msg << "\n\n"<<quebraLinha<<"\n\n";
  }
  std::cout << "Finalizando programa ...\n";
  return; 
}

int main(int argc, char *argv[]) {
  std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
  std::string opcao;
  bool flag = true;

  while(flag){
    std::cout << "Escolha uma opção:\n\n1- Cifrar uma mensagem\n2- Decifrar uma mensagem com a chave\n3- Quebrar a cifra da mensagem sem a chave\n4- Para sair\n";
    std::cin >> opcao;
    if(opcao == "1"){
      criptografa(alfabeto);
      flag = false;
    }
    else if(opcao == "2"){
      descriptografa(alfabeto);
      flag = false;
    }
    else if(opcao == "3"){
      quebra(alfabeto);
      flag =false;
    }
    else if(opcao == "4"){
      flag = false;
    }
    else system("clear");
  }



  //solve(argv[1], alfabeto);
  
}
