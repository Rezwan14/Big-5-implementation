// --> Rezwan Rahman
// For this project we had to implement our points2d.h file, which consisted of our Big-Five functions, and operator overload.
//The purpose of this assignment was to create a Points2D class from scratech with limited help from the STL.
//Since Points2D can have arbitrary size, we used pointers. The structure of our code was already provided. 
//We simply had to implement our "big five", and stream insertion (<<) and extraction(>>) operators.
//We also implemented our + and [] operators. Then we tested our project to see if it works. 


#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2D {
  public:
    // Zero-parameter constructor.
    // Set size to 0.
    // set sequence to null
    Points2D()
    {//start Points2D
        size_ = 0;
        sequence_ = nullptr;
    }//end Points2D

    // Copy-constructor.
    //Code data from certain variables into new ones
    Points2D(const Points2D &rhs)
    {//start copy const
        //set size & sequence to rhs
        size_ = rhs.size_;
        sequence_ = new std::array<Object, 2> [rhs.size_];
        //loop through size to generate sequence
        for(size_t i = 0; i < rhs.size_; i++)
        {//start for
            sequence_[i][0] = rhs.sequence_[i][0];
            sequence_[i][1] = rhs.sequence_[i][1];
        }//end for
    }//end copy const

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    Points2D& operator=(const Points2D &rhs)
    {//start operator =
        Points2D copy = rhs;
        std::swap(*this, copy);
        return *this;
    }//end operator =

    // Move-constructor.
    //Just set our variables to rhs and reset the rhs
    Points2D(Points2D &&rhs)
    {//start move-const
        //set our values to rhs
        size_ = rhs.size_;
        sequence_ = rhs.sequence_;

        //we have to reset the rhs
        rhs.size_ = 0;
        rhs.sequence_ = nullptr;
    }//end move-const

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points2D& operator=(Points2D &&rhs)
    {//start move-assn
        std::swap(size_ , rhs.size_);
        std::swap(sequence_, rhs.sequence_);
        return *this;
    }//end move-assn

    //delete private data members
    ~Points2D()
    {//start destructor
        size_ = 0;
        delete sequence_;
    }//end destructor

    // End of big-five.

    // One parameter constructor. 
    Points2D(const std::array<Object, 2>& item) 
    {//start One Patam const
        //set everything to one
        size_ = 1;
        sequence_ = new std::array<Object, 2> [1]; 
        sequence_[0][0] = item[0];
        sequence_[0][1] = item[1];
    }//end One Param Const

    size_t size() const 
    {//start size_
        return size_;
    }//end size_

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 2>& operator[](size_t location) const 
    {
        //abort if location > size
        if (location > size_)
        {
            std::abort();
        }
        // else return point of location
        else 
        {
            return sequence_[location];
        }
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) 
    { //start operator+

        //set variables representing size of (c1) & (c2)
        size_t larger, smaller;
        //if c1 bigger than c2
        if(c1.size_ > c2.size_)
        {//start if
            larger = c1.size_;
            smaller = c2.size_;
        }//end if

        //if c2 > c1
        else
        {//start else
            larger = c2.size_;
            smaller = c1.size_;
        }//end else

        Points2D sum; //variable that represents sum of sequences
        sum.sequence_ = new std::array<Object, 2>[larger];
        sum.size_ = larger;

        //for loop returns sum c1+c2
        for(size_t i = 0; i < smaller; i++)
        {//start for
            sum.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
            sum.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
        }//end for

        if(c1.size_ > c2.size_)
        {//start if c1>c2
            for(size_t i = smaller; i < larger; i++)
            {// returns c1
                sum.sequence_[i][0] = c1.sequence_[i][0];
                sum.sequence_[i][1] = c1.sequence_[i][1];
            }
        }//end c1>c2

        //if c2 > c1
        else if(c2.size_ > c1.size_)
        {
            for(size_t i = smaller; i < larger; i++)
            {// returns c2 sequence
                sum.sequence_[i][0] = c2.sequence_[i][0];
                sum.sequence_[i][1] = c2.sequence_[i][1];
            }//end for
        }//end c2>c1
        return sum;
    }//end operator+

    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) 
    {//start ostream
        //if output = 0 return "()"
        if(some_points.size_ == 0)
        {//start if size = 0
            out<< "()" ;
        }//end if
        else
        {//start else
            //iterate through our values
            for(size_t i=0; i < some_points.size_; i++)
            {
                //if 
                out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ")" << " ";
            }
        
        }//end else
        out << "\n";
        return out;
    }//end ostream

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) 
    {//start istream
        in >> some_points.size_;
        some_points.sequence_ = new std::array<Object, 2>[some_points.size_];
        for(size_t i = 0; i < some_points.size_; i++)
        {//start for
            //if our input is outside our chain, return error
            if (!(in >> some_points.sequence_[i][0] >> some_points.sequence_[i][1]))
            {//start if
                std::cerr << "ERROR" << std::endl;
                std::abort();
            }//end if
        }//end for
        std::cout << '\n';
        return in;
    }//end istream

  private:
    // Sequence of points.
    std::array<Object, 2> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
