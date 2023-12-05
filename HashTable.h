#pragma once
#include <vector>
#include <iostream>
#include <list>

using namespace std;

// Declares the HashTable Class
class HashTable
{
	// Basic Variables that can only be modified by the class
	int capacity = 10;
	vector<list<string>> Table;
	int LoadFactor = 1.75;
	int size = 0;


	int getHashCode(string word) {
		// Adds up the ASCII values of each letter and takes the modulo of capacity for the hash code
		int hashVal = 0;
		for (int x = 0; x < word.size(); x++) {
			hashVal += int(word.at(x));
		}
		return hashVal % capacity;
	}

	void rehash() {

		// Checks if the load is less than load factor
		if (size / capacity >= LoadFactor) {
			//Increases capacity and creates a new table with double the current size
			capacity *= 2;
			vector<list<string>> newTable;
			newTable.resize(capacity);

			// Allocates every node in the new table. Expensive, but keeps search times quick
			for (int x = 0; x < Table.size(); x++) {
				for (auto it = Table.at(x).begin(); it != Table.at(x).end(); it++) {
					int hash = this->getHashCode(*it);
					newTable[hash].push_back(*it);
				}
			}
			// Sets old Table equal to new table and discards old table
			Table = newTable;
		}
	}

public:

	HashTable() {

		// Sets the initial table to size 10, called by default
		Table.resize(10);
	}

	void insert(string word) {

		// Inserts into the hash table by getting the hash code and pushing the word into its respective list
		int hash = this->getHashCode(word);
		Table[hash].push_back(word);
		size++;

		//See the rehash function
		rehash();

	}

	bool search(string word) {

		// Simple search, gets the hash code and traverses through respective list to find if word exists. Usually short thanks to rehashing
		int hash = this->getHashCode(word);
		for (auto it = Table.at(hash).begin(); it != Table.at(hash).end(); it++) {
			if (*it == word) {
				return true;
			}
		}

		return false;
	}
};
