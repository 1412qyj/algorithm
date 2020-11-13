#include "../include/5MinDepth.h"

int MinDepth(TreeNode* root)
{
	int ret = 0;

	if (root->left == nullptr && root->right != nullptr)
	{
		ret = MinDepth(root->right)+1;
	}

	else if (root->right == nullptr && root->left != nullptr)
	{
		ret = MinDepth(root->left)+1;
	}

	else if (root->left != nullptr && root->right != nullptr)
	{
		ret = MIN(MinDepth(root->right), MinDepth(root->left)) + 1;
	}
	else if (root->left == nullptr && root->right == nullptr)
	{
		ret = 1;
	}

	return ret;

}


TreeNode * CreateTree5(int *data, int index, int size)
{
	TreeNode *pnode = nullptr;

	if (index > size || data[index] == -1)
		return nullptr;

	else
	{
		pnode = (TreeNode *)malloc(sizeof(TreeNode));

		pnode->val = data[index];
		pnode->left = CreateTree5(data, 2 * index + 1, size);
		pnode->right = CreateTree5(data, 2 * index + 2, size);
	}

	return pnode;
}

#ifdef PRINT
void prinTree(TreeNode *p_tree)
{
	if (p_tree != nullptr)
	{
		cout << p_tree->val << endl;

		prinTree(p_tree->left);

		prinTree(p_tree->right);
	}
}

#endif