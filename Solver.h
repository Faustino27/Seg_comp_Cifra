#include <vector>
#include <algorithm>
#include <map>
#include <utility>

class Solver
{
private:
    int frequency_size = 100;
    std::string cripto;
    std::vector<double> en = {0.08167,0.01492,0.02782,0.04253,0.12702, 0.02228, 0.02015,
    0.06094, 0.06966, 0.00153,0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095,
    0.05987, 0.06327, 0.09056, 0.02758, 0.0097, 0.02360, 0.00150, 0.01974, 0.00074};
    std::vector<double> pt = {0.14634, 0.01043, 0.03882, 0.04992, 0.12570, 0.01023, 0.01303, 
    0.00781, 0.06186, 0.00397, 0.00015, 0.02779, 0.04738, 0.04446,0.09735, 0.02523, 0.01204,
    0.06530, 0.06805, 0.04336, 00.3639, 0.01575, 0.00037, 0.00253, 0.00006, 0.00470};


    std::pair<std::vector<int>, int> numeroOcorrencias(std::string cifrado)
    {
        std::vector<int> resultado;
        int tamanho = cifrado.size();
        int total = 0;
        // vai compara texto cifrado com ele mesmo para ver quantas vezes um letra reaparece
        // e armazena isso em um vetor para ser usado mais tarde
        for (int i = 1; i < tamanho; i++)
        {
            int igual = 0;
            for (int j = 0; i + j < tamanho; j++)
            {
                if (cifrado[i + j] == cifrado[j])
                    igual++;
            }
            total += igual;
            resultado.push_back(igual);
        }
        //std::cout << "total:" <<  total << "maior" << maior << "\n";
        //mudar os segundo valor que vamos usar como base
        return {resultado, total/tamanho};
    }

    std::vector<int> frequenciaSpike(std::vector<int> ocorrencias, int media)
    {
        int tamanho = ocorrencias.size();
        std::vector<int> frequencia;
        //std::cout << "media:  " << media << std::endl;

        for (int i = 0; i < tamanho; i++)
        {
            std::cout << ocorrencias[i] << " ";
            if(ocorrencias[i] > media) frequencia.push_back(i);
        }
        return frequencia;
    }

    std::vector<int> keysize() {
        std::map<std::string, int> last;
        std::vector<int> frequency(this->frequency_size), spacing, retorno; 
        std::vector<std::pair<int,int>> possible;
        std::string aux = this->cripto;

        for(int i = 0; i+2 < aux.size(); i++) {
          
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

            for(int i = 1; i < frequency.size(); i++) 
                if(num%i == 0) 
                    frequency[i]++; 
        }

        for(int i = 2; i < frequency.size(); i++) 
            possible.emplace_back(frequency[i], i);

        sort(possible.rbegin(), possible.rend());

        for(auto [a, b]: possible)
            retorno.emplace_back(b);

        return retorno;
    }
public:
    // Solver
    std::string solve(std::string cifrado){
    
        std::vector<int> ocorrencias;
        int media;
        // pega o numero de ocorrencias de repeticoes de caracteres em cada deslocacao e um
        // valor usado para representar um numero q podemos considerar muito maior do que
        // o resultado esprado
        tie(ocorrencias, media) = numeroOcorrencias(cifrado);
        std::vector<int> frequencia =   frequenciaSpike(ocorrencias, media);
        std::cout << std::endl;
        //for(auto x: frequencia) std::cout << x << " ";

        return "";
    }

    // construtores
    Solver()
    {
        Tabela cifra();
    }

    Solver(std::string alfabeto)
    {
        Tabela cifra(alfabeto);
        // não sei se vai precisar das funções dessa classe, mas deixei ai caso precise
    }

    Solver(std::string alfabeto, std::string cripto, int frequency_size=100) {
        this->frequency_size = frequency_size;
        this->cripto = cripto;
    }

    // teste
    std::vector<int> testeKeysize() {
        return this->keysize();
    }
};
