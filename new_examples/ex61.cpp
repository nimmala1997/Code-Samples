#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("uncompressed.txt"); //open the input file
    int count = 0;
    char c;
    stringstream strStream;
    strStream << inFile.rdbuf();  //read the file
    string str = strStream.str(); //str holds the content of the file
    for (int i = 0; i < str.length() - 1;)
    {
        if (str[i] == str[i + 1])
        {
            count = 0;
            c = str[i];
            while (str[i] == str[i + 1])
            {
                count++;
                i++;
            }
            if (count >= 3)
            {
                cout << c;
                cout << count + 1;
            }
            else
            {
                for (int j = 0; j < count + 1; j++)
                    cout << str[i];
            }
        }
        else
        {
            cout << str[i];
        }
        i++;
    }

    //cout << count;
}