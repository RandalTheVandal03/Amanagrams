#pragma once
struct TrieNode {

    //Basic variables that can be modified at will
    char letter = ' ';
    vector<TrieNode> connectedLetters;
    bool isEnd = false;

    void insertLetter(string word, TrieNode& node) {

        //Checks if the letter already exists, if it does, it recursively calls this function down that letter
        bool isHere = false;
        for (int x = 0; x < node.connectedLetters.size(); x++) {
            if (node.connectedLetters.at(x).letter == word.at(0)) {
                if (word.size() == 1) {
                    //Sets preexisting letter as an ending for searching purposes
                    isEnd = true;
                    return;
                }
                return insertLetter(word.substr(1), node.connectedLetters.at(x));
                bool isHere = true;
            }

        }

        //If letter does not exist, creates a new Trie Node with that letter and recursively calls this function down that letter
        if (isHere == false) {
            TrieNode newNode;
            newNode.letter = word.at(0);

            if (word.size() > 1) {
                node.connectedLetters.push_back(newNode);
            }
            if (word.size() == 1) {
                //Sets the newly created letter as an ending for searching purposes
                newNode.isEnd = true;
                node.connectedLetters.push_back(newNode);
                return;
            }
            return insertLetter(word.substr(1), node.connectedLetters.at(node.connectedLetters.size() - 1));
        }
    }

    bool search(string word, TrieNode& node) {

        //Similar to the Insert function but simpler
        for (int x = 0; x < node.connectedLetters.size(); x++) {
            //Goes down the node's connected letters to see if the desired letter exists
            if (node.connectedLetters.at(x).letter == word.at(0)) {
                //Recursively calls this function if desired letter exists, then checks if the letter is a final letter when checking the final letter of the word (See Insert for More)
                if (word.size() == 1) {
                    if (node.connectedLetters.at(x).isEnd == false) {
                        return false;
                    }
                    return true;
                }
                return search(word.substr(1), node.connectedLetters.at(x));
            }
        }

        return false;

    }
};

