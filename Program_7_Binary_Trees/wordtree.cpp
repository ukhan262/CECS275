/*
Umar Khan
CECS 275
014477331
Program 7 Word Tree
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

/*node of the tree*/
class Node{
	public :
		string word;
		int count;
		Node *left;
		Node *right;
		Node(string w){
			word = w;
			count = 1;
			left = right = NULL;
		}
};
/*word tree*/
class WordTree{
	private : 	
		Node *root;	
		Node* newNode(string w);
		/*recursive functions*/
		int sizeOfTree(Node* current);
		int depth(Node* current);
		void printRec(Node* current);
		Node* insertRec(string w,Node* current);
	public : 
		WordTree();
		/*non recursive functions*/
		int _sizeOfTree();
		int _depth();
		void insert(string w);
		void print();
};
/*constructor*/
WordTree :: WordTree(){
	root = NULL;
}
/*create a new node*/
Node* WordTree :: newNode(string w){
	Node* newnode = new Node(w);
	return newnode;
}
/*recursive insert method*/
Node* WordTree :: insertRec(string w,Node* current){
	if(current == NULL){
		return newNode(w);
	}
	/*if word does not already exist in binary tree, add it
		 * otherwise increase the word counter*/
	int cmpStringResult;
	int m = w.length();
	for(int i = 0; i < m; i++){
		w[i] = toupper(w[i]);
	}
	m = current->word.length();
	for(int i = 0; i < m; i++){
		current->word[i] = toupper(current->word[i]);
	}
	cmpStringResult = w.compare(current->word);
	if(cmpStringResult == 0)
		current->count++;
	else if(cmpStringResult < 0)
		current->left = insertRec(w,current->left);
	else 
		current->right = insertRec(w,current->right);
	return current;
}
/*non-recursive insert method*/
void WordTree :: insert(string w){
	root = insertRec(w,root);
}
/*recursive print method*/
void WordTree :: printRec(Node* current){
	if(current != NULL){
		printRec(current->left);
		cout <<left << setfill(' ') << setw(60) << current->word << current->count<< endl;
		printRec(current->right);
	}
}
/*non-recursive print method*/
void WordTree :: print(){
	printRec(root);
}
/*recursive method to calculate the size of the tree*/
int WordTree :: sizeOfTree(Node* current){
	if(current == NULL)
		return 0;
	return (sizeOfTree(current->left) + 1 + sizeOfTree(current->right));
}
/*recursive method to calculate the depth of the tree*/
int WordTree :: depth(Node* current){
	if(current == NULL)
		return 0;
	// Base case : Leaf Node. This accounts for height = 1.
    if (current->left == NULL && current->right == NULL)
       return 1;
 
    // If left subtree is NULL, recur for right subtree
    if (!current->left)
       return depth(current->right) + 1;
 
    // If right subtree is NULL, recur for right subtree
    if (!current->right)
       return depth(current->left) + 1;
 
    return min(depth(current->left), depth(current->right)) + 1;
}
/*non-recursive method to calculate the size of the tree*/
int WordTree :: _sizeOfTree(){
	return sizeOfTree(root);
}
/*non-recursive method to calculate the depth of the tree*/
int WordTree :: _depth(){
	return depth(root);
}

int main(){
	string file;
	WordTree bt;
	char ch;
	int siz,dep;
	cout << "Enter file name : ";
	cin >> file;
	ifstream inFile(file.c_str());
	
	if(!inFile)
	{
		cout << "Error, can't open file" << endl;
		return 1;
	}
	else {
		string line,s;
		/*read input file and store all the words in binary tree*/
		while(getline(inFile,line)){
			istringstream ss;
			ss.str(line);
			while(ss >> s){
				bt.insert(s);
			}
		}
		bt.print();
		siz = bt._sizeOfTree();
		dep = bt._depth();
		inFile.close();
		
	}
	/*cout << "size : " << siz << endl;
	cout << "depth : " << dep << endl;*/
	cout << "Press any key to continue ... ";
	//getch();
	cin >>ch;
	return 0;
}







