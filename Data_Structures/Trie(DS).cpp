#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct Trie {	
	Trie * children[10];	
	bool end;	
};

Trie *root;
Trie* createNode( ){
	Trie * x= new Trie() ;
	
	for(int i=0;i<10;i++){
		x->children[i] = NULL;
	} 
	x->end = false;
	return x;
}

bool search(string s){
	
	if(root==NULL){
		return false;
	}
	
	Trie *curr = root; 
	// 913
	for( int i=0;i<s.length(); i++ ){
		char ch = s[i];
		int index = ch - '0' ;// '3'-'0' -> 3 
		
		if( curr -> children[index] == NULL ){
			return false;
		}
		curr = curr -> children[index];
	}
	
	if ( curr!=NULL && curr->end == true) {
		 return true ;
	}
	else {
		return false;
	}
}

void insert(string s){
	if(root==NULL){
		root = createNode();
	}
	
	Trie *curr = root; 
	// 913
	for( int i=0;i<s.length(); i++ ){
		char ch = s[i];
		int index = ch - '0' ;// '3'-'0' -> 3 
		
		if( curr -> children[index] ==NULL ){
			curr -> children[index] = createNode();
		}else{
			//nothing to be done;
		}
		
		curr = curr -> children[index];
	}
	curr->end = true;	
}

int main(){
	
	string s[] = {"9876543210","9876543211","9876543213"};
	
	for(int i=0;i<3;i++){
		insert(s[i]);
	}
	
	cout<<"checking 9876543213  found : "<<search("9876543213")<<endl;	
	cout<<"checking 4327823487  found : "<<search("4327823487")<<endl;	
	cout<<"checking 9876543210  found : "<<search("9876543210")<<endl;	
		
	// save 
	//rocket,batman, mouse, touchmad, hasmap 	
	return 0;
}
