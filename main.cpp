#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> inputs;

bool es_primo(int n){
    for(int i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

vector<int> factors(int n)
{
    vector<int> lista;
    for(int i=2;i<=n;i++)
    {

        int cantidad=0;
        if(es_primo(i))
        {
            while(n%i==0)
            {
                cantidad++;
                n=n/i;
            }
            lista.push_back(cantidad);
        }

    }
    return lista;

}
int cifras(int n)
{
    int c=0;
    while(n>=10){
        c++;
        n=n/10;
    }
    return c;
}

void suma(vector<vector<int>>todos,int input)
{
    vector<int> numeros;
    for(auto i:todos){

        for(int j=0;j<i.size();j++){
            if(j==numeros.size()){
                numeros.push_back(1);
            }
            else{
                numeros[j]+=i[j];
            }
        }
    }
        for (int k = 2; k>cifras(input); k--) {
            cout << " ";
        }

    cout<<input<<"! =";
            for (int l=0;l<numeros.size();l++) {
                if(l==15)
                {
                    cout<<endl;
                    cout<<" "<<" "<<" "<<" "<<" "<<" ";
                }
                for (int k = 2; k > cifras(numeros[l]); k--) {
                    cout << " ";
                }


                cout << numeros[l];

            }
    cout<<endl;
}

void total(int n)
{
    vector<vector<int>>final;
    for(int i=2;i<=n;i++)
        final.push_back(factors(i));
    suma(final,n);
}


int main() {


    int input;
    while(true) {
        cin >> input;
        if(input!=0) {
            inputs.push_back(input);
        }
        else
            break;
    }
    for(auto i:inputs){
        total(i);
    }

    return 0;
}