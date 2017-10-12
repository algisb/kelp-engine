///
///  @file Input.cpp
///  @brief globals that deals with control input

#include "Input.h"

using namespace kelp;


std::vector<int> Input::keys = std::vector<int>();
std::vector<int> Input::keys_p = std::vector<int>();//pressed
std::vector<int> Input::keys_r = std::vector<int>();//released
std::vector<int> Input::keys_h = std::vector<int>();//held-down
bool Input::initInput = false;

void Input::init()
{
    keys.push_back(KEY_SPACE         );
    keys.push_back(KEY_APOSTROPHE    );
    keys.push_back(KEY_COMMA         );
    keys.push_back(KEY_MINUS         );
    keys.push_back(KEY_PERIOD        );
    keys.push_back(KEY_SLASH         );
    keys.push_back(KEY_0             );
    keys.push_back(KEY_1             );
    keys.push_back(KEY_2             );
    keys.push_back(KEY_3             );
    keys.push_back(KEY_4             );
    keys.push_back(KEY_5             );
    keys.push_back(KEY_6             );
    keys.push_back(KEY_7             );
    keys.push_back(KEY_8             );
    keys.push_back(KEY_9             );
    keys.push_back(KEY_SEMICOLON     );
    keys.push_back(KEY_EQUAL         );
    keys.push_back(KEY_A             );
    keys.push_back(KEY_B             );
    keys.push_back(KEY_C             );
    keys.push_back(KEY_D             );
    keys.push_back(KEY_E             );
    keys.push_back(KEY_F             );
    keys.push_back(KEY_G             );
    keys.push_back(KEY_H             );
    keys.push_back(KEY_I             );
    keys.push_back(KEY_J             );
    keys.push_back(KEY_K             );
    keys.push_back(KEY_L             );
    keys.push_back(KEY_M             );
    keys.push_back(KEY_N             );
    keys.push_back(KEY_O             );
    keys.push_back(KEY_P             );
    keys.push_back(KEY_Q             );
    keys.push_back(KEY_R             );
    keys.push_back(KEY_S             );
    keys.push_back(KEY_T             );
    keys.push_back(KEY_U             );
    keys.push_back(KEY_V             );
    keys.push_back(KEY_W             );
    keys.push_back(KEY_X             );
    keys.push_back(KEY_Y             );
    keys.push_back(KEY_Z             );
    keys.push_back(KEY_LEFT_BRACKET  );
    keys.push_back(KEY_BACKSLASH     );
    keys.push_back(KEY_RIGHT_BRACKET );
    keys.push_back(KEY_GRAVE_ACCENT  );
    keys.push_back(KEY_WORLD_1       );
    keys.push_back(KEY_WORLD_2       );
    
    keys.push_back(KEY_ESCAPE        );
    keys.push_back(KEY_ENTER         );
    keys.push_back(KEY_TAB           );
    keys.push_back(KEY_BACKSPACE     );
    keys.push_back(KEY_INSERT        );
    keys.push_back(KEY_DELETE        );
    keys.push_back(KEY_RIGHT         );
    keys.push_back(KEY_LEFT          );
    keys.push_back(KEY_DOWN          );
    keys.push_back(KEY_UP            );
    keys.push_back(KEY_PAGE_UP       );
    keys.push_back(KEY_PAGE_DOWN     );
    keys.push_back(KEY_HOME          );
    keys.push_back(KEY_END           );
    keys.push_back(KEY_CAPS_LOCK     );
    keys.push_back(KEY_SCROLL_LOCK   );
    keys.push_back(KEY_NUM_LOCK      );
    keys.push_back(KEY_PRINT_SCREEN  );
    keys.push_back(KEY_PAUSE         );
    keys.push_back(KEY_F1            );
    keys.push_back(KEY_F2            );
    keys.push_back(KEY_F3            );
    keys.push_back(KEY_F4            );
    keys.push_back(KEY_F5            );
    keys.push_back(KEY_F6            );
    keys.push_back(KEY_F7            );
    keys.push_back(KEY_F8            );
    keys.push_back(KEY_F9            );
    keys.push_back(KEY_F10           );
    keys.push_back(KEY_F11           );
    keys.push_back(KEY_F12           );
    keys.push_back(KEY_F13           );
    keys.push_back(KEY_F14           );
    keys.push_back(KEY_F15           );
    keys.push_back(KEY_F16           );
    keys.push_back(KEY_F17           );
    keys.push_back(KEY_F18           );
    keys.push_back(KEY_F19           );
    keys.push_back(KEY_F20           );
    keys.push_back(KEY_F21           );
    keys.push_back(KEY_F22           );
    keys.push_back(KEY_F23           );
    keys.push_back(KEY_F24           );
    keys.push_back(KEY_F25           );
    keys.push_back(KEY_KP_0          );
    keys.push_back(KEY_KP_1          );
    keys.push_back(KEY_KP_2          );
    keys.push_back(KEY_KP_3          );
    keys.push_back(KEY_KP_4          );
    keys.push_back(KEY_KP_5          );
    keys.push_back(KEY_KP_6          );
    keys.push_back(KEY_KP_7          );
    keys.push_back(KEY_KP_8          );
    keys.push_back(KEY_KP_9          );
    keys.push_back(KEY_KP_DECIMAL    );
    keys.push_back(KEY_KP_DIVIDE     );
    keys.push_back(KEY_KP_MULTIPLY   );
    keys.push_back(KEY_KP_SUBTRACT   );
    keys.push_back(KEY_KP_ADD        );
    keys.push_back(KEY_KP_ENTER      );
    keys.push_back(KEY_KP_EQUAL      );
    keys.push_back(KEY_LEFT_SHIFT    );
    keys.push_back(KEY_LEFT_CONTROL  );
    keys.push_back(KEY_LEFT_ALT      );
    keys.push_back(KEY_LEFT_SUPER    );
    keys.push_back(KEY_RIGHT_SHIFT   );
    keys.push_back(KEY_RIGHT_CONTROL );
    keys.push_back(KEY_RIGHT_ALT     );
    keys.push_back(KEY_RIGHT_SUPER   );
    keys.push_back(KEY_MENU          );
    initInput = true;
}

