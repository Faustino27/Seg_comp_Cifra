#include <vector>
#include <map>
#include <string>

// maybe change the name of this?
// I dont think we need another class just to make the cypher
// maybe call this class Cifra(?) or cypher
// 1 question: why would we need the table? 
// if this question is answered we might continue like that
// otherwise I think we can make with only one class
class Tabela {

  private:
    std::vector<std::string> tabela;
    std::vector<int> indexOf; // fiquei agoniado e troquei
    // std::map<char, int> indexOf; //  podemos trocar isso por um vector de 128 posicoes -> se sobrar tempo
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    int tamanho = 0;

    void init() {
      
      // calculando o tamanho do alfabeto
      this->tamanho = this->alfabeto.size();

      // populando o map indexOf
      // e inicializando
      indexOf.assign(256, -1);
      for(int i = 0; i < this->tamanho; i++) {
        indexOf[alfabeto[i]] = i;
      }

      // inicializando e
      // populando a tabela
      tabela.assign(this->tamanho, std::string(this->tamanho, ' '));
      for(int i = 0; i < this->tamanho; i++) {
        for(int j = 0; j < this->tamanho; j++) {
          tabela[i][j] = this->alfabeto[(i+j)%this->tamanho];
        }
      }


    }  
  
    char getEncrypt(char a, char b) {
      // i dont think we need the real table here
      // we can just calculate the value of each cell
      int idA = this->indexOf[a];
      int idB = this->indexOf[b];
      if(idA == -1 || idB == -1) {
        std::cout << "letra nao pertencente ao alfabeto!" << std::endl;
        exit(1);
      }return this->alfabeto[(idA+idB)%this->tamanho];
      // deixar a tabela explicita caso o faustino ainda queira
      // return this->tabela[this->indexOf[a]][this->indexOf[b]];
    }

    // char a is the key
    // char b is the encrypted message
    char getDecrypt(char a, char b) {
      int idA = this->indexOf[a];
      int idB = this->indexOf[b];
      if(idA == -1 || idB == -1) {
        std::cout << "letra nao pertencente ao alfabeto!" << std::endl;
        exit(1);
      }
      return this->alfabeto[(idB-idA+this->tamanho)%this->tamanho]; 
    }

    void normalizeKey(std::string& text, std::string& key) {
      std::string copyKey = key;
      while(key.size() < text.size()) 
        key += copyKey;
      while(key.size() > text.size())
        key.pop_back();
    }
    
  public:

    Tabela() {
      init();
    }

    Tabela(std::string al) {
      this->alfabeto = al;
      init();
    }

    // do we need this?
    int getId(char c) {
      return indexOf[c]; 
    } 

    std::string coder(std::string text, std::string key) {
      std::string ans = "";
      this->normalizeKey(text, key);

      int tamanho = text.size();
      for(int i = 0; i < tamanho; i++) 
        ans += this->getEncrypt(text[i], key[i]);
      return ans; 
    }

    std::string decoder(std::string text, std::string key) {
      std::string ans = "";
      this->normalizeKey(text, key);

      int tamanho = text.size();
      for(int i = 0; i < tamanho; i++) 
        ans += this->getDecrypt(key[i], text[i]);
      return ans;
    } 
};
