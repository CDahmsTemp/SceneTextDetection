// DetectTextAreas.h

#ifndef DETECT_TEXT_AREAS_H
#define DETECT_TEXT_AREAS_H

#include<opencv2/opencv.hpp>

#include "Main.h"
#include "PossibleTextArea.h"
#include "PossibleChar.h"
#include "VisionUtilities.h"

// global constants ///////////////////////////////////////////////////////////////////////////////
const double TEXT_AREA_WIDTH_PADDING_FACTOR = 1.15;
const double TEXT_AREA_HEIGHT_PADDING_FACTOR = 1.15;

const int MIN_PIXEL_WIDTH = 2;
const int MIN_PIXEL_HEIGHT = 8;

const double MIN_ASPECT_RATIO = 0.25;
const double MAX_ASPECT_RATIO = 1.0;

const int MIN_PIXEL_AREA = 80;
const int MAX_PIXEL_AREA = 400;

// constants for comparing two chars
const double MIN_DIAG_SIZE_MULTIPLE_AWAY = 0.3;
const double MAX_DIAG_SIZE_MULTIPLE_AWAY = 5.0;

const double MAX_CHANGE_IN_AREA = 0.5;

const double MAX_CHANGE_IN_WIDTH = 0.8;
const double MAX_CHANGE_IN_HEIGHT = 0.2;

const double MAX_ANGLE_BETWEEN_CHARS = 12.0;

// other constants
const int MIN_NUMBER_OF_MATCHING_CHARS = 3;

const int MIN_CONTOUR_AREA = 70;

// function prototypes ////////////////////////////////////////////////////////////////////////////
std::vector<PossibleTextArea> detectTextAreas(cv::Mat &imgOriginalScene);
std::vector<PossibleChar> findPossibleCharsInScene(std::vector<std::vector<cv::Point>> contours);
bool checkIfPossibleChar(PossibleChar &possibleChar);
std::vector<std::vector<PossibleChar> > findVectorOfVectorsOfMatchingChars(const std::vector<PossibleChar> &vectorOfPossibleChars);
std::vector<PossibleChar> findVectorOfMatchingChars(const PossibleChar &possibleChar, const std::vector<PossibleChar> &vectorOfChars);
double distanceBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar);
double angleBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar);
std::vector<PossibleChar> removeInnerOverlappingChars(std::vector<PossibleChar> &vectorOfMatchingChars);





# endif	// DETECT_PLATES_H



