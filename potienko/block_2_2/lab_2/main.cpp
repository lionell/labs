/*
 * Author: Ruslan Sakevych
 * Verdict: Accepted
*/
#include <cstring>
#include <fstream>
#include "Train.h"
#include "Station.h"
#include "tests.h"

char DEFAULT_PATH[] = "/home/lionell/Developing/university/laboratories/block_2_2/lab_2/";
char DEFAULT_INPUT_FILE_NAME[] = "in.txt";
char DEFAULT_OUTPUT_FILE_NAME[] = "out.txt";

const int MAX_LENGTH = 255;

char *get_file_path(char *file_name) {
    char *result = new char[strlen(DEFAULT_PATH) + strlen(file_name) + 1];
    strcpy(result, DEFAULT_PATH);
    strcat(result, file_name);
    return result;
}

Train *read_train() {
    Train *train = new Train();
    char *wagon_string = new char[MAX_LENGTH];
    // Reading wagons from file
    while (!std::cin.eof()) {
        std::cin >> wagon_string;
        if (strcmp(wagon_string, "Tank") == 0) train->push_back(new Tank());
        else if (strcmp(wagon_string, "Fridge") == 0) train->push_back(new Fridge());
        else if (strcmp(wagon_string, "Open") == 0) train->push_back(new Open());
        else throw("Error! Unknown type of wagon.");
    }
    delete[] wagon_string;
    return train;
}

int main(int argv, char **argc) {
    try {
        if (argv > 2) {
            // Now we have at least two parameters
            if (strcmp(argc[1], "-m") == 0 || strcmp(argc[1], "--mode") == 0) {
                // Now we have mode passed
                if (strcmp(argc[2], "1") == 0) {
                    Tester tester;
                    tester.add(new Test1());
                    tester.add(new Test2());
                    tester.add(new Test3());
                    tester.add(new Test4());
                    tester.run_all_tests();
                } else if (strcmp(argc[2], "2") == 0) {
                    char *input_file_name = nullptr;
                    char *output_file_name = nullptr;
                    // Try to find input and output filenames
                    if (argv > 4 && (strcmp(argc[3], "-i") == 0 || strcmp(argc[3], "--input") == 0)) input_file_name = argc[4];
                    if (argv > 4 && (strcmp(argc[3], "-o") == 0 || strcmp(argc[3], "--output") == 0)) output_file_name = argc[4];
                    if (argv > 6 && (strcmp(argc[5], "-i") == 0 || strcmp(argc[5], "--input") == 0)) input_file_name = argc[6];
                    if (argv > 6 && (strcmp(argc[5], "-o") == 0 || strcmp(argc[5], "--output") == 0)) output_file_name = argc[6];
                    // If nothing is found, we should use DEFAULT_FILE_NAMEs
                    if (input_file_name == nullptr) input_file_name = DEFAULT_INPUT_FILE_NAME;
                    if (output_file_name == nullptr) output_file_name = DEFAULT_OUTPUT_FILE_NAME;
                    // Getting full file paths
                    char *input_file_path = get_file_path(input_file_name);
                    char *output_file_path = get_file_path(output_file_name);
                    // Opening files
                    freopen(input_file_path, "r", stdin);
                    freopen(output_file_path, "w", stdout);
                    Train *train = read_train();
                    // Printing result to file
                    std::cout << "Input train:" << std::endl;
                    print(train);
                    Train **trains = Station::unload(train);
                    std::cout << "Output trains:" << std::endl;
                    for (int i = 0; i < 3; ++i) print(trains[i]);
                    // Cleaning dynamic memory
                    delete train;
                    delete[] trains;
                    delete[] input_file_path;
                    delete[] output_file_path;
                    fclose(stdin);
                    fclose(stdout);
                } else throw ("Error! No such mode found.");
            } else throw ("Error! Mode expected.");
        } else throw ("Error! More parameters expected.");
    } catch (const char *message) {
        std::cerr << message;
    }
    return 0;
}