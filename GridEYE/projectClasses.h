//
//  projectClasses.h
//  Project
//
//  Created by Richard Oman on 11/11/17.
//  Copyright © 2017 Richard Oman. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>
#include <mouse.hpp>
#ifndef projectClasses_h
#define projectClasses_h

using namespace std;

/*/ --------------- Frame Class --------------- /*/
class frame{                        //      Stores sensor data
    //     0  1  2  3  4  5  6  7
protected:                            // 0  [] [] [] [] [] [] [] []
    float mean;                     // 1  [] [] [] [] [] [] [] []
    short max;                      // 3  [] [] [] [] [] [] [] []
    short sensor_values[8][8];      // 4  [] [] [] [] [] [] [] []
                                    // 4  [] [] [] [] [] [] [] []
    virtual void set_max();         // 5  [] [] [] [] [] [] [] []
    virtual void set_mean();        // 6  [] [] [] [] [] [] [] []
                                    // 7  [] [] [] [] [] [] [] []
public:
    /*
     frame();
     frame(GridEYE gridward);
     ~frame();
     */
    short access( short row , short col );
    virtual short get_max() =0;
    virtual float get_mean() =0;
    
    void new_max( short newMax );
    void new_mean( float newMean );
    
    virtual void print() =0;
    
};

/*/ ----------- GrideEye Class ---------- /*/
class GridEYE : public frame{
    friend class video;
private:
    void set_max();
    void set_mean();
    
public:
    GridEYE();
    GridEYE(int address); //Hint: My board has it set at 0x68 :)
    ~GridEYE();
    
    void reset(void);
    void test(int row, int col);    //Draw Test pattern
    int runTime;                    // Run Time in Seconds
    short pixelL;
    int r,g,b;
    int FPS;
    
    short get_max();
    float get_mean();
    
    int getFPS();
    void setFPS( int temp );
    void print();
};

/*/ ---------- End GridEYE Class ---------- /*/



/*
class pixelMask {
private:
 short r;
 short g;
 short b;
    
public:
    frame_mask();
    ~frame_mask();
    
    void setMask( short temp ); // Uses algorithm to determine RGB values
};
*/

/*/ --------------- End Frame Class --------------- /*/

/*/ --------------- Video Class --------------- /*/
class video{
private:
    short frameCount; // frameCount = FPS * runtime
    short FPS;
    int runtime;

    short max;
    float mean;
    
    vector< frame* > data;  // Storing up to 31,800 frames maximum
    
    void set_runtime();
    void set_max();
    void set_mean();
    
public:
    video();
    video( GridEYE gridward );
    ~video();
    
    void addFrame(GridEYE* gPtr);
    frame* getFrame( int index );

    short getframeCount();
    void exportVideo( string filename );
    void print();
    
};
/*/ --------------- End Video Class --------------- /*/

/*/ --------------- Session Class --------------- /*/
class session{
private:
    vector< video* > current; // session.current[vCount] 
    int vCount;
    
public:
    session();
    session( video* newVid );
    ~session();
    
    void addVideo( video* newVid ); // Implement Save button
    void undoRec();                 // Implement Delete Button
    void print();
};
/*/ --------------- End Session Class --------------- /*/



/*/ --------------- Settings Menu Class --------------- /*/



#endif /* projectClasses_h */

