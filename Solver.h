#include <vector>

class Solver{
private:
    std::vector<double> en = {0.08167,0.01492,0.02782,0.04253,0.12702, 0.02228, 0.02015,
    0.06094, 0.06966, 0.00153,0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095,
    0.05987, 0.06327, 0.09056, 0.02758, 0.0097, 0.02360, 0.00150, 0.01974, 0.00074};
    std::vector<double> pt = {0.14634, 0.01043, 0.03882, 0.04992, 0.12570, 0.01023, 0.01303, 
    0.00781, 0.06186, 0.00397, 0.00015, 0.02779, 0.04738, 0.04446,0.09735, 0.02523, 0.01204,
    0.06530, 0.06805, 0.04336, 00.3639, 0.01575, 0.00037, 0.00253, 0.00006, 0.00470};


    std::pair<std::vector<int>, int> numeroOcorrencias(std::string cifrado){
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

    std::vector<int> frequenciaSpike(std::vector<int> ocorrencias, int media){
        int tamanho = ocorrencias.size();
        std::vector<int> frequencia;
        //std::cout << "media:  " << media << std::endl;

        for (int i = 0; i < tamanho; i++){
            std::cout << ocorrencias[i] << " ";
            if(ocorrencias[i] > media) frequencia.push_back(i);
        }
        return frequencia;
    }

    std::string compute(int tChave, std::string cifrado, int lingua){
        std::string res = "";
        for(int t = 0;t < tChave;t++){
            std::vector<int> letras(26,0);
            int total=0;
            for(int i = t;i < cifrado.size();i += tChave){
                letras[cifrado[i]]++;
                total++;
            }
            std::vector<double> frequenciaCifrado;
            for(int i = 0;i < letras.size();i++){
                frequenciaCifrado.push_back((letras[i]/(double)total));
            }
            std::vector<double> frequenciaAlfabeto = pt; 
            if(lingua)frequenciaAlfabeto = en;
            double maior = 0.0;
            int shift = 0, tFreq= frequenciaAlfabeto.size();
            for(int i = 0;i < tFreq;i++){
                double multi = 0.0;
                for(int j = 0;j<tFreq;j++){
                    multi += frequenciaAlfabeto[(j+i)%tFreq]*frequenciaCifrado[j];
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

        return "";
    }

    // construtores
    Solver(){
        Tabela cifra();
    }

    Solver(std::string alfabeto){
        Tabela cifra(alfabeto);
        // não sei se vai precisar das funções dessa classe, mas deixei ai caso precise
    }
};
