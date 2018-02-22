// DetectTextAreas.h

#ifndef DETECT_TEXT_AREAS_H
#define DETECT_TEXT_AREAS_H

#include<opencv2/opencv.hpp>

#include "Main.h"
#include "PossibleTextArea.h"

// global constants ///////////////////////////////////////////////////////////////////////////////
const double TEXT_AREA_WIDTH_PADDING_FACTOR = 1.15;
const double TEXT_AREA_HEIGHT_PADDING_FACTOR = 1.15;

// function prototypes ////////////////////////////////////////////////////////////////////////////
std::vector<PossibleTextArea> detectTextAreas(cv::Mat &imgOriginalScene);

# endif	// DETECT_PLATES_H








