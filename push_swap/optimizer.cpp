#include <iostream>
#include <string>

void	processOp(std::string& op, std::string& lastOp, std::string& lastA, std::string& lastB)
{
	if (op == "sa")
	{
		if (lastOp == "sa")
			std::cout << "Consecutive sa" << std::endl;
		if (lastOp == "sb")
			std::cout << "Can concatenate sa and sb" << std::endl;
		lastA = op;
	}
	else if (op == "sb")
	{
		if (lastOp == "sb")
			std::cout << "Consecutive sb" << std::endl;
		if (lastOp == "sa")
			std::cout << "Can concatenate sa and sb" << std::endl;
		lastB = op;
	}
	else if (op == "ra")
	{
		if (lastOp == "rra")
			std::cout << "Consecutive rra and ra" << std::endl;
		else if (lastA == "rra")
			std::cout << "Doing rra, modifiying only b, then doing ra" << std::endl;
		if (lastOp == "rb")
			std::cout << "Can concatenate ra and rb" << std::endl;
		lastA = op;
	}
	else if (op == "rb")
	{
		if (lastOp == "rrb")
			std::cout << "Consecutive rrb and rb" << std::endl;
		else if (lastB == "rrb")
			std::cout << "Doing rrb, modifiying only a, then doing rb" << std::endl;
		if (lastOp == "ra")
			std::cout << "Can concatenate ra and rb" << std::endl;
		lastB = op;
	}
	else if (op == "rra")
	{
		if (lastOp == "ra")
			std::cout << "Consecutive ra and rra" << std::endl;
		else if (lastA == "ra")
			std::cout << "Doing ra, modifiying only b, then doing rra" << std::endl;
		if (lastOp == "rrb")
			std::cout << "Can concatenate rra and rrb" << std::endl;
		lastA = op;
	}
	else if (op == "rrb")
	{
		if (lastOp == "rb")
			std::cout << "Consecutive rb and rrb" << std::endl;
		else if (lastB == "rb")
			std::cout << "Doing rb, modifiying only a, then doing rrb" << std::endl;
		if (lastOp == "rra")
			std::cout << "Can concatenate rra and rrb" << std::endl;
		lastB = op;
	}
	else if (op == "pa")
	{
		if (lastOp == "pb")
			std::cout << "Consecutive pb and pa" << std::endl;
		lastA = op;
		lastB = op;
	}
	else if (op == "pb")
	{
		if (lastOp == "pa")
			std::cout << "Consecutive pa and pb" << std::endl;
		lastA = op;
		lastB = op;
	}
}

int main()
{
	std::string op;
	std::string lastOp = "";
	std::string lastAOp = "";
	std::string lastBOp = "";

    while(std::getline(std::cin, op))
    {
        processOp(op, lastOp, lastAOp, lastBOp);
		lastOp = op;
    }
}