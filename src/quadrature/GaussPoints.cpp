/*=========================================================================

  Program: FEMUS
  Module: Gauss
  Authors: Eugenio Aulisa, Giorgio Bornia
 
  Copyright (c) FEMTTU
  All rights reserved. 

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notice for more information.

  =========================================================================*/

#include "GaussPoints.hpp"
#include <iostream>
#include <stdlib.h> 
#include <string.h> 


Gauss::Gauss(const char *solid, const char *order_gauss){
      if (!strcmp(order_gauss,"zero")  || !strcmp(order_gauss,"first")) {
	gauss_order=0;
      } 
      else if (!strcmp(order_gauss,"second") || !strcmp(order_gauss,"third") ) {
	gauss_order=1;
      } 
      else if (!strcmp(order_gauss,"fourth") || !strcmp(order_gauss,"fifth") ) {
	gauss_order=2;
      } 
      else if (!strcmp(order_gauss,"sixth")  || !strcmp(order_gauss,"seventh") ) {
	gauss_order=3;
      } 
      else if (!strcmp(order_gauss,"eighth") || !strcmp(order_gauss,"ninth") ) {
	gauss_order=4;
      } else {
	std::cout<<order_gauss<<"is not a valid option for the Gauss points of"<<solid<<std::endl;
	exit(0);
      }

      if (!strcmp(solid,"hex")) {  
	GaussWeight = hex_gauss::Gauss[gauss_order];
	GaussPoints = hex_gauss::GaussPoints[gauss_order];  
      }
      else if (!strcmp(solid,"wedge")) {
	GaussWeight = wedge_gauss::Gauss[gauss_order];
	GaussPoints = wedge_gauss::GaussPoints[gauss_order];
      }
      else if (!strcmp(solid,"tet")) {
	GaussWeight = tet_gauss::Gauss[gauss_order];
	GaussPoints = tet_gauss::GaussPoints[gauss_order];
      }
      else if (!strcmp(solid,"quad")) {
	GaussWeight = quad_gauss::Gauss[gauss_order];
	GaussPoints = quad_gauss::GaussPoints[gauss_order];
      }
      else if (!strcmp(solid,"tri")) {
	GaussWeight = tri_gauss::Gauss[gauss_order];
	GaussPoints = tri_gauss::GaussPoints[gauss_order];
      }	
      else if (!strcmp(solid,"line")) {
	GaussWeight = line_gauss::Gauss[gauss_order];
	GaussPoints = line_gauss::GaussPoints[gauss_order];
      }
      else {
	std::cout<<solid<<" is not a valid option"<<std::endl; 
	abort();
      }
      
    }
  








  // ************** HEX_GAUSS ***************
const unsigned hex_gauss::GaussPoints[5]= {1,8,27,64,125};
const double * hex_gauss::Gauss[5]= { Gauss0[0], Gauss1[0], Gauss2[0], Gauss3[0], Gauss4[0] };


