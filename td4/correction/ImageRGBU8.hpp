#include <iostream>
#include <vector>


#ifndef __IMAGERGBU8_HPP__
#define __IMAGERGBU8_HPP__


/// \class ImageRGBU8
/// \brief class defining images RGB of unsigned char (8bits x 3)
class ImageRGBU8 {
     
public:

    /// \brief default constuctor (no image)
    ImageRGBU8();

    /// \brief size constructor (color = white)
    /// \param w : image width
    /// \param h : image height
    ImageRGBU8(const unsigned int w,const unsigned int h);

    /// \brief constructor for size and data
    /// \param w : image width
    /// \param h : image height
    /// \param data : std::vector<unsigned char> of size (w x h x 3) contraining the image data
    ImageRGBU8(const unsigned int w,const unsigned int h, const std::vector<unsigned char> data);

    /// \brief copy constructor
    /// \param image2 : the image to be copied
    ImageRGBU8(const ImageRGBU8 & image2);

    /// \brief destructor
    ~ImageRGBU8();

private :
    unsigned int _width;                /*!< width of the image */
    unsigned int _height;               /*!< height of the image */
    std::vector<unsigned char> _data;   /*!< vector containing the image pixel data intensity */


public :

    /// \brief getter for the image width
    /// \return an unsigned int containing the image width
    inline unsigned int width() const { return _width;}

    /// \brief getter for the image height
    /// \return an unsigned int containing the image height
    inline unsigned int height() const {return _height;}

    /// \brief getter for the image data pointer
    /// \return a pointer on the image data array
    inline  unsigned char * data() {return _data.data();}

    /// \brief getter for the image data pointer (const version)
    /// \return a constant pointer on the image data array
    inline  const unsigned char * data() const {return _data.data();}

    /// \brief operator() (const version)
    /// \param x : column component
    /// \param y : row component
    /// \param c : channel component (R=0, G=1, B=2)
    /// \return a const unsigned char value of the requested pixel
    inline const unsigned char & operator()(const unsigned int x, const unsigned int y, const unsigned int c) const 
    { 
        return _data[(y*_width+x)*3+c];
    }  

    /// \brief operator() 
    /// \param x : column component
    /// \param y : row component
    /// \param c : channel component (R=0, G=1, B=2)
    /// \return an unsigned char value of the requested pixel
    inline unsigned char & operator()(const unsigned int x, const unsigned int y, const unsigned int c)
    {
        return _data[(y*_width+x)*3+c];
    }  



    /// \brief convert the image to a  grey scale image 
    void toGreyScale();

    /// \brief draw a circle lin the middle of the image
    /// \param r : red color component of the circle
    /// \param g : green color component of the circle
    /// \param b : blue color component of the circle
    void drawCircle(const unsigned char r=255, const unsigned char g=0, const unsigned char b=0);

    /// \brief fill a channel with zero
    /// \param channel : the channel to be removed (R=0, G=1, B=2)
    void removeChannel(const unsigned int channel);

    /// \brief threshold an image (by the average color of each pixel)
    /// \param threshold : the threshold (between 0 and 255)
    void threshold(const unsigned char threshold);

};


#endif
