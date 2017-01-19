#include <iostream>

using namespace std;

int fib(int k){
const int n = k;
int fib[n];
    fib[0] = 0;
    fib[1] = 1;

for (int i = 2; i <= n; i++)
{
fib[i] = fib[i - 1] + fib[i - 2];
}

for (int i = 1; i < n+1; i++)
{
cout << fib[i];
if(i < n) cout<<", ";
}


}

int main(int argc, char* argv[]){
int pos;
string ok = argv[1];

//cout<<ok<<endl;
//cout << "Enter a position" << endl;
//cin >> pos;

fib(stoi(ok));
    return 0;
}
