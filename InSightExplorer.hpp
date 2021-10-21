
Mat roi;
string holeWindow = "구멍 탐지";

int search_valueIdx(Mat hist, int bias = 0) { 
	for (int i = 0; i < hist.rows; i++) {
		int idx = abs(bias - i);
		if (hist.at<float>(idx) > 0) return idx;
	}
	return -1;
}


void  InSightExplorer(Mat  image)
{
	if (inspect_mode == BLOB) 
	{
		roi = image(Rect(pt1, pt2));
		cvtColor(roi, roi, COLOR_BGR2GRAY);
		vector<Vec3f> holes;
		HoughCircles(roi, holes, HOUGH_GRADIENT, 1, 60, 100, 28, 0, 0);

		rectangle(image, pt1, pt2, Scalar(255, 0, 0), 3);

		for (int i = 0; i < holes.size(); i++) {
			Vec3i c = holes[i]; 
			Point center(c[0], c[1]);
			int radius = c[2];

			circle(roi, center, radius, Scalar(255, 255, 255), 2); 
			circle(roi, center, 2, Scalar(255, 255, 255), 3); 
		}

		if (flag1 == 0) {
			if (holes.size() > 0) {
				cout << "구멍 검출, 정상" << endl;
			}
			else cout << "구멍 없음, 불량" << endl;
			flag1 = 1;
		}
		
		namedWindow(holeWindow, WINDOW_AUTOSIZE);
		resizeWindow(holeWindow, 150, 150);
		moveWindow(holeWindow, 1000, 150);
		imshow(holeWindow, roi);

	}
	else if (inspect_mode == HISTO) 
	{
		roi = image(Rect(pt1, pt2));
		cvtColor(roi, roi, COLOR_BGR2GRAY);

		const int* channel_numbers = { 0 }; 
		float channel_range[] = { 0.0, 255.0 };
		const float* channel_ranges = channel_range;
		int number_bins = 64;
		MatND histogram;

		calcHist(&roi, 1, channel_numbers, Mat(), histogram, 1, &number_bins, &channel_ranges);

		float bin_width = (float)255 / number_bins;
		int low_value = (int)(search_valueIdx(histogram, 0) * bin_width); 
		int high_value = (int)(search_valueIdx(histogram, histogram.rows - 1)*bin_width); 

		if (flag1 == 0) {
			cout << "high_value = " << high_value << endl;
			cout << "low_value = " << low_value << endl;
			if (high_value - low_value > 80 && low_value < 100) {
				cout << "얼룩 있음, 불량" << endl;
			}
			else cout << "문제 없음, 정상" << endl;
			flag1 = 1;
		}

		rectangle(image, pt1, pt2, Scalar(0, 255, 0), 3);
	}

	imshow(title, image);
}

