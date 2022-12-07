#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "CriaTabela.cpp"

using namespace std;


int main(){
    unordered_map<string, int> mp;
    vector<string> elementos = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", ".", "\"", "\'", ",", "?", "!", "-", ":", ";", "\\", "@", "*", "&", "%", "$", "#", "<", ">", "+", "_", "=", "§", "|", "º", "ª", "°", "ç", "á", "à", "é", "è", "ó", "ò", "ì", "í", "ú", "ù", "â", "ô", "ê", "ã", "õ", "ñ", "~", "^", "´", "`", };
    int tamanhoElementos = elementos.size();
    for(int i = 0;i < tamanhoElementos;i++){
        mp[elementos[i]] = i;
    }
}