void Input::update(int _key, int _action)
{
    if(!initInput)
        init();
    for(int i = 0; i < keys.size(); i++)
        if(_key == keys[i])
        {
            switch(_action)
            {
                case GLFW_PRESS:
                    keys_p.push_back(_key);
                    keys_h.push_back(_key);
                    break;
                case GLFW_RELEASE:
                    keys_r.push_back(_key);
                    for(int j = 0; j < keys_h.size(); j++)
                        if(keys_h[j] == _key)
                            keys_h.erase(keys_h.begin() + j);
                    break;
            }
            break;
        }
}

void Input::clear()
{
    keys_p.clear();
    keys_r.clear();
}

void Input::printKeyList()
{
    for(int i = 0; i < keys_p.size(); i++)
        printf("%d pressed\n", keys_p[i]);
    
    for(int i = 0; i < keys_r.size(); i++)
        printf("%d released\n", keys_r[i]);
    
    for(int i = 0; i < keys_h.size(); i++)
        printf("%d held\n", keys_h[i]);
}

bool Input::isPressed(kelp::Key _key)
{
    for(int i = 0; i < keys_p.size(); i++)
        if(keys_p[i] == _key)
            return true;
        return false;
}

bool Input::isReleased(kelp::Key _key)
{
    for(int i = 0; i < keys_r.size(); i++)
        if(keys_r[i] == _key)
            return true;
        return false;
}

bool Input::isHeld(kelp::Key _key)
{
    for(int i = 0; i < keys_h.size(); i++)
        if(keys_h[i] == _key)
            return true;
        return false;
}
