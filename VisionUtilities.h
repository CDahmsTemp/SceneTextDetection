// VisionUtilities.h

#ifndef VISION_UTILITIES_H
#define VISION_UTILITIES_H

#include<opencv2/opencv.hpp>

#include"Main.h"
#include"PossibleChar.h"

// function prototypes ////////////////////////////////////////////////////////////////////////////
void showCharContours(std::vector<PossibleChar> possibleChars, cv::Size imageSize);
void showPossibleTextAreaContours(std::vector<PossibleTextArea> possibleTextAreas, cv::Size imageSize);








#endif   // VISION_UTILITIES_H
