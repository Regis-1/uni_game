#ifndef AITREE_HH
#define AITREE_HH

#include <iostream>
#include <vector>

class AiTree{
	private:
		AiTree *parent;
		std::vector<AiTree *> child;
		int id;
		//here goes the data
	public:
		AiTree();
		AiTree(AiTree *parent, int id /*and data here*/);
		void insert_child(int id);
};

#endif
