#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prioridad(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; 
}

int main() {
    string linea;
    getline(cin, linea);
    int t = stoi(linea);

    for (int caso = 0; caso < t; caso++) {
        stack<char> ops;
        string salida;
        bool empezo = false;

        while (getline(cin, linea)) {
            size_t p = linea.find_first_not_of(" \t\r\n");
            if (p == string::npos) {         
                if (empezo) break;            
                else continue;                
            }
            empezo = true;
            char c = linea[p];

            if (c >= '0' && c <= '9') {
                salida += c;
            }
            else if (c == '(') {
                ops.push(c);
            }
            else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    salida += ops.top();
                    ops.pop();
                }
                if (!ops.empty()) ops.pop();  
            }
            else { 
                while (!ops.empty() && ops.top() != '(' &&
                    prioridad(ops.top()) >= prioridad(c)) {
                    salida += ops.top();
                    ops.pop();
                }
                ops.push(c);
            }
        }

        while (!ops.empty()) {
            salida += ops.top();
            ops.pop();
        }

        cout << salida << "\n";
        if (caso < t - 1) cout << "\n";        
    }
    return 0;
}
