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
#ifndef CORE_KELP_H_
#define CORE_KELP_H_

#include "GL/glew.h"
#include "Config.h"
#include "Input.h"
#include "Time.h"

#include "World.h"
#include "Entity.h"
#include "component/Transform.h"
#include "kep/Core.h"
#include "world/World_0.h"
#include "Texture.h"
//Fore initialising worlds
namespace kelp
{
    class Core
    {
    public:
        MeshLoad * m_plane;
        MeshLoad * m_sphereMesh;
        MeshLoad * m_cubeMesh;
        MeshLoad * m_highPolyMesh;
        MeshLoad * m_monkeyMesh;
        MeshLoad * m_sandBox;
        
        MeshLoad * m_externalMesh;
        MeshLoad * m_m4a1s;
        MeshLoad * m_dungeon;
        
        ShaderMin * m_shaderMinimal;
        ShaderDefault * m_shaderDefault;
        
        Texture * m_testTexture;
        Texture * m_m4a1sTexture;
        
        World * m_world;
        Core(int _argc, char ** _argv);
        ~Core();
        void update();
    };
};
#endif // CORE_KELP_H_

