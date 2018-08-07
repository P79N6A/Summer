#include <iostream>
#include <vector>
using namespace std;

template <typename Comparable>
class AVLTree
{

public:
	typedef enum _order { PREORDER, INORDER, POSTORDER } ORDER; // ͨ��enum���峣��  

public:
	AVLTree() :m_root(nullptr) {}
	AVLTree(const AVLTree &rhs)
	{
		m_root = clone(rhs.m_root);
	}
	~AVLTree()
	{
		makeEmpty();
	}

	/**
	* �������ĸ߶ȡ������ĸ߶ȶ���Ϊ-1
	*/
	int getHeight() const
	{
		return m_root.height;
	}

	/**
	* �ҵ����е���Сֵ��ͨ������private��findMinʵ�ֵݹ�
	*/
	const Comparable & findMin() const
	{
		return findMin(m_root)->element;
	}

	/**
	* �ҵ����е����ֵ��ͨ������private��findMaxʵ�ֵݹ�
	*/
	const Comparable & findMax() const
	{
		return findMax(m_root)->element;
	}

	/**
	* ��x�ҵ�ʱ�����棬���򷵻ؼ�
	* ������private���Ǹ�ͬ�������������Ϊ�˵ݹ�ʵ��
	*����Ϊprivate�а�����һ��AVLNode��ָ��t��
	*/
	bool contains(const Comparable &x) const
	{
		return contains(x, m_root);
	}

	/**
	* �ж����Ƿ�Ϊ��
	*/
	bool isEmpty() const
	{
		return  nullptr == m_root;
	}

	/**
	* ��������һ�飨˳������Լ�ѡ��Ĭ��Ϊ����
	*/
	void printTree(ORDER or = INORDER, ostream & out = cout) const
	{
		if (isEmpty())
			out << "Empty tree!" << endl;
		else
		{
			switch (or )
			{
			case PREORDER:
				preOrder(m_root, cout);
				cout << endl;
				break;
			case INORDER:
				inOrder(m_root, cout);
				cout << endl;
				break;
			case POSTORDER:
				postOrder(m_root, cout);
				cout << endl;
				break;
			default:
				cerr << "��ӡ����˳��ֻ��ΪPREORDER, INORDER, POSTORDER!" << endl;
				break;
			}
		}
	}

	/**
	* �����
	*/
	void makeEmpty()
	{
		makeEmpty(m_root);
	}

	/**
	* ��x�������У�����ظ��˾ͺ���
	*/
	void insert(const Comparable &x)
	{
		insert(x, m_root);
	}

	/**
	* ��x������ɾ�������x�������о�ʲô��������
	*/
	void remove(const Comparable &x)
	{
		remove(x, m_root);
	}

	/**
	* ���
	*/
	const AVLTree & operator= (const AVLTree &rhs)
	{
		if (this != &rhs)
		{
			AVLNode *tmp = clone(rhs.m_root);
			makeEmpty();
			m_root = tmp;
		}
		return *this;
	}


private:
	struct AVLNode {
		Comparable element;
		AVLNode *left;
		AVLNode *right;
		int height;

		AVLNode(const Comparable &theElement,
			AVLNode *lt,
			AVLNode *rt,
			int h = 0)
			: element(theElement), left(lt), right(rt), height(h) {}
	};

	AVLNode *m_root; // ���ڵ�  
	static const int ALLOW_IMBALANCE = 1; // ����ʵʩƽ��ĸ߶Ƚ���  

										  /**
										  * ���ڱȽ��������Ĵ�С����Ҫ���ڱȽϸ߶ȣ�
										  */
	int max(int a, int b)
	{
		return a >= b ? a : b;
	}

	/**
	* ��ýڵ�߶�,�����ĸ߶�Ϊ-1
	*/
	inline int height(AVLNode *t) const
	{
		return nullptr == t ? -1 : t->height;
	}

	/**
	* ����t�в���Ԫ��x������ظ���ʲôҲ����
	*/
	void insert(const Comparable &x, AVLNode * &t);

	/**
	* ����t��ɾ��Ԫ��x
	*/
	void remove(const Comparable &x, AVLNode * &t);


	/**
	* ������С��Ԫ��, ͨ���ݹ�ķ���
	*/
	AVLNode * findMin(AVLNode *t) const;


	/**
	* ��������Ԫ��, ͨ��ѭ���ķ���
	*/
	AVLNode * findMax(AVLNode *t) const;