const double hex_gauss::Gauss0[4][1]= {{8},  {0},  {0},  {0} };

 const double hex_gauss::Gauss1[4][8]= {{1,1,1,1,1,1,1,1},
  {-0.57735026918963,-0.57735026918963,-0.57735026918963,-0.57735026918963,0.57735026918963,0.57735026918963,0.57735026918963,0.57735026918963},
  {-0.57735026918963,-0.57735026918963,0.57735026918963,0.57735026918963,-0.57735026918963,-0.57735026918963,0.57735026918963,0.57735026918963},
  {-0.57735026918963,0.57735026918963,-0.57735026918963,0.57735026918963,-0.57735026918963,0.57735026918963,-0.57735026918963,0.57735026918963}
};

 const double hex_gauss::Gauss2[4][27]= {{0.17146776406036,0.27434842249657,0.17146776406036,0.27434842249657,0.43895747599451,0.27434842249657,0.17146776406036,0.27434842249657,0.17146776406036,0.27434842249657,0.43895747599451,0.27434842249657,0.43895747599451,0.70233196159122,0.43895747599451,0.27434842249657,0.43895747599451,0.27434842249657,0.17146776406036,0.27434842249657,0.17146776406036,0.27434842249657,0.43895747599451,0.27434842249657,0.17146776406036,0.27434842249657,0.17146776406036},
  {-0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,0,0,0,0,0,0,0,0,0,0.77459666924148,0.77459666924148,0.77459666924148,0.77459666924148,0.77459666924148,0.77459666924148,0.77459666924148,0.77459666924148,0.77459666924148},
  {-0.77459666924148,-0.77459666924148,-0.77459666924148,0,0,0,0.77459666924148,0.77459666924148,0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,0,0,0,0.77459666924148,0.77459666924148,0.77459666924148,-0.77459666924148,-0.77459666924148,-0.77459666924148,0,0,0,0.77459666924148,0.77459666924148,0.77459666924148},
  {-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148}
};

 const double hex_gauss::Gauss3[4][64]= {{0.042091477490532,0.078911515795071,0.078911515795071,0.042091477490532,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.042091477490532,0.078911515795071,0.078911515795071,0.042091477490532,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.14794033605678,0.27735296695391,0.27735296695391,0.14794033605678,0.14794033605678,0.27735296695391,0.27735296695391,0.14794033605678,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.14794033605678,0.27735296695391,0.27735296695391,0.14794033605678,0.14794033605678,0.27735296695391,0.27735296695391,0.14794033605678,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.042091477490532,0.078911515795071,0.078911515795071,0.042091477490532,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.078911515795071,0.14794033605678,0.14794033605678,0.078911515795071,0.042091477490532,0.078911515795071,0.078911515795071,0.042091477490532},
  {-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405},
  {-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405},
  {-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405}
};

 const double hex_gauss::Gauss4[4][125]= {{0.013299736420633,0.026867508765372,0.031934207352848,0.026867508765372,0.013299736420633,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.031934207352848,0.064512,0.076677730069345,0.064512,0.031934207352848,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.013299736420633,0.026867508765372,0.031934207352848,0.026867508765372,0.013299736420633,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.054276491234628,0.10964684245454,0.13032414106965,0.10964684245454,0.054276491234628,0.064512,0.13032414106965,0.1549007829622,0.13032414106965,0.064512,0.054276491234628,0.10964684245454,0.13032414106965,0.10964684245454,0.054276491234628,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.031934207352848,0.064512,0.076677730069345,0.064512,0.031934207352848,0.064512,0.13032414106965,0.1549007829622,0.13032414106965,0.064512,0.076677730069345,0.1549007829622,0.18411210973937,0.1549007829622,0.076677730069345,0.064512,0.13032414106965,0.1549007829622,0.13032414106965,0.064512,0.031934207352848,0.064512,0.076677730069345,0.064512,0.031934207352848,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.054276491234628,0.10964684245454,0.13032414106965,0.10964684245454,0.054276491234628,0.064512,0.13032414106965,0.1549007829622,0.13032414106965,0.064512,0.054276491234628,0.10964684245454,0.13032414106965,0.10964684245454,0.054276491234628,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.013299736420633,0.026867508765372,0.031934207352848,0.026867508765372,0.013299736420633,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.031934207352848,0.064512,0.076677730069345,0.064512,0.031934207352848,0.026867508765372,0.054276491234628,0.064512,0.054276491234628,0.026867508765372,0.013299736420633,0.026867508765372,0.031934207352848,0.026867508765372,0.013299736420633},
  {-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866},
  {-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,0,0,0,0,0,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,0,0,0,0,0,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,0,0,0,0,0,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,0,0,0,0,0,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,0,0,0,0,0,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866},
  {-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866}
};


 // ************** WEDGE ***************
const unsigned wedge_gauss::GaussPoints[5]= {1,8,21,52,95};
const double * wedge_gauss::Gauss[5]= { Gauss0[0], Gauss1[0], Gauss2[0], Gauss3[0], Gauss4[0]};


const double wedge_gauss::Gauss0[4][1]= {{1},
  {0.33333333333333},
  {0.33333333333333},
  {0}
};

const double wedge_gauss::Gauss1[4][8]= {{-0.28125,-0.28125,0.26041666666667,0.26041666666667,0.26041666666667,0.26041666666667,0.26041666666667,0.26041666666667},
  {0.33333333333333,0.33333333333333,0.6,0.6,0.2,0.2,0.2,0.2},
  {0.33333333333333,0.33333333333333,0.2,0.2,0.6,0.6,0.2,0.2},
  {-0.57735026918963,0.57735026918963,-0.57735026918963,0.57735026918963,-0.57735026918963,0.57735026918963,-0.57735026918963,0.57735026918963}
};

