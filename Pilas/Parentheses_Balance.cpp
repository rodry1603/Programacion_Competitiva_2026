#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool esCorrecta(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        }
        else if (c == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
        }
        else if (c == ']') {
            if (st.empty() || st.top() != '[') return false;
            st.pop();
        }
      
    }
    return st.empty();
}

int main() {
    string linea;
    getline(cin, linea);
    int n = stoi(linea);

    for (int i = 0; i < n; i++) {
        if (!getline(cin, linea)) linea = "";  
        cout << (esCorrecta(linea) ? "Yes" : "No") << "\n";
    }
    return 0;
}
