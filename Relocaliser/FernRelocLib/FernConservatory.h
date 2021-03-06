/**
* This file is part of RESLAM.
*
* Copyright (C) 2014-2019 Schenk Fabian <schenk at icg dot tugraz dot at> (Graz University of Technology)
* For more information see <https://github.com/fabianschenk/RESLAM/>
*
* RESLAM is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* RESLAM is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with RESLAM. If not, see <http://www.gnu.org/licenses/>.
* 
*
*  If you use this software please cite at least one of the following publications:
*  - RESLAM: A robust edge-based SLAM system,  Schenk Fabian, Fraundorfer Friedrich, ICRA 2019
*  - Robust Edge-based Visual Odometry using Machine-Learned Edges, Schenk Fabian, Fraundorfer Friedrich, IROS 2017
*  - Combining Edge Images and Depth Maps for Robust Visual Odometry, Schenk Fabian, Fraundorfer Friedrich, BMVC 2017
*/

/**
 * 
 * Some of the code is also part of InfiniTAM
 * Copyright 2014-2017 Oxford University Innovation Limited and the authors of InfiniTAM
 * 
 */
#pragma once
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "../../config/Defines.h"
namespace RESLAM
{
namespace FernRelocLib
{
	struct FernTester
	{
        cv::Point2i location;
		float threshold;
	};

	class FernConservatory
	{
	public:
		FernConservatory(const cv::Size2i &imgSize, const cv::Vec2f &bounds);
		~FernConservatory(void);

		// takes a (small) image, applies the binary tests in the ferns, creates
		// the code fragments as an array
        void computeCodeDepth(const cv::Mat& img, char *codeFragments) const; //depth
        void computeCodeRGB(const cv::Mat& img, char *codeFragments) const; //RGB
        void computeCodeRGBDepth(const cv::Mat& imgRGB, const cv::Mat& imgDepth, char *codeFragments) const; //RGB


		void SaveToFile(const std::string &fernsFileName);
		void LoadFromFile(const std::string &fernsFileName);

		int getNumFerns(void) const { return FernDBNumFerns; }
		int getNumCodes(void) const { return FernDBNumCodes; }
		int getNumDecisions(void) const { return FernDBNumDecisionsionsPerFern; }

		FernConservatory(const FernConservatory&) = delete; //no copies
	private:
		FernTester *mEncoders;
	};
}
}
