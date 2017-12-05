#ifndef CONTACT_H_
#define CONTACT_H_
#include "../../Core.h"
#include "../../RigidBody.h"
namespace kep
{
    class Contact
    {
    public:
        RigidBody * body[2];
        Vector3 position;
        Vector3 normal;
        real penetration;
        
        Contact();
        ~Contact();
    };
};

#endif // CONTACT_H_
