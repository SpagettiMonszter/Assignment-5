/*
    Name: Tess_Mulkey, 8000138541, 202.1001, ASSIGNMENT_1
    Description: Assembly interpreter
    Input: Varying asm files
    Output: values dependent on assembly file instructions
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <array>

//setting namespace
using namespace std;


// Forward declaration of Symbol
// used to store name of a label, and  memory that represents the location where a memory should jump to
struct Symbol
{
	string labelName = "";
	int memoryLocation = 0;
};

// Forward declaration of Opcode
// stores name of the opcode and mnemonic representation (int)
// Opcode = custom data type ????
struct Opcode
{
	string codeName;
	int codeNumber;
	Opcode(string name, int number) : codeName(name), codeNumber(number){}
};
// stored values for name command and code
Opcode code00("const", 0);
Opcode code01("get", 1);
Opcode code02("put",2);
Opcode code03("ld X", 3);
Opcode code04("st X", 4);
Opcode code05("add X", 5);
Opcode code06("sub X", 6);
Opcode code07("mul X", 7);
Opcode code08("div X", 8);
Opcode code09("comp X", 9);
Opcode code10("jpos X", 10);
Opcode code11("jz X", 11);
Opcode code12("j X", 12);
Opcode code13("jl X", 13);
Opcode code14("jle X", 14);
Opcode code15("jg X", 15);
Opcode code16("jge X", 16);
Opcode code17("halt X", 17);

// Global constant variables
const int LABEL_COUNT = 100; 	///< default number of labels
const int OPCODE_COUNT = 18; 	///< default number of opcodes
const int MAX_CHARS = 5;		///< maximum number of characters
const int STACK_SIZE = 1000;	///< maximum capacity of array

/// list of opcodes needed for interpretation 
const std::string OPCODE_LIST = 
"const get put ld st add sub mul div cmp jpos jz j jl jle jg jge halt"; 

// YOUR CODE GOES HERE
//Function split opcode
void splitOpcode(string inst, Opcode* opcodes)
{
	stringstream opcodeSS(OPCODE_LIST);
	array<string, 18> opcode_array;
	string opcode;
	int index = 0;
	while (opcodeSS >> opcode)
	{
		opcode_array[index] = opcode;
		index ++;
	};
}


// -->

// Helper functions

/// Returns the number of spaced needed for padding.
/// @param str the string that needs padding.
/// @param len the maximum number of characters.
/// @return the number of spaces needed.
int padding(std::string str, int len) {
	int n = static_cast<int>(str.length());
	return len + abs(len - n);
}

/// Dumps the name and numerical value that each instrcution represents
/// @param op the array of opcodes.
/// @param count the number of opcodes.
/// @return void.
// void dumpOpcodes(Opcode *opcodes, int count) {
// 	std::cout << "Opcodes" << std::endl;
// 	int pad = 0;
// 	for (int i = 0; i < count; ++i) {
// 		pad = padding(opcodes[i].name, MAX_CHARS);
// 		std::cout << "> " << opcodes[i].name << std::string(pad, ' ') 
// 		<< opcodes[i].code << std::endl;
// 	}
// }

// /// Dumps the name of a label and its corresponding location in memory.
// /// @param sym an array of symbols.
// /// @param count the number of symbols in the array.
// /// @return void.
// void dumpSymbols(Symbol* labels, int count) {
// 	std::cout << "Symbols" << std::endl;
// 	int pad = 0;
// 	for (int i = 0; i < count; ++i) {
// 		pad = padding(labels[i].name, MAX_CHARS);
// 		std::cout << "> " << "[" << labels[i].name << "] = " 
		// << labels[i].mem << std::endl; 
// 	}
// }

// /// Dumpds the address of each instruction and label.
// /// @param memory the array of addresses.
// /// @param count the number of addresses.
// /// @return void.
// void dumpMemory(int* memory, int count) {
// 	std::cout << "Memory" << std::endl;
// 	std::cout.fill('0');
// 	for (int i = 0; i < count; ++i) {
// 		std::cout << std::setw(8) << memory[i] << std::endl;
// 	}
// }

/// Entry point of the main program.
/// @param argc the number of command-line arguments.
/// @param argv the vector of command-line arguments.
/// @return 0 if the program runs to complition.
int main(int argc, char *argv[]) {
	// <---
	// YOUR CODE GOES HERE
	// read in file
	cout << "Running Program ..." << endl;
	if(argc < 2)
	{ 
		return 1;
	}

	fstream inFile;
	// read from the file
	inFile.open(argv[1]);
	if (inFile)
	{
		string line;
		int count = 0; // initialize counter keep track values stored
		string labels[LABEL_COUNT];
		string labels2[LABEL_COUNT];
		string commands[LABEL_COUNT];
		while (getline(inFile, line))
		{	
			istringstream iss(line);
			string word = "";

			if (!isspace(line[0]))
			{
				// label | command | label
				iss >> word;
				if(word[0]== ';')
				{
					count++;
					continue;
				}
				labels[count] = word;
				iss >> word;
				if(word[0]== ';')
				{
					count++;
					continue;
				}
				commands[count] = word;
				iss >> word;
				if(word[0]== ';')
				{
					count++;
					continue;
				}
				if ( word != commands[count])
				{
					labels2[count] = word;
				}
			} 
			else if (line.size() > 0)
			{
				//       | command | label
				labels[count] = "";
				iss >> word;
				if(word[0]== ';')
				{
					count++;
					continue;
				}
				commands[count] = word;
				iss >> word;
				if(word[0]== ';')
				{
					count++;
					continue;
				}
				if ( word != commands[count])
				{
					labels2[count] = word;
				}
			}
			
			count++;
		}

		cout << "Checking Stored Data:" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << labels[i] << " " << commands[i] << " " << labels2[i] << endl;
		}


	
		inFile.close();
			
		// write code that will parse through each character and 
		// stops once it finds a white spacethen save that code into array for labels
	}
	// check to see if file opens
	else
	{
		cout << "break" << endl;
		cout << "ERROR: file not found!" << endl;	
	}

	
	// create the table of opcodes
	


	
	// parse the list of opcodes
	
	// check command-line arguments
		//
		//--------------------------------------------
		// PASS #1
		//
		// (1) Removing comments
		// (2) Remember labels
		// (3) Save instruction/opcode and address
		// (4) Write generated code to an output file
		//
	
		//
		// --------------------------------------------
		//
		// PASS #2
		//
		// (1) Read output file
		// (2) Replace numeric values and pack them into
		//
	
		//
		// --------------------------------------------
		//
		// INTEPRETER
		//
		// (1) Execute instructions in sequential order
		//
	//std::cout << "Running program..." << std::endl;
	int reg = 0; // register variable
	// -->
	return EXIT_SUCCESS;
}