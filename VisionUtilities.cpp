// VisionUtilities.cpp

#include "VisionUtilities.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void showCharContours(std::vector<PossibleChar> possibleChars, cv::Size imageSize) {
    cv::Mat imgPossibleChars = cv::Mat(imageSize, CV_8UC3, SCALAR_BLACK);
    for (auto &currentChar : possibleChars) {
        std::vector<std::vector<cv::Point>> vectorOfOneContour;
        vectorOfOneContour.push_back(currentChar.contour);
        cv::drawContours(imgPossibleChars, vectorOfOneContour, -1, SCALAR_WHITE);
    }
    cv::imshow("imgPossibleChars", imgPossibleChars);
}









