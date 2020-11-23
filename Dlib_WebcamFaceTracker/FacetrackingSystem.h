#pragma once
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/serialize.h>
#include <vector>
#include <Windows.h>

// �t�B���^�p�W��
#define LPF_VALUE_PRE 0.4
#define LPF_VALUE_CUR (1 - LPF_VALUE_PRE)
#define FACIAL_POINTS 68

// ��p�x�̍ő�l
#define MAX_FACE_ANGLE 35





// ��N���X
class Face {
public:
	float h_pos;
	float v_pos;
	float yaw;
	float pitch;
	float roll;
	float eye_L_X;
	float eye_L_Y;
};

// �ڗ̈�
typedef struct eye_region {
	cv::Point2d top;
	cv::Point2d bottom;
}EYE_REGION;

// ����
typedef struct iris {
	cv::Point2f center;
	double radius;
}IRIS;

// ���[�J���֐�
void Trackingsystem(cv::VideoCapture cap);
static void DrawFaceBox(cv::Mat frame, std::vector<cv::Point2d> reprojectdst); // ��g����
static void SetInitialPoints(std::vector<cv::Point3d>* in_BoxPoints, std::vector<cv::Point3d>* in_FaceLandmarkPoints); // ��튯�_�̐ݒ�
static double calc_dst(cv::Point2d a, cv::Point2d b);
static IRIS detect_iris(cv::Mat eye_img);
static cv::Mat threshold_by_ptile(cv::Mat img_gs, double ratio);