	#include<iostream>
	#include<vector>
	using namespace std ; 
	
	class Trie{
	public :
		Trie* nextZero ;
		Trie* nextOne ;
		Trie() {
			nextZero = nullptr ;
			nextOne = nullptr ;
		}    
	};

	void insertInTrie(Trie* root, int value, int maximumNumberOfBits) {
		vector<int> inputValue(maximumNumberOfBits, 0) ;
		int index = maximumNumberOfBits - 1;
		while(value > 0) {
			int reminder = value % 2 ;
			inputValue[index--] = reminder ;
			value = value / 2 ;
		}
		for(int i = 0 ; i < inputValue.size() ; i++) {
			if(inputValue.at(i) == 0) {
				if(!root->nextZero) root->nextZero = new Trie() ;
				root = root->nextZero ;
			}
			else{
				if(!root->nextOne) root->nextOne = new Trie() ;
				root = root->nextOne ;
			}
		}
	}

	int getMaximumValue(Trie* root , int value, int maximumNumberOfBits) {
		vector<int> inputValue(maximumNumberOfBits, 0) ;
		int index = maximumNumberOfBits - 1;
		while (value > 0) {
			int reminder = value % 2 ;
			inputValue[index--] = reminder ;
			value = value / 2 ;
		}
		int answer = 0 ;
		for (int i = 0 ; i < inputValue.size() ; i++) {
			if (inputValue.at(i) == 1) {
				if (root->nextZero) {
					answer += pow(2, maximumNumberOfBits - 1 - i) ;
					root = root->nextZero ;
				}
				else {
					root = root->nextOne ;
				}
			}
			else {
				if (root->nextOne) {
					answer += pow(2, maximumNumberOfBits - 1 - i) ;
					root = root->nextOne ;
				}
				else{
					root = root->nextZero ;
				}
			}
		}
		return answer ;
	}

	int logbase2(int x) {
		if(x == 0 || x == 1) return 0 ;
		int answer = log(x) / log(2) ;
		return answer ;
	}
     
     int solveXor(vector<int> &A) {
		int maximumNumberOfBits = INT_MIN ;
		Trie* root = new Trie() ;
		for (int i = 0 ; i < A.size() ; i++) {
			maximumNumberOfBits = max(logbase2(A.at(i)) + 1, maximumNumberOfBits) ;
		}
		for(int i = 0 ; i < A.size() ; i++) {
			insertInTrie(root, A.at(i), maximumNumberOfBits) ;
		}
		int maximumValue = INT_MIN ;
		for(int i = 0 ; i < A.size() ; i++) {
			int getMaxValue = getMaximumValue(root, A.at(i), maximumNumberOfBits) ;
			maximumValue = max(getMaxValue, maximumValue) ;
		}
          return maximumValue ;
     }


	vector<int> solve(vector<int> &A) {
		vector<int> prefixArray ;
		int temp = 0 ; 
		unordered_map<int, int> myMap ;
		for (int i = 0 ; i < A.size() ; i++) {
			temp = temp ^ A.at(i) ;
			prefixArray.push_back(temp) ;
			myMap[temp] = i ;
		}
		int maxSubArrayXor = solveXor(prefixArray) ;
		vector<int> answer(INT_MIN, INT_MAX) ;
		for (int i = 0 ; i < A.size() ; i++) {
			if (maxSubArrayXor == A.at(i)) {
				answer[0] = i + 1 ;
				answer[1] = i + 1 ;
				return answer ;
			}
		}
		for(int i = 0 ; i < prefixArray.size() ; i++) {
			int currentXor = prefixArray[i] ^ maxSubArrayXor ;
			if(myMap.count(currentXor) > 0 && myMap[currentXor] - i > answer[1] - answer[0]) {
				answer[0] = i + 2 ;
				answer[1] = myMap[currentXor] + 1 ;
			}
		}	
		return answer ;
	}

	int main() {
		return 0 ;
	}
