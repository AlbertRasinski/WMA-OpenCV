#include "OpenCVClass.h"

OpenCVClass::OpenCVClass() {														//konstruktor klasy
	ThreshholdValue = 100;
	AreaCard = 10;
	SciezkaDoFilmu = "";
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card2.jpg")));		//wczytanie zdjecia o okreslonym znaku/symbolu-wzorcowe do matchtemplate
	cv::cvtColor(CardTemplate[0], CardTemplate[0], cv::COLOR_BGR2GRAY, 0);		//przekszta³cenie obrazu w odcieniach szaroœci
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card3.jpg")));
	cv::cvtColor(CardTemplate[1], CardTemplate[1], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card4.jpg")));
	cv::cvtColor(CardTemplate[2], CardTemplate[2], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card5.jpg")));
	cv::cvtColor(CardTemplate[3], CardTemplate[3], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card6.jpg")));
	cv::cvtColor(CardTemplate[4], CardTemplate[4], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card7.jpg")));
	cv::cvtColor(CardTemplate[5], CardTemplate[5], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card8.jpg")));
	cv::cvtColor(CardTemplate[6], CardTemplate[6], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card9.jpg")));
	cv::cvtColor(CardTemplate[7], CardTemplate[7], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("Card10.jpg")));
	cv::cvtColor(CardTemplate[8], CardTemplate[8], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardAS.jpg")));
	cv::cvtColor(CardTemplate[9], CardTemplate[9], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardJ.jpg")));
	cv::cvtColor(CardTemplate[10], CardTemplate[10], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardK.jpg")));
	cv::cvtColor(CardTemplate[11], CardTemplate[11], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardQ.jpg")));
	cv::cvtColor(CardTemplate[12], CardTemplate[12], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardJoker.jpg")));
	cv::cvtColor(CardTemplate[13], CardTemplate[13], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardTrefl.jpg")));
	cv::cvtColor(CardTemplate[14], CardTemplate[14], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardKaro.jpg")));
	cv::cvtColor(CardTemplate[15], CardTemplate[15], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardKier.jpg")));
	cv::cvtColor(CardTemplate[16], CardTemplate[16], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardPik.jpg")));
	cv::cvtColor(CardTemplate[17], CardTemplate[17], cv::COLOR_BGR2GRAY, 0);
	CardTemplate.push_back(cv::imread(cv::samples::findFile("CardJoker.jpg")));
	CardTemplate.push_back(cv::imread(cv::samples::findFile("bialy.jpg")));
}

void OpenCVClass::Wykrywanie(cv::Mat inputimg, bool &WlaczeniePrzetwarzania) {
	Card.clear();																		//czyszczenie wektora z zapisanym poprzednio kartami
	cv::Mat mask;
	cv::inRange(inputimg, cv::Scalar(ThreshholdValue, ThreshholdValue, ThreshholdValue), cv::Scalar(255, 255, 255), mask);	//progowanie koloru bia³ego
	cv::erode(mask, mask, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));	//erozja
	cv::dilate(mask, mask, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));	//dylatacja

	cv::Canny(mask, mask, 100, 200);													//wyznaczenie krawêdzi za pomoc¹ filtru Canny'ego
	cv::Mat tmp = mask.clone();
	cv::floodFill(tmp, cv::Point(0, 0), cv::Scalar(255));								//wype³nienie wszystko poza zawartoœci¹ krawêdzi
	cv::bitwise_not(tmp, tmp);															//odwrócenie wype³nienia
	mask = (tmp | mask);																//po³¹czenie pocz¹tkowego obrazu z krawêdziami i obrazu z poprzedniego kroku => otrzymujemy obraz z krawêdziami z wype³nionym wnêtrzem

	std::vector<std::vector<cv::Point>> contours;
	std::vector<std::vector<cv::Point>> contoursFinal;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(mask, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));	//wyznaczenie konturów (rozró¿nienie na unikalne karty)

	for (int i = 0; i < contours.size(); ++i) {	
		if (cv::contourArea(contours[i]) > (AreaCard * inputimg.size().width * inputimg.size().height / 100 * 0.7)) {	//znajdowanie konturów, których pole jest wiêksze ni¿ dane ustawione pole (dodatkowo usuwa szumy)
			contoursFinal.push_back(contours[i]);
		}
	}
	
	OpenCVKarta tmpCreate = { cv::Mat::zeros(cv::Size(310, 410), CV_8UC3), "","" };							//tymczasowe cechy karty
	for (int i = 0; i < contoursFinal.size(); ++i) {														//stworzenie wektora opisuj¹cy karty
		Card.push_back(tmpCreate);
	}
	
	std::vector<std::vector<cv::Point>> approx;
	approx = contoursFinal;
	cv::Mat outputimg = inputimg.clone();
	for (int i = 0; i < Card.size(); ++i) {
		approxPolyDP(contoursFinal[i], approx[i], 0.05 * arcLength(contoursFinal[i], true), true);				//aproksymowanie konturów za pomoc¹ odcinków	
		drawContours(outputimg, approx, i, cv::Scalar(0, 0, 255), 4, cv::LINE_8, hierarchy, 0);
	}

	std::vector<std::pair<std::vector<cv::Point>::iterator, std::vector<cv::Point>::iterator>> val1, val2;
	std::vector<cv::Point> minmax;
	for (int i = 0; i < Card.size(); ++i) {
		val1.push_back(std::minmax_element(approx[i].begin(), approx[i].end(), [](cv::Point const& a, cv::Point const& b) {return a.x < b.x; }));	//wyznaczenie punktów kart o minimalnym/maksymalnym x
		val2.push_back(std::minmax_element(approx[i].begin(), approx[i].end(), [](cv::Point const& a, cv::Point const& b) {return a.y < b.y; }));	//wyznaczenie punktów kart o minimalnym/maksymalnym y
	}
	
	for (int i = 0; i < Card.size(); ++i) {
		cv::circle(outputimg, cv::Point(val1[i].first->x, val1[i].first->y), 15, cv::Scalar(255, 0, 255), cv::FILLED, 8, 0);		//rysowanie min/max punktów
		cv::circle(outputimg, cv::Point(val1[i].second->x, val1[i].second->y), 15, cv::Scalar(0, 255, 0), cv::FILLED, 8, 0);
		cv::circle(outputimg, cv::Point(val2[i].first->x, val2[i].first->y), 15, cv::Scalar(255, 0, 0), cv::FILLED, 8, 0);
		cv::circle(outputimg, cv::Point(val2[i].second->x, val2[i].second->y), 15, cv::Scalar(0, 255, 255), cv::FILLED, 8, 0);
	}
	cv::Point2f PointsFromPic0[4];															//tablica punktów min/max x i y
	cv::Point2f PointsFromPic1[4];	
	cv::Point2f PointsNew[4];																//tablica wpó³rzêdnych rogów obrazka przedstawiaj¹cy kartê
	PointsNew[0] = cv::Point2f(0, 0);														//konkretne punkty obrazka (rogi)
	PointsNew[1] = cv::Point2f(0, 435);
	PointsNew[2] = cv::Point2f(310, 435);
	PointsNew[3] = cv::Point2f(310, 0);
	std::vector<cv::Mat> tmpCard;
	std::vector<cv::Mat> tmpCard1;
	int NumberOfBlackPixels1 = 0;
	int NumberOfBlackPixels2 = 0;
	cv::Mat tmpMark;

	for (int i = 0; i < Card.size(); i++) {
		tmpCard.push_back(cv::Mat::zeros(cv::Size(310, 435), CV_8UC3));
		tmpCard1.push_back(cv::Mat::zeros(cv::Size(310, 435), CV_8UC3));
		PointsFromPic0[0] = cv::Point2f(val2[i].first->x, val2[i].first->y);																		//przypisanie rogów kart
		PointsFromPic0[1] = cv::Point2f(val1[i].first->x, val1[i].first->y);
		PointsFromPic0[2] = cv::Point2f(val2[i].second->x, val2[i].second->y);
		PointsFromPic0[3] = cv::Point2f(val1[i].second->x, val1[i].second->y);
		cv::warpPerspective(inputimg, tmpCard[i], cv::getPerspectiveTransform(PointsFromPic0, PointsNew), cv::Size(310, 435), cv::INTER_LINEAR);	//stworzenie obrazka z wyprostowanymi kartami (w œrodku macierz transformacji)
		cv::erode(mask, mask, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, 1)));
		tmpMark = tmpCard[i](cv::Rect(0, 4, 60, 65));																								//wyciecie rogu z karty (bêdziemy porównywaæ 2 rogi w celu zidentyfikowania, ktory róg jest rogiem z znakiem)
		cv::inRange(tmpMark, cv::Scalar(ThreshholdValue, ThreshholdValue, ThreshholdValue), cv::Scalar(255, 255, 255), tmpMark);					//porogowanie wycinka
		NumberOfBlackPixels1 = cv::countNonZero(tmpMark);																							//zliczamy czarne punkty

		PointsFromPic1[0] = cv::Point2f(val1[i].first->x, val1[i].first->y);																		//to samo dla drugiej mo¿liwoœci u³o¿enia karty
		PointsFromPic1[1] = cv::Point2f(val2[i].second->x, val2[i].second->y);
		PointsFromPic1[2] = cv::Point2f(val1[i].second->x, val1[i].second->y);
		PointsFromPic1[3] = cv::Point2f(val2[i].first->x, val2[i].first->y);
		cv::warpPerspective(inputimg, tmpCard1[i], cv::getPerspectiveTransform(PointsFromPic1, PointsNew), cv::Size(310, 435), cv::INTER_LINEAR);

		tmpMark = tmpCard1[i](cv::Rect(0, 4, 60, 65));
		cv::inRange(tmpMark, cv::Scalar(ThreshholdValue, ThreshholdValue, ThreshholdValue), cv::Scalar(255, 255, 255), tmpMark);
		NumberOfBlackPixels2 = cv::countNonZero(tmpMark);
		if (NumberOfBlackPixels1 < NumberOfBlackPixels2) {																							//porównujemy, w którym rogu jest wiêcej pikseli czarnych => wiemy, ¿e dany róg ma iœæ w konkretne miejsce nowego obrazu
			Card[i].Karta = cv::Mat(tmpCard[i]);
		}
		else {
			Card[i].Karta = cv::Mat(tmpCard1[i]);
		}
	}
	
	double maxMark = 0;
	double maxSymbol = 0;
	int CardMark = 0;
	int CardSymbol = 0;
	double maxtmpMark=0;
	double maxtmpSymbol = 0;
	cv::Mat tmpSymbol;
	cv::Mat MatchedMark;
	cv::Mat MatchedSymbol;

	for (int i = 0; i < Card.size(); ++i) {
		maxMark = 0;
		maxSymbol = 0;
		CardMark = 0;
		CardSymbol = 0;
		maxtmpMark = 0;
		maxtmpSymbol = 0;
		cv::Mat tmpSymbol;
		tmpMark = Card[i].Karta(cv::Rect(0, 4, 50, 70));													//wyciêcie z obrazu karty znaku liczby (A, 2-10, J, K, Q)
		tmpSymbol = Card[i].Karta(cv::Rect(0, 60, 50, 60));													//wyciêcie z obrazu karty symbolu (trefl, karo, kier, pik)
		cv::Mat tmpMarkRed = tmpMark.clone();
		cv::Mat tmpMarkBlack = tmpMark.clone();
		cv::inRange(tmpMark, cv::Scalar(ThreshholdValue, ThreshholdValue, ThreshholdValue), cv::Scalar(255, 255, 255), tmpMark);				//progowanie wycinka
		cv::inRange(tmpSymbol, cv::Scalar(ThreshholdValue, ThreshholdValue, ThreshholdValue), cv::Scalar(255, 255, 255), tmpSymbol);			
		for (int j = 0; j < 14; ++j) {																		//porównywanie kolejnych znaków z wycinkiem
			cv::matchTemplate(tmpMark, CardTemplate[j], MatchedMark, cv::TM_CCOEFF_NORMED, cv::noArray());		//porównanie
			cv::minMaxLoc(MatchedMark, NULL, &maxtmpMark);															//wyznaczenie najwiêkszej wartoœci podobieñstwa
			if (maxtmpMark > maxMark) {																				//zapisanie najwiêkszej wartoœci (najbardziej podobne)
				maxMark = maxtmpMark;
				CardMark = j;
			}
		}

		if (CardMark != 13) {
			for (int k = 0; k < 4; ++k) {																		//porównywanie kolejnych symboli z wycinkiem
				cv::matchTemplate(tmpSymbol, CardTemplate[k + 14], MatchedSymbol, cv::TM_CCOEFF_NORMED, cv::noArray());
				cv::minMaxLoc(MatchedSymbol, NULL, &maxtmpSymbol);
				if (maxtmpSymbol > maxSymbol) {
					maxSymbol = maxtmpSymbol;
					CardSymbol = k;
				}
			}
			switch (CardSymbol) {									//przypisanie karcie symbolu
			case 0:
				Card[i].symbol = " Trefl ";
				break;
			case 1:;
				Card[i].symbol = " Karo ";
				break;
			case 2:
				Card[i].symbol = " Kier ";
				break;
			case 3:
				Card[i].symbol = " Pik ";
				break;
			}
		}
		else {
			Card[i].symbol = "";
		}

		switch (CardMark) {									//przypisanie karcie znaku
		case 13:
			Card[i].znak = " Joker ";
			break;
		case 12:;
			Card[i].znak = " Dama ";
			break;
		case 11:
			Card[i].znak = " Król ";
			break;
		case 10:
			Card[i].znak = " Walet ";
			break;
		case 9:
			Card[i].znak = " AS ";
			break;
		default:
			Card[i].znak = std::to_string(CardMark + 2);
			break;
		}	
		cv::cvtColor(tmpMarkRed, tmpMarkRed, cv::COLOR_BGR2HSV);								//wycinek symbolu w kolorze HSV
		cv::Mat mask1_, mask2_;
		cv::inRange(tmpMarkRed, cv::Scalar(0, 90, 70), cv::Scalar(8, 255, 255), mask1_);		//progowanie obrazu w HSV w poszukiwaniu czerwonego
		cv::inRange(tmpMarkRed, cv::Scalar(170, 90, 70), cv::Scalar(180, 255, 255), mask2_);
		mask1_ = mask1_ | mask2_;
		if (cv::countNonZero(mask1_) > 0) {			//zliczanie czerwonych punktów, je¿eli wystêpuj¹ to znaczy, ¿e kolor to czerwony, jak nie to czarny
			Card[i].kolor = "Czerwona";
		}
		else {
			Card[i].kolor = "Czarna";
		}
	}
	ObrazKoncowy = outputimg;
	WlaczeniePrzetwarzania = true;
}

bool OpenCVClass::Skora(cv::Mat inputimg) {
	bool Obecny = false;
	cv::Mat HSVimg;
	cv::cvtColor(inputimg, HSVimg, cv::COLOR_BGR2HSV);											//zdjecie w HSV
	cv::inRange(HSVimg, cv::Scalar(0, 48, 60), cv::Scalar(30, 255, 255), HSVimg);				//progowanie dla odcieni skóry
	cv::erode(HSVimg, HSVimg, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(41, 41)));		//erozja, du¿y kelner, bo nie interesuj¹ nas ma³e obiekty, a rêka jest du¿a
	if (cv::countNonZero(HSVimg) > 0) {															//szukanie czy którykolwiek piksel jest prawd¹ (jest skóra)
		Obecny = true;
	}
	return Obecny;
}