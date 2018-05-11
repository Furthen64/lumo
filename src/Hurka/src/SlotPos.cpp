#include "SlotPos.hpp"



/// @param _hpos         An HPos object with the absolute iso positions set
///
/// (-+)
SlotPos::SlotPos(HPos *_hpos)
{
    int debugLevel = 0;

    if(textureName == "") {
        std::cout << "ERROR " << cn << " Could not create block with empty texturename=" << textureName << "\"!\n";
        return ;
    }


    // Apply texture
    TextureManager *textureMgr;
    textureMgr = textureMgr->getInstance();

    bool result = textureMgr->applyTexture(textureName, &texture);
    if(!result) { std::cout << "ERROR Block creation, cannot find texture \"" << textureName << "\".\n";  return ;  }

    // Set SFML sprite
    sprite = sf::Sprite(texture);
    textureSize = sprite.getTextureRect();


    if(debugLevel > 0) {
        std::cout << "height= " << textureSize.height << ", width=" << textureSize.width << "\n";
    }


    // Now we have texture size, set the gPix positions



    //set_pos_by_abs_iso(_hpos);
}





// (--) TEST
void SlotPos::draw( sf::RenderTarget& rt, HPos *viewHPos)
{
    int y = hpos->gpix_y;
    int x = hpos->gpix_x;

    // Viewing offset
    y += viewHPos->gpix_y;
    x += viewHPos->gpix_x;

    sf::Vector2f vpos = {(float)x,(float)y};

    sprite.setPosition(vpos);

    rt.draw(sprite);
}
