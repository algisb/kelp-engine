#include "Camera.h"

using namespace kelp;

Camera::Camera(kep::Matrix4 _projectionMat)
{
    m_projectionMat = _projectionMat;
}
Camera::~Camera()
{
}

void Camera::init()
{
    if(m_owner->m_world->m_renderCamera == NULL)
        m_owner->m_world->m_renderCamera = this;
    m_transform = m_owner->getComponent<Transform>();
}
void Camera::update()
{
    m_transform->m_orientation.normalize();
    m_viewMat.setOrientationAndPos(m_transform->m_orientation, m_transform->m_position);
    m_viewMat.invert();
    m_viewMat = m_viewMat.transpose(); //cuz opengl is idgaf-major
}

void Camera::render()
{
}
