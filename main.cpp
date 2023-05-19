#include <iostream>

#include <thread>
#include <vector>

#include "sdl/Application.hpp"
#include "sdl/LifeAdapter.hpp"

using namespace std;


int main(int argc, char** argv) {
    int cellsColumns = 10;
    int cellsRows = 10;
    int windowHeight = 800;
    int windowWidth = 800;
    if(argc >= 3) {
        cellsColumns = stoi(argv[1]);
        cellsRows = stoi(argv[2]);
    }
    if(argc >= 5) {
        windowWidth = stoi(argv[3]);
        windowHeight = stoi(argv[4]);
    }
    std::unique_ptr<LifeAdapter> lifeAdapter = std::make_unique<LifeAdapter>(cellsRows,cellsColumns);
    Application application(windowWidth, windowHeight);
    application.addSdlElement(std::move(lifeAdapter));
    application.run();
}
