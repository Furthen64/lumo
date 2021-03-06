#ifndef BLOCK_H
#define BLOCK_H



#include <SFML/Graphics.hpp>

#include "Singletons/TextureManager.hpp"
#include "GameMatrix.hpp"
#include "Constants.hpp"


using namespace sf;

/// //////////////////////////////////////////////
/// (--) Block
/// ? x ? pixels        Auto adjusted where its positioned for drawing based upon its texture resolution

class Block
{
public:

    Block(HPos *, std::string );
    Block(HPos *, int );

    void draw( RenderTarget& rt, HPos *viewHPos);

    void dump(std::string);
    void minimaldump(std::string ind);

    int getTextureID();

    void setTextureByName(std::string _textureName);

    Block *clone();

    std::string getTextureName();

    void set_pos_by_abs_iso(HPos *_abs_iso);

    HPos *getHPos();



private:
    int textureID;
    Texture texture;
    IntRect textureSize;
    std::string textureName;
    Sprite sprite;
    Vector2f pos;
    std::string cn = "Block.cpp";
    HPos *hpos;
};

#endif
