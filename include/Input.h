#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <GLFW/glfw3.h>

namespace kelp
{
    class Input
    {
        public:
            std::vector<int> keys;
            std::vector<int> keys_p;//pressed 
            std::vector<int> keys_r;//released
            
            Input();
            ~Input();
            void update(int _key, int _action);
            void clear();
            void printKeyList();
    };
}
