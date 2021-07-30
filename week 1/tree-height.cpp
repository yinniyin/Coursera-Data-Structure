/*
#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int get_max_height(Node* n, int prev_height)
{
	if (n->children.size() == 0)
	{
		return prev_height + 1;
	}
	//handle very long tree to avoid stack overflow
	if (n->children.size() == 1)
	{
		int curr_height = prev_height + 1;
		Node* next = n->children[0];
		while (next != NULL)
		{
			curr_height++;
			if (next->children.size() == 1)
			{
				next = next->children[0];
			}
			else if(next->children.size() > 1)
			{
				int height = get_max_height(next, curr_height - 1);
				curr_height = (height > curr_height) ? height : curr_height;
				break;
			}
			else
			{
				break;
			}
		}
		return curr_height;
	}
	int ret = prev_height + 1;
	for (Node* c : n->children)
	{
		if (c != NULL)
		{
			int height = get_max_height(c, prev_height + 1);
			ret = (height > ret) ? height : ret;
		}
	}
	return ret;
}


int main_with_large_stack_space() {
	std::ios_base::sync_with_stdio(0);
	int n;
	std::cin >> n;

	std::vector<Node> nodes;
	Node* pRoot = NULL;
	nodes.resize(n);
	for (int child_index = 0; child_index < n; child_index++) 
	{
		int parent_index;
		std::cin >> parent_index;
		if (parent_index >= 0)
		{
			nodes[child_index].setParent(&nodes[parent_index]);
		}
		else
		{
			pRoot = &(nodes[child_index]);
		}
		nodes[child_index].key = child_index;
	}
	int maxHeight = 0;
	if (pRoot)
	{
		maxHeight = get_max_height(pRoot, 0);
	}

	std::cout << maxHeight << std::endl;
	system("pause");
	return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
*/