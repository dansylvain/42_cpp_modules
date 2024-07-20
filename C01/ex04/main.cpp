#include <iostream>
#include <fstream>

std::string replaceAllOccurrences(const std::string& str, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        return str; // Avoid infinite loop if s1 is empty
    }

    std::string result;
    size_t pos = 0;
    size_t prev_pos = 0;

    while ((pos = str.find(s1, prev_pos)) != std::string::npos) {
		std::cout << "pos: " << pos << std::endl;
        result.append(str.substr(prev_pos, pos - prev_pos)); // Append part before s1
        result.append(s2); // Append s2 instead of s1
        prev_pos = pos + s1.length(); // Move past the occurrence of s1
    }

    result.append(str.substr(prev_pos)); // Append the remainder of the string
    return result;
}

int main( int argc, char **argv )
{
	std::string line;
	std::string srcFile;
	std::string destFile;
	std::string s1;
	std::string s2;

	// arg number check
	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}

	//initialize variables
	srcFile = argv[1];
	destFile = srcFile + ".replace";
	s1 = argv[2];
	s2 = argv[3];

	// test1
	std::cout << argv[1] << std::endl;
	std::cout << destFile << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


	// open input file stream + check
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cout << "Error: file not found" << std::endl;
		return (2);
	}

	// open output file stream + check
	std::ofstream outputFile(destFile.c_str());
	if (!outputFile)
	{
		std::cout << "could not create output file" << std::endl;
		return (3);
	}
	
	std::string newline;
	while (std::getline(inputFile, line))
	{
		newline = replaceAllOccurrences(line, s1, s2);
		outputFile << newline << std::endl;
	}


	// replace s1 with s2

	// close input file stream
	inputFile.close();

	return (0);
	(void)argc;
}