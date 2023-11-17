//============================================================================
// Name        : DAA02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	char data;
	int freq;
	Node *left,*right;
	Node(char data,int freq){
		this->data=data;
		this->freq=freq;
		left=NULL;
		right=NULL;
	}
};
class Compare{
public:
	bool operator()(Node *a,Node *b){
		return a->freq > b->freq;
	}
};
void Display(Node *root,string s){
	if(root==NULL)return;
	if(root->data!='$')cout<<root->data<<" : "<<s<<endl;
	Display(root->left,s+"0");
	Display(root->right,s+"1");
}
void Huffman(char data[],int freq[],int size){
	Node *left,*right;
	priority_queue<Node*,vector<Node*>,Compare>pq;
	for(int i=0;i<size;i++){
		pq.push(new Node(data[i],freq[i]));
	}
	while(pq.empty()!=1){
		left=pq.top();
		pq.pop();
		right=pq.top();
		pq.pop();
		Node *temp=new Node('$',left->freq+right->freq);
		temp->right=right;
		temp->left=left;
		pq.push(temp);
	}
	Display(pq.top(),"");
}
int main() {
	char data[] = {'A', 'B', 'C', 'D'};
		int freq[] = {23, 12, 34, 10};
		Huffman(data, freq, 4);
	return 0;
}
