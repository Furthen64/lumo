#ifndef CORE_H
#define CORE_H


#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <chrono>


// Project includes
#include "HurkaMap.hpp"
#include "Constants.hpp"
#include "Utils.hpp"
#include "Grid.hpp"
#include "TextureManager.hpp"
#include "Toolbar.hpp"
#include "TrafficManager.hpp"       // ==> RoadNetwork.hpp
                                    // ==> Bus.hpp
#include "GameMatrix.hpp"
#include "Block.hpp"
#include "Locomotive.hpp"
#include "FileManager.hpp"



using namespace sf;



class Core
{

public:
    Core();
    ~Core();

    int boot();

    int allocateResources();

    int loadResources(std::string _mapName);

    int setup(int, int, std::string);

    void run();

    void reset();

    void clearResources();

    void updateTraffic();




private:

    int debugLevel = 1;

    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 720;
    int lockFPS = true;
    int lockFPS_n = 10;

    std::string windowTitle = "HurkaLumo editor alpha-0.1";
    std::string cn = "Core.cpp";
    std::string startmapStr = "data/bus_traffic_test.txt";


    int mouseSensitivity = 4*ceil(100/lockFPS_n); // Pan speed in percentage

    Vector2i viewPos = {-2178,-331};

    TextureManager *textureMgr; // Singleton!

    TrafficManager *trafficMgr;
    GameMatrix *gm;
    Bus *bus = nullptr;
    Locomotive *loco = nullptr;
    Toolbar *toolbarTop = nullptr;
    Grid *grid = nullptr;
    HurkaMap *hmap = nullptr;
    HurkaMatrix *roadMatrix = nullptr;
    FileManager *fmgr;

    bool drawGm = 1;
    bool drawLoco = 0;
    bool drawBuses = 1;
    bool drawToolbar = 1;
    bool drawGrid = 1;
    bool drawBlocks = 1;




    Font font;
    Text lastClickedText;




};



#endif
