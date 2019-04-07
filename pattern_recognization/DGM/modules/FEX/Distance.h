// NDVI feature extraction class interface
// Written by Sergey G. Kosov in 2015 for Project X
#pragma once

#include "ILocalFeatureExtractor.h"

namespace DirectGraphicalModels
{
namespace fex
{
// ================================ Distance Class ==============================
/**
	* @brief Distance feature extraction class
	* @details This class is applied to perform the distance transformation.
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CDistance : public ILocalFeatureExtractor {
  public:
    /**
		* @brief Constructor.
		* @param img Input image of type \b CV_8UC1 or \b CV_8UC3.
		*/
    CDistance( const Mat& img )
        : ILocalFeatureExtractor( img ) {}
    virtual ~CDistance( void ) {}

    virtual Mat get( void ) const { return get( m_img ); }

    /**
		* @brief Extracts the distance feature.
		* @details For each pixel of the source image this function calculates the distance to the closest pixel, which value is larger or equal to \a threshold. 
		* Resulting feature image is multiplied by \a multiplier
		* @param img Input image of type \b CV_8UC1 or \b CV_8UC3.
		* @param threshold Threshold value. 
		* @param multiplier Amplification coefficient for the resulting feature image.
		* @return The distance feature image of type \b CV_8UC1.
		*/
    static Mat get( const Mat& img, byte threshold = 16, double multiplier = 4.0 );
};
}
}
