// PossibleTextArea.h

#ifndef POSSIBLE_TEXT_AREA_H
#define POSSIBLE_TEXT_AREA_H

#include<string>
#include<opencv2/opencv.hpp>

#include"PossibleChar.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
class PossibleTextArea {
public:
    // member variables ///////////////////////////////////////////////////////////////////////////
    std::vector<PossibleChar> possibleChars;

    // ToDo: will have to change this to a cv::RotatedRect
    cv::Rect boundingRect;
    
    // function prototypes ////////////////////////////////////////////////////////////////////////
    PossibleTextArea(std::vector<PossibleChar> _possibleChars);

};


#endif   // POSSIBLE_TEXT_AREA_H
