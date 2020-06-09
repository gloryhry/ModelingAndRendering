#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#include <QVector3D>
#include <QMatrix4x4>
#include <QtMath>

#include <cmath>
using namespace std;


class Camera
{
public:

    enum Movement
    {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    // Camera Attributes
    QVector3D position;
    QVector3D front;
    QVector3D up;

    // Euler Angles
    float yaw;
    float pitch;

    // Camera options
    float movementSpeed;
    float mouseSensitivity;
    float fov;

    Camera(const QVector3D& pos = QVector3D())
        : position(pos)
        , front(QVector3D(0.0f, 0.0f, -1.0f))
        , up(QVector3D(0.0f, 1.0f, 0.0f))
        , yaw(-90.0f)
        , pitch(0.0f)
        , movementSpeed(0.02f)
        , mouseSensitivity(0.1f)
        , fov(45.0f)
    {}

    QMatrix4x4 viewMatrix() const
    {
        QMatrix4x4 view;
        view.lookAt(position, position + front, up);
        return view;
    }

    void move(Movement direction)
    {
        float velocity = movementSpeed;

        switch (direction) {

        case FORWARD:
        {
            QVector3D dir(velocity * front.x(), 0.0f, velocity * front.z());
            position += dir;
        }
            break;

        case BACKWARD:
        {
            QVector3D dir(velocity * front.x(), 0.0f, velocity * front.z());
            position -= dir;
        }
            break;

        case LEFT:
        {
            QVector3D dir(velocity * front.x(), 0.0f, velocity * front.z());
            QMatrix4x4 transform;
            transform.rotate(90.0f, 0.0f, 1.0f, 0.0f);
            position += transform * dir;
        }
            break;

        case RIGHT:
        {
            QVector3D dir(velocity * front.x(), 0.0f, velocity * front.z());
            QMatrix4x4 transform;
            transform.rotate(-90.0f, 0.0f, 1.0f, 0.0f);
            position += transform * dir;        }
            break;
        }
    }

    void rotate(float xoffset, float yoffset)
    {
        xoffset *= mouseSensitivity;
        yoffset *= mouseSensitivity;

        yaw   += xoffset;
        pitch += yoffset;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        front.setX(cosf(qDegreesToRadians(yaw)) * cosf(qDegreesToRadians(pitch)));
        front.setY(sinf(qDegreesToRadians(pitch)));
        front.setZ(sinf(qDegreesToRadians(yaw)) * cosf(qDegreesToRadians(pitch)));
        front.normalize();
    }

    void zoomIn()
    {
        const float sensitivity = 5.0f;
        fov -= sensitivity;

        if (fov <= 1.0f)
            fov = 1.0f;
    }

    void zoomOut()
    {
        const float sensitivity = 5.0f;
        fov += sensitivity;

        if (fov >= 150.0f)
            fov = 150.0f;
    }
};


#endif // CAMERA_H
