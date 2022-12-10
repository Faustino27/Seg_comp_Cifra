#include <vector>
#include <Tabela.h>

class Solver{
    private:


    public:

        //Solver
        std::string Solve(std:: string cifrado){
            std::vector<int> ocorrencias;
            int tamanho = cifrado.size();
            int total = 0;
            //vai compara texto cifrado com ele mesmo para ver quantas vezes um letra reaparece
            //e armazena isso em um vetor para ser usado mais tarde
            for(int i = 0;i < tamanho;i++){
                int igual = 0;
                for(int j = 0;j < tamanho;j++){
                    if(cifrado[i] == cifrado[j])igual++;
                }
                total += igual;
                ocorrencias.push_back(igual);
            }
        }




        //construtores
        Solver(){
            Tabela cifra();
        }

        Solver(std::string alfabeto){
            Tabela cifra(alfabeto); 
            // não sei se vai precisar das funções dessa classe, mas deixei ai caso precise 
        }
};
