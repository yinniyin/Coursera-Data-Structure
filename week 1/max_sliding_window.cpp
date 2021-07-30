#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;

void max_sliding_window_naive(vector<int> const & A, int w) 
{
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

void max_sliding_window(vector<int> const & A, int w)
{
	if (w == 1)
	{
		for (int i : A)
		{
			cout << i << " ";
		}
		return;
	}
	deque<int> indeces;
	//first find the maximum index in the first window
	indeces.push_back(0);
	for (int i = 1; i < w; i++)
	{
		while (A[i] >= A[indeces.back()])
		{
			indeces.pop_back();
			if (indeces.size() == 0)
			{
				break;
			}
		}
		indeces.push_back(i);
	}
	cout << A[indeces.front()] << " ";
	//loop through the remaining sequence
	for (int i = w; i < A.size(); i++)
	{
		int start_id = i - w + 1;
		if (indeces.front() < start_id)
		{
			indeces.pop_front();
		}
		if (indeces.size() > 0)
		{
			while (A[indeces.back()] < A[i])
			{
				indeces.pop_back();
				if (indeces.size() == 0)
				{
					break;
				}
			}
		}
		indeces.push_back(i);
		cout << A[indeces.front()] << " ";
	}
	return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

	system("pause");
    return 0;
}
