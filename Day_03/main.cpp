#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    // Öffnen der Datei "Input_Day03.txt"
    std::ifstream infile("Input_Day03.txt");
    if (!infile) {
        std::cerr << "Fehler beim Öffnen der Datei 'Input_Day03.txt'." << std::endl;
        return 1;
    }

    // Lesen der gesamten Eingabe aus der Datei
    std::string input((std::istreambuf_iterator<char>(infile)),
                       std::istreambuf_iterator<char>());

    // Regulärer Ausdruck zur Erkennung von mul, do() und don't()
    std::regex pattern(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\)|do\(\)|don't\(\))");

    std::sregex_iterator iter(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    bool enabled = true; // Anfangszustand: mul-Anweisungen sind aktiviert
    long long sum = 0;

    for (; iter != end; ++iter) {
        std::smatch match = *iter;

        if (match.str() == "do()") {
            enabled = true;
        } else if (match.str() == "don't()") {
            enabled = false;
        } else if (match[0].str().substr(0, 4) == "mul(" && enabled) {
            int num1 = std::stoi(match[1].str());
            int num2 = std::stoi(match[2].str());
            sum += static_cast<long long>(num1) * num2;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
