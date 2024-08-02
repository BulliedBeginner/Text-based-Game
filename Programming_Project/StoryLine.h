#pragma once
#include <iostream>
void Beginning() {
	std::cout
		<< "\n\n"
		<< "\t\t\tWelcome to Dungeon Adventure\n\n"
		<< "\t\t\tYou are a S tier adventurer.\n"
		<< "\t\t\tFew days ago, a group of adventure found an abandoned dungeon.\n"
		<< "\t\t\tYou are interested so you plan to go for it.\n"
		<< "\n\n\n\n\n\n";

	system("Pause");
	system("CLS");
}

void AfterInitialise() {
	std::cout 
		<< "\nYou are now at the entrance of the dungeon.\n"
		<< "You will get gold by killing monster.\n"
		<< "By killing monster, your skill level will increase.\n"
		<< "You can only enter the shop when you are not in battle.\n"
		<< "Press any key or button to enter the dungeon.\n\n";

	system("Pause");
	system("CLS");
}