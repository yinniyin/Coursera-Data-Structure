/*
#include <iostream>
#include <stack>
#include <string>

struct Bracket 
{
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) 
	{
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() 
{
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
	int error_line = 0;
	bool unmatch = false;
    for (int position = 0; position < text.length(); ++position) 
	{
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') 
		{
            // Process opening bracket, write your code here
			Bracket b(next, position + 1);
			opening_brackets_stack.push(b);
        }

		if (next == ')' || next == ']' || next == '}')
		{
			// Process closing bracket, write your code here
			if (!opening_brackets_stack.empty())
			{
				Bracket top = opening_brackets_stack.top();
				if (top.Matchc(next))
				{
					opening_brackets_stack.pop();
				}
				else
				{
					error_line = position + 1;
					unmatch = true;
					break;
				}
			}
			else
			{
				error_line = position + 1;
				unmatch = true;
				break;
			}
		}
    }
	if (!opening_brackets_stack.empty() && !unmatch)
	{
		error_line = opening_brackets_stack.top().position;
	}

    // Printing answer, write your code here
	if (error_line != 0)
	{
		std::cout << error_line << std::endl;
	}
	else
	{
		std::cout << "Success" << std::endl;
	}
	system("pause");
    return 0;
}
*/