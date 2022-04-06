#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

#include <string>
#include <algorithm>
using namespace std;




TEST_CASE("Addition and subtraction") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr = {
    3, 0,  0, 0,
    0, 3,  0, 0,
    0, 0, -3, 0,
    0, 0,  0, 3
    };
	Matrix a{identity, 3, 3};
    Matrix b{arr, 4, 4};
	
    CHECK_THROWS(a+b);
	CHECK_THROWS(a-b);
    try{
        a+=b;
        CHECK_EQ(false,true);
    }
    catch(std::exception &){
    
    }
    try{
        b+=a;
        CHECK_EQ(false,true);
    }
    catch(std::exception &){
    
    }

    try{
        a-=b;
        CHECK_EQ(false,true);
    }
    catch(std::exception &){
    
    }
    try{
        b-=a;
        CHECK_EQ(false,true);
    }
    catch(std::exception &){
    
    }
    std::vector<double> arr_negative = {
    -3,  0,  0,  0,
     0, -3,  0,  0,
     0,  0,  3,  0,
     0,  0,  0, -3
    };
    Matrix b_neg{arr_negative, 4, 4};

	CHECK(b_neg==-b);
    CHECK(-b_neg==b);
    CHECK(+b_neg==b_neg);
    CHECK(+b==b);
    CHECK(-b-b==-(b+b));
    Matrix b_temp{arr, 4, 4};
    b_temp+=b;
    CHECK(b_temp != b);
    CHECK(b_temp > b);
    CHECK(b_temp == b+b);
    //b didn't change due to the above line
    CHECK(b_temp != b); 
    Matrix b_neg_temp{arr_negative, 4, 4};
    //4x4 zeros matrix
    b_neg_temp-=b_neg;
    CHECK(b_neg_temp != b_neg);
    CHECK(b_neg_temp > b_neg);
    CHECK(b_neg_temp == b_neg-b_neg);
    //b_neg didn't change due to the above line
    CHECK(b_neg_temp != b_neg); 
    CHECK(b_neg_temp-b_neg == -b_neg);

}
TEST_CASE("boolean logic and increment") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr = {
    3, 0,  0, 0,
    0, 3,  0, 0,
    0, 0,  3, 0,
    0, 0,  0, 3
    };
    std::vector<double> arr2 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    std::vector<double> arr3 = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> addition= {0, 1, 1, 1, 0, 1, 1, 1, 0};
	Matrix a{identity, 3, 3};
    Matrix a2{identity, 3, 3};
    Matrix b{arr, 4, 4};
    Matrix c{arr2, 3,3};
    Matrix d{arr3, 3, 3};
    Matrix add{addition, 3, 3};
    CHECK(a<b);
    CHECK(a<=b);
    CHECK(b>a);
    CHECK(b>=a);
    CHECK( (b<c || b>c || b==c || b<=c || b>=c)==false );
    CHECK(b<d);
    CHECK(d>b);
    CHECK(b<=d);
    CHECK(d>=b);
    CHECK(a!=b);
    CHECK(a!=d);
    CHECK(a<d);
    CHECK(a==a2);
    CHECK(a<=a2);
    CHECK(a>=a2);
    CHECK(a*4==c);
    d+=add;
    CHECK(c != d);
    CHECK(c++ != d);
    CHECK(c == d);
    CHECK(--c != d);
    CHECK(++c == d);
    CHECK(c-- == d);
}
TEST_CASE("multiplication") {
    std::vector<double> ans1 = {
    9, 0, 0,
    0, 9, 0,
    0, 0, 0
    };
    std::vector<double> ans2 = {
    9, 0,
    0, 9
    };
    std::vector<double> arr1 = {
    3, 0,  
    0, 3,  
    0, 0
    };
    std::vector<double> arr2 = {
    3, 0, 0,
    0, 3, 0
    };
    std::vector<double> arr3 = {
    3, 0, 0,
    0, 3, 0,
    0, 0, 3
    };
    std::vector<double> arr4 = {
    -3, 0, 0,
    0, -3, 0,
    0, 0, -3
    };
    std::vector<double> arr5 = {
    9, 0, 0,
    0, 9, 0,
    0, 0, 9
    };
    std::vector<double> identity = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
    };
    
	Matrix a1{ans1, 3, 3};
    Matrix a2{ans2, 2, 2};
    Matrix b1{arr1, 3, 2};
    Matrix b2{arr2, 2, 3};
    Matrix b2_temp{arr2, 2, 3};
    Matrix c{arr3, 3, 3};
    Matrix id{identity, 3, 3};
    Matrix id2{identity, 3, 3};
    Matrix d{arr4, 3, 3};
    Matrix dd{arr5, 3, 3};
    CHECK(b1*b2==a1);
    CHECK(b2*b1==a2);
    CHECK(b2_temp != a2);
    b2_temp*=b1;
    CHECK(b2_temp == a2);

    CHECK(3*id==c);
    CHECK(id*3==c);
    CHECK(id2!=c);
    id2*=3;
    CHECK(id2==c);

    CHECK(id*5==2.5*(id+id));
    CHECK(id*5==2.2*id+2.8*id);
    CHECK(-id*5<id);

    d*=d;
    CHECK(d==dd);

    
    

}