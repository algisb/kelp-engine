#ifndef BOUNDINGSPHERE_H_
#define BOUNDINGSPHERE_H_
#include "../Core.h"

namespace kep
{
    class BoundingSphere
    {
    public:
        bool exterP;
        Vector3 * position;
        real radius;
        BoundingSphere();
        BoundingSphere(Vector3 _position, real _radius);
        BoundingSphere(Vector3 * _position, real _radius);
        ~BoundingSphere();
        bool overlaps(BoundingSphere *_other);
    };
};



#endif //BOUNDINGSPHERE_H_
