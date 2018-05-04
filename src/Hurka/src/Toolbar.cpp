#include "Toolbar.hpp"

/// //////////////////////////////////////////////
/// and up comes the Toolbar


Toolbar::Toolbar(HPos *_hpos)
{

    set_pos_by_gpix(_hpos);

    toolbarXOffset = pos->gpix_x;



    // get the whole texture for all the buttons
    texture.loadFromFile("C:\\github\\lumo\\src\\Hurka\\bin\\Release\\TOOLBAR.png");



    // allocate all the sprites
    sprites = new Sprite[nrButtons*2];
    visibleSpritesTopArr = new int [nrButtons];
    for(int i = 0; i < nrButtons; i++) { visibleSpritesTopArr[i] = true; }


    // map all the sprites correctly
    // position the sprites
    float x, y;

    for(int i = 0; i < nrButtons*2; i++){
        sprites[i] = Sprite(texture);
        sprites[i].setTextureRect( {i*widthPx, 0, 16, 16} );

        x = i*widthPx+ toolbarXOffset;
        y = 0;

        sprites[i].setPosition({x,y});
    }

}



Toolbar::~Toolbar()
{
    delete sprites;
    delete visibleSpritesTopArr;
}


void Toolbar::set_pos_by_gpix(HPos *_hpos)
{
    pos->gpix_y = _hpos->gpix_y;
    pos->gpix_x = _hpos->gpix_x;

}


void Toolbar::pushButton(int relXPos)
{
    // set the status of the dang thing
    visibleSpritesTopArr[0] = !visibleSpritesTopArr[0];

}

void Toolbar::draw( RenderTarget& rt, HPos *viewHPos)
{
    // draw all the buttons individually
    for(int i = 0; i < nrButtons; i++){
        if(visibleSpritesTopArr[i] == true) {
            sprites[i].setTextureRect( {i*widthPx, 0, 16, 16} );    // Show the top one
        } else {
            sprites[i].setTextureRect( {i*widthPx, 16, 16, 16} );
        }

        // Draw it
        rt.draw( sprites[i] );
    }
}




HPos *Toolbar::getPos()
{
    return pos;
}

int *Toolbar::getVisibleSpritesTopArr()
{
    return visibleSpritesTopArr;
}
