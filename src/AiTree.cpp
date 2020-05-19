#include "../include/AiTree.hh"

AiTree::AiTree(){
	this->parent = NULL;
	this->id = 0;
}

AiTree::AiTree(AiTree *parent, int id){
	this->parent = parent;
	this->id = id;
}

void AiTree::insert_child(int id){
	AiTree *child = new AiTree(this,id);
	this->child.push_back(child);
}
