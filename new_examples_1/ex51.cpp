#include<iostream>
#include<vector>
#include <utility>
#include<algorithm>
using namespace std;

class Trie{
public:
    vector<int> index ;
    vector<Trie* > allCharacters;
    Trie(){
        allCharacters = vector<Trie* >(26, nullptr);
    }
};

void insertInTrie(Trie* root, string input, int indexValue){
    for(int i = 0 ; i < input.size() ; i++){
        Trie* currentCharacter = root->allCharacters.at(input.at(i) - 'a');
        if(currentCharacter == nullptr){
            currentCharacter = new Trie();
        }
        if(currentCharacter->index.size() < 5) currentCharacter->index.push_back(indexValue);
        root->allCharacters.at(input.at(i) - 'a') = currentCharacter;
        root = currentCharacter;
    }
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

void printAll(Trie* root, string prefix, vector<int>& allStringIndexs) {
    for(int i = 0 ; i < root->index.size() ; i++) {
        allStringIndexs.push_back(root->index.at(i));
    }
}

bool compare(pair<string, int> pair1, pair<string, int> pair2){
    return pair1.second > pair2.second;
}

void inputOutput(){
    // vector<string> nStrings, mStrings;
    // vector<int> nWeights;
    // int n , m ;
    // cin>>n;
    // cin>>m;
    // for(int i = 0 ; i < n ; i++){
    //     string inputString;
    //     cin>>inputString;
    //     nStrings.push_back(inputString);
    // }
    // for(int i = 0 ; i < n ; i++){
    //     int stringWeight;
    //     cin>>stringWeight;
    //     nWeights.push_back(stringWeight);
    // }
    // for(int i = 0 ; i < m ; i++){
    //     string prefixString;
    //     cin>>prefixString;
    //     mStrings.push_back(prefixString);
    // }
    int n = 6 ;
    int m = 3 ;
    vector<string> nStrings ={"abcd", "aecd", "abaa", "abef", "acdcc", "acbcc"};
    vector<int> nWeights = {2, 1, 3, 4, 6, 5};
    vector<string> mStrings = {"ab", "abc" ,"a"};

    Trie* root = new Trie();
    vector<pair<string, int> > nStringsandWeights ;
    for(int i = 0 ; i < nStrings.size() ; i++) {
        nStringsandWeights.push_back(make_pair(nStrings[i], nWeights[i]));
    }
    sort(nStringsandWeights.begin(), nStringsandWeights.end(), compare) ;
    for(int i = 0 ; i < n ; i++){
        insertInTrie(root, nStringsandWeights[i].first, i);
    }

    for(int i = 0 ; i < m ; i++){
        pair<bool, Trie*> curr = search(root, mStrings.at(i));
        vector<int> allStringIndexs;
        if(curr.first){
            printAll(curr.second, mStrings.at(i), allStringIndexs);
            for(int j = 0 ; j < allStringIndexs.size() ; j++){
                cout<<nStringsandWeights.at(allStringIndexs[j]).first<<" ";
            }
        }
        else{
            cout<<"-1 ";
        }
        cout<<endl;
        allStringIndexs.clear();
    }
}

int main() {
    int numbersOfTestCases, n, m;
    //cin>>numbersOfTestCases;
    vector<string> nStrings ={"abcd", "aecd", "abaa", "abef", "acdcc", "acbcc"};
    vector<int> nWeights = {2, 1, 3, 4, 6, 5};
    vector<string> mStrings = {"ab", "abc" ,"a"};
    inputOutput();
    return 0;
}