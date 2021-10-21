
int   hue; 									

void place_icons(Size size)						
{
	vector<string> icon_name = { "hole", "tab"};
			
	int k = 0;
		for (int j = 0; j < 2; j++, k++) {
			Point   pt(j*size.width, 0);			
			icons.push_back(Rect(pt, size));					

			Mat icon = imread("../icon/" + icon_name[k] + ".jpg", 1);
			if (icon.empty()) continue; 					

			resize(icon, icon, size);					
			icon.copyTo(image(icons[k]));					
		}
}


