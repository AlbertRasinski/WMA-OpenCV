#pragma once
#include <opencv2/opencv.hpp>
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include <string>
#include <vector>


struct OpenCVKarta {
public:
	cv::Mat Karta;
	std::string znak;
	std::string symbol;
	std::string kolor;
};

class OpenCVClass {
public:
	std::string SciezkaDoFilmu;
	int ThreshholdValue;
	int AreaCard;
	std::vector<cv::Mat> CardTemplate;
	std::vector<OpenCVKarta> Card;
	cv::Mat ObrazKoncowy;

	OpenCVClass();

	void Wykrywanie(cv::Mat inputimg, bool &WlaczeniePrzetwarzania);
	bool Skora(cv::Mat inputimg);
};
