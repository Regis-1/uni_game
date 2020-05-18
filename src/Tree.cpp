#include "../include/Tree.hh"

Tree::Tree(){
	this->parent = NULL;
	this->id = 0;
}

Tree::Tree(Tree *parent, int id){
	this->parent = parent;
	this->id = id;
}

void Tree::insert_child(int id){
	Tree *child = new Tree(this,id);
	this->child.push_back(child);
}
