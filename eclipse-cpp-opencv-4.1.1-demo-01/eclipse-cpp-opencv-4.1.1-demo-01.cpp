// һ�μ򵥵Ĳ��Դ���
#include <opencv2/opencv.hpp>
int main() {
  cv::Mat img = cv::imread("D:\\PlateDetect\\��������\\����\\����Դ����\\1.jpg"); //�ĳ����Լ���ͼƬ·��
  cv::imshow("plate", img);
  cv::waitKey(0);
}