const double wedge_gauss::Gauss2[4][21]= {{0.0625,0.1,0.0625,0.034983105706896,0.055972969131034,0.034983105706896,0.034983105706896,0.055972969131034,0.034983105706896,0.034983105706896,0.055972969131034,0.034983105706896,0.036776153552363,0.05884184568378,0.036776153552363,0.036776153552363,0.05884184568378,0.036776153552363,0.036776153552363,0.05884184568378,0.036776153552363},
  {0.33333333333333,0.33333333333333,0.33333333333333,0.79742698535309,0.79742698535309,0.79742698535309,0.10128650732346,0.10128650732346,0.10128650732346,0.10128650732346,0.10128650732346,0.10128650732346,0.05971587178977,0.05971587178977,0.05971587178977,0.47014206410511,0.47014206410511,0.47014206410511,0.47014206410511,0.47014206410511,0.47014206410511},
  {0.33333333333333,0.33333333333333,0.33333333333333,0.10128650732346,0.10128650732346,0.10128650732346,0.79742698535309,0.79742698535309,0.79742698535309,0.10128650732346,0.10128650732346,0.10128650732346,0.47014206410511,0.47014206410511,0.47014206410511,0.05971587178977,0.05971587178977,0.05971587178977,0.47014206410511,0.47014206410511,0.47014206410511},
  {-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148}
};

const double wedge_gauss::Gauss3[4][52]= {{-0.026014332327752,-0.048770689906083,-0.048770689906083,-0.026014332327752,0.030544309089101,0.057263319627501,0.057263319627501,0.030544309089101,0.030544309089101,0.057263319627501,0.057263319627501,0.030544309089101,0.030544309089101,0.057263319627501,0.057263319627501,0.030544309089101,0.009278547190612,0.017395070613808,0.017395070613808,0.009278547190612,0.009278547190612,0.017395070613808,0.017395070613808,0.009278547190612,0.009278547190612,0.017395070613808,0.017395070613808,0.009278547190612,0.013412197676224,0.025144682768905,0.025144682768905,0.013412197676224,0.013412197676224,0.025144682768905,0.025144682768905,0.013412197676224,0.013412197676224,0.025144682768905,0.025144682768905,0.013412197676224,0.013412197676224,0.025144682768905,0.025144682768905,0.013412197676224,0.013412197676224,0.025144682768905,0.025144682768905,0.013412197676224,0.013412197676224,0.025144682768905,0.025144682768905,0.013412197676224},
  {0.33333333333333,0.33333333333333,0.33333333333333,0.33333333333333,0.47930806784192,0.47930806784192,0.47930806784192,0.47930806784192,0.26034596607904,0.26034596607904,0.26034596607904,0.26034596607904,0.26034596607904,0.26034596607904,0.26034596607904,0.26034596607904,0.86973979419557,0.86973979419557,0.86973979419557,0.86973979419557,0.065130102902216,0.065130102902216,0.065130102902216,0.065130102902216,0.065130102902216,0.065130102902216,0.065130102902216,0.065130102902216,0.63844418856981,0.63844418856981,0.63844418856981,0.63844418856981,0.63844418856981,0.63844418856981,0.63844418856981,0.63844418856981,0.048690315425316,0.048690315425316,0.048690315425316,0.048690315425316,0.048690315425316,0.048690315425316,0.048690315425316,0.048690315425316,0.31286549600488,0.31286549600488,0.31286549600488,0.31286549600488,0.31286549600488,0.31286549600488,0.31286549600488,0.31286549600488},
  {0.33333333333333,0.33333333333333,0.33333333333333,0.33333333333333,0.26034596607904,0.26034596607904,0.26034596607904,0.26034596607904,0.47930806784192,0.47930806784192,0.47930806784192,0.47930806784192,0.26034596607904,0.26034596607904,0.26034596607904,0.26034596607904,0.065130102902216,0.065130102902216,0.065130102902216,0.065130102902216,0.86973979419557,0.86973979419557,0.86973979419557,0.86973979419557,0.065130102902216,0.065130102902216,0.065130102902216,0.065130102902216,0.048690315425316,0.048690315425316,0.048690315425316,0.048690315425316,0.31286549600488,0.31286549600488,0.31286549600488,0.31286549600488,0.63844418856981,0.63844418856981,0.63844418856981,0.63844418856981,0.31286549600488,0.31286549600488,0.31286549600488,0.31286549600488,0.63844418856981,0.63844418856981,0.63844418856981,0.63844418856981,0.048690315425316,0.048690315425316,0.048690315425316,0.048690315425316},
  {-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405}
};

