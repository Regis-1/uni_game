#ifndef TREE_HH
#define TREE_HH

#include <iostream>
#include <vector>

class Tree{
	private:
		Tree *parent;
		std::vector<Tree *> child;
		int id;
		//here goes the data
	public:
		Tree();
		Tree(Tree *parent, int id /*and data here*/);
		void insert_child(int id);
};

#endif
