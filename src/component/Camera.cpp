#include "Camera.h"

using namespace kelp;

Camera::Camera(kep::Matrix4 _projectionMat)
{
    m_projectionMat = _projectionMat;
//     m_projectionMat = kep::perspectiveProjection(
//         45.0f, 
//         Config::s_windowWidth, 
//         Config::s_windowHeight, 
//         0.1f, 
//         2000.0f).transpose();
}
Camera::~Camera()
{
}

void Camera::init()
{
    //printf("kektus\n");
    if(m_owner->m_world->m_renderCamera == NULL)
        m_owner->m_world->m_renderCamera = this;
    m_transform = m_owner->getComponent<Transform>();
}
void Camera::update()
{
}

void Camera::render()
{
}
