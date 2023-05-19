#include <iostream>

#include <thread>
#include <vector>

#include "sdl/Application.hpp"
#include "sdl/LifeAdapter.hpp"

using namespace std;


int main(int argc, char** argv) {
    int height = stoi(argv[1]);
    int width = stoi(argv[2]);
    std::unique_ptr<LifeAdapter> lifeAdapter = std::make_unique<LifeAdapter>(height,width);
    Application application(1000, 1000);
    application.addSdlElement(std::move(lifeAdapter));
    application.run();
}
