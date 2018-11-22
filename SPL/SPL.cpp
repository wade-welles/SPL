#include <iostream>
#include <fstream>
#include <vector>

void runFile(std::string path) {
	std::ifstream sourceFile(path, std::ios::ate);
	std::streamsize size = sourceFile.tellg();
	sourceFile.seekg(0, std::ios::beg);

	std::vector<char> buffer(size);
	if (sourceFile.read(buffer.data(), size)) {
		// Do something here.
	}
	else {
		throw "File couldn't be read.";
	}
}

void runREPL() {
	std::vector<char> buffer;
	while (true) {
		char ch;
		while (std::cin.get(ch) && ch != '\n') {
			buffer.push_back(ch);
		}
		// Do something here.
	}
}

int main(int argc, char* argv[]) {
	if (argc > 2) {
		std::cout << "Error: Lots of arguement. Usage: spl [file.spl]";
		return 64;
	}
	if (argc == 2) {
		runFile(std::string(argv[1]));
	}
	else {
		runREPL();
	}
}