	/**
	* ͨ�������ķ�������x�Ƿ���������������t��
	*/
	bool contains(const Comparable &x, AVLNode * t) const;

	/**
	* �����
	*/
	void makeEmpty(AVLNode * &t);

	/**
	* ��ǰ���ӡ����
	*/

	void preOrder(AVLNode *t, ostream & out) const;
	/**
	* �������ӡ����
	*/

	void inOrder(AVLNode *t, ostream & out) const;
	/**
	* �������ӡ����
	*/
	void postOrder(AVLNode *t, ostream & out) const;

	/**
	* ��������
	*/
	AVLNode * clone(AVLNode *t) const;

	/**
	* ƽ������
	*/
	void balance(AVLNode * &t);

	/**
	* ����������������������2�������²����Ԫ�������������ұߣ�
	* ��ʱ��������(k1)Ϊ�ᣬ���ĸ�(k2)��������
	* �������Ϊ���ĸ���������ߣ������������������ת��
	*      K2                           K1
	*     /  \                         /  \
	*    X    k1         -----        K2   Z
	*         / \                    /  \   \
	*        Y   Z                  X    Y   Z'
	*             \
	*              Z'
	* Z'������Z����ߣ�Ҳ������Z���ұߡ������м������ұߡ�
	**/
	void rotateWithRightChild(AVLNode * & k2);

	/**
	* ����������������������2�������²����Ԫ��������������ߣ�
	* ��ʱ����������k1��Ϊ�ᣬ���ĸ���k2����������
	* �������Ϊ���ĸ��������ұߣ��������������ұ���ת��
	*       k2                      k1
	*      /  \                    /  \
	*     k1   Z      -------     X    k2
	*    /  \                    /     / \
	*   X    Y                  X'     Y   Z
	*  /
	* X'
	* X'������X����ߣ�Ҳ������X���ұߡ������м�������ߡ�
	*/
	void rotateWithLeftChild(AVLNode * & k2);

	/**
	* ����˫����������K1��������D��2�������²����Ԫ����������K1���ұ�K2��
	* ��һ������������k1����һ������(��Ϊk2)
	* �ڶ�������������k3����һ����������Ϊk2��
	*       k3                k3              k2
	*      /  \              /  \            /  \
	*     k1   D    ----    k2   D  ----    k1   k3
	*    / \               / \             / \   / \
	*   A   k2            k1  C           A   B  C  D
	*       / \          / \
	*      B   C        A   B
	*/
	void doubleWithLeftChild(AVLNode * & k3);

	/**
	* ����˫����������K1��������A��2�������²����Ԫ����������K1�����K2��
	* ��һ������������k1����һ����������Ϊk2��
	* �ڶ�������������k3����һ����������Ϊk2��
	*      k3              k3                 k2
	*     /  \            /  \               /  \
	*    A    k1   ----  A    k2     ----  k3    k1
	*        / \             /  \         /  \  /  \
	*       K2  D           B    k1      A    B C   D
	*      / \                  /  \
	*     B   C                C    D
	*/
	void doubleWithRightChild(AVLNode * & k3);

	/**
	* ���½ڵ�ĸ߶�
	*/
	inline void updateHeight(AVLNode * & t)
	{
		t->height = max(height(t->left), height(t->right)) + 1;
	}

};


/**
* ��������
*/
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode *
AVLTree<Comparable>::clone(
	typename AVLTree<Comparable>::AVLNode *t) const
{
	if (t == nullptr)
		return nullptr;

	return new AVLNode(t->element, clone(t->left), clone(t->right));
}

/**
* ��ǰ���ӡ����
*/
template <typename Comparable>
void AVLTree<Comparable>::preOrder(
	typename AVLTree<Comparable>::AVLNode*t,
	ostream & out) const
{
	if (nullptr != t)
	{
		out << t->element << " ";
		preOrder(t->left, out);
		preOrder(t->right, out);
	}
}



/**
* �������ӡ����
*/
template <typename Comparable>
void AVLTree<Comparable>::inOrder(
	typename AVLTree<Comparable>::AVLNode *t,
	ostream & out) const
{
	if (nullptr != t)
	{
		inOrder(t->left, out);
		out << t->element << " ";
		inOrder(t->right, out);
	}
}

