
void onMouse(int event, int x, int y, int flags, void* param) {

	Point pt(x, y);

	if (event == EVENT_LBUTTONDOWN) {
		pt1 = pt;
		mouse_mode = 2;
		flag1 = 0;
	}

	else if (event == EVENT_LBUTTONUP) {
		for (int i = 0; i < (int)icons.size(); i++) {
			if (icons[i].contains(pt)) {
				mouse_mode = 0;
				switch (i) {
				case 0:
					cout << "BLOB" << endl;
					break;
				case 1:
					cout << "HISTO" << endl;
					break;
				}
				inspect_mode = i;
				return;
			}
		}
		pt2 = pt;
		mouse_mode = 1;

		if (mouse_mode >= 2) {
			Rect rect(0, 0, 125, image.rows);
			mouse_mode = (rect.contains(pt)) ? 0 : 3;
			pt2 = pt;
		}
	}
}

void key_check(int& no) {
	int key = waitKeyEx(10);
	if (key == 0x280000) {
		flag2 = 0;
		inspect_mode = 3;
		no++;
		if (no > 18) no = 1;
		destroyWindow(holeWindow);
	}
	else if (key == 0x260000) {
		flag2 = 0;
		inspect_mode = 3;
		no--;
		if (no < 1) no = 18;
		destroyWindow(holeWindow);
	}
	else if (key == 27 || key == 32) exit(0);

	if (flag2 == 0) {
		cout << to_string(no) << "¹ø ¿µ»ó" << endl;
		flag2 = 1;
	}
	string fname = format("../braket_img/%02d.bmp", no);
	image = imread(fname, 1);

	place_icons(Size(30, 30));
	imshow(title, image);
}
