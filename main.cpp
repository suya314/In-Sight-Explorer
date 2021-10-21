#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

vector<Rect> icons; 
Mat image; 
int  mouse_mode = 0, inspect_mode = 0;
Point pt1, pt2;
string title = "불량 검출기";
bool flag1 = 1; 
bool flag2 = 1;
int no = 1;

#include "menu.hpp"
#include "icon_flag.hpp"
#include "InSightExplorer.hpp"
#include "event.hpp"

int main() {
	
	cout << to_string(no) << "번 영상" << endl;
	string fname = format("../braket_img/%02d.bmp", no);
	image = imread(fname, 1);

	place_icons(Size(30, 30));

	imshow(title, image);

	setMouseCallback(title, onMouse);

	while (1) {
		if (mouse_mode == 1) {
			InSightExplorer(image);
		}
		key_check(no);
	}
	waitKey(0);
	return 0;
}