/**
* �������ӡ����
*/
template <typename Comparable>
void AVLTree<Comparable>::postOrder(
	typename AVLTree<Comparable>::AVLNode*t,
	ostream & out) const
{

	if (nullptr != t)
	{
		postOrder(t->left, out);
		postOrder(t->right, out);
		out << t->element << " ";
	}
}


/**
* �����
*/
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(
	typename AVLTree<Comparable>::AVLNode * &t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

/**
* ������С��Ԫ��, ͨ���ݹ�ķ���
*/
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode *
AVLTree<Comparable>::findMin(
	typename AVLTree<Comparable>::AVLNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

/**
* ��������Ԫ��, ͨ��ѭ���ķ���
*/
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode *
AVLTree<Comparable>::findMax(
	typename AVLTree<Comparable>::AVLNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

/**
* ����t��ɾ��Ԫ��x,һ��Ҫ��Ҫ��������ƽ��
*/
template <typename Comparable>
void AVLTree<Comparable>::remove(
	const Comparable &x,
	typename AVLTree<Comparable>::AVLNode * &t)
{
	if (t == nullptr)
		return; // û����Ҫɾ���Ľڵ�x  

	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr &&
		t->right != nullptr)
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		//typename AVLTree<Comparable>::AVLNode * oldNode = t;  
		auto oldNode = t; // ��һ�����������ǳ�������䣬���Կ���C++11�е�auto���Ƿǳ����� ��  
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}

	balance(t);
}

/**
* ����t�в���Ԫ��x������ظ���ʲôҲ����
*/
template <typename Comparable>
void AVLTree<Comparable>::insert(
	const Comparable &x,
	typename AVLTree<Comparable>::AVLNode * &t)
{
	if (nullptr == t)
		t = new AVLNode(x, nullptr, nullptr);
	else if (x < t->element)
	{
		insert(x, t->left); // ����������ֵС��Ŀǰ�Ľڵ㣬�������������  
							/*
							if (height(t->left) - height(t->right) == 2) // ���������ڵ������������������2
							{
							if (x < t->left->element)
							rotateWithLeftChild(t); // ����
							else
							doubleWithLeftChild(t); // ��-��˫��
							}
							*/

	}
	else if (t->element < x)
	{
		insert(x, t->right);// ����������ֵ����Ŀǰ�Ľڵ㣬�������������  
							/*
							if (height(t->right) - height(t->left) == 2)// ���������ڵ������������������2
							{
							if (t->right->element < x)
							rotateWithRightChild(t); // ����
							else
							doubleWithRightChild(t); // ��-��˫��
							}
							*/

	}
	else
		; // ��ʾ�������ҵ���x����ʲôҲ����  

	balance(t); // ÿ����ɲ��붼��������Ƿ�ƽ�⣨����Ĭ�ϸ��½ڵ�t�ĸ߶ȣ�  
}

/**
* ƽ������
*/
template <typename Comparable>
void AVLTree<Comparable>::balance(
	typename AVLTree<Comparable>::AVLNode * &t)
{
	if (nullptr == t)
		return;
	// ����������ĸ߶����������߶Ȳ����ʵʩƽ��������޶�  
	if (height(t->left) - height(t->right) > AVLTree<Comparable>::ALLOW_IMBALANCE)
	{
		// �ж�������������߸߻����ұ߸ߣ������������߸�  
		if (height(t->left->left) >= height(t->left->right))
		{
			rotateWithLeftChild(t);
		}
		else
		{
			doubleWithLeftChild(t);
		}

	}
	// ����������ĸ߶����������߶Ȳ����ʵʩƽ��������޶�  
	else if (height(t->right) - height(t->left) > AVLTree<Comparable>::ALLOW_IMBALANCE)
	{
		if (height(t->right->right) >= height(t->right->left))
		{
			rotateWithRightChild(t);
		}
		else
		{
			doubleWithRightChild(t);
		}
	}
	else
		;

	updateHeight(t);
}

/**
* ͨ�������ķ�������x�Ƿ���������������t��
*/
template <typename Comparable>
bool AVLTree<Comparable>::contains(
	const Comparable &x,
	typename AVLTree<Comparable>::AVLNode * t) const
{
	if (t == nullptr) // ������δ�ҵ�Ԫ�ص���ֹ����  
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else // ��� x ������ Ҳ ��С��t��ָ�Ľڵ��е�Ԫ�أ���x==t->element  
		return true;
}

/**
* ����������������������2�������²����Ԫ��������������ߣ�
* ��ʱ����������k1��Ϊ�ᣬ���ĸ���k2����������
* �������Ϊ���ĸ��������ұߣ��������������ұ���ת��
*       k2                      k1
*      /  \                    /  \
*     k1   Z      -------     X    k2
*    /  \                    /     / \
*   X    Y                  X'     Y   Z
*  /
* X'
* X'������X����ߣ�Ҳ������X���ұߡ������м�������ߡ�
*/
template <typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(
	typename AVLTree<Comparable>::AVLNode * & k2)
{
	//typename AVLTree<Comparable>::AVLNode * k1 = k2->left; // ���k2����ڵ�  
	auto k1 = k2->left; // ʹ��auto����  
						// ��ʼ��ת  
	k2->left = k1->right;
	k1->right = k2;
	//���¸߶�, �ȸ���k2���ԣ�����k1ʱ����һ��height�����ĵ���  
	k2->height = max(height(k2->left), height(k2->right)) + 1;//�ȼ���updateHeight(k2)  
	k1->height = max(height(k1->left), k2->height) + 1;

	k2 = k1;

}

/**
* ����������������������2�������²����Ԫ�������������ұߣ�
* ��ʱ��������(k1)Ϊ�ᣬ���ĸ�(k2)��������
* �������Ϊ���ĸ���������ߣ������������������ת��
*      K2                           K1
*     /  \                         /  \
*    X    k1         -----        K2   Z
*         / \                    /  \   \
*        Y   Z                  X    Y   Z'
*             \
*              Z'
* Z'������Z����ߣ�Ҳ������Z���ұߡ������м������ұߡ�
**/
template <typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(
	typename AVLTree<Comparable>::AVLNode * & k2)
{
	//typename AVLTree<Comparable>::AVLNode * k1 = k2->right;  
	auto k1 = k2->right; // ʹ��auto����  
						 // ��ʼ��ת  
	k2->right = k1->left;
	k1->left = k2;
	//���¸߶�, �ȸ���k2���Լ���һ��height�����ĵ���  
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(k2->height, height(k1->right)) + 1;

	k2 = k1;
}

/**
* ����˫����������K1��������D��2�������²����Ԫ����������K1���ұ�K2��
* ��һ������������k1����һ������(��Ϊk2)
* �ڶ�������������k3����һ����������Ϊk2��
*       k3                k3              k2
*      /  \              /  \            /  \
*     k1   D    ----    k2   D  ----    k1   k3
*    / \               / \             / \   / \
*   A   k2            k1  C           A   B  C  D
*       / \          / \
*      B   C        A   B
* ע��һ����˵��ֻ����B��Cһ�����ڣ��ͻ��������ƽ�����
*/
template <typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(
	typename AVLTree<Comparable>::AVLNode * & k3)
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}


