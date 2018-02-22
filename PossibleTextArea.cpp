// PossibleTextArea.cpp

#include "PossibleTextArea.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
PossibleTextArea::PossibleTextArea(std::vector<PossibleChar> _possibleChars) {
    possibleChars = _possibleChars;

    int xMin = 999999;
    int xMax = 0;
    int yMin = 999999;
    int yMax = 0;

    for (auto &possibleChar : possibleChars) {

        cv::Rect currentBoundingRect = cv::boundingRect(possibleChar.contour);

        int currentRectXMin = currentBoundingRect.x;
        int currentRectXMax = currentBoundingRect.x + currentBoundingRect.width;
        int currentRectYMin = currentBoundingRect.y;
        int currentRectYMax = currentBoundingRect.y + currentBoundingRect.height;

        if (currentRectXMin < xMin) xMin = currentRectXMin;
        if (currentRectXMax > xMax) xMax = currentRectXMax;
        if (currentRectYMin < yMin) yMin = currentRectYMin;
        if (currentRectYMax > yMax) yMax = currentRectYMax;

    }

    boundingRect.x = xMin;
    boundingRect.y = yMin;
    boundingRect.width = xMax - xMin;
    boundingRect.height = yMax - yMin;
}




