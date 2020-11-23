#include "FacetrackingSystem.h"
#include "CameraDetector.h"

int main(void) {
	// カメラデバイスの取得
	int dev_id;
	if(CameraDeviceDetect() != 0) return -1;

	// 選択
	std::cout << "Select device: ";
	std::cin >> dev_id;

	// カメラオープン
	cv::VideoCapture cap(dev_id);
	if (!cap.isOpened()) {

		std::cout << "Unable to connect." << std::endl;
		return -1;

	}

	Trackingsystem(cap);

	return 0;
}