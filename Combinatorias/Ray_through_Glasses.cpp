#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string suma (string a, string b){
  string resultado = "";

  int carry = 0;
  int i = a.size() - 1;
  int j = b.size() - 1;

  while(i >= 0 || j >= 0 || carry){
    int suma = carry;

    if(i >= 0){
      suma += a[i--] - '0';
    }
    if(j >= 0){
      suma += b[j--] - '0':
    }
    resultado += char((suma % 10) + '0');

    carry = suma / 10;
  }
  reverse(resultado.begin(), resultado.end());

  return resultado;
}

int main(){
  string a[1001];

  a[0] = "1";
  a[1] = "2";

  for(int i = 2; i <= 1000; i++){
    a[i] = sumar(a[i-1], a[i-2]);
  }

  int n;

  while(cin >> n){
    cout << a[n] << '\n';
  }

  return 0;
}
