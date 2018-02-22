// Main.cpp

#include "Main.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
    // attempt to open the original image
    cv::Mat imgOriginalScene = cv::imread("LOWER PLATE CMM - C4_Page_1.png");

    // if the image was not opened successfully, show an error message and bail
    if (imgOriginalScene.empty()) {
        std::cout << "error: image not read from file\n\n";
        _getch();
        return(0);
    }

    std::vector<PossibleTextArea> textAreas = detectTextAreas(imgOriginalScene);

    cv::Mat imgSceneWithWriting = imgOriginalScene.clone();

    // draw a green box around each text area
    for (auto &textArea : textAreas) {
        cv::rectangle(imgSceneWithWriting, textArea.boundingRect, SCALAR_GREEN, 2);
    }

    // show the original scene with the drawn-in text areas
    cv::imshow("imgSceneWithWriting", imgSceneWithWriting);
    cv::imwrite("imgSceneWithWriting.png", imgSceneWithWriting);

    cv::waitKey();

    return(0);
}


