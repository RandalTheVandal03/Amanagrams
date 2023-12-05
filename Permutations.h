#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "TrieNode.h"
#include "HashTable.h"

using namespace std;

// Declares the Permutations Class
class Permutations {

public:
	// Declares the Methods used to Calculate the Letter and Word Options' Permutations
	vector<vector<string>> permutations(vector<string> letters);
	vector<vector<string>> getPermutations();
	void updateWords(TrieNode& root, HashTable& hash, vector<vector<string>>& desiredOrientations,
		vector<vector<string>>& desiredTrie, vector<vector<string>>& desiredHash);


};