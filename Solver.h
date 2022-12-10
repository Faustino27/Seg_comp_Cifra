#include <vector>

class Solver
{
private:
    std::pair<std::vector<int>, int> numeroOcorrencias(std::string cifrado)
    {
        std::vector<int> resultado;
        int tamanho = cifrado.size();
        int total = 0, maior = 0;
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
            maior = std::max(maior, igual);
            resultado.push_back(igual);
        }
        //std::cout << "total:" <<  total << "maior" << maior << "\n";
        //mudar os segundo valor que vamos usar como base
        return {resultado, tamanho/total};
    }

    std::vector<int> frequenciaSpike(std::vector<int> ocorrencias, int media)
    {
        int tamanho = ocorrencias.size();
        std::vector<int> frequencia;
        //std::cout << "media:  " << media << std::endl;

        for (int i = 0; i < tamanho; i++)
        {
            std::cout << ocorrencias[i] << " ";
            if(ocorrencias[i] >= media) frequencia.push_back(i);
        }
        return frequencia;
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
};
