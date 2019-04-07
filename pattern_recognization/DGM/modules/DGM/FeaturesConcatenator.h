// Features Concatenator base abstract class
// Written by Sergey Kosov in 2015 for Project X
#pragma once

#include "macroses.h"
#include "types.h"

namespace DirectGraphicalModels
{
// ============================= Samples Concatenatenator Class =============================
/**
	* @brief Features concatenator base abstract class
	* @details This class allows for binding two feature vectors (\a e.g. two n-dimensinal points in feature space) together into a new feature vector
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CFeaturesConcatenator {
  public:
    /**
		* @brief Constructor
		* @param nFeatures Number of features
		*/
    CFeaturesConcatenator( word nFeatures )
        : m_nFeatures( nFeatures ) {}
    virtual ~CFeaturesConcatenator( void ) {}

    /**
		* @brief Returns the length of the concatenated feature vector
		* @returns Number of features in the concatenated feature vector
		*/
    virtual word getNumFeatures( void ) const = 0;
    /**
		* @brief Concatenated two feature vectors 
		* @param[in] featureVector1 The first feature vector: Mat(size: nFeatures x 1; type: CV_8UC1) 
		* @param[in] featureVector2 The second feature vector: Mat(size: nFeatures x 1; type: CV_8UC1) 
		* @param[out] dst The resulting feture vector: Mat(size: this->nFeaturs() x 1; type: CV_8UC1) 
		*/
    virtual void concatenate( const Mat& featureVector1, const Mat& featureVector2, Mat& dst ) const = 0;

  protected:
    word m_nFeatures;   ///< Number of features in the concatenated feature vector
};

// ============================= Simple Samples Concatenatenator Class =============================
/**
	* @brief Simple features concatenator class
	* @details This class concatenates two feature vectors \f$\textbf{f}_1\f$ and \f$\textbf{f}_2\f$ as follows:
	* \f[\textbf{dst} = \left\{f^{1}_{1},f^{2}_{1},f^{1}_{2},f^{2}_{2},\dots,f^{n}_{2},f^{n}_{2}\right\}\f]
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CSimpleFeaturesConcatenator : public CFeaturesConcatenator {
  public:
    /**
		* @brief Constructor
		* @param nFeatures Number of features
		*/
    CSimpleFeaturesConcatenator( word nFeatures )
        : CFeaturesConcatenator( nFeatures ) {}
    virtual ~CSimpleFeaturesConcatenator( void ) {}
    virtual word getNumFeatures( void ) const { return 2 * m_nFeatures; }
    virtual void concatenate( const Mat& featureVector1, const Mat& featureVector2, Mat& dst ) const {
        // Assertions
        DGM_ASSERT( featureVector1.size() == featureVector2.size() );
        DGM_ASSERT( featureVector1.type() == featureVector2.type() );
        // DGM_ASSERT ( dst )

        for ( word f = 0; f < m_nFeatures; f++ ) {
            dst.at< byte >( 2 * f, 0 )     = featureVector1.at< byte >( f, 0 );
            dst.at< byte >( 2 * f + 1, 0 ) = featureVector2.at< byte >( f, 0 );
        }
    }
};

// ============================= Simple Samples Concatenatenator Class =============================
/**
	* @brief Difference features concatenator class
	* @details This class concatenates two feature vectors \f$\textbf{f}_1\f$ and \f$\textbf{f}_2\f$ as follows:
	* \f[\textbf{dst} = \left\{127.5 + f^{1}_{1} - f^{2}_{1}, 127.5 + f^{1}_{2} - f^{2}_{2},\dots,127.5 + f^{n}_{2}-f^{n}_{2}\right\}\f]
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CDiffFeaturesConcatenator : public CFeaturesConcatenator {
  public:
    /**
		* @brief Constructor
		* @param nFeatures Number of features
		*/
    CDiffFeaturesConcatenator( word nFeatures )
        : CFeaturesConcatenator( nFeatures ) {}
    virtual ~CDiffFeaturesConcatenator( void ) {}
    virtual word getNumFeatures( void ) const { return 1 * m_nFeatures; }
    virtual void concatenate( const Mat& featureVector1, const Mat& featureVector2, Mat& dst ) const {
        // Assertions
        DGM_ASSERT( featureVector1.size() == featureVector2.size() );
        DGM_ASSERT( featureVector1.type() == featureVector2.type() );
        // DGM_ASSERT ( dst )

        for ( word f = 0; f < m_nFeatures; f++ ) {
            dst.at< byte >( 1 * f, 0 ) = static_cast< byte >( MIN( 255, MAX( 0, 127.5 + 1.0 * featureVector1.at< byte >( f, 0 ) - 1.0 * featureVector2.at< byte >( f, 0 ) ) ) );
        }
    }
};
}
