#include<iostream>
#include<fstream>

int main() 
{
	std::ofstream output("hello.cait");
	output << "Caitlyn language";
	output.close();
	return 0;
}
