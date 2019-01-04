#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;
//maybe a class is better
/////////// need to set //////////////////
unsigned int run_times = 300000;
int value_max = 60;
int value_min = 0;
unsigned int height = 9;
//////////////////////////////////////////

unsigned int h = 0;
auto n = value_max - value_min;
unsigned int tree_node_id = 0;
enum class TreeType
{
	BinaryTree,
	FullBinaryTree,
};
TreeType tree_type = TreeType::BinaryTree;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *root = new TreeNode(0);
void GenerateTree(TreeNode *p)
{
	if (h < height - 1)
		switch (rand() % 4)
		{
		case 1:
		{
			p->left = new TreeNode(rand() % n + value_min);
			h++;
			GenerateTree(p->left);
			break;
		}
		case 2:
		{
			p->right = new TreeNode(rand() % n + value_min);
			h++;
			GenerateTree(p->right);
			break;
		}
		case 0:
		{
		}
		case 3:
		{
			p->left = new TreeNode(rand() % n + value_min);
			h++;
			GenerateTree(p->left);
			p->right = new TreeNode(rand() % n + value_min);
			h++;
			GenerateTree(p->right);
			break;
		}
		}

	h--;
}

void PrintPicture(TreeNode *p, unsigned int parent_node_id, ostream &out)
{
	if (p == nullptr)
	{
		tree_node_id++;
		out << "Node" << tree_node_id << "[label = \"NULL\"];" << endl;
		out << "Node" << tree_node_id << "->Node" << parent_node_id << ";" << endl;
		return;
	}

	tree_node_id++;
	out << "Node" << tree_node_id << "[label = \"" << p->val << "\"];" << endl;
	out << "Node" << tree_node_id << "->Node" << parent_node_id << ";" << endl;
	auto self_id = tree_node_id;
	PrintPicture(p->left, self_id, out);
	PrintPicture(p->right, self_id, out);
}

int main()
{
	ofstream file_out("tree.dot");
	file_out << "digraph DAG{" << endl;
	file_out << "rankdir = BT;" << endl;
	file_out << "node[shape = box];" << endl;
	file_out << "edge[fontcolor = darkgreen];" << endl;

	srand(time(NULL));
	switch (tree_type)
	{
	case TreeType::BinaryTree:
	{
		if (height == 0)
		{
			root = nullptr;
			break;
		}
		root->val = rand() % n + value_min;
		GenerateTree(root);
		break;
	}
	case TreeType::FullBinaryTree:
	{
		break;
	}
	default:
	{
		cout << "error tree type" << endl;
		return -1;
	}
	}
	if (root != nullptr)
	{
		auto self_id = tree_node_id;
		file_out << "Node" << tree_node_id << "[label = \"" << root->val << "\"];" << endl;
		PrintPicture(root->left, self_id, file_out);
		PrintPicture(root->right, self_id, file_out);
	}
	else
	{
		cout << "root is null" << endl;
	}
	file_out << "}" << endl;

	return 0;
}
