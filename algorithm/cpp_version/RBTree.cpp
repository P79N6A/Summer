#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

template<class KEY, class U>
class RB_Tree
{
private:
	RB_Tree(const RB_Tree& input) {}
	const RB_Tree& operator=(const RB_Tree& input) {}
private:
	enum COLOR { RED, BLACK };
	class RB_Node
	{
	public:
		RB_Node()
		{
			//RB_COLOR = BLACK;
			right = NULL;
			left = NULL;
			parent = NULL;
		}
		COLOR RB_COLOR;
		RB_Node* right;
		RB_Node* left;
		RB_Node* parent;
		KEY key;
		U data;
	};
public:
	RB_Tree()
	{
		this->m_nullNode = new RB_Node();
		this->m_root = m_nullNode;
		this->m_nullNode->right = this->m_root;
		this->m_nullNode->left = this->m_root;
		this->m_nullNode->parent = this->m_root;
		this->m_nullNode->RB_COLOR = BLACK;
	}

	bool Empty()
	{
		if (this->m_root == this->m_nullNode)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//查找key
	RB_Node* find(KEY key)
	{
		RB_Node* index = m_root;
		while (index != m_nullNode)
		{
			if (key<index->key)
			{
				index = index->left;  //比当前的小，往左
			}
			else if (key>index->key)
			{
				index = index->right;  //比当前的大，往右
			}
			else
			{
				break;
			}
		}
		return index;
	}

	bool Insert(KEY key, U data)
	{
		RB_Node* insert_point = m_nullNode;
		RB_Node* index = m_root;
		while (index != m_nullNode)
		{
			insert_point = index;
			if (key<index->key)
			{
				index = index->left;
			}
			else if (key>index->key)
			{
				index = index->right;
			}
			else
			{
				return false;
			}
		}
		RB_Node* insert_node = new RB_Node();
		insert_node->key = key;
		insert_node->data = data;
		insert_node->RB_COLOR = RED;
		insert_node->right = m_nullNode;
		insert_node->left = m_nullNode;
		if (insert_point == m_nullNode) //如果插入的是一颗空树
		{
			m_root = insert_node;
			m_root->parent = m_nullNode;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
			m_nullNode->parent = m_root;
		}
		else
		{
			if (key<insert_point->key)
			{
				insert_point->left = insert_node;
			}
			else
			{
				insert_point->right = insert_node;
			}
			insert_node->parent = insert_point;
		}
		InsertFixUp(insert_node);    //调用InsertFixUp修复红黑树性质。
	}

	void InsertFixUp(RB_Node* node)
	{
		while (node->parent->RB_COLOR == RED)
		{
			if (node->parent == node->parent->parent->left)   //
			{
				RB_Node* uncle = node->parent->parent->right;
				if (uncle->RB_COLOR == RED)   //插入情况1，z的叔叔y是红色的。
				{
					node->parent->RB_COLOR = BLACK;
					uncle->RB_COLOR = BLACK;
					node->parent->parent->RB_COLOR = RED;
					node = node->parent->parent;
				}
				else if (uncle->RB_COLOR == BLACK)  //插入情况2：z的叔叔y是黑色的，。
				{
					if (node == node->parent->right) //且z是右孩子
					{
						node = node->parent;
						RotateLeft(node);
					}
					else                 //插入情况3：z的叔叔y是黑色的，但z是左孩子。
					{
						node->parent->RB_COLOR = BLACK;
						node->parent->parent->RB_COLOR = RED;
						RotateRight(node->parent->parent);
					}
				}
			}
			else //这部分是针对为插入情况1中，z的父亲现在作为祖父的右孩子了的情况，而写的。
				 //15 else (same as then clause with "right" and "left" exchanged)
			{
				RB_Node* uncle = node->parent->parent->left;
				if (uncle->RB_COLOR == RED)
				{
					node->parent->RB_COLOR = BLACK;
					uncle->RB_COLOR = BLACK;
					uncle->parent->RB_COLOR = RED;
					node = node->parent->parent;
				}
				else if (uncle->RB_COLOR == BLACK)
				{
					if (node == node->parent->left)
					{
						node = node->parent;
						RotateRight(node);     //与上述代码相比，左旋改为右旋
					}
					else
					{
						node->parent->RB_COLOR = BLACK;
						node->parent->parent->RB_COLOR = RED;
						RotateLeft(node->parent->parent);   //右旋改为左旋，即可。
					}
				}
			}
		}
		m_root->RB_COLOR = BLACK;
	}

	//左旋代码实现
	bool RotateLeft(RB_Node* node)
	{
		if (node == m_nullNode || node->right == m_nullNode)
		{
			return false;//can't rotate
		}
		RB_Node* lower_right = node->right;
		lower_right->parent = node->parent;
		node->right = lower_right->left;
		if (lower_right->left != m_nullNode)
		{
			lower_right->left->parent = node;
		}
		if (node->parent == m_nullNode) //rotate node is root
		{
			m_root = lower_right;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
			//m_nullNode->parent = m_root;
		}
		else
		{
			if (node == node->parent->left)
			{
				node->parent->left = lower_right;
			}
			else
			{
				node->parent->right = lower_right;
			}
		}
		node->parent = lower_right;
		lower_right->left = node;
	}

	//右旋代码实现
	bool RotateRight(RB_Node* node)
	{
		if (node == m_nullNode || node->left == m_nullNode)
		{
			return false;//can't rotate
		}
		RB_Node* lower_left = node->left;
		node->left = lower_left->right;
		lower_left->parent = node->parent;
		if (lower_left->right != m_nullNode)
		{
			lower_left->right->parent = node;
		}
		if (node->parent == m_nullNode) //node is root
		{
			m_root = lower_left;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
			//m_nullNode->parent = m_root;
		}
		else
		{
			if (node == node->parent->right)
			{
				node->parent->right = lower_left;
			}
			else
			{
				node->parent->left = lower_left;
			}
		}
		node->parent = lower_left;
		lower_left->right = node;
	}

	bool Delete(KEY key)
	{
		RB_Node* delete_point = find(key);
		if (delete_point == m_nullNode)
		{
			return false;
		}
		if (delete_point->left != m_nullNode && delete_point->right != m_nullNode)
		{
			RB_Node* successor = InOrderSuccessor(delete_point);
			delete_point->data = successor->data;
			delete_point->key = successor->key;
			delete_point = successor;
		}
		RB_Node* delete_point_child;
		if (delete_point->right != m_nullNode)
		{
			delete_point_child = delete_point->right;
		}
		else if (delete_point->left != m_nullNode)
		{
			delete_point_child = delete_point->left;
		}
		else
		{
			delete_point_child = m_nullNode;
		}
		delete_point_child->parent = delete_point->parent;
		if (delete_point->parent == m_nullNode)//delete root node
		{
			m_root = delete_point_child;
			m_nullNode->parent = m_root;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
		}
		else if (delete_point == delete_point->parent->right)
		{
			delete_point->parent->right = delete_point_child;
		}
		else
		{
			delete_point->parent->left = delete_point_child;
		}
		if (delete_point->RB_COLOR == BLACK && !(delete_point_child == m_nullNode && delete_point_child->parent == m_nullNode))
		{
			DeleteFixUp(delete_point_child);
		}
		delete delete_point;
		return true;
	}

	void DeleteFixUp(RB_Node* node)
	{
		while (node != m_root && node->RB_COLOR == BLACK)
		{
			if (node == node->parent->left)
			{
				RB_Node* brother = node->parent->right;
				if (brother->RB_COLOR == RED)   //情况1：x的兄弟w是红色的。
				{
					brother->RB_COLOR = BLACK;
					node->parent->RB_COLOR = RED;
					RotateLeft(node->parent);
				}
				else     //情况2：x的兄弟w是黑色的，
				{
					if (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK)
						//且w的俩个孩子都是黑色的。
					{
						brother->RB_COLOR = RED;
						node = node->parent;
					}
					else if (brother->right->RB_COLOR == BLACK)
						//情况3：x的兄弟w是黑色的，w的右孩子是黑色（w的左孩子是红色）。
					{
						brother->RB_COLOR = RED;
						brother->left->RB_COLOR = BLACK;
						RotateRight(brother);
					}
					else if (brother->right->RB_COLOR == RED)
						//情况4：x的兄弟w是黑色的，且w的右孩子时红色的。
					{
						brother->RB_COLOR = node->parent->RB_COLOR;
						node->parent->RB_COLOR = BLACK;
						brother->right->RB_COLOR = BLACK;
						RotateLeft(node->parent);
						node = m_root;
					}
				}
			}
			else  //下述情况针对上面的情况1中，node作为右孩子而阐述的。
				  //22        else (same as then clause with "right" and "left" exchanged)
				  //同样，原理一致，只是遇到左旋改为右旋，遇到右旋改为左旋，即可。其它代码不变。
			{
				RB_Node* brother = node->parent->left;
				if (brother->RB_COLOR == RED)
				{
					brother->RB_COLOR = BLACK;
					node->parent->RB_COLOR = RED;
					RotateRight(node->parent);
				}
				else
				{
					if (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK)
					{
						brother->RB_COLOR = RED;
						node = node->parent;
					}
					else if (brother->left->RB_COLOR == BLACK)
					{
						brother->RB_COLOR = RED;
						brother->right->RB_COLOR = BLACK;
						RotateLeft(brother);
					}
					else if (brother->left->RB_COLOR == RED)
					{
						brother->RB_COLOR = node->parent->RB_COLOR;
						node->parent->RB_COLOR = BLACK;
						brother->left->RB_COLOR = BLACK;
						RotateRight(node->parent);
						node = m_root;
					}
				}
			}
		}
		m_nullNode->parent = m_root;   //最后将node置为根结点，
		node->RB_COLOR = BLACK;    //并改为黑色。
	}

	//
	inline RB_Node* InOrderPredecessor(RB_Node* node)
	{
		if (node == m_nullNode)       //null node has no predecessor
		{
			return m_nullNode;
		}
		RB_Node* result = node->left;     //get node's left child
		while (result != m_nullNode)         //try to find node's left subtree's right most node
		{
			if (result->right != m_nullNode)
			{
				result = result->right;
			}
			else
			{
				break;
			}
		}            //after while loop result==null or result's right child is null
		if (result == m_nullNode)
		{
			RB_Node* index = node->parent;
			result = node;
			while (index != m_nullNode && result == index->left)
			{
				result = index;
				index = index->parent;
			}
			result = index;         // first right parent or null
		}
		return result;
	}

	//
	inline RB_Node* InOrderSuccessor(RB_Node* node)
	{
		if (node == m_nullNode)       //null node has no successor
		{
			return m_nullNode;
		}
		RB_Node* result = node->right;   //get node's right node
		while (result != m_nullNode)        //try to find node's right subtree's left most node
		{
			if (result->left != m_nullNode)
			{
				result = result->left;
			}
			else
			{
				break;
			}
		}                              //after while loop result==null or result's left child is null
		if (result == m_nullNode)
		{
			RB_Node* index = node->parent;
			result = node;
			while (index != m_nullNode && result == index->right)
			{
				result = index;
				index = index->parent;
			}
			result = index;         //first parent's left or null
		}
		return result;
	}

	//debug
	void InOrderTraverse()
	{
		cout << "中序遍历序列：";
		InOrderTraverseCore(m_root);
		cout << endl;
	}
	void PreOrderTraverse()
	{
		cout << "先序遍历序列：";
		PreOrderTraverseCore(m_root);
		cout << endl;
	}
	void CreateGraph(string filename)
	{
		//delete
	}
	void InOrderCreate(ofstream& file, RB_Node* node)
	{
		//delete
	}
	void InOrderTraverseCore(RB_Node* node)
	{
		if (node == m_nullNode)
		{
			return;
		}
		else
		{
			InOrderTraverseCore(node->left);
			if (node->RB_COLOR == RED) 
			{
				cout << node->key <<"(R) ";
			}
			else
			{
				cout << node->key <<"(B) ";
			}
			InOrderTraverseCore(node->right);
		}
	}
	void PreOrderTraverseCore(RB_Node* node)
	{
		if (node == m_nullNode)
		{
			return;
		}
		else
		{
			if (node->RB_COLOR == RED)
			{
				cout << node->key <<"(R) ";
			}
			else
			{
				cout << node->key <<"(B) ";
			}
			PreOrderTraverseCore(node->left);
			PreOrderTraverseCore(node->right);
		}
	}
	~RB_Tree()
	{
		clear(m_root);
		delete m_nullNode;
	}
private:
	// utility function for destructor to destruct object;
	void clear(RB_Node* node)
	{
		if (node == m_nullNode)
		{
			return;
		}
		else
		{
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}
private:
	RB_Node *m_nullNode;
	RB_Node *m_root;
};


//以下是红黑树的测试入口
void TestRBTree()
{
	cout << "红黑树测试" << endl;
	RB_Tree<int, int> tree;
	vector<int> v;

	for (int i = 0; i<20; ++i)
	{
		v.push_back(i);
	}
	for (int i = 0; i<20; ++i)
	{
		tree.Insert(v[i], i);
		cout << "insert:" << v[i] << endl;//添加结点
		tree.PreOrderTraverse();
		tree.InOrderTraverse();
	}
	for (int i = 0; i<20; ++i)
	{
		cout << "Delete:" << v[i] << endl;
		tree.Delete(v[i]);//删除结点
		tree.PreOrderTraverse();
		tree.InOrderTraverse();
	}
}