#include "Config.h"
using namespace kelp;

int Config::windowWidth = 800;
int Config::windowHeight = 600;
bool Config::capFrameRate = true;
int Config::targetFrameRate = 60;
float Config::targetDeltaT = (float)(1.0f/(float)targetFrameRate);
