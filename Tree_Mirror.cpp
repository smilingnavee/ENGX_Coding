// Tree_Mirror.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

struct node *ROOT;
struct node *track_array[1001];
int arr[1001]={0};
int ind=0;
ofstream outfile;
/* swaps the nodes */
void mirror(struct node* node) 
{
  if (node==NULL) 
    return;  
  else
  {
    struct node* temp;
     
    /* do the subtrees */
    mirror(node->left);
    mirror(node->right);
 
    /* swap the pointers in this node */
    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
}

void inorderTraversal(struct node* root)
{
    if (root)
    {
        inorderTraversal( root->left );
		if(root->data!=-1) {
			cout<< root->data << "-";
			outfile<<root->data<<" ";
		}
        inorderTraversal( root->right );
    }
}

void insertInBinaryTree(int data) {
 struct node *temp, *ptr;
 temp = newNode(data);
 
 if (ROOT == NULL) {
  ROOT = temp;
  //printf("\n %d is added as root\n", temp->data);
  track_array[ind] = ROOT;
 } else {
  ptr = track_array[(int) (ind / 2)];
  if (ptr->left == NULL) {
   ptr->left = temp;
   //printf("\n %d is assigned as left child if %d\n", temp->data,ptr->data);
  } else {
   ptr->right = temp;
   //printf("\n %d is assigned as right child if %d\n", temp->data,ptr->data);
  }
  ind++;
  track_array[ind] = temp;
 }

}

int main()
{
	ifstream in("input.txt");

	if(!in) {
		cout << "Cannot open input file.\n";
		return 1;
	}
	string line;
	int left_child = 0, right_child =  0;
	char ch;
	
	int i =0;
	arr[i++] = 1;
	while(getline(in, line)) {
		istringstream iss(line);
		if (!(iss >> left_child >> right_child)) {
			cerr << "Input parsing error !!! - " << line << endl;
			break; // error
		}
		arr[i++]= left_child;
		arr[i++] = right_child;
	}
	for(int j = 0;j<1001;j++)
		//cout<<arr[j];
		insertInBinaryTree(arr[j]);

	cout<<endl;
	//cout<<"Before"<<endl;
	//inorderTraversal(ROOT);

	mirror(ROOT);
	//cout<<"After"<<endl;
	outfile.open("test.txt", ofstream::out|ofstream::app);
	inorderTraversal(ROOT);
	outfile.close();
	return 0;
}


