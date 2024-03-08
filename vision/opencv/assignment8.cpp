#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


struct MouseParams {
    Mat img;
    vector<Point2f> in, out;
};


static void onMouse(int event, int x, int y, int, void* param) {
    MouseParams* mp = (MouseParams*)param;
    if (event == EVENT_LBUTTONDOWN) {
        mp->out.push_back(Point2f(x, y));
    }
    if (event == EVENT_RBUTTONDOWN) {
        mp->out.clear();
    }
}

int main()
{
    VideoCapture cap1, cap2;
    Mat background, input;
    int width, height;
    int window_width, window_height;
    int delay;

    cap1.open("Timesquare.mp4");
    width = cap1.get(CAP_PROP_FRAME_WIDTH);
    height = cap1.get(CAP_PROP_FRAME_HEIGHT);
    delay = 1000 / cap1.get(CAP_PROP_FPS);

    cap2.open("contest.mp4");
    window_width = cap2.get(CAP_PROP_FRAME_WIDTH);
    window_height = cap2.get(CAP_PROP_FRAME_HEIGHT);
    Mat mask(window_height, window_width, CV_8UC1, Scalar(255));

    MouseParams mp;
    mp.in.push_back(Point2f(0, 0));
    mp.in.push_back(Point2f(window_width, 0));
    mp.in.push_back(Point2f(window_width, window_height));
    mp.in.push_back(Point2f(0, window_height));

    Mat result, tmp;
    while (1) 
    {
        cap1 >> background;
        cap2 >> input;

        if (background.empty())
            break;
        mp.img = background;

        if (mp.out.size() == 4) 
        {
            tmp = background.clone();
            Mat homo_mat = getPerspectiveTransform(mp.in, mp.out);
            warpPerspective(input, result, homo_mat, Size(width, height));
            warpPerspective(mask, tmp, homo_mat, Size(width, height));
            result.copyTo(background, tmp);
            imshow("background", background);
        }
        else 
        {
            for (size_t i = 0; i < mp.out.size(); i++)
                circle(background, mp.out[i], 3, Scalar(0, 0, 255), 5);            
        }

        imshow("input", input);
        imshow("background", background);
        setMouseCallback("background", onMouse, (void*)&mp);
        waitKey(delay);
    }
    waitKey(0);
    return 0;
}