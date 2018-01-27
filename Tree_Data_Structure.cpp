#include <iostream>
using namespace std;

struct list{
	int data;
	list* next;
};

typedef list* nodePtr;

struct tree{
	int data;
	tree* left;
	tree* right;
};

typedef tree* treePtr;

int countSubnodes(treeptr root, int value, bool enable);
void ConstructTree(treePtr& root, int value);
void PrintTree(treePtr root);
void DeleteFromTree(treePtr& root, int value);
int FindHeightTree(treePtr root, int value); //maximun depth of tree is another suitable name for this function
int FindDepthNode(treePtr root,int value);
int FindBalanceFactor(treePtr root,int value);
void FindMax(treePtr root,int& max); //no sorting assumed INITIALIZE variable max
void FindMin(treePtr root,int& min); //no sorting assumed INITIALIZE variable min
treePtr FindMaxOrdered(treePtr root); //sorted tree needed
treePtr FindMinOrdered(treePtr root); //sorted tree needed
int CountNodes(treePtr root);
int sumTree(treePtr root);
treePtr LeftRotation(treePtr root);
treePtr RightRotation(treePtr root);
int CountLeafNodes(treePtr root);
int countEvenNodes(treePtr root);
int twoChildNodes(treePtr root);
int oneChildNodes(treePtr root);
void CopyTreeToLinkedList(treePtr root, nodePtr& hdList);
int FindMaxOnlySmart(nodeptr root);
void deallocate_tree(node root);
void nodeDepth(treeptr root,int currDepth,int& nodedepths,int data); //initialize to -1 the variables
void heightoftree(treeptr root,int currDepth,int& nodedepths); //initialize to -1 the variables
void printsubtrees(treeptr root,bool enable,int value);



void printsubtrees(treeptr root,bool enable,int value){
	if(root==NULL){
		return;
	}
	if(enable){
		cout << root->data << endl;
	}
	if(root->data==value){
		enable = true;
	}
	printsubtrees(root->left,enable,value);
	printsubtrees(root->right,enable,value);
}

void heightoftree(treeptr root,int currDepth,int& nodedepths){
	if(root!=NULL){
		currDepth++;
		heightoftree(root->left,currDepth,nodedepths);
		if(currDepth > nodedepths){
			nodedepths = currDepth;
		}
		heightoftree(root->right,currDepth,nodedepths);
	}
}

void deallocate_tree(node root){
	if(root!=NULL){
		deallocate_tree(root->left);
		deallocate_tree(root->right);
		delete root;
	}
}


void nodeDepth(treeptr root,int currDepth,int& nodedepths,int data){
	if(root!=NULL){
		currDepth++;
		nodeDepth(root->left,currDepth,nodedepths,data);
		if(data == root->data){
			nodedepths = currDepth;
		}
		nodeDepth(root->right,currDepth,nodedepths,data);
	}
}

int oneChildNodes(treePtr root){
	int count;
	if(root==NULL){
		return 0;
	}
	else if((root->left!=NULL && root->right==NULL) || (root->left==NULL && root->right!=NULL)){
		count = 1;
	}
	else {
		count = 0;
	}
	return oneChildNodes(root->left) + oneChildNodes(root->right) + count;
}


void CopyTreeToLinkedList(treePtr root,nodePtr& hdList){
	if(root==NULL){
		return;
	}
	else{
		nodePtr temp = new list;
		temp->data = root->data;
		temp->next = hdList;
		hdList = temp;
		CopyTreeToLinkedList(root->left,hdList);
		CopyTreeToLinkedList(root->right,hdList);
	}
}



int twoChildNodes(treePtr root){
	int count;
	if(root==NULL){
		return 0;
	}
	else if(root->left!=NULL && root->right!=NULL){
		count = 1;
	}
	else {
		count = 0;
	}
	return twoChildNodes(root->left) + twoChildNodes(root->right) + count;
}

treePtr RightRotation(treePtr root){
	treePtr temp = root->left;
	root->left = (root->left)->right;
	temp->right = root;
	return temp;
}

treePtr LeftRotation(treePtr root){
	treePtr temp = root->right;
	root->right = (root->right)->left;
	temp->left = root;
	return temp;
}


int sumTree(treePtr root){
	if(root == NULL){
		return 0;
	}
	return sumTree(root->left) + sumTree(root->right) + root->data;
}