/**
* ����˫����������K1��������A��2�������²����Ԫ����������K1�����K2��
* ��һ������������k1����һ����������Ϊk2��
* �ڶ�������������k3����һ����������Ϊk2��
*      k3              k3                 k2
*     /  \            /  \               /  \
*    A    k1   ----  A    k2     ----  k3    k1
*        / \             /  \         /  \  /  \
*       K2  D           B    k1      A    B C   D
*      / \                  /  \
*     B   C                C    D
*ע��һ����˵��ֻ����B��Cһ�����ڣ��ͻ��������ƽ�����
*/
template <typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(
	typename AVLTree<Comparable>::AVLNode * & k3)
{
	rotateWithLeftChild(k3->right);
	rotateWithRightChild(k3);
}

//������AVL���Ĳ������
void TestAVLTree()
{
	cout << "AVL������" << endl;
	AVLTree<int> tree;
	vector<int> v;

	for (int i = 0; i<20; ++i)
	{
		v.push_back(i);
	}
	for (int i = 0; i<20; ++i)
	{
		tree.insert(v[i]);
		cout << "insert:" << v[i] << endl;//��ӽ��
		tree.printTree(tree.PREORDER);
		tree.printTree(tree.INORDER);
	}
	for (int i = 0; i<20; ++i)
	{
		cout << "Delete:" << v[i] << endl;
		tree.remove(v[i]);//ɾ�����
		tree.printTree(tree.PREORDER);
		tree.printTree(tree.INORDER);
	}
}