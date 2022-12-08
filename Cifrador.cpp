#include <unordered_map>
#include "CriaTabela.cpp"


using namespace std;

//digitar "chcp 65001" no terminal
int main(){
    vector<string> elementos ={"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "a", "b", 
    "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", 
    "t", "u", "v", "w", "x", "y", "z", ".", "\"", "\'", ",", "?", "!", "-", ":", ";", 
    "\\", "@", "*", "&", "%", "$", "#", "<", ">", "+", "_", "=", "§", "|", "º", "ª", 
    "°", "ç", "á", "à", "é", "è", "ó", "ò", "ì", "í", "ú", "ù", "â", "ô", "ê", "ã", 
    "õ", "ñ", "~", "^", "´", "`"};


    int tamanhoElementos = elementos.size();
    unordered_map<string, int> mp;

    for(int i = 0;i < tamanhoElementos;i++){
        mp[elementos[i]] = i;
    }

    //freopen("cifrado.txt", "w", stdout);
    vector<vector<string>> tabela = geraTabela(elementos);

    string chave = "key", texto = "eu não gosto de uvas", cifrado = "";
    int cSize = chave.size(), tSize  = texto.size();

    for(int i = 0;i < tSize;i++){
        string x =  "", y = "";
        x += chave[i%cSize]; y +=  texto[i];
        cout << x << y << endl;
        if(mp.find(x)!= mp.end() and mp.find(y) != mp.end()){
            cifrado += tabela[mp[x]][mp[y]];
        }
        else cifrado += texto[i];
    }
    cout << cifrado << endl;

//#####################
    vector<wstring> welementos = {L"1",L"2",L"3",L"4",L"5",L"6",L"7",L"8",L"9",L"0",L"a",L"b"
    ,L"c",L"d",L"e",L"f",L"g",L"h",L"i",L"j",L"k",L"l",L"m",L"n",L"o",L"p",L"q",L"r",L"s",
    L"t",L"u",L"v",L"w",L"x",L"y",L"z",L".",L"\"",L"\'",L",",L"?",L"!",L"-",L":",L";",L"\\",
    L"@",L"*",L"&",L"%",L"$",L"#",L"<",L">",L"+",L"_",L"=",L"§",L"|",L"º",L"ª",L"°",L"ç",
    L"á",L"à",L"é",L"è",L"ó",L"ò",L"ì",L"í",L"ú",L"ù",L"â",L"ô",L"ê",L"ã",L"õ",L"ñ",L"~",
    L"^",L"´",L"`"};
    unordered_map<wstring, int> wmp;

    for(int i = 0;i < tamanhoElementos;i++){
        wmp[welementos[i]] = i;
    }
    vector<vector<wstring>> wtabela = wgeraTabela(welementos);

    wstring wchave = L"key", wtexto = L"eu não gosto de uvasè", wcifrado = L"";
    int wcSize = wchave.size(), wtSize  = wtexto.size();

    for(int i = 0;i < tSize;i++){
        wstring x = L"", y = L"";
        x += chave[i%wcSize];y += wtexto[i];
        wcout << x << y << endl;
        if(wmp.find(x)!= wmp.end() and wmp.find(y) != wmp.end()){
            wcifrado += wtabela[wmp[x]][wmp[y]];
        }
        else wcifrado += wtexto[i];
    }
    wcout << wcifrado << endl;

    
}
