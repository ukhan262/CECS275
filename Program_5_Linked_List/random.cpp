/*
Umar Khan
CECS 275
014477331
Word Counter
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

typedef struct wordstruct {
	string word;
	short count;
	wordstruct* next;
}wordstruct;
ifstream inFile;


wordstruct* insertNode(wordstruct* head, string key) {
	wordstruct *t = head;
	int i = 0;
	while (key[i] != '\0') {
		key[i] = toupper(key[i]);
		i++;
	}
	if (head == NULL) {
		struct wordstruct *temp = (wordstruct *)malloc(sizeof(wordstruct));
		temp->word = key;
		temp->count = 1;
		temp->next = NULL;
		head = temp;
		return head;
	}

	if (head->word.compare(key) == 0) {
		head->count += 1;
		return head;
	}

	if (head->word.compare(key)>0) {
		struct wordstruct *temp = (wordstruct *)malloc(sizeof(wordstruct));
		temp->word = key;
		temp->count = 1;
		temp->next = head;
		head = temp;
		return head;
	}

	while (head->next != NULL && head->next->word.compare(key)<0) {
		head = head->next;
	}
	if (head->next != NULL && head->next->word.compare(key) == 0) {
		head->next->count += 1;
		return t;
	}
	if (head->next != NULL && head->next->word.compare(key)>0) {
		struct wordstruct *temp = (wordstruct *)malloc(sizeof(wordstruct));
		temp->word = key;
		temp->count = 1;
		wordstruct* temp2 = head->next;
		temp->next = temp2;
		head->next = temp;
		return t;
	}

	if (head->next == NULL) {
		struct wordstruct *temp = (wordstruct *)malloc(sizeof(wordstruct));
		temp->word = key;
		temp->next = NULL;
		head->next = temp;
		return t;
	}


}

void showAll(wordstruct *head) {

	while (head != NULL) {
		cout << head->word << "\t\t" << head->count << endl;
		head = head->next;
	}
	cout << "Press and Key to Continue......" << endl;
}


int main() {
	wordstruct* root = NULL;
	string key;
	inFile.open("input.txt");
	if (inFile.fail()) {
		cerr << "Could not find file" << endl;
		exit(0);
	}
	while (inFile >> key)
		root = insertNode(root, key);

	showAll(root);
}