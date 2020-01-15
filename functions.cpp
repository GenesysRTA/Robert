#include "functions.h"

void Insert(Node* trieTree, char* word) {
	Node* currentNode = trieTree;
	while (*word != '\0') {
		if (currentNode->children[*word - CASE] == nullptr) {
			currentNode->children[*word - CASE] = new Node();
			currentNode->children[*word - CASE]->parent = currentNode;
		}
		currentNode = currentNode->children[*word - CASE];
		word++;
	}
	currentNode->occurrences++;
}

void Search1(Node* trieTree, char* word) {
	while (*word != '\0') {
		if (trieTree->children[*word - CASE] != nullptr) {
			trieTree = trieTree->children[*word - CASE];
			word++;
		}
		else {
			cout << "Nu exista" << endl;
			break;
		}
	}
	if (trieTree->occurrences != 0)
		cout << "Exista" << endl;
}

Node* Search2(Node* trieTree, char* word) {
	while (*word != '\0') {
		if (trieTree->children[*word - CASE] != nullptr) {
			trieTree = trieTree->children[*word - CASE];
			word++;
		}
		else return nullptr;
	}
	return (trieTree->occurrences != 0) ? trieTree : nullptr;
}

void Delete(Node* trieTree, char* word) {
	Node* currentNode = Search2(trieTree, word);
	if (currentNode != nullptr) {
		currentNode->occurrences--;
		Node* parent = nullptr;
		bool isLeaf = true;
		int i;
		for (i = 0; i < ALPHABET_SIZE; i++)
			if (currentNode->children[i] != nullptr) {
				isLeaf = false;
				break;
			}
		while (currentNode->parent != nullptr && isLeaf && currentNode->occurrences == 0) {
			parent = currentNode->parent;
			for (i = 0; i < ALPHABET_SIZE; i++) {
				if (parent->children[i] == currentNode) {
					parent->children[i] = nullptr;
					delete currentNode;
					currentNode = parent;
				}
				else if (parent->children[i] != nullptr) {
					isLeaf = false;
					break;
				}
			}
		}
	}
}

void Print(Node* trieTree, vector<char> word, ofstream& fout) {
	if (trieTree->occurrences > 0) {
		for (auto i = word.begin(); i != word.end(); i++)
			fout << *i;
		fout << " " << trieTree->occurrences << endl;
	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (trieTree->children[i] != nullptr) {
			word.push_back(CASE + i);
			Print(trieTree->children[i], word, fout);
			word.pop_back();
		}
}