const double wedge_gauss::Gauss4[4][95]= {{0.01150704126072,0.023245989405946,0.027629738666667,0.023245989405946,0.01150704126072,0.0037120164325851,0.0074988429007482,0.0089129813333333,0.0074988429007482,0.0037120164325851,0.0037120164325851,0.0074988429007482,0.0089129813333333,0.0074988429007482,0.0037120164325851,0.0037120164325851,0.0074988429007482,0.0089129813333333,0.0074988429007482,0.0037120164325851,0.009219718311893,0.018625245999218,0.022137611377778,0.018625245999218,0.009219718311893,0.009219718311893,0.018625245999218,0.022137611377778,0.018625245999218,0.009219718311893,0.009219718311893,0.018625245999218,0.022137611377778,0.018625245999218,0.009219718311893,0.0094353454699826,0.01906084595224,0.022655357155556,0.01906084595224,0.0094353454699826,0.0094353454699826,0.01906084595224,0.022655357155556,0.01906084595224,0.0094353454699826,0.0094353454699826,0.01906084595224,0.022655357155556,0.01906084595224,0.0094353454699826,0.003030020024682,0.0061211054864291,0.0072754289777778,0.0061211054864291,0.003030020024682,0.003030020024682,0.0061211054864291,0.0072754289777778,0.0061211054864291,0.003030020024682,0.003030020024682,0.0061211054864291,0.0072754289777778,0.0061211054864291,0.003030020024682,0.0051275171532025,0.010358371602353,0.012311762488889,0.010358371602353,0.0051275171532025,0.0051275171532025,0.010358371602353,0.012311762488889,0.010358371602353,0.0051275171532025,0.0051275171532025,0.010358371602353,0.012311762488889,0.010358371602353,0.0051275171532025,0.0051275171532025,0.010358371602353,0.012311762488889,0.010358371602353,0.0051275171532025,0.0051275171532025,0.010358371602353,0.012311762488889,0.010358371602353,0.0051275171532025,0.0051275171532025,0.010358371602353,0.012311762488889,0.010358371602353,0.0051275171532025},
  {0.3333333,0.3333333,0.3333333,0.3333333,0.3333333,0.02063496,0.02063496,0.02063496,0.02063496,0.02063496,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.1258208,0.1258208,0.1258208,0.1258208,0.1258208,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.6235929,0.6235929,0.6235929,0.6235929,0.6235929,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.910541,0.910541,0.910541,0.910541,0.910541,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986,0.221963,0.221963,0.221963,0.221963,0.221963,0.221963,0.221963,0.221963,0.221963,0.221963},
  {0.3333333,0.3333333,0.3333333,0.3333333,0.3333333,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.02063496,0.02063496,0.02063496,0.02063496,0.02063496,0.4896825,0.4896825,0.4896825,0.4896825,0.4896825,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.1258208,0.1258208,0.1258208,0.1258208,0.1258208,0.4370896,0.4370896,0.4370896,0.4370896,0.4370896,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.6235929,0.6235929,0.6235929,0.6235929,0.6235929,0.1882035,0.1882035,0.1882035,0.1882035,0.1882035,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.910541,0.910541,0.910541,0.910541,0.910541,0.04472951,0.04472951,0.04472951,0.04472951,0.04472951,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986,0.221963,0.221963,0.221963,0.221963,0.221963,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.221963,0.221963,0.221963,0.221963,0.221963,0.03683841,0.03683841,0.03683841,0.03683841,0.03683841,0.7411986,0.7411986,0.7411986,0.7411986,0.7411986},
  {-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866}
};


