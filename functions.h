#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;
const int CASE = 'a';

struct Node {
	Node* parent = nullptr;
	Node* children[ALPHABET_SIZE] = {};
	int occurrences = 0;
};

void Insert(Node* trieTree, char* word);
void Search1(Node* trieTree, char* word);
Node* Search2(Node* trieTree, char* word);
void Delete(Node* trieTree, char* word);
void Print(Node* trieTree, vector<char> word, ofstream& fout);