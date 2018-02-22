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

///////////////////////////////////////////////////////////////////////////////////////////////////
void showPossibleTextAreaContours(std::vector<PossibleTextArea> possibleTextAreas, cv::Size imageSize) {
    cv::Mat imgPossibleTextAreas = cv::Mat(imageSize, CV_8UC3, SCALAR_BLACK);

    cv::RNG rng;
    for (auto &possibleTextArea : possibleTextAreas) {
        int intRandomBlue = rng.uniform(0, 256);
        int intRandomGreen = rng.uniform(0, 256);
        int intRandomRed = rng.uniform(0, 256);

        std::vector<std::vector<cv::Point>> contours;
        for (auto &possibleChar : possibleTextArea.possibleChars) {
            contours.push_back(possibleChar.contour);
        }
        cv::drawContours(imgPossibleTextAreas, contours, -1, cv::Scalar((double)intRandomBlue, (double)intRandomGreen, (double)intRandomRed));

    }
    cv::imshow("imgPossibleTextAreas", imgPossibleTextAreas);
    cv::imwrite("imgPossibleTextAreas.png", imgPossibleTextAreas);
}







