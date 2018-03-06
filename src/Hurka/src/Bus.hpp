#ifndef BUS_H
#define BUS_H

#include "SFML/Graphics.hpp"
#include "Utils.hpp"
#include "GameMatrix.hpp"
#include "TextureManager.hpp"
#include "HurkaMatrix.hpp"

using namespace sf;


class Bus
{
public:
    Bus(const Vector2f& _pos);

    void draw( RenderTarget& rt) const;

    void setDirectionConst( const Vector2f& dir);

    void setDirection( Vector2f dir);

    void setPos( Vector2f _p);

    void setNextPos( Vector2f _np);


    void update( float dt);

    Vector2f getPos();


    Vector2f randStartingPos(HurkaMatrix *roadMatrix);



private:

    Vector2f pos;   // Current position


    Vector2f vel = {0.0f, 0.0f};

    float speed = 100.0f; // 1 pixel per update?
    Vector2f nextPos;



    Texture texture;
    Sprite sprite;


    std::string cn = "Bus.cpp";
};

#endif
