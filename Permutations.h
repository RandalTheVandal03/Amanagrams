#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "TrieNode.h"
#include "HashTable.h"

using namespace std;

class Permutations {

public:
	vector<vector<string>> permutations(vector<string> letters);
	vector<vector<string>> getPermutations();
	void updateWords(TrieNode& root, HashTable& hash, vector<vector<string>>& desiredOrientations,
		vector<vector<string>>& desiredTrie, vector<vector<string>>& desiredHash);


};