// ************** TETRAHEDRA ***************
const unsigned tet_gauss::GaussPoints[5] = {1,5,15,31,45};
const double * tet_gauss::Gauss[5] = { Gauss0[0], Gauss1[0], Gauss2[0], Gauss3[0], Gauss4[0]};

const double tet_gauss::Gauss0[4][1] = {{0.16666666666667},
  {0.25},
  {0.25},
  {0.25}
};

const double tet_gauss::Gauss1[4][5] = {{-0.13333333333333,0.075,0.075,0.075,0.075},
  {0.25,0.5,0.16666666666667,0.16666666666667,0.16666666666667},
  {0.25,0.16666666666667,0.5,0.16666666666667,0.16666666666667},
  {0.25,0.16666666666667,0.16666666666667,0.5,0.16666666666667}
};

const double tet_gauss::Gauss2[4][15] = {{0.030283678097089,0.006026785714286,0.006026785714286,0.006026785714286,0.006026785714286,0.011645249086029,0.011645249086029,0.011645249086029,0.011645249086029,0.010949141561386,0.010949141561386,0.010949141561386,0.010949141561386,0.010949141561386,0.010949141561386},
  {0.25,0,0.33333333333333,0.33333333333333,0.33333333333333,0.72727272727273,0.090909090909091,0.090909090909091,0.090909090909091,0.43344984642634,0.43344984642634,0.43344984642634,0.066550153573664,0.066550153573664,0.066550153573664},
  {0.25,0.33333333333333,0,0.33333333333333,0.33333333333333,0.090909090909091,0.72727272727273,0.090909090909091,0.090909090909091,0.43344984642634,0.066550153573664,0.066550153573664,0.43344984642634,0.43344984642634,0.066550153573664},
  {0.25,0.33333333333333,0.33333333333333,0,0.33333333333333,0.090909090909091,0.090909090909091,0.72727272727273,0.090909090909091,0.066550153573664,0.43344984642634,0.066550153573664,0.43344984642634,0.066550153573664,0.43344984642634}
};

const double tet_gauss::Gauss3[4][31] = {{0.01826422,0.01059994,0.01059994,0.01059994,0.01059994,-0.06251774,-0.06251774,-0.06251774,-0.06251774,0.004891425,0.004891425,0.004891425,0.004891425,0.0009700176,0.0009700176,0.0009700176,0.0009700176,0.0009700176,0.0009700176,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732,0.02755732},
  {0.25,0.7653604,0.07821319,0.07821319,0.07821319,0.6344704,0.1218432,0.1218432,0.1218432,0.002382507,0.3325392,0.3325392,0.3325392,0,0,0,0.5,0.5,0.5,0.6,0.6,0.6,0.2,0.2,0.2,0.1,0.1,0.1,0.1,0.1,0.1},
  {0.25,0.07821319,0.7653604,0.07821319,0.07821319,0.1218432,0.6344704,0.1218432,0.1218432,0.3325392,0.002382507,0.3325392,0.3325392,0,0.5,0.5,0,0,0.5,0.2,0.1,0.1,0.6,0.1,0.1,0.6,0.6,0.2,0.2,0.1,0.1},
  {0.25,0.07821319,0.07821319,0.7653604,0.07821319,0.1218432,0.1218432,0.6344704,0.1218432,0.3325392,0.3325392,0.002382507,0.3325392,0.5,0,0.5,0,0.5,0,0.1,0.2,0.1,0.1,0.6,0.1,0.2,0.1,0.6,0.1,0.6,0.2}
};

