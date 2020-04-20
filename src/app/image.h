#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/opencv.hpp>
#include <string>
//#include "glfw/glfw3.h"
#include "glad/glad.h"

namespace Chaf
{
	class CImage
	{
	public:
		CImage();
		void Init();

	public:
		bool Load_Image(const std::string path, const std::string name="demo");
		void Set_Display_Output();
		void Set_DIsplay_Input();
		void Reset_Image_Size();
		void Set_Image_Size(const int width, const int height);
		void Reset();

	public:
		cv::Mat input_img;
		cv::Mat output_img;

		std::vector<cv::Rect> res_boxes;
		std::vector<std::string> res_classes;

	public:
		int width();
		int height();
		int texture();
		std::string name();

	private:
		bool LoadTexture(GLuint* out_texture);
		unsigned char* Mat_to_Byte(const cv::Mat img);

	private:
		std::string img_path;
		std::string img_name;
		GLuint img_gui_texture;

		cv::Mat display_img;
		
		int img_width = 0;
		int img_height = 0;


	};
}

#endif