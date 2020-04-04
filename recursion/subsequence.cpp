#include<bits/stdc++.h>
using namespace std;


void subsequences(char *in, char *out, int i, int j)
{
    //Base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout << out << " " << endl;
        return;
    }

    //Recursive case
    //1. Include the current character
    out[j]=in[i];
    subsequences(in, out, i+1, j+1);
    
    //2. Exclude the current character
    subsequences(in, out, i+1, j);

}

int main()
{
    char in[100];
    cin >> in;


    char out[100];
    subsequences(in, out, 0, 0);

    return 0;
}