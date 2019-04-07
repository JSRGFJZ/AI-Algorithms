// Global-features Extraction class
// Writtem by Sergey G. Kosov in 2016 for Project X
#pragma once

#include "Global.h"
#include "IFeatureExtractor.h"

namespace DirectGraphicalModels
{
namespace fex
{
// ================================ Base GLOBAL Feature Extractor Class ==============================
/**
	* @ingroup moduleGFEX
	* @brief Interface class for global feature extraction algorithms
	* @details The derived algorithms are supposed to extract one feature per image
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CGlobalFeatureExtractor : public IFeatureExtractor {
  public:
    /**
		* @brief Constructor.
		* @param img Input image.
		*/
    CGlobalFeatureExtractor( const Mat& img )
        : IFeatureExtractor( img ) {}
    virtual ~CGlobalFeatureExtractor( void ) {}

    /**
		* @brief Returns the number of staight lines in the image.
		* @param threshold1 The higher threshold of the two, passed to the \a Canny edge detector(the lower one is twice smaller).
		* @param threshold2 The accumulator threshold parameter.Only those lines are detected that get enough votes(> \b threshold2).
		* @returns The number of staight lines in the source image
		*/
    size_t getNumLines( int threshold1 = 100, int threshold2 = 50 ) const { return global::getNumLines( m_img, threshold1, threshold2 ); }
    /**
		* @brief Returns the number of circles in the source image
		* @param threshold1 The higher threshold of the two, passed to the \a Canny edge detector (the lower one is twice smaller).
		* @param threshold2 The accumulator threshold for the circle centers at the detection stage. The smaller it is, the more false circles may be detected. 
		* @return The number of circles in the source image
		*/
    size_t getNumCircles( int threshold1 = 100, int threshold2 = 30 ) const { return global::getNumCircles( m_img, threshold1, threshold2 ); }
    /**
		* @brief Returns the weighted-mean transparancy of the source image
		* @details The weighted-mean transparancy is evaluated as follows:
		* \f[ \frac{1}{width \times hight} \sum^{width}_{x = 1}\sum^{height}_{y = 1} (1 - d_{x,y}) \cdot (img_{x,y} - \mu), \f]
		* where \f$d_{x,y}\f$ is the normalized distance between a position \f$(x,y)\f$ and the image center.
		* @returns The weighted-mean transparancy of the source image.
		*/
    float getOpacity( void ) const { return global::getOpacity( m_img ); }
    /**
		* @brief Retunrs the variance of the source image.
		* @returns The variance of the source image
		*/
    float getVariance( void ) { return global::getVariance( m_img ); }
    /**
		* @brief Returns the number of non-zero pixels in the source image.
		* @returns The number of non-zero pixels in the source image.
		*/
    int getArea( void ) { return global::getArea( m_img ); }
    /**
		* @brief Returns the perimeter of an object in the source image.
		* @details This function retunrs the number of edge pixels, assuming a pixel to belong to an edge if any of its neighboring pixels have different value.
		* @returns The number of edge pixels in the source image.
		*/
    int getPerimeter( void ) { return global::getPerimeter( m_img ); }
    /**
		* @brief Returns the compactness of the object in the source image.
		* @details The compactness is calculates as follows: \f$\frac{P^2}{4\Pi S}\f$, where \a P and \a S are perimeter and area of the object, respectively.
		* @returns The compactness of the object in the source image.
		*/
    float getCompactness( void ) { return global::getCompactness( m_img ); }
};
}
}