const double tet_gauss::Gauss4[4][45] = {{-0.03932701,0.004081316,0.004081316,0.004081316,0.004081316,0.0006580868,0.0006580868,0.0006580868,0.0006580868,0.004384259,0.004384259,0.004384259,0.004384259,0.004384259,0.004384259,0.01383006,0.01383006,0.01383006,0.01383006,0.01383006,0.01383006,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.004240437,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874,0.00223874},
  {0.25,0.6175872,0.1274709,0.1274709,0.1274709,0.9037635,0.03207883,0.03207883,0.03207883,0.4502229,0.4502229,0.4502229,0.0497771,0.0497771,0.0497771,0.3162696,0.3162696,0.3162696,0.1837304,0.1837304,0.1837304,0.51328,0.51328,0.51328,0.02291779,0.02291779,0.02291779,0.2319011,0.2319011,0.2319011,0.2319011,0.2319011,0.2319011,0.1937465,0.1937465,0.1937465,0.7303134,0.7303134,0.7303134,0.03797005,0.03797005,0.03797005,0.03797005,0.03797005,0.03797005},
  {0.25,0.1274709,0.6175872,0.1274709,0.1274709,0.03207883,0.9037635,0.03207883,0.03207883,0.4502229,0.0497771,0.0497771,0.4502229,0.4502229,0.0497771,0.3162696,0.1837304,0.1837304,0.3162696,0.3162696,0.1837304,0.02291779,0.2319011,0.2319011,0.51328,0.2319011,0.2319011,0.51328,0.51328,0.02291779,0.02291779,0.2319011,0.2319011,0.7303134,0.03797005,0.03797005,0.1937465,0.03797005,0.03797005,0.1937465,0.1937465,0.7303134,0.7303134,0.03797005,0.03797005},
  {0.25,0.1274709,0.1274709,0.6175872,0.1274709,0.03207883,0.03207883,0.9037635,0.03207883,0.0497771,0.4502229,0.0497771,0.4502229,0.0497771,0.4502229,0.1837304,0.3162696,0.1837304,0.3162696,0.1837304,0.3162696,0.2319011,0.02291779,0.2319011,0.2319011,0.51328,0.2319011,0.02291779,0.2319011,0.51328,0.2319011,0.51328,0.02291779,0.03797005,0.7303134,0.03797005,0.03797005,0.1937465,0.03797005,0.7303134,0.03797005,0.1937465,0.03797005,0.1937465,0.7303134}
};


// ************** SQUARE ***************
//number of gauss point for the previous SQUARE vector
const unsigned quad_gauss::GaussPoints[5]= {1,4,9,16,25};
const double * quad_gauss::Gauss[5]= { Gauss0[0], Gauss1[0], Gauss2[0], Gauss3[0], Gauss4[0]};

//first row-weights, second row: x-coordinates, third row y-coordinate
const double  quad_gauss::Gauss0[3][1]= {{4},
  {0},
  {0}
};

const double  quad_gauss::Gauss1[3][4]= {{1,1,1,1},
  {-0.57735026918963,-0.57735026918963,0.57735026918963,0.57735026918963},
  {-0.57735026918963,0.57735026918963,-0.57735026918963,0.57735026918963}
};

const double  quad_gauss::Gauss2[3][9]= {{0.30864197530864,0.49382716049383,0.30864197530864,0.49382716049383,0.79012345679012,0.49382716049383,0.30864197530864,0.49382716049383,0.30864197530864},
  {-0.77459666924148,-0.77459666924148,-0.77459666924148,0,0,0,0.77459666924148,0.77459666924148,0.77459666924148},
  {-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148,-0.77459666924148,0,0.77459666924148}
};

const double  quad_gauss::Gauss3[3][16]= {{0.1210029932856,0.22685185185185,0.22685185185185,0.1210029932856,0.22685185185185,0.42529330301069,0.42529330301069,0.22685185185185,0.22685185185185,0.42529330301069,0.42529330301069,0.22685185185185,0.1210029932856,0.22685185185185,0.22685185185185,0.1210029932856},
  {-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.86113631159405,-0.33998104358486,-0.33998104358486,-0.33998104358486,-0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.33998104358486,0.86113631159405,0.86113631159405,0.86113631159405,0.86113631159405},
  {-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405,-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405}
};

const double  quad_gauss::Gauss4[3][25]= {{0.056134348862429,0.1134,0.13478507238752,0.1134,0.056134348862429,0.1134,0.22908540422399,0.27228653255075,0.22908540422399,0.1134,0.13478507238752,0.27228653255075,0.32363456790123,0.27228653255075,0.13478507238752,0.1134,0.22908540422399,0.27228653255075,0.22908540422399,0.1134,0.056134348862429,0.1134,0.13478507238752,0.1134,0.056134348862429},
  {-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.90617984593866,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,-0.53846931010568,0,0,0,0,0,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.53846931010568,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866,0.90617984593866},
  {-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866,-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866}
};