int countSubnodes(treeptr root, int value, bool enable){
	int count;
	if(root==NULL){
		return 0;
	}
	if(enable){
		count = 1;
	}
	else{
		count = 0;
	}
	if(root->data == value){
		enable = true;
	}
	return countSubnodes(root->left,value,enable) + countSubnodes(root->right,value,enable) + count;
}


int countEvenNodes(treePtr root){
	int count;
	if(root == NULL){
		return 0;
	}
	else if(root->data % 2 == 0){
		count = 1;
	}
	else {
		count = 0;
	}
	count+=countEvenNodes(root->left);
	count+=countEvenNodes(root->right);
	return count;
}

treePtr FindMinOrdered(treePtr root){
	if(root->left==NULL){
			return root;
	}
	else{
		FindMinOrdered(root->left);
	}
}

treePtr FindMaxOrdered(treePtr root){
	if(root->right==NULL){
		return root;
	}
	else{
		FindMaxOrdered(root->right);
	}
}

int CountLeafNodes(treePtr root){
	if(root==NULL){
		return 0;
	}
	else if(root->left==NULL && root->right==NULL){
		return 1;
	}
	else{
		return countLeafNodes(root->left) + countLeafNodes(root->right);
	}
}

int CountNodes(treePtr root){
	int count;
	if(root == NULL){
		return 0;
	}
	else{
		count = 1;
		count+=countNodes(root->left);
		count+=countNodes(root->right);
	}
	return count;
}

void FindMax(treePtr root, int& max){
	if(root==NULL){
		return;
	}
	FindMax(root->left,max);
	if(root->data > max){
		max = root->data;
	}
	FindMax(root->right,max);
}

void FindMin(treePtr root, int& min){
	if(root==NULL){
		return;
	}
	FindMin(root->left,min);
	if(root->data < min){
		min = root->data;
	}
	FindMin(root->right,min);
}

void ConstructTree(treePtr& root,int value){
	if(root == NULL){
		root = new node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	else if(root->data > value){
		ConstructTree(root->left,value);
	}
	else{
		ConstructTree(root->right,value);
	}
}

void PrintTree(treePtr root){
	if(root==NULL){
		return;
	}
	else{
		PrintTree(root->left);
		cout << root->data << " ";
		PrintTree(root->right);
	}
}

void DeleteFromTree(treePtr& root, int value){
	if(root==NULL){
		return;
	}
	else if(root->left==NULL && root->right==NULL && root->data==value){
		treePtr temp = root;
		root = NULL;
		delete temp;
		return;
	}
	else if(root->data == value && root->left!=NULL && root->right==NULL){
		treePtr temp = root;
		root = root->left;
		delete temp;
		DeleteFromTree(root,value);
	}
	else if(root->data == value && root->right!=NULL && root->left==NULL){
		treePtr temp = root;
		root = root->right;
		delete temp;
		DeleteFromTree(root,value);
	}
	else if(root->data==value && root->left!=NULL && root->right!=NULL){
		treePtr temp = FindMin(root->right);
    	root->data = temp->data;
    	DeleteFromTree(root->right, temp->data);
	}
	else if(root->data > value){
		DeleteFromTree(root->left,value);
	}
	else{
		DeleteFromTree(root->right,value);
	}
}

int FindDepthNode(treePtr root,int value){
	int L,R = -1;
	if(root->data==value){
		return -1;
	}
	if(root->left!=NULL){
		L = FindDepthNode(root->left,value);
	}
	else if(root->right!=NULL){
		R = FindDepthNode(root->right,value);
	}
	if(L>R){
		return L+1;
	}
	else{
		return R+1;
	}
}

int FindHeightTree(treePtr root){
	int L,R = -1;
	if(root==NULL){
		return -1;
	}
	if(root->left!=NULL){
		L = FindHeightTree(root->left);
	}
	else if(root->right!=NULL){
		R = FindHeightTree(root->right);
	}
	if(L>R){
		return L+1;
	}
	else{
		return R+1;
	}
}


int FindBalanceFactor(treePtr root,int value){
	return heightoftree(root->right,currDepth,nodeDepths) - heightoftree(root->left,currDepth,nodeDepths);
	}

int FindMaxSmart(nodeptr root){
	int max = -1;
	if(root==NULL){
		return max;
	}
	else{
		int left = FindMax(root->left);
		max = root->data;
		int right = FindMax(root->right;)
	}
	if(left > max){
		max = left;
	}
	if(right > max){
		max = right;
	}
	return max;
}
