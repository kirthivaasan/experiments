#include "bloom.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int total_words = 0;
	char filename[] = {"words.txt"};
	ifstream words(filename);
	string word;
	cout << "Calculating number of words.";
	while (words >> word) {
		total_words++;
	}
	words.close();
	
	kirthi::bloom<string> bloom_filter(total_words);
	
	words.open(filename);
	cout << "Total words: " << total_words << endl << "Loading words into bloom filter." << endl;
	while (words >> word) {
		bloom_filter.add(word);
	}
	cout << "Done loading." << endl << endl;
	
	do {
		cout << "Query a word [q to exit]: ";
		cin >> word;
		if (word == "q") break;
		if (bloom_filter.contains(word))
			cout << "[ " << word <<  " ] found.";
		else
			cout << "[ " << word <<  " ] NOT found.";
		cout << endl << endl;
	} while (true);
	
}