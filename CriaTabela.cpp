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

vector<vector<wstring>> wgeraTabela(vector<wstring> elementos){
    vector<vector<wstring>> tabela;
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

template <typename T>
vector<vector<T>> gerarTabelaDinamica(vector<T> alfabeto) {
  
}

