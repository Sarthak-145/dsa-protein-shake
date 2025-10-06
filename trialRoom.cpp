// try every fukin doubt here.
#include <iostream>
#include <string>

// this guy is modern
#include <format>

// Isn't working rn, maybe my env isn't 20+
std::string name = "kafka";
int main() { std::cout << std::format("Hello{}", name) }