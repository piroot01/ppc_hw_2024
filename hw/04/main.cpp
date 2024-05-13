/*** PPC - HW03 ***/
/* Tento soubor se neodevzdava. Brute dosadi vlastni */

#include <iostream>
#include <string>

#include "matrix.hpp"
#include "matrix_friends.hpp"

using namespace std;

int main(int argc, char** argv) {
    string levelarg;
    if (argc > 1)
        levelarg = string(argv[1]);
    else
    {
        cerr << "Missing level argument. Terminating." << endl;
        return 1;
    }

    int testId,testVal;
    if (!levelarg.compare("-l1"))
    {   
        /*3B - nacteni matic ruznych rozmeru, tvorba ruznych matic (eye, zeros, uniform...), scitani a odcitani matic i skalaru*/
        
        /* Constructors */
        testId=100000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m0;
        cout << m0;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m1(3,5);
        cout << m1;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m2(5,3);
        cout << m2;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m3(3,3);
        cout << m3;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m4(3);
        cout << m4;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m5(1);
        cout << m5;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m6(5,0);
        cout << m6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix m7(0,5);
        cout << m7;



        /* Uniform */
        testId=101000-1; cout << endl;
        testVal = 5; // Toto cislo se muze pri vyhodnoceni zmenit

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m0.uniform(testVal);
        cout << m0;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m1.uniform(testVal);
        cout << m1;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m2.uniform(testVal);
        cout << m2;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m3.uniform(testVal);
        cout << m3;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m4.uniform(testVal);
        cout << m4;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m5.uniform(testVal);
        cout << m5;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m6.uniform(testVal);
        cout << m6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m7.uniform(testVal);
        cout << m7;

        /* Eye */
        testId=102000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m0.eye();
        cout << m0;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m1.eye();
        cout << m1;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m2.eye();
        cout << m2;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m3.eye();
        cout << m3;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m4.eye();
        cout << m4;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m5.eye();
        cout << m5;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m6.eye();
        cout << m6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m7.eye();
        cout << m7;

        /* Bias */
        testId=103000-1;  cout << endl;
        testVal = -4; // Toto cislo se muze pri vyhodnoceni zmenit

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m0.bias(testVal);
        cout << m0;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m1.bias(testVal);
        cout << m1;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m2.bias(testVal);
        cout << m2;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m3.bias(testVal);
        cout << m3;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m4.bias(testVal);
        cout << m4;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m5.bias(testVal);
        cout << m5;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m6.bias(testVal);
        cout << m6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m7.bias(testVal);
        cout << m7;

        /* Copy constructor */
        testId=104000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n0(m0);
        cout << n0;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n1(m1);
        cout << m1;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n2(m2);
        cout << n2;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n3(m3);
        cout << n3;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n4(m4);
        cout << n4;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n5(m5);
        cout << n5;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n6(m6);
        cout << n6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        Matrix n7(m7);
        cout << n7;

        /* Operator ==: true outputs*/
        testId=105000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==n0?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==n1?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==n2?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m3==n3?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m4==n4?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m5==n5?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m6==n6?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m7==n7?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m7==n7?"Pass":"Fail") << endl;

        /* Zeros */
        testId=106000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m0.zeros();
        cout << m0;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m1.zeros();
        cout << m1;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m2.zeros();
        cout << m2;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m3.zeros();
        cout << m3;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m4.zeros();
        cout << m4;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m5.zeros();
        cout << m5;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m6.zeros();
        cout << m6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m7.zeros();
        cout << m7;

        /* Operator ==, same dimensions, various outputs*/
        testId=107000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==n0?"Pass":"Fail") << endl; 
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==n1?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==n2?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m3==n3?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m4==n4?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m5==n5?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m6==n6?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m7==n7?"Pass":"Fail") << endl;


        /* Operator ==, various dimensions*/
        testId=108000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==m1?"Fail":"Pass") << endl; 
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==m2?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==m3?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==m4?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==m5?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==m6?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m0==m7?"Fail":"Pass") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==m2?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==m3?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==m4?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==m5?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==m6?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m1==m7?"Fail":"Pass") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==m1?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==m3?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==m4?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==m5?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==m6?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m2==m7?"Fail":"Pass") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m6==m7?"Fail":"Pass") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << (m7==m6?"Fail":"Pass") << endl;

        /* Operator = */
        testId=109000-1; cout << endl;
        Matrix t(3,3); t.eye(); t.bias(3); // Zpusob inicializace t se muze zmenit. 
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n0; cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n1; cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n2; cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n3; cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n4; cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n5; cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n6; cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = n7; cout << t;

        /* LOAD  correct*/
        testId=110000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(m0,"m-empty.txt"); cout<< m0;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(m1,"m-wide.txt"); cout<< m1;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(m2,"m-tall.txt"); cout<< m2;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(m3,"m-square.txt"); cout<< m3;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(m5,"m-scalar.txt"); cout<< m5;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(m6,"m-empty-tall.txt"); cout<< m6;
        if (m6.nrows<=0 || m6.ncols!=0) return testId;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(m7,"m-empty-wide.txt"); cout<< m7;
        if (m7.nrows!=0 || m7.ncols<=0) return testId;

        /* LOAD  exceptions*/
        testId=111000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"does_not_exixst.txt");}
        catch(cannot_open_file const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"m-badhead1.txt");}
        catch(matrix_in_bad_header const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"m-badhead2.txt");}
        catch(matrix_in_bad_header const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"m-badhead3.txt");}
        catch(matrix_in_bad_header const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"m-badbody1.txt");}
        catch(matrix_in_bad_body const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"m-badbody2.txt");}
        catch(matrix_in_bad_body const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"m-badbody3.txt");}
        catch(matrix_in_bad_body const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{loadMatrixFile(t,"m-badbody4.txt");}
        catch(matrix_in_bad_body const &e){cout << "Pass: "<< e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}


        /* Random Access READ */
        testId=112000-1; cout << endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(t,"m-ewide.txt");
        cout << t(0,0) << " ";
        cout << t(t.nrows-1,t.ncols-1) << " ";
        cout << t(0,t.ncols-1) << " ";
        cout << t(t.nrows-1,1) << " ";
        cout << t((t.nrows-1)*2/3,(t.ncols-1)*1/2) << " ";
        cout << t((t.nrows-1)*1/4,(t.ncols-1)*2/3) << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{cout << t(-1,1);}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{cout << t(1, -1);}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{cout << t(-5,-6);}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{cout << t(t.nrows,t.ncols);}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{cout << t(t.nrows,1);}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{cout << t(t.nrows-1,t.ncols+8);}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{cout << t(t.nrows+5, -20);}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        /* Random Access WRITE */
        testId=113000-1;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = Matrix(10); t.uniform(testVal);
        t(1,1) = 99;
        t(t.nrows-1,t.ncols-1) = 98;
        t(1,t.ncols-1) = 97;
        t(t.nrows-1,1) = 96;
        t((t.nrows-1)*2/3,(t.ncols-1)*1/2) = 95;
        t((t.nrows-1)*1/4,(t.ncols-1)*2/3) = 94;
        cout<<t;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t(-1,1)=0;}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t(1, -1)=0;}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t(-5,-6)=0;}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t(t.nrows,t.ncols)=0;}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t(t.nrows,1)=0;}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t(t.nrows-1,t.ncols+8)=0;}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t(t.nrows+5, -20)=0;}
        catch(std::out_of_range const &e){cout << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

/*
        testId=114000-1;  cout << endl;
        testVal = -1; // Toto cislo se muze pri vyhodnoceni zmenit

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m0+n0;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n1=m1; n1.eye(); n1.bias(testVal); cout << m1+n1;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n2=m2; n2.eye(); n2.bias(testVal); cout << m2+n2;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n3=m3; n3.eye(); n3.bias(testVal); cout << m3+n3;
        //skip m4+n4
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n5=m5; n5.eye(); n5.bias(testVal); cout << m5+n5;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n6=m6; n6.eye(); n6.bias(testVal);cout << m6+n6;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n6=m6; n6.eye(); n6.bias(testVal); cout << m6+n6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = m1; t.zeros(); cout << ((m1==m1+t)?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = m2; t.zeros(); cout << ((m2==t+m2)?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = m3; t.eye(); t.bias(1); cout << ((m3+t==t+m3)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = m0+n1;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = m2+n1;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = m2+n5;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        try{t = m3+n7;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}


        testId=115000-1;  cout << endl;
        testVal = 9; // Toto cislo se muze pri vyhodnoceni zmenit

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m0+testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m1+testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal+m2;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m3+testVal;
        //skip m4+ntestVal
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal+m5;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m6+testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal+m6;

        testVal = -6; // Toto cislo se muze pri vyhodnoceni zmenit
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m0+testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m1+testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal+m2;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m3+testVal;
        //skip m4+ntestVal
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal+m5;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m6+testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal+m6;


        testId=116000-1; cout << endl;
        testVal = -1; // Toto cislo se muze pri vyhodnoceni zmenit

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m0-n0;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n1=m1; n1.eye(); n1.bias(testVal); cout << m1-n1;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n2=m2; n2.eye(); n2.bias(testVal); cout << m2-n2;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n3=m3; n3.eye(); n3.bias(testVal); cout << m3-n3;
        //skip m4+n4
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n5=m5; n5.eye(); n5.bias(testVal); cout << m5-n5;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n6=m6; n6.eye(); n6.bias(testVal);cout << m6-n6;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        n6=m6; n6.eye(); n6.bias(testVal); cout << m6-n6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = m1; t.zeros(); cout << ((m1==m1-t)?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = m2; t.zeros(); 
        m4=t; m4.uniform(testVal);
        n4=t; n4.uniform(-1*testVal);
        cout << ((n4==t-m4)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = m0-n1;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = m2-n1;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = m2-n5;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        try{t = m3-n7;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
;
        testId=117000-1;  cout << endl;

        testVal = 9; // Toto cislo se muze pri vyhodnoceni zmenit
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m0-testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m1-testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal-m2;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m3-testVal;
        //skip m4+ntestVal
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal-m5;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m6-testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal-m6;

        
        testVal = -6; // Toto cislo se muze pri vyhodnoceni zmenit
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m0-testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m1-testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal-m2;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m3-testVal;
        //skip m4+ntestVal
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal-m5;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << m6-testVal;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << testVal-m6;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((m1==m1-0)?"Pass":"Fail") << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        m4.uniform(testVal);
        n4.uniform(-1*testVal);
        cout << ((n4==(0-m4))?"Pass":"Fail") << endl;


        // Constructor exceptions
        testId=118000-1;  cout << endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = Matrix(-1,1);}
        catch(matrix_negative_size const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = Matrix(2,-3);}
        catch(matrix_negative_size const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = Matrix(-3,-4);}
        catch(matrix_negative_size const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "====================" << endl;

    } 
    else if (!levelarg.compare("-l2"))
    {

        Matrix hvect; loadMatrixFile(hvect, "m-hvect.txt");
        Matrix vvect; loadMatrixFile(vvect, "m-vvect.txt");
        Matrix scalar_hv; loadMatrixFile(scalar_hv, "m-scalar_hv.txt");
        Matrix square_hv; loadMatrixFile(square_hv,"m-square_hv.txt");
        Matrix square; loadMatrixFile(square,"m-square_hv.txt");
        Matrix tall; loadMatrixFile(tall, "m-tall.txt");
        Matrix wide; loadMatrixFile(wide, "m-wide.txt");
        Matrix etall; loadMatrixFile(etall,"m-etall.txt");
        Matrix ewide; loadMatrixFile(ewide, "m-ewide.txt");
        Matrix base; loadMatrixFile(base, "m-base.txt");
        Matrix t,u,v;

        
        // matrix*matrix
        testId=200000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((hvect*vvect == scalar_hv)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((vvect*hvect == square_hv)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << wide*tall;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << tall*wide;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << square_hv*square;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(wide.ncols); t.eye(); 
        cout << ((wide == wide*t)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(tall.nrows); t.eye(); 
        cout << ((tall == t*tall)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((Matrix(0) == Matrix(0,10)*Matrix(10,0))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((Matrix(tall.nrows,0) == tall*Matrix(tall.ncols,0))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((Matrix(0,tall.ncols) == Matrix(0,tall.nrows)*tall)?"Pass":"Fail") << endl;
        
        //transpose
        testId=201000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=square; t.transpose(); cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=tall; t.transpose(); cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=wide; t.transpose(); cout << t;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=ewide; u=ewide; u.transpose();u.transpose();
        cout << ((t == u)?"Pass":"Fail") << endl;

        //scale
        testId=202000-1; cout << endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=square; t.scale(3); cout << t;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=ewide; u=ewide; u.scale(-1);
        cout << ((0-t == u)?"Pass":"Fail") << endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=etall; u=etall; u.scale(-1);
        cout << ((0-t == u)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=wide; u=wide; u.scale(-1); v=Matrix(wide.ncols); v.eye(); v=0-v; 
        cout << ((u == t*v)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=tall; u=tall; u.scale(-1); v=Matrix(tall.nrows); v.eye(); v=0-v; 
        cout << ((u == v*t)?"Pass":"Fail") << endl;

        // scalar * Matrix, Matrix * scalar
        testId=203000-1; cout << endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=square; cout << t*3;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=ewide; u=ewide; 
        cout << ((0-t == u*(-1))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=ewide; u=ewide; 
        cout << ((0-t == -1*u)?"Pass":"Fail") << endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=etall; u=etall;
        cout << ((0-t-t == u*(-2))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=etall; u=etall;
        cout << ((0-(5*t) == (-5)*u)?"Pass":"Fail") << endl;

        // hadamard
        testId=204000-1; cout << endl;
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=square; t.eye(), t.scale(-1); 
        cout << hadamard(t,square);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=tall; t.eye(), t.scale(-3); 
        cout << hadamard(t,tall);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=wide; t.uniform(3), 
        cout << hadamard(t,wide);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=etall; t.transpose();
        cout << ((hadamard(t,ewide) == hadamard(ewide,t))?"Pass":"Fail") << endl;

        // power
        testId=205000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << power(base,3);

        cout << "=== TEST #" << ++testId << " ===" << endl; 
        cout << ((power(base,5)==power(base,3)*power(base,2))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((base == power(base,1))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=base; t.eye();
        cout << ((t == power(base,0))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        u=t, u.zeros();
        cout << ((t == power(u,0))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        bool b = true;
        u=t, u.scale(-1);
        for (int i = 0; i<=100; i+=2) b &= (t == power(u,i));;   
        cout << (b?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        b = true;
        for (int i = 1; i<=101; i+=2) b &= (u == power(u,i));;   
        cout << (b?"Pass":"Fail") << endl;

        // Operator * exceptions
        testId=206000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hvect*hvect;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = vvect*vvect;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = vvect*square_hv;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = square_hv*hvect;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = tall*Matrix();}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = Matrix()*wide;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = tall*Matrix(0,tall.ncols);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = Matrix(tall.nrows,0)*tall;}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}


        // Hadamard exceptions
        testId=207000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hadamard(hvect,vvect);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hadamard(vvect,hvect);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hadamard(tall,wide);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hadamard(wide,tall);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hadamard(tall,square);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hadamard(wide,square);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = hadamard(square,Matrix(square.ncols+3));}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        
        // Power exceptions

        testId=208000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = power(tall,1);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{t = power(wide,1);}
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        
        cout << "====================" << endl;

    }
    else if (!levelarg.compare("-l3"))
    {
        Matrix m; loadMatrixFile(m, "m-square.txt");
        Matrix n=m;
        Matrix t,u;
        int orows = m.nrows;
        int ocols = m.ncols;

        // Diagonal constructor & conversion to diagonal
        testId=300000-1; cout << endl;

        std::vector<int> vect = {1,2,3,0,6,5,4}; // Cisla se mohou zmenit
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(vect); cout << t;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        vect.clear();
        vect = t(); for (int i=0;i<vect.size();i++) cout<<vect[i]<<";"; cout<<endl;

                cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(t, "m-tall.txt"); 
        vect = t(); for (int i=0;i<vect.size();i++) cout<<vect[i]<<";"; cout<<endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        loadMatrixFile(t, "m-wide.txt"); 
        vect = t(); for (int i=0;i<vect.size();i++) cout<<vect[i]<<";"; cout<<endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        t = Matrix(); vect = t();
        cout << (vect.empty()?"Pass":"Fail") << endl; 

        // changedim
        testId=301000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m.changedim(orows-2,ocols);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m.changedim(orows+2,ocols);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m=n;
        m.changedim(orows,ocols-2);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m.changedim(orows,ocols+2);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m=n;
        m.changedim(orows-2,ocols-2);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m.changedim(orows,ocols);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m=n;
        m.changedim(orows,ocols);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m=n;
        m.changedim(orows+1,ocols+1);
        cout << m;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        m.changedim(0,0);
        cout << m;

        // changedim exceptions
        testId=302000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{m.changedim(0,-1);}
        catch(matrix_negative_size const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{m.changedim(-2,-3);}
        catch(matrix_negative_size const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try{m.changedim(-4,2);}
        catch(matrix_negative_size const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}


        // horzcat
        testId=303000-1; cout << endl;

        Matrix square; loadMatrixFile(square,"m-square_hv.txt");
        Matrix tall; loadMatrixFile(tall, "m-tall.txt");
        Matrix wide; loadMatrixFile(wide, "m-wide.txt");
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << horzcat(square,square);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << horzcat(square,wide);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << horzcat(wide, square);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((horzcat(tall,Matrix(tall.nrows,0))==horzcat(Matrix(tall.nrows,0),tall))?"Pass":"Fail") << endl; 
        
        // horzcat exceptions
        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { horzcat(square,Matrix()); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { cout << horzcat(square,tall); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { cout << horzcat(tall, square); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}
 


        // vertcat
        testId=304000-1; cout << endl;
        
        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << vertcat(square,square);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << vertcat(square,tall);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << vertcat(tall, square);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((vertcat(wide,Matrix(0,wide.ncols))==vertcat(Matrix(0,wide.ncols),wide))?"Pass":"Fail") << endl; 

        // vertcat exceptions
        testId=305000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { vertcat(square,Matrix()); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { cout << vertcat(square,wide); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { cout << vertcat(wide, square); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        // blkdiag
        testId=306000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << blkdiag(square,square);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << blkdiag(square,5);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << blkdiag(-5,square);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(3); t.eye(); t=t*2+3;
        cout << blkdiag(square, t);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(3); t.eye(); u=Matrix(5); u.eye();
        cout << ((blkdiag(u,t)==blkdiag(t,u))?"Pass":"Fail") << endl; 

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(3); t.eye(); u=Matrix(5); u.eye();
        cout << ((blkdiag(square,Matrix(0))==blkdiag(Matrix(0),square))?"Pass":"Fail") << endl; 

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << ((blkdiag(Matrix(0),Matrix(0))==Matrix(0))?"Pass":"Fail") << endl; 

        // blkdiag exceptions
        testId=307000-1; cout << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(square,wide); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(square,tall); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(tall,wide); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(wide,tall); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(tall,square); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(wide,square); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(Matrix(0,4),square); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(Matrix(4,0),square); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(Matrix(0,3),Matrix(0)); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        cout << "=== TEST #" << ++testId << " ===" << endl;
        try { t= blkdiag(Matrix(0),Matrix(0,3)); }
        catch(matrix_bad_sizes const &e){cout << "Pass: " << e.what() << endl;}
        catch(std::exception const &e){cout << "Fail: "<< e.what() << endl; return testId;}

        // kronecker
        testId=308000-1; cout << endl;

        loadMatrixFile(t,"m-base.txt"); t.changedim(3,2);
        u = tall; u.changedim(2,3);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << kronecker(t,u);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        cout << kronecker(u,t);

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(2), t.eye();
        cout << ((blkdiag(square,square)==kronecker(t,square))?"Pass":"Fail") << endl; 

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(1), t.uniform(5);
        cout << ((kronecker(tall,t)==kronecker(t,tall))?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(1), t.uniform(-5);
        cout << ((kronecker(wide,t)==(-5)*wide)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(0);
        cout << ((kronecker(wide,t)==t)?"Pass":"Fail") << endl;

        cout << "=== TEST #" << ++testId << " ===" << endl;
        t=Matrix(0);
        cout << ((kronecker(t,wide)==t)?"Pass":"Fail") << endl;

        cout << "====================" << endl;
*/
    }   
    else
    {
        cerr << "Invalid level argument. Terminating." << endl;
        return 1;
    } 

    return 0;
}

/*
zapis matice v souboru:
3 2
    1     2
    3     4
    5     6

vypis matice do stdout: bez headeru, delka policka 5, zarovnani vpravo, oddeleni mezerou a newline.
*/
