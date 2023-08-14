#include<iostream>
#include<vector>
#include <utility>
using namespace std;

class Trie{
public:
    bool isWord;
    int weight;
    vector<Trie* > allCharacters;
    Trie(){
        isWord = false;
        allCharacters = vector<Trie* >(26, nullptr);
    }
};

void insertInTrie(Trie* root, string input, int weight){
    for(int i = 0 ; i < input.size() ; i++){
        Trie* currentCharacter = root->allCharacters.at(input.at(i) - 'a');
        if(currentCharacter == nullptr){
            currentCharacter = new Trie();
        }
        root->allCharacters.at(input.at(i) - 'a') = currentCharacter;
        root= currentCharacter;
    }
    root->weight = weight;
    root->isWord = true;
}

pair<bool, Trie*> search(Trie* root, string input){
    for(int i = 0 ; i < input.size() ; i++){
        Trie* currentCharacter = root->allCharacters.at(input.at(i) - 'a');
        if(currentCharacter != nullptr){
            root = currentCharacter;
        }
        else return make_pair(false, nullptr);
    }
    return make_pair(true,root);
}

void printAll(Trie* root, string prefix, vector<pair<string, int> > &allStrings){
    for(int i = 0 ; i < 26; i++){
        Trie* temp = root->allCharacters.at(i);
        char currCharacter = i + 97;
        if(temp){
            if(temp->isWord){
                allStrings.push_back(make_pair(prefix+currCharacter, temp->weight));
            }
            printAll(temp, prefix+currCharacter , allStrings);
        }
    }
}

bool compare(pair<string, int> pair1, pair<string, int> pair2){
    return pair1.second > pair2.second;
}

void inputOutput(){
    vector<string> nStrings, mStrings;
    vector<int> nWeights;
    int n , m ;
    cin>>n;
    cin>>m;
    for(int i = 0 ; i < n ; i++){
        string inputString;
        cin>>inputString;
        nStrings.push_back(inputString);
    }
    for(int i = 0 ; i < n ; i++){
        int stringWeight;
        cin>>stringWeight;
        nWeights.push_back(stringWeight);
    }
    for(int i = 0 ; i < m ; i++){
        string prefixString;
        cin>>prefixString;
        mStrings.push_back(prefixString);
    }

    vector<vector<string> > answer;
    Trie* root = new Trie();

    for(int i = 0 ; i < n ; i++){
        insertInTrie(root, nStrings.at(i), nWeights.at(i));
    }

    for(int i = 0 ; i < m ; i++){
        pair<bool, Trie*> curr = search(root, mStrings.at(i));
        vector<pair<string, int> > allStrings;
        if(curr.first){
           printAll(curr.second, mStrings.at(i), allStrings); 
           sort(allStrings.begin(), allStrings.end(), compare);
           for(int j = 0 ; j < allStrings.size() && j < 5 ; i++){
               cout<<allStrings.at(i).first<<" ";
           }
        }
        else{
            cout<<"-1";
        }
        cout<<endl;
        allStrings.clear();
    }
}


int main() {
    int numbersOfTestCases, n, m;
    cin>>numbersOfTestCases;
    vector<string> nStrings, mStrings;
    vector<int> nWeights;
    for(int i = 0 ; i < numbersOfTestCases ; i++){
       inputOutput();
    }
    return 0;
}