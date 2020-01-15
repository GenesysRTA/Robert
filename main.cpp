#include "functions.h"
#include <ctime>

ifstream fin("input4k.txt");
ofstream fout("output4k.txt");

int main() {
	clock_t start, finish;
	double duration;
	vector<char> word;
	Node* trieTree = new Node();
	char cuv[20];
	start = clock();
	while (!fin.eof()) {
		fin >> cuv;
		Insert(trieTree, cuv);
	}
	Print(trieTree, word, fout);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << duration;
	return 0;
}
