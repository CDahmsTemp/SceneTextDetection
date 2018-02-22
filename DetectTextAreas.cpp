// DetectTextAreas.cpp

#include "DetectTextAreas.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<PossibleTextArea> detectTextAreas(cv::Mat &imgOriginalScene) {
    // this will be the return value
    std::vector<PossibleTextArea> possibleTextAreas;

    // convert to grayscale
    cv::Mat imgSceneGrayscale;
    cv::cvtColor(imgOriginalScene, imgSceneGrayscale, CV_BGR2GRAY);
    cv::imshow("imgSceneGrayscale", imgSceneGrayscale);

    // threshold
    cv::Mat imgThresh;
    cv::threshold(imgSceneGrayscale, imgThresh, 0, 255.0, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
    cv::imshow("imgThresh", imgThresh);

    // find contours
    cv::Mat imgContours = cv::Mat(imgOriginalScene.size(), CV_8UC3, SCALAR_BLACK);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(imgThresh.clone(), contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
    cv::drawContours(imgContours, contours, -1, SCALAR_WHITE, 1);
    cv::imshow("imgContours", imgContours);


    std::vector<PossibleChar> possibleChars = findPossibleCharsInScene(contours);

    showCharContours(possibleChars, imgOriginalScene.size());

    





    return possibleTextAreas;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<PossibleChar> findPossibleCharsInScene(std::vector<std::vector<cv::Point>> contours) {
    // this will be the return value
    std::vector<PossibleChar> possibleChars;

    for (auto &contour : contours) {
        PossibleChar possibleChar(contour);
        // check if a contour is a possible char, note this does not compare to other chars (yet) . . .   
        if (checkIfPossibleChar(possibleChar)) {
            // if so, add to vector of possible chars
            possibleChars.push_back(possibleChar);
        }
    }
    return possibleChars;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool checkIfPossibleChar(PossibleChar &possibleChar) {
    // this function is a 'first pass' that does a rough check on a contour to see if it could be a char,
    // note that we are not (yet) comparing the char to other chars to look for a group
    if (possibleChar.boundingRect.area() > MIN_PIXEL_AREA && possibleChar.boundingRect.area() <= MAX_PIXEL_AREA && 
        possibleChar.boundingRect.width > MIN_PIXEL_WIDTH && possibleChar.boundingRect.height > MIN_PIXEL_HEIGHT &&
        MIN_ASPECT_RATIO < possibleChar.dblAspectRatio && possibleChar.dblAspectRatio < MAX_ASPECT_RATIO) {
        return(true);
    }
    else {
        return(false);
    }
}


