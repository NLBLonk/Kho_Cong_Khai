BSTDungCu Search(BSTDungCu root, KeyType x);
dungcu DeleteMin(BSTDungCu& root);
int DeleteNode(BSTDungCu& root, KeyType maDC);
BSTDungCu SearchByName(BSTDungCu root, const char* tenDC);


//Tim dung cu the thao khi biet ma dung cu
BSTDungCu Search(BSTDungCu root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maDC, x) == 0)
			return root;
		else
			if (strcmp(root->info.maDC, x) < 0)
				return Search(root->right, x);
			else
				return Search(root->left, x);
	}
	return NULL;
}

//Ham xoa nut nho nhat (nam ngoài cùng bên trái) tai vi tri root va thay the bang nut ben phai
dungcu DeleteMin(BSTDungCu& root)
{
	if (root->left == NULL)
	{
		dungcu x = root->info;
		root = root->right;
		return x;
	}
	else return DeleteMin(root->left);
}
//Ham xoa thong tin dung cu the thao voi ma dung cu
int DeleteNode(BSTDungCu& root, KeyType maDC)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maDC, maDC) == 0)
		{
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			else root->info = DeleteMin(root->right);
			return 1;
		}
		else if (_strcmpi(root->info.maDC, maDC) > 0)
			return DeleteNode(root->left, maDC);
		else return DeleteNode(root->right, maDC);
	}
	return 0;
}





