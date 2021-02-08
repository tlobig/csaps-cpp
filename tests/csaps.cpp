#include "csaps.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Univariate auto smoothing", "[csaps]")
{
  SECTION("21 points")
  {
    const size_t pcount = 21;

    csaps::DoubleArray xdata(pcount);
    xdata <<
      0, 0.314159265358979, 0.628318530717959, 0.942477796076938, 1.25663706143592,
      1.5707963267949, 1.88495559215388, 2.19911485751286, 2.51327412287183,
      2.82743338823081, 3.14159265358979, 3.45575191894877, 3.76991118430775,
      4.08407044966673, 4.39822971502571, 4.71238898038469, 5.02654824574367,
      5.34070751110265, 5.65486677646163, 5.96902604182061, 6.28318530717959;

    csaps::DoubleArray ydata(pcount);
    ydata <<
      -0.0308480549621108, 0.321227871478931, 0.581558026193185, 0.837552852746324,
      0.979054097107034, 0.977259260528264, 0.928702941809463, 0.839204212128449,
      0.633599187660844, 0.346610257849157, -0.0142182730042132, -0.308917481822601,
      -0.569438958775259, -0.787746791676657, -0.964031440816114, -0.993880381393437,
      -0.950748199764373, -0.857640149415879, -0.560502590131236, -0.270752875311336,
      -0.013511401609863;

    const size_t xidata_size = 120;

    csaps::UnivariateCubicSmoothingSpline sp(xdata, ydata);

    csaps::DoubleArray xidata;
    csaps::DoubleArray yidata = std::get<0>(sp(xidata_size, xidata));

    csaps::DoubleArray desired_yidata(xidata_size);
    desired_yidata <<
      -0.0235609972734076, 0.0342554130011887, 0.0917604768962524, 0.148642848032251,
      0.204591180029653, 0.259294126508924, 0.312440351240669, 0.363812477806949,
      0.413516746584544, 0.461729017734914, 0.508625151419519, 0.554381007799819,
      0.59917235322775, 0.643050468816528, 0.685696744725134, 0.726724183969348,
      0.765745789564952, 0.802374564527724, 0.836223661222756, 0.866972935842014,
      0.894473725242276, 0.918604542323229, 0.939243899984561, 0.956270311125961,
      0.969562963467305, 0.979144106608908, 0.985355180101302, 0.988580811987222,
      0.989205630309408, 0.987614263110598, 0.984190455154498, 0.979211074442117,
      0.972745418402277, 0.964838935929978, 0.955537075920216, 0.944885287267991,
      0.932927490881626, 0.919589386774692, 0.904596282338286, 0.88765407387356,
      0.868468657681665, 0.846745930063754, 0.822194253635299, 0.794653654806466,
      0.76415937272086, 0.73076244387651, 0.694513904771452, 0.655464791903716,
      0.613667457460308, 0.569225401037061, 0.522308564522944, 0.473091330257213,
      0.421748080579123, 0.368453197827928, 0.313386409949078, 0.256884901954999,
      0.199465270307742, 0.141653871417018, 0.0839770616925367, 0.0269611975440111,
      -0.0288790108903068, -0.0832967177157068, -0.136312941281018, -0.187960346206531,
      -0.238271597112534, -0.287279358619317, -0.335016296758048, -0.381515103495269,
      -0.426808493559216, -0.47092918245087, -0.513909885671217, -0.555783318721242,
      -0.596577904130849, -0.636257828862702, -0.674737831212602, -0.711931377484918,
      -0.74775193398402, -0.782112967014277, -0.814916147256374, -0.845917383266534,
      -0.874774272419685, -0.901142570534573, -0.92467803342995, -0.945036416924564,
      -0.961906593475871, -0.975319318974765, -0.985507042193372, -0.99270481875293,
      -0.997147704274675, -0.999070754379844, -0.998693087710525, -0.996095112164348,
      -0.991285814362011, -0.984273590665723, -0.975066837437697, -0.963673951040142,
      -0.95006546257481, -0.933932055202886, -0.914838983410284, -0.892350910038224,
      -0.86603249792793, -0.835448409920623, -0.800282146364173, -0.76096707154776,
      -0.718228237424455, -0.672791349033563, -0.625382111414392, -0.576726229606248,
      -0.527490657611685, -0.478024578050658, -0.428570228926154, -0.379369767649891,
      -0.330665351633583, -0.282699138288946, -0.23565484652653, -0.189444552928148,
      -0.143901464676976, -0.098858780436212, -0.0541496988690512, -0.00960741863869263;

    REQUIRE(yidata.isApprox(desired_yidata));
  }

  SECTION("4 points")
  {
    const size_t pcount = 4;

    csaps::DoubleArray xdata(pcount);
    xdata << 1, 2, 4, 6;

    csaps::DoubleArray ydata(pcount);
    ydata << 2, 4, 5, 7;

    csaps::UnivariateCubicSmoothingSpline sp(xdata, ydata);

    const size_t xidata_size = 10;

    csaps::DoubleArray xidata;
    csaps::DoubleArray yidata = std::get<0>(sp(xidata_size, xidata));

    csaps::DoubleArray desired_yidata(xidata_size);
    desired_yidata <<
      2.2579392157892, 3.0231172855707, 3.6937304019483,
      4.21971044584031, 4.65026761247821, 5.04804510368134,
      5.47288175793241, 5.94265482897362, 6.44293945952166,
      6.95847986982311;

    REQUIRE(yidata.isApprox(desired_yidata));
  }

  SECTION("2 points")
  {
    const size_t pcount = 2;

    csaps::DoubleArray xdata(pcount); xdata << 1., 2.;
    csaps::DoubleArray ydata(pcount); ydata << 3., 4.;
    csaps::DoubleArray xidata(pcount + 1); xidata << 1., 1.5, 2.;

    csaps::UnivariateCubicSmoothingSpline sp(xdata, ydata);

    csaps::DoubleArray yidata = std::get<0>(sp(xidata));

    csaps::DoubleArray desired_yidata(pcount + 1); 
    desired_yidata << 3., 3.5, 4.;

    REQUIRE(yidata.isApprox(desired_yidata));
  }
}


