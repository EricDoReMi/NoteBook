// MyTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortTree.h"

int main(int argc, char* argv[])
{
	MyBTree<Monster>* pMyBTree=new MyBTree<Monster>();
	pMyBTree->PreOrderTraverse(pMyBTree->GetRoot());

	return 0;
}

