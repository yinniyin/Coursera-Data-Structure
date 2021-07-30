/*
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
	vector<int> max; //store the max up to that index
	int curr_max = 0;
  public:

    void Push(int value) {
        stack.push_back(value);
		if (value > curr_max)
		{
			curr_max = value;
		}
		max.push_back(curr_max);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        //return *max_element(stack.begin(), stack.end());
		return max[stack.size() - 1];
    }
};

int main() 
{
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
	system("pause");
    return 0;
}
*/