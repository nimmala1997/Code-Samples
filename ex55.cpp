#include<iostream>
#include<vector>
#include <utility>
#include<algorithm>
using namespace std;

class Trie{
public:
    bool isWord;
    int weight;
    int count;
    vector<Trie* > allCharacters;

    Trie(){
        isWord = false;
        count = 0;
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
        root = currentCharacter;
    }
    root->weight = weight;
    root->isWord = true;
}

void printAll(Trie* root, string prefix, vector<pair<string, int> > &allStrings){
    for(int i = 0 ; i < 26; i++){
        Trie* temp = root->allCharacters.at(i);
        char currCharacter = i + 97;
        if(temp){
            if(temp->isWord){
                for(int j = 0 ; j < temp->count ; j++)
                    allStrings.push_back(make_pair(prefix+currCharacter, temp->weight+j));
            }
            printAll(temp, prefix+currCharacter , allStrings);
        }
    }
}

bool compare(pair<string, int> pair1, pair<string, int> pair2){
    return pair1.second > pair2.second;
}

void searchAndPrint(Trie* root, string prefix) {
    pair<bool, Trie* > result;
    vector<pair<string, int> > allStrings;
    for(int i = 0 ; i < prefix.size() ; i++){
        Trie* currentCharacter = root->allCharacters.at(prefix.at(i) - 'a');
        if(currentCharacter != nullptr){
            root = currentCharacter;
        }
        else result = make_pair(false, nullptr);
    }
    result = make_pair(true,root);

    if(result.first){
        if(result.second->isWord){
            allStrings.push_back(make_pair(prefix, result.second->weight));
        }
        printAll(result.second, prefix, allStrings);
        sort(allStrings.begin(), allStrings.end(), compare);
        for(int j = 0 ; j < allStrings.size() && j < 5 ; j++){
            cout<<allStrings.at(j).first<<" ";
        }
    }
    else{
        cout<<"-1 ";
    }
    cout<<endl;
}

void inputOutput() {
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> nStrings;

    for (int i = 0; i < n; i++) {
        string inputString;
        cin >> inputString;
        int stringWeight;
        cin >> stringWeight;
        nStrings.push_back(make_pair(inputString, stringWeight));
    }

    vector<string> mStrings;
    for (int i = 0; i < m; i++) {
        string prefixString;
        cin >> prefixString;
        mStrings.push_back(prefixString);
    }

    Trie* root = new Trie();

    for (const auto& entry : nStrings) {
        insertInTrie(root, entry.first, entry.second);
    }

    for (string prefix : mStrings) {
        searchAndPrint(root, prefix);
    }

    delete root;
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