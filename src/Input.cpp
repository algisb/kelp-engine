#include "Input.h"

using namespace kelp;

Input::Input()
{
    
    
    keys.push_back(GLFW_KEY_SPACE         );
    keys.push_back(GLFW_KEY_APOSTROPHE    );
    keys.push_back(GLFW_KEY_COMMA         );
    keys.push_back(GLFW_KEY_MINUS         );
    keys.push_back(GLFW_KEY_PERIOD        );
    keys.push_back(GLFW_KEY_SLASH         );
    keys.push_back(GLFW_KEY_0             );
    keys.push_back(GLFW_KEY_1             );
    keys.push_back(GLFW_KEY_2             );
    keys.push_back(GLFW_KEY_3             );
    keys.push_back(GLFW_KEY_4             );
    keys.push_back(GLFW_KEY_5             );
    keys.push_back(GLFW_KEY_6             );
    keys.push_back(GLFW_KEY_7             );
    keys.push_back(GLFW_KEY_8             );
    keys.push_back(GLFW_KEY_9             );
    keys.push_back(GLFW_KEY_SEMICOLON     );
    keys.push_back(GLFW_KEY_EQUAL         );
    keys.push_back(GLFW_KEY_A             );
    keys.push_back(GLFW_KEY_B             );
    keys.push_back(GLFW_KEY_C             );
    keys.push_back(GLFW_KEY_D             );
    keys.push_back(GLFW_KEY_E             );
    keys.push_back(GLFW_KEY_F             );
    keys.push_back(GLFW_KEY_G             );
    keys.push_back(GLFW_KEY_H             );
    keys.push_back(GLFW_KEY_I             );
    keys.push_back(GLFW_KEY_J             );
    keys.push_back(GLFW_KEY_K             );
    keys.push_back(GLFW_KEY_L             );
    keys.push_back(GLFW_KEY_M             );
    keys.push_back(GLFW_KEY_N             );
    keys.push_back(GLFW_KEY_O             );
    keys.push_back(GLFW_KEY_P             );
    keys.push_back(GLFW_KEY_Q             );
    keys.push_back(GLFW_KEY_R             );
    keys.push_back(GLFW_KEY_S             );
    keys.push_back(GLFW_KEY_T             );
    keys.push_back(GLFW_KEY_U             );
    keys.push_back(GLFW_KEY_V             );
    keys.push_back(GLFW_KEY_W             );
    keys.push_back(GLFW_KEY_X             );
    keys.push_back(GLFW_KEY_Y             );
    keys.push_back(GLFW_KEY_Z             );
    keys.push_back(GLFW_KEY_LEFT_BRACKET  );
    keys.push_back(GLFW_KEY_BACKSLASH     );
    keys.push_back(GLFW_KEY_RIGHT_BRACKET );
    keys.push_back(GLFW_KEY_GRAVE_ACCENT  );
    keys.push_back(GLFW_KEY_WORLD_1       );
    keys.push_back(GLFW_KEY_WORLD_2       );
    
    keys.push_back(GLFW_KEY_ESCAPE        );
    keys.push_back(GLFW_KEY_ENTER         );
    keys.push_back(GLFW_KEY_TAB           );
    keys.push_back(GLFW_KEY_BACKSPACE     );
    keys.push_back(GLFW_KEY_INSERT        );
    keys.push_back(GLFW_KEY_DELETE        );
    keys.push_back(GLFW_KEY_RIGHT         );
    keys.push_back(GLFW_KEY_LEFT          );
    keys.push_back(GLFW_KEY_DOWN          );
    keys.push_back(GLFW_KEY_UP            );
    keys.push_back(GLFW_KEY_PAGE_UP       );
    keys.push_back(GLFW_KEY_PAGE_DOWN     );
    keys.push_back(GLFW_KEY_HOME          );
    keys.push_back(GLFW_KEY_END           );
    keys.push_back(GLFW_KEY_CAPS_LOCK     );
    keys.push_back(GLFW_KEY_SCROLL_LOCK   );
    keys.push_back(GLFW_KEY_NUM_LOCK      );
    keys.push_back(GLFW_KEY_PRINT_SCREEN  );
    keys.push_back(GLFW_KEY_PAUSE         );
    keys.push_back(GLFW_KEY_F1            );
    keys.push_back(GLFW_KEY_F2            );
    keys.push_back(GLFW_KEY_F3            );
    keys.push_back(GLFW_KEY_F4            );
    keys.push_back(GLFW_KEY_F5            );
    keys.push_back(GLFW_KEY_F6            );
    keys.push_back(GLFW_KEY_F7            );
    keys.push_back(GLFW_KEY_F8            );
    keys.push_back(GLFW_KEY_F9            );
    keys.push_back(GLFW_KEY_F10           );
    keys.push_back(GLFW_KEY_F11           );
    keys.push_back(GLFW_KEY_F12           );
    keys.push_back(GLFW_KEY_F13           );
    keys.push_back(GLFW_KEY_F14           );
    keys.push_back(GLFW_KEY_F15           );
    keys.push_back(GLFW_KEY_F16           );
    keys.push_back(GLFW_KEY_F17           );
    keys.push_back(GLFW_KEY_F18           );
    keys.push_back(GLFW_KEY_F19           );
    keys.push_back(GLFW_KEY_F20           );
    keys.push_back(GLFW_KEY_F21           );
    keys.push_back(GLFW_KEY_F22           );
    keys.push_back(GLFW_KEY_F23           );
    keys.push_back(GLFW_KEY_F24           );
    keys.push_back(GLFW_KEY_F25           );
    keys.push_back(GLFW_KEY_KP_0          );
    keys.push_back(GLFW_KEY_KP_1          );
    keys.push_back(GLFW_KEY_KP_2          );
    keys.push_back(GLFW_KEY_KP_3          );
    keys.push_back(GLFW_KEY_KP_4          );
    keys.push_back(GLFW_KEY_KP_5          );
    keys.push_back(GLFW_KEY_KP_6          );
    keys.push_back(GLFW_KEY_KP_7          );
    keys.push_back(GLFW_KEY_KP_8          );
    keys.push_back(GLFW_KEY_KP_9          );
    keys.push_back(GLFW_KEY_KP_DECIMAL    );
    keys.push_back(GLFW_KEY_KP_DIVIDE     );
    keys.push_back(GLFW_KEY_KP_MULTIPLY   );
    keys.push_back(GLFW_KEY_KP_SUBTRACT   );
    keys.push_back(GLFW_KEY_KP_ADD        );
    keys.push_back(GLFW_KEY_KP_ENTER      );
    keys.push_back(GLFW_KEY_KP_EQUAL      );
    keys.push_back(GLFW_KEY_LEFT_SHIFT    );
    keys.push_back(GLFW_KEY_LEFT_CONTROL  );
    keys.push_back(GLFW_KEY_LEFT_ALT      );
    keys.push_back(GLFW_KEY_LEFT_SUPER    );
    keys.push_back(GLFW_KEY_RIGHT_SHIFT   );
    keys.push_back(GLFW_KEY_RIGHT_CONTROL );
    keys.push_back(GLFW_KEY_RIGHT_ALT     );
    keys.push_back(GLFW_KEY_RIGHT_SUPER   );
    keys.push_back(GLFW_KEY_MENU          );
    
    

    
}

Input::~Input()
{
}


void Input::update(int _key, int _action)
{
    for(int i = 0; i < keys.size(); i++)
        if(_key == keys[i])
        {
            switch(_action)
            {
                case GLFW_PRESS:
                    keys_p.push_back(_key);
                    break;
                case GLFW_RELEASE:
                    keys_r.push_back(_key);
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
}
