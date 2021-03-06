#ifndef HPOS_H
#define HPOS_H

#include <iostream>
#include <assert.h>


class SlotPos;  // Forward declaration
/*
    - Whoa !

      Why so many variables for a position?! Shouldn't there only be one position?

    - No. NOOOOO. I have to make it harder than it is! I have to have ABSOLUTE ISO POSITION (abs_iso_y, abs_iso_x)
      so I know where this ~thing~ is on the entire gameboard.

      I also have to know within a smaller matrix like roadnetworks where the thing is, like a bus, where that bus is
      inside that little rectangle (rel_iso_y, rel_iso_x).

    - So what's with the gpix positions?

    - Well, now that I know where they are in the ISOMETRIC game board and roadnetworks, I need to have PIXEL awareness.
    I need to know where in the entire board its at, pixelwise, and then where it's actually rendered.

    Where it's actually at: (gpix_y, gpix_x) gpix stands for "gameboard pix"



*/



/* Wishlist:
        + Maybe redesign completely (again! ;D)

                    Have two position objects per thing, whatever that thing is

                    Block cat = new Block("CAT_TEXTURE");

                    cat.pixelpos = new PixelPos(0,0);
                    cat.isopos   = new IsoPos(cat.position);



        + More constrctors - I wanna be able to create hpos on the fly based on these different set of positions!
                             By using an ENUM?

                             gpixPos = new HPos(1024,768, USE_GPIX);
                             iso_pos = new HPos(0,1, USE_GPIX);             < would be a FAULTY use of this, so, you should
                                                                              be able to spot that youve made an error by
                                                                              left hand side saying "iso" and right saying "gpix"

                              iso_pos = new HPos(0,1, USE_ISO);

*/





enum PositionTypes { USE_GPIX, USE_ISO };


class HPos
{

public:

    HPos(int _y, int _x, int positionType);
    HPos(int _y, int _x, int positionType, int typeOfElement);
    HPos();

    void transform_gpix_to_slotpos(SlotPos *slotpos, HPos *hpos);
    void synchGpixToIsoValues(int height, int width);
    std::string relToString();
    std::string absToString();
    int compare(HPos *other);
    int compareAbsIso(HPos *other);

    int abs_iso_y;  // Absolute tile position  from 0,0 to gameboard's max min
    int abs_iso_x;
    int rel_iso_y;  // Relative tile position  useful for inside rectangles on the gameboard
    int rel_iso_x;
    int gpix_y_topleft;     // Topleft tile pixel position
    int gpix_x_topleft;
    int gpix_y_middle;     // Middle of tile pixel position
    int gpix_x_middle;
    int wpix_y;     // Window pixel (0,0 to 640,480)
    int wpix_x;

    HPos *clone();
    void dump(std::string ind);



    static bool ArightOfB(HPos *A, HPos *B)
    {

        if(A->abs_iso_x > B->abs_iso_x) {
            return true;
        }

        return false;
    }



    // (-+)
    static int compareTwoAbsIso(HPos *first, HPos *other)
    {

        if(first->abs_iso_y == other->abs_iso_y
           &&
           first->abs_iso_x == other->abs_iso_x)
        {
            return 0;
        }

        return -1;
    }



    // (-+)
    static int compareTwoGpixTopLeft(HPos *first, HPos *other)
    {
        if(first->gpix_y_topleft == other->gpix_y_topleft
           &&
           first->gpix_x_topleft == other->gpix_x_topleft)
        {
            return 0;
        }

        return -1;
    }


    void testFunctions();




private:




};

#endif
