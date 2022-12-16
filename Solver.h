#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <deque>

class Solver{
private:
    int frequency_size = 100;
    int lingua = 0;
    Tabela cifra;
    std::string cripto;
    std::vector<double> en = {0.08167,0.01492,0.02782,0.04253,0.12702, 0.02228, 0.02015,
    0.06094, 0.06966, 0.00153,0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095,
    0.05987, 0.06327, 0.09056, 0.02758, 0.0097, 0.02360, 0.00150, 0.01974, 0.00074};
    std::vector<double> pt = {0.1463, 0.0104, 0.0388, 0.0499, 0.1257, 0.0102, 0.0130, 
    0.0128, 0.0618, 0.0040, 0.0002, 0.0278, 0.0474, 0.0505,0.1073, 0.0252, 0.0120,
    0.0653, 0.0781, 0.0434, 0.0463, 0.0167, 0.0001, 0.0021, 0.0001, 0.0047};

    //computa a possível chave utilizandoa frequencia do alfabeto
    std::string compute(int tChave){        
        std::string res = "";
        int tCripto = cripto.size();
        for(int t = 0;t < tChave;t++){
            std::vector<int> letras(26,0);
            int total=0;
            for(int i = t;i < tCripto;i += tChave){
                letras[cripto[i]-'a']++;
                total++;
            }
            int  tLetras = letras.size();
            std::deque<double> frequenciaCifrado;
            for(int i = 0;i < tLetras;i++){
                frequenciaCifrado.push_back((letras[i]/(double)26));
            }

            std::vector<double> frequenciaAlfabeto = pt; 
            if(this->lingua)frequenciaAlfabeto = en;

            double maior = 0.0;
            int shift = 0, tFreq= frequenciaAlfabeto.size();
            for(int i = 0;i < tFreq;i++){
                double multi = 0.0;
                for(int j = 0; j < 26; j++) {
                  multi += frequenciaAlfabeto[j] * frequenciaCifrado[(j+i)%tFreq];
                }
                if(multi > maior){
                    maior = multi;
                    shift = i;
                }
            }

            res += 'a'+shift;
        }
        return res;
    }

    //calcula os possiveis tamanhos das chaves utilizando as triplas repetidas na mensagem cifrada
    std::vector<int> keysize() {
        std::map<std::string, int> last;
        std::vector<int> frequency(this->frequency_size), spacing, retorno; 
        std::vector<std::pair<int,int>> possible;
        std::string aux = this->cripto;
        int tAux = aux.size(), tFreq = frequency.size();
        for(int i = 0; i+2 < tAux; i++) {
          
            std::string triplet = aux.substr(i, 3);
            if(last.find(triplet) == last.end()) 
              last[triplet] = i;
            else {
                spacing.push_back(i-last[triplet]);
                last[triplet] = i;
            }
        }

        while(spacing.size()) {
            auto num = spacing.back(); spacing.pop_back();
            for(int i = 1; i < tFreq; i++) 
                if(num%i == 0) 
                    frequency[i]++; 
        }

        for(int i = 2; i < tFreq; i++) 
            possible.emplace_back(frequency[i], i);

        sort(possible.rbegin(), possible.rend());

        for(auto [a, b]: possible)
            retorno.emplace_back(b);

        return retorno;
    }
public:
    // funcao que juntas as funcoes anteriores para quebrar a cifra
    std::vector<std::pair<std::string, std::string>> solve(int maxKeys = 3){
        std::vector<std::string> possibleKeys, possibleTexts;
        std::vector<std::pair<std::string, std::string>> possible;
        std::vector<int> sizeKeys = keysize();
        //para cada key size encontrado na ordem de relevancia até o valor determinado pelo usuário
        for(int i = 0;i < (int)sizeKeys.size() and i < maxKeys;i++){
            possibleKeys.push_back(compute(sizeKeys[i]));
        }
        // para cada chave possivel encontrada rodamos o decoder padrao da cifra com a chave conhecida
        for(const std::string& key: possibleKeys){
            possible.emplace_back(key, cifra.decoder(cripto, key));
            possibleTexts.push_back(cifra.decoder(cripto, key));
        }
        return possible;
        
    }

    // construtores
    Solver(){
        Tabela cifra();
    }

    Solver(std::string alfabeto, std::string cripto, int frequency_size=100, int lingua = 0) {
        this->lingua = lingua;
        this->frequency_size = frequency_size;
        this->cripto = cripto;
    }

    // teste
    std::vector<int> testeKeysize() {
        return this->keysize();
    }
};