TEST_CASE("Diff 4 elements", "[diff]")
{
  csaps::DoubleArray arr(4);
  arr << 1, 2, 4, 6;

  csaps::DoubleArray d = csaps::Diff(arr);

  csaps::DoubleArray dd(3);
  dd << 1, 2, 2;

  REQUIRE(d.isApprox(dd));
}


TEST_CASE("Make diagonal sparse matrix", "[spdiag][hide]")
{
  csaps::DoubleArray2D diags(3, 3); 
  diags <<
    1, 2, 3,
    4, 5, 6,
    7, 8, 9;
  
  csaps::IndexArray offsets(3);

  SECTION("Make 3x3 matrix with offsets -1 0 1")
  {
    offsets << -1, 0, 1;

    csaps::DoubleSparseMatrix m = csaps::MakeSparseDiagMatrix(diags, offsets, 3, 3);

    csaps::DoubleSparseMatrix dm(3, 3);
    dm.coeffRef(0, 0) = 4;
    dm.coeffRef(1, 0) = 1;
    dm.coeffRef(0, 1) = 8;
    dm.coeffRef(1, 1) = 5;
    dm.coeffRef(2, 1) = 2;
    dm.coeffRef(1, 2) = 9;
    dm.coeffRef(2, 2) = 6;

    /*

     4     8     0
     1     5     9
     0     2     6

    */

    REQUIRE(m.isApprox(dm));
  }

  SECTION("Make 3x5 matrix with offsets -1 0 1")
  {
    offsets << -1, 0, 1;

    csaps::DoubleSparseMatrix m = csaps::MakeSparseDiagMatrix(diags, offsets, 3, 5);

    csaps::DoubleSparseMatrix dm(3, 5);
    dm.coeffRef(0, 0) = 4;
    dm.coeffRef(1, 0) = 2;
    dm.coeffRef(0, 1) = 7;
    dm.coeffRef(1, 1) = 5;
    dm.coeffRef(2, 1) = 3;
    dm.coeffRef(1, 2) = 8;
    dm.coeffRef(2, 2) = 6;
    dm.coeffRef(2, 3) = 9;

    /*

     4     7     0     0     0
     2     5     8     0     0
     0     3     6     9     0

    */

    REQUIRE(m.isApprox(dm));
  }

  SECTION("Make 5x3 matrix with offsets -1 0 1")
  {
    offsets << -1, 0, 1;

    csaps::DoubleSparseMatrix m = csaps::MakeSparseDiagMatrix(diags, offsets, 5, 3);

    csaps::DoubleSparseMatrix dm(5, 3);
    dm.coeffRef(0, 0) = 4;
    dm.coeffRef(1, 0) = 1;
    dm.coeffRef(0, 1) = 8;
    dm.coeffRef(1, 1) = 5;
    dm.coeffRef(2, 1) = 2;
    dm.coeffRef(1, 2) = 9;
    dm.coeffRef(2, 2) = 6;
    dm.coeffRef(3, 2) = 3;

    /*

     4     8     0
     1     5     9
     0     2     6
     0     0     3
     0     0     0

    */

    REQUIRE(m.isApprox(dm));
  }

  SECTION("Make 5x3 matrix with offsets -2 -1 0")
  {
    offsets << -2, -1, 0;

    csaps::DoubleSparseMatrix m = csaps::MakeSparseDiagMatrix(diags, offsets, 5, 3);

    csaps::DoubleSparseMatrix dm(5, 3);
    dm.coeffRef(0, 0) = 7;
    dm.coeffRef(1, 0) = 4;
    dm.coeffRef(2, 0) = 1;
    dm.coeffRef(1, 1) = 8;
    dm.coeffRef(2, 1) = 5;
    dm.coeffRef(3, 1) = 2;
    dm.coeffRef(2, 2) = 9;
    dm.coeffRef(3, 2) = 6;
    dm.coeffRef(4, 2) = 3;

    /*

     7     0     0
     4     8     0
     1     5     9
     0     2     6
     0     0     3

    */

    REQUIRE(m.isApprox(dm));
  }

  SECTION("Make 3x3 matrix with offset 0")
  {
    csaps::DoubleArray diag(3);
    diag << 1, 2, 3;

    csaps::IndexArray offset(1);
    offset << 0;

    csaps::DoubleSparseMatrix m = csaps::MakeSparseDiagMatrix(diag.transpose(), offset, 3, 3);

    std::cout << m << std::endl;

    csaps::DoubleSparseMatrix dm(3, 3);
    dm.coeffRef(0, 0) = 1;
    dm.coeffRef(1, 1) = 2;
    dm.coeffRef(2, 2) = 3;

    /*

     1     0     0
     0     2     0
     0     0     3

    */

    REQUIRE(m.isApprox(dm));
  }
}
