// Bayes training class interface
// Written by Sergey G. Kosov in 2012 - 2015 for Project X
#pragma once

#include "PriorNode.h"
#include "TrainNode.h"

namespace DirectGraphicalModels
{
class IPDF;

// ====================== Bayes Train Class =====================
/** 
	* @ingroup moduleTrainNode
	* @brief Bayes training class 
	* @details This class implements the <a href="http://en.wikipedia.org/wiki/Naive_Bayes_classifier" target="blank">naive Bayes classifier</a>,
	* which is based on strong (naive) independence assumptions between the features.
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CTrainNodeBayes : public CTrainNode, private CPriorNode {
  public:
    /**
		* @brief Constructor
		* @param nStates Number of states (classes)
		* @param nFeatures Number of features
		*/
    CTrainNodeBayes( byte nStates, word nFeatures );
    virtual ~CTrainNodeBayes( void );

    virtual void reset( void );

    virtual void addFeatureVec( const Mat& featureVector, byte gt );
    virtual void train( bool doClean = false );

    /**
		* @brief Returns the normalized probability density function (PDF) for specific state (class) and feature 
		* @param state The state (class)
		* @param feature The feature
		* @return The probability density function 
		*/
    IPDF* getPDF( byte state, word feature ) const { return m_pPDF[state][feature]; }
    /**
		* @brief Returns the 2D normalized probability density function (PDF) for specific state (class) 
		* @note Used for test purposes. Use this function when only 2 features are in use. 
		* @param state The state (class)
		* @return The probability density function for 2 features
		*/
    IPDF* getPDF2D( byte state ) const { return m_pPDF2D[state]; }
    /**
		* @brief Smothes the underlying Probability Density Functions (PDFs)
		* @param nIt Number of smooth iterations
		*/
    void smooth( int nIt = 1 );

  protected:
    virtual void saveFile( FILE* pFile ) const;
    virtual void loadFile( FILE* pFile );
    /**
		* @brief Calculates the node potential, based on the feature vector.
		* @details This function calculates the potentials of the node, described with the sample \b featureVector (\f$ \textbf{f} \f$):
		* \f[ nodePot_s = prior_s\cdot\prod_{f\in\mathbb{F}} (H_{s,f}.data[\textbf{f}_f] / H_{s,f}.n); \forall s\in\mathbb{S}, \f] 
		* where \f$\mathbb{S}\f$ and \f$\mathbb{F}\f$ are sets of all states (classes) and features correspondently. In other words, the indexes: 
		* \f$ s \in [0; nStates) \f$ and \f$ f \in [0; nFeatures) \f$.
		* Here \f$ H.data[256] \f$ is a 1D histogram, \f$ H.n \f$ is the number of entries in histogram, \a i.e.  \f$ H.n = \sum^{255}_{i = 0} H.data[i] \f$.
		* And \f$ \textbf{f}_f \in [0; 255], \forall f \in [0; nFeatures) \f$, \a i.e. has (type: CV_8UC1).
		* @param[in]	featureVector Multi-dimensinal point \f$\textbf{f}\f$: Mat(size: nFeatures x 1; type: CV_{XX}C1)
		* @param[in,out]	potential %Node potentials: Mat(size: nStates x 1; type: CV_32FC1). This parameter should be preinitialized and set to value 0.
		* @param[in,out]	mask Relevant %Node potentials: Mat(size: nStates x 1; type: CV_8UC1). This parameter should be preinitialized and set to value 1 (all potentials are relevant).
		*/
    void calculateNodePotentials( const Mat& featureVector, Mat& potential, Mat& mask ) const;

  private:
    IPDF*** m_pPDF;    ///< The 1D PDF for node potentials	 [state][feature]
    IPDF** m_pPDF2D;   ///< The 2D data histogram for node potentials and 2 features[state]
    Mat m_prior;       ///< The class prior probability vector
};
}
