#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat query, image, descriptors2, descriptors1;
	Ptr<ORB> orbF = ORB::create(1000);
	vector<KeyPoint> keypoints2, keypoints1;
	vector< vector< DMatch> > matches;
	vector< DMatch > goodMatches;
	BFMatcher matcher(NORM_HAMMING);
	Mat imgMatches;

	int i, k;
	float nndr;
	string query_file;
	vector<String> dbs;
	string db_file;
	string match_file;
	int match, pre_match, cnt;

	std::cout << "Enter Query image name: ";
	std::cin >> query_file;
	query = imread("query_image/" + query_file);
	if (query.empty()) {
		cout << "No file!" << endl;
		return 0;
	}
	resize(query, query, Size(640, 480));
	orbF->detectAndCompute(query, noArray(), keypoints1, descriptors1);

	glob("DBs/*.jpg", dbs, false);
	if (dbs.size() == 0) {
		cout << "No database!" << endl;
		return 0;
	}
	cout << "Sample image Load Size: " << dbs.size() << endl;
	for (cnt = 0, match = 0, pre_match = 0; cnt < dbs.size(); cnt++) {
		db_file = dbs[cnt];
		image = imread(db_file);
		if (image.empty()) {
			cout << "No file in database!";
			return 0;
		}
		resize(image, image, Size(640, 480));
		orbF->detectAndCompute(image, noArray(), keypoints2, descriptors2);
		
		k = 2;
		matcher.knnMatch(descriptors1, descriptors2, matches, k);
		nndr = 0.6f;
		for (i = 0; i < matches.size(); i++)
			if (matches.at(i).size() == 2 && matches.at(i).at(0).distance <= nndr * matches.at(i).at(1).distance)
				goodMatches.push_back(matches[i][0]);
		cout << "Image number " << cnt + 1 << " Matching: " << goodMatches.size() << endl;
		match = static_cast<int>(goodMatches.size());
		if (pre_match < match) {
			pre_match = match;
			match_file = db_file;
		}
		
		matches.clear();
		goodMatches.clear();
		matcher.clear();
	}
	if (0 < pre_match)
		cout << "Match found!" << endl;

	image = imread(match_file);
	resize(image, image, Size(640, 480));
	orbF->detectAndCompute(image, noArray(), keypoints2, descriptors2);

	k = 2;
	matcher.knnMatch(descriptors1, descriptors2, matches, k);
	nndr = 0.6f;
	for (i = 0; i < matches.size(); i++)
		if (matches.at(i).size() == 2 && matches.at(i).at(0).distance <= nndr * matches.at(i).at(1).distance)
			goodMatches.push_back(matches[i][0]);

	drawMatches(image, keypoints1, query, keypoints2, goodMatches, imgMatches, Scalar::all(-1), Scalar(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("Query", query);
	imshow("Best_matching", imgMatches);
	waitKey(0);
	return 0;
}