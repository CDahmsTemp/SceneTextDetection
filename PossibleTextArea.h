// PossibleTextArea.h

#ifndef POSSIBLE_TEXT_AREA_H
#define POSSIBLE_TEXT_AREA_H

#include <string>
#include<opencv2/opencv.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
class PossibleTextArea {
public:
    // member variables ///////////////////////////////////////////////////////////////////////////
    cv::Mat imgTextArea;
    cv::Mat imgGrayscale;
    cv::Mat imgThresh;

    cv::RotatedRect rrLocationOfPlateInScene;

    std::string strChars;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    static bool sortDescendingByNumberOfChars(const PossibleTextArea &ptaLeft, const PossibleTextArea &ptaRight) {
        return(ptaLeft.strChars.length() > ptaRight.strChars.length());
    }

};


#endif   // POSSIBLE_TEXT_AREA_H
