#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//digitar chcp 65001 no terminal

int main(){
    // vector<wstring> letras = { L"a", L"b", L"c", L"d", L"e", L"f", L"g", L"h", L"i", L"j", L"k", L"l", L"m", L"n", L"o", L"p", L"q", L"r", L"s", L"t", L"u", L"v", L L"w", L"x", L"y", L"z"};
//vector<wstring>numeros={ L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"0"};
//vector<wstring>pontuacao={ L".", L"\"", L"\'", L",", L"?", L"!", L"-", L":", L";"};
//vector<wstring>simbolos={ L"\\", L"@", L"*", L"&", L"%", L"$", L"#", L"<", L">", L"+", L"_", L"=", L"§", L"|", L"º", L"ª", L"°"};
//vector<wstring>acentos={ L"ç","á", L"à", L"é", L"è", L"ó", L"ò", L"ì", L"í", L"ú", L"ù", L"â", L"ô", L"ê", L"ã", L"õ", L"ñ", L"~", L"^", L"´", L"`"};
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
    cout << "{\n";
    for(int i = 0;i < escolha.size();i++){
        tabela.push_back({});
        cout << "{";
        for(int j = 0;j < escolha.size();j++){
            tabela[i].push_back(escolha[(i+j)%escolha.size()]);
            cout << "\"" << escolha[(i+j)%escolha.size()] << "\"" << ", ";
        }
        cout << "},";
        cout << "\n";
    }
    cout << "}";
    







}