// ************** TRIANGLE ***************
const unsigned tri_gauss::GaussPoints[5]= {1,4,7,13,19};
const double * tri_gauss::Gauss[5]= { Gauss0[0], Gauss1[0], Gauss2[0], Gauss3[0], Gauss4[0]};

const double tri_gauss::Gauss0[3][1]= {{0.5},
  {0.33333333333333},
  {0.33333333333333}
};

const double tri_gauss::Gauss1[3][4]= {{-0.28125,0.26041666666667,0.26041666666667,0.26041666666667},
  {0.33333333333333,0.6,0.2,0.2},
  {0.33333333333333,0.2,0.6,0.2}
};

const double tri_gauss::Gauss2[3][7]= {{0.1125,0.062969590272414,0.062969590272414,0.062969590272414,0.066197076394253,0.066197076394253,0.066197076394253},
  {0.33333333333333,0.79742698535309,0.10128650732346,0.10128650732346,0.05971587178977,0.47014206410511,0.47014206410511},
  {0.33333333333333,0.10128650732346,0.79742698535309,0.10128650732346,0.47014206410511,0.05971587178977,0.47014206410511}
};

const double tri_gauss::Gauss3[3][13]= {{-0.074785022233835,0.087807628716602,0.087807628716602,0.087807628716602,0.026673617804419,0.026673617804419,0.026673617804419,0.038556880445128,0.038556880445128,0.038556880445128,0.038556880445128,0.038556880445128,0.038556880445128},
  {0.33333333333333,0.47930806784192,0.26034596607904,0.26034596607904,0.86973979419557,0.065130102902216,0.065130102902216,0.63844418856981,0.63844418856981,0.048690315425316,0.048690315425316,0.31286549600488,0.31286549600488},
  {0.33333333333333,0.26034596607904,0.47930806784192,0.26034596607904,0.065130102902216,0.86973979419557,0.065130102902216,0.048690315425316,0.31286549600488,0.63844418856981,0.31286549600488,0.63844418856981,0.048690315425316}
};

const double tri_gauss::Gauss4[3][19]= {{0.0485679,0.01566735,0.01566735,0.01566735,0.03891377,0.03891377,0.03891377,0.03982387,0.03982387,0.03982387,0.01278884,0.01278884,0.01278884,0.02164177,0.02164177,0.02164177,0.02164177,0.02164177,0.02164177},
  {0.3333333,0.02063496,0.4896825,0.4896825,0.1258208,0.4370896,0.4370896,0.6235929,0.1882035,0.1882035,0.910541,0.04472951,0.04472951,0.03683841,0.03683841,0.7411986,0.7411986,0.221963,0.221963},
  {0.3333333,0.4896825,0.02063496,0.4896825,0.4370896,0.1258208,0.4370896,0.1882035,0.6235929,0.1882035,0.04472951,0.910541,0.04472951,0.7411986,0.221963,0.03683841,0.221963,0.03683841,0.7411986}
};


// ************** LINE ***************
const unsigned line_gauss::GaussPoints[5]= {1,2,3,4,5};
const double * line_gauss::Gauss[5]= { Gauss0[0], Gauss1[0], Gauss2[0], Gauss3[0], Gauss4[0]};


//first row-weights, second row: x-coordinates
const double line_gauss::Gauss0[2][1]= {{2},
  {0}
};

const double line_gauss::Gauss1[2][2]= {{1,1},
  {-0.57735026918963,0.57735026918963}
};

const double line_gauss::Gauss2[2][3]= {{0.55555555555556,0.88888888888889,0.55555555555556},
  {-0.77459666924148,0,0.77459666924148}
};

const double line_gauss::Gauss3[2][4]= {{0.34785484513745,0.65214515486255,0.65214515486255,0.34785484513745},
  {-0.86113631159405,-0.33998104358486,0.33998104358486,0.86113631159405}
};

const double line_gauss::Gauss4[2][5]= {{0.23692688505619,0.47862867049937,0.56888888888889,0.47862867049937,0.23692688505619},
  {-0.90617984593866,-0.53846931010568,0,0.53846931010568,0.90617984593866}
};


