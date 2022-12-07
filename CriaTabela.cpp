#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//digitar "chcp 65001" no terminal

vector<vector<string>> geraTabela(vector<string> elementos){
    vector<vector<string>> tabela;
    int n = elementos.size();
    for(int i = 0;i < n;i++){
        tabela.push_back({});
        for(int j = 0;j < n;j++){
            tabela[i].push_back(elementos[(i+j)%n]);
        }
    }
    return tabela;
}

void gerarTxtTabela(vector<string> elementos){
    freopen("output.txt", "w", stdout);
    int n = elementos.size();
    cout << "{\n";
    for(int i = 0;i < n;i++){
        cout << "{";
        for(int j = 0;j < n;j++){
            cout << "\"";  
            if(elementos[(i+j)%n] == "\\"  or elementos[(i+j)%n] == "\"" or elementos[(i+j)%n] == "\'") cout << "\\";
            cout << elementos[(i+j)%n] << "\"" << ", ";
        }
        cout << "},";
        cout << "\n";
    }
    cout << "}";
}

int main(){
    vector<string> letras = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",  "w", "x", "y", "z"};
    vector<string> numeros = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
    vector<string> pontuacao = { ".", "\"", "\'", ",", "?", "!", "-", ":", ";"};
    vector<string> simbolos = { "\\", "@", "*", "&", "%", "$", "#", "<", ">", "+", "_", "=", "§", "|", "º", "ª", "°"};
    vector<string> acentos = { "ç","á", "à", "é", "è", "ó", "ò", "ì", "í", "ú", "ù", "â", "ô", "ê", "ã", "õ", "ñ", "~", "^", "´", "`"};

    vector<string> escolha = {};
    escolha.insert(escolha.end(), numeros.begin(), numeros.end());
    escolha.insert(escolha.end(), letras.begin(), letras.end());
    escolha.insert(escolha.end(), pontuacao.begin(), pontuacao.end());
    escolha.insert(escolha.end(), simbolos.begin(), simbolos.end());
    escolha.insert(escolha.end(), acentos.begin(), acentos.end());

    
    vector<vector<string>> tabela;
    freopen("output.txt", "w", stdout);
    int n = escolha.size();
    cout << "{\n";
    for(int i = 0;i < n;i++){
        tabela.push_back({});
        cout << "{";
        for(int j = 0;j < n;j++){
            tabela[i].push_back(escolha[(i+j)%n]);
            cout << "\"";  
            if(escolha[(i+j)%n] == "\\"  or escolha[(i+j)%n] == "\"" or escolha[(i+j)%n] == "\'") cout << "\\";
            cout << escolha[(i+j)%n] << "\"" << ", ";
        }
        cout << "},";
        cout << "\n";
    }
    cout << "}";


}