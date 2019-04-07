// SIFT feature extraction class interface
// Written by Sergey G. Kosov in 2016 for Project X
#pragma once

#include "ILocalFeatureExtractor.h"

namespace DirectGraphicalModels
{
namespace fex
{
// ================================ SIFT Class ==============================
/**
	* @brief SIFT (<a href="https://en.wikipedia.org/wiki/Scale-invariant_feature_transform" target="_blank">scale-invariant feature transform</a>) feature extraction class.
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CSIFT : public ILocalFeatureExtractor {
  public:
    /**
		* @brief Constructor.
		* @param img Input image of type \b CV_8UC1 or \b CV_8UC3.
		*/
    CSIFT( const Mat& img )
        : ILocalFeatureExtractor( img ) {}
    virtual ~CSIFT( void ) {}

    virtual Mat get( void ) const { return get( m_img ); }

    /**
		* @brief Extracts the SIFT feature.
		* @details For each pixel of the source image this function performs the scale-invariant feature transform.
		* @param img Input image of type \b CV_8UC1 or \b CV_8UC3.
		* @return Common feature extractor class with extracted SIFT feature of type \b CV_8UC{128}.
		*/
    static Mat get( const Mat& img );
};
}
}