// Main.cpp

#include "Main.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
    // attempt to open the original image
    cv::Mat imgOriginalScene = cv::imread("2189913_Radiallagergehäuse D30 links SW.png");

    // if the image was not opened successfully, show an error message and bail
    if (imgOriginalScene.empty()) {
        std::cout << "error: image not read from file\n\n";
        _getch();
        return(0);
    }

    std::vector<PossibleTextArea> testAreas = detectTextAreas(imgOriginalScene);

    cv::Mat imgSceneWithWriting = imgOriginalScene.clone();


    cv::imshow("imgSceneWithWriting", imgSceneWithWriting);

    cv::waitKey();

    return(0);
}


