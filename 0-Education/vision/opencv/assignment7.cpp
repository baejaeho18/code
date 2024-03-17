#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap;
	int delay;
	Mat frame;
	Mat cvtFrame;
	int key = -1;
	int steadyKey = -1;
	int prev_steadyKey = steadyKey;
	char cnt_t_press = 0;

	Mat tracking_image, gray_image, image;
	Mat blue_background = Mat(frame.size(), frame.type(), Scalar(255, 0, 0));
	CascadeClassifier face_classifier;
	face_classifier.load("haarcascade_frontalface_alt.xml");
	vector<Rect> faces;
	Rect face_rectangle;
	int i = 0;

	if (cap.open("Faces.mp4") == 0)
	{
		cout << "no suche file!" << endl;
		waitKey(0);
	}
	delay = 1000 / cap.get(CAP_PROP_FPS);

	while (1)
	{
		cap >> frame;
		if (frame.empty())
		{
			cout << "end pf video" << endl;
			break;
		}

		key = waitKey(delay);
		if (key != -1)
			steadyKey = key;
		cvtColor(frame, gray_image, CV_BGR2GRAY);
		image = frame.clone();

		if (steadyKey == 78 || steadyKey == 110)	// N, n
		{
			face_classifier.detectMultiScale(gray_image, faces, 1.1, 4, 0, Size(75, 75), Size(90, 90));
			if (faces.empty())
				continue;
			if (faces.size() > 1)
			{
				if (faces[0].area() > faces[i].area())
					i = 0;
				else
					i = 1;
			}
			Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point tr(faces[i].x, faces[i].y);
			rectangle(image, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
			prev_steadyKey = steadyKey;

			if (cnt_t_press == 1)
			{
				face_rectangle = Rect(faces[i].x, faces[i].y - 20, faces[i].width, faces[i].height + 40);
				Mat face = frame(face_rectangle); 
				frame.copyTo(blue_background, face);
				imshow("traking", blue_background);
			}
		}
		else if (steadyKey == 77 || steadyKey == 109)	// M, m
		{
			face_classifier.detectMultiScale(gray_image, faces, 1.1, 7, 0, Size(50, 50), Size(58, 58));
			if (faces.empty())
				continue;
			if (faces.size() > 1)
			{
				if (faces[0].area() > faces[1].area())
					i = 0;
				else
					i = 1;
			}
			else 
			{
				i = 0;
			}
			Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point tr(faces[i].x, faces[i].y);
			rectangle(image, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
			prev_steadyKey = steadyKey;


			if (cnt_t_press == 1)
			{
				face_rectangle = Rect(faces[i].x, faces[i].y - 20, faces[i].width, faces[i].height + 40);
				Mat face = frame(face_rectangle);
				frame.copyTo(blue_background, face);
				imshow("traking", blue_background);
			}
		}
		else if (steadyKey == 70 || steadyKey == 102)	// F, f
		{
			face_classifier.detectMultiScale(gray_image, faces, 1.1, 4, 0, Size(25, 25), Size(35, 35));
			if (faces.empty())
				continue;
			if (faces.size() > 1) 
			{
				if (faces[0].area() < faces[1].area())
					i = 0;
				else
					i = 1;
			}
			else
			{
				i = 0;
			}
			Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point tr(faces[i].x, faces[i].y);
			rectangle(image, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
			prev_steadyKey = steadyKey;

			if (cnt_t_press == 1)
			{
				//face_rectangle = Rect(faces[i].x, faces[i].y - 10, faces[i].width, faces[i].height + 20);
				//Mat face = blue_background(face_rectangle);
				//frame(face_rectangle).copyTo(face);
				Mat mask = Mat::zeros(frame.size(), CV_8U); // 빈 마스크 이미지 생성
				Rect regionOfInterest(faces[i].x, faces[i].y - 10, faces[i].width, faces[i].height + 20);
				rectangle(mask, regionOfInterest, Scalar(255), CV_FILLED); // 영역을 흰색(255)으로 채움
				frame.copyTo(blue_background, mask);

				Mat background = Mat::zeros(frame.size(), frame.type()); // 파란색 배경 이미지 생성
				rectangle(background, regionOfInterest, Scalar(255, 0, 0), CV_FILLED); // 파란색 배경으로 영역 채우기
				blue_background.copyTo(blue_background, ~mask); // 결과 이미지에서 얼굴이 아닌 영역 복사

				imshow("traking", blue_background);
			}
		}
		else if (steadyKey == 82 || steadyKey == 114)	// R, r
		{
			destroyWindow("traking");
			cnt_t_press = 0;
		}
		else if ((steadyKey == 84 || steadyKey == 116))	// T, t
		{
			if (cnt_t_press > 0)
			{
				destroyWindow("traking");
				cnt_t_press = 0;
				break;
			}
			if ( !(prev_steadyKey == 78 || prev_steadyKey == 110	// N, n
				|| prev_steadyKey == 77 || prev_steadyKey == 109	// M, m
				|| prev_steadyKey == 70 || prev_steadyKey == 102))	// F, f
				putText(image, format("Detect before tracking"), Point(0, 20), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 1);
			
			steadyKey = prev_steadyKey;
			cnt_t_press++;
		}
		else
		{
			steadyKey = prev_steadyKey;
		}
		prev_steadyKey = steadyKey;
		imshow("Faces", image);

	}

	return 0;
}