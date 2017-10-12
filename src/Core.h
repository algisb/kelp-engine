//      .--..--..--..--..--..--.
//    .' \  (`._   (_)      ---\------------<<<//END ME
//  .'    |  '._)         (_)  |
//  \ _.')\      .----..---.   /
//  |(_.'  |    /    .-\-.  \  |
//  \     0|    |   ( O| O) | o|
//   |  _  |  .--.____.'._.-.  |
//   \ (_) | o         -` .-`  |
//    |    \   |`-._ _ _ _ _\ /
//    \    |   |  `. |_||_|   |     KELP ENGINE
//    | o  |    \_      \     |     -.   .-.
//    |.-.  \     `--..-'   O |     `.`-' .'
//  _.'  .' |     `-.-'      /-.__   ' .-'
//.' `-.` '.|='=.='=.='=.='=|._/_ `-'.'
//`-._  `.  |________/\_____|    `-.'
//   .'   ).| '=' '='\/ '=' |
//   `._.`  '---------------'
//           //___\   //___\
//             ||       ||
//             ||_.-.   ||_.-.
//            (_.--__) (_.--__)
#ifndef CORE_H_
#define CORE_H_

#include "GL/glew.h"
#include "Config.h"
#include "Input.h"
#include "Time.h"

#include "World.h"
#include "Entity.h"
#include "component/Transform.h"
#include "kep/Core.h"
#include "world/World_0.h"

//Fore initialising worlds
namespace kelp
{
    class Core
    {
    public:
        World * m_world;
        Core();
        ~Core();
        void update();
    };
};
#endif // CORE_H_

