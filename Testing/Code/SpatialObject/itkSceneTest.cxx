/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkSceneTest.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

// Disable warning for long symbol names in this file only
#ifdef _MSC_VER
#pragma warning ( disable : 4786 )
#endif

/** This is a test file for the itkScene class. */
#include "itkScene.h"
#include "itkEllipseSpatialObject.h"

int itkSceneTest(int, char* [])
{
  // Create the scene
  typedef itk::Scene<3>  SceneType;
  SceneType::Pointer scene = SceneType::New();

  // Create two ellipses to put in the scene
  typedef itk::EllipseSpatialObject<3>   EllipseType;
  EllipseType::Pointer ellipse1 = EllipseType::New();
  EllipseType::Pointer ellipse2 = EllipseType::New();

  scene->AddSpatialObject(ellipse1);
  scene->AddSpatialObject(ellipse2);

  if(scene->GetNumberOfObjects() !=2 )
  {
    std::cout << "[FAILURE]" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "[PASSED]" << std::endl;

  scene->GetMTime(); // coverage
  std::cout << scene << std::endl;

  std::cout << "[DONE]" << std::endl;

  return EXIT_SUCCESS;

}
