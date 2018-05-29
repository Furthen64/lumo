#include "Grid.hpp"



/// //////////////////////////////////////////////
/// Grid           cr 2018-02-22
// The grid follows the static grid size of 64 x 64 px


// (--)
Grid::Grid(int _height, int _width)
{
    width = _width;
    height = _height;
    texture.loadFromFile("C:\\github\\lumo\\src\\Hurka\\bin\\Release\\GRID_1.png");
    sprite = Sprite(texture);


    textureSelected.loadFromFile("C:\\github\\lumo\\src\\Hurka\\bin\\Release\\GRID_SELECTED.png");
    spriteSelected = Sprite(textureSelected);

    // Load font
    if (!font.loadFromFile("consola.ttf"))
    {
        std::cout << "ERROR " << cn << " could not load font.\n";
    }
}


// (--)
void Grid::draw( RenderTarget& rt, HPos *viewHPos)
{
    int gx = 0;
    int gy = 0;
    int wx = 0;
    int wy = 0;

    Vector2f wPos = Vector2f(); // SFML specific...


    /*Vector2f firstGPos = Vector2f();        // Game position of the first grid cell
    Vector2f firstWPos = Vector2f();        // Window position of the first grid cell

    bool once = false;

    */


    for(int M= 0; M<height; M++){
        for(int N= 0; N < width; N++) {

            gx = convert_iso_to_gpix_x(M,N, GRID_TEXTURE_WIDTH, GRID_TEXTURE_HEIGHT,0);
            gy = convert_iso_to_gpix_y(M,N, GRID_TEXTURE_WIDTH, GRID_TEXTURE_HEIGHT,0);

  /*          if(!once)
            {
                firstGPos.x = gx;
                firstGPos.y = gy;
            }
*/
            wx = gx + viewHPos->gpix_x;
            wy = gy + viewHPos->gpix_y;

/*            if(!once) {
                firstWPos.x = wx;
                firstWPos.y = wy;
                once = true;
            }
*/

            wPos.x = wx;
            wPos.y = wy;

            sprite.setPosition(wPos);
            rt.draw(sprite);

        }

    }


    // Draw the selected grid that should be more visible
    gx = convert_iso_to_gpix_x(selected_iso_pos.y, selected_iso_pos.x, GRID_TEXTURE_WIDTH, GRID_TEXTURE_HEIGHT, 0);
    gy = convert_iso_to_gpix_y(selected_iso_pos.y, selected_iso_pos.x, GRID_TEXTURE_WIDTH, GRID_TEXTURE_HEIGHT, 0);

    wx = gx+ viewHPos->gpix_x;
    wy = gy+ viewHPos->gpix_y;

    wPos.x = wx;
    wPos.y = wy;

    spriteSelected.setPosition(wPos);
    rt.draw(spriteSelected);



    /// Also draw coordinates in text for the top one
    /*
    text.setFont(font);

    std::stringstream sstm;
    sstm << "GPOS(" << firstGPos.y << ", " << firstGPos.x << ")\n";
    sstm << "WPOS(" << firstWPos.y << ", " << firstWPos.x << ")\n";

    std::string txtStr = sstm.str();
    text.setString(txtStr );
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);


    // inside the main loop, between window.clear() and window.display()
    text.setPosition(firstWPos);
    rt.draw(text);
*/


}



// Hm... The Pos coming in have pix_positions..
//these pixel positions could have been generated by aa tall house block with height=64, while
//the grid is =32 so... we get a faulty gpix_x and gpix_y ... should really re-compute it if we need it here
// Beta material!

void Grid::setVisible(HPos *_pos)
{
    drawSelectedGrid = true;

    selected_iso_pos.y = _pos->abs_iso_y;
    selected_iso_pos.x = _pos->abs_iso_x;

    selected_pix_pos.y = _pos->gpix_y;
    selected_pix_pos.x = _pos->gpix_x;
}



// HPOSDELETE
/*
void Grid::setVisible(Vector2f iso_pos)
{
    drawSelectedGrid = true;


    selected_iso_pos = iso_pos;

    selected_pix_pos.x = convert_iso_to_gpix_x(iso_pos.y, iso_pos.x, GRID_TEXTURE_WIDTH, GRID_TEXTURE_HEIGHT, 0);
    selected_pix_pos.y = convert_iso_to_gpix_y(iso_pos.y, iso_pos.x, GRID_TEXTURE_WIDTH, GRID_TEXTURE_HEIGHT, 0 );



 //   std::cout << "Visible grid position: " << selected_pix_pos.x << " , " << selected_pix_pos.y << "\n";
}

*/





void Grid::hideVisible()
{
    drawSelectedGrid = false;
}





// (--) Test
HPos *Grid::findGrid(HurkaMatrix *hmatrix, HRect *relRect, HPos *searchPos)
{
	int debugLevel = 2;
	
	
	if(debugLevel >=1) {
	std::cout << "findGrid() Not tested!\n";

	std::cout << "Input hmatrix:\n";
	hmatrix->dump("  ");
	
	std::cout << "Input relrect:\n";
	relRect->dump("  ");
	
	std::cout << "Input searchPos:\n";
	searchPos->dump("  ");
	}
	int nrTiles = subMtxRows * subMtxCOls;
	
	
	if(nrTiles < 16) {
		return bruteForceFindGrid( mY, mX, subMtxRows, subMtxCols, hmatrix);
	}
	
	
	// Now we approach it the smart way
	
	// Divide the submatrix into four squares
	
	HRect *sq0, *sq1, *sq2, *sq3;
	
	// Where is the first cell ?
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
		HRect(int _absStartY, 
			int _absStartX, 
			int _rows, 
			int _cols, 
			int _relStartY, 
			int _relStartX, 
			int _height,
			int _width);

	*/
	
	
	
	

	if(
}