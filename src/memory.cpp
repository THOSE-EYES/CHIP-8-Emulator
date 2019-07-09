#include "memory.h"

Memory::Memory() {
	//Initialize variables
	adress = 0x00;
	stack_adress = 0x00;
}

Memory::~Memory() {

}

void Memory::write(unsigned char data) {
	//Check if block number is bigger than memory size

	//Write data
	memory[adress] = data;

	//Move the pointer
	adress++;
}

unsigned char Memory::read() {
	//Check if block number is bigger than memory size

	//Read a block
	unsigned char data = memory[adress];

	//Move the pointer
	adress++;

	//Return data
	return data;
}

void Memory::move(unsigned short block) {
	//Check if block number is bigger than memory size
	if(block >= MEM_SIZE | block < 0) {
		//Raise an exception
	}

	//Move the pointer to the block
	adress = block;
}

void Memory::storeReturnAdress() {
	if (stack_adress == STACK_SIZE) {
		//Raise an exception
	}

	//Store the adress in the stack
	stack[stack_adress] = adress;

	//Move the adress to a free block
	stack_adress++;
}

void Memory::recurr() {
	if (stack_adress == 0) {
		//Raise an exception
	}

	//Recovering the previous adress of memory to continue executing the previous task
	adress = stack[stack_adress];

	//Moving to the next stack block
	stack_adress--;
}