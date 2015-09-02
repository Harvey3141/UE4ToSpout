#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class SpoutLogger {
public:
	static void logSpout(const char *str);
	static void logSpout(std::string str);
	static void logSpout(int _int);
	static void clearLogSpout();
};




