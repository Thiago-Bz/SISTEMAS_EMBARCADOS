// CARREGA IMAGEM E EXPOE NA JANELA
#include<stdio.h>
#include<stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    String imageName( "fotoboa1.jpg" ); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }
    Mat image;
    image = imread( imageName, IMREAD_GRAYSCALE ); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
// Especificar a localização da ROI, assumindo que: 
// x,y = (190,230)   
// largura, altura = (260, 60)
        cv::Rect roi = cv::Rect(80, 10, 320, 30);

// Criar uma nova imagem a partir da ROI setada na imagem original:
        cv::Mat sub_img = image(roi);
// Abre a foto na janela
//        cv::imshow("crop", sub_img);
//        cv::waitKey(0);
        cv::imwrite("cinza_corte.jpg", sub_img);
//---------------------------------------------------------------
// APLICANDO O TESSERACT
        system("tesseract cinza_corte.jpg dados");
        printf("\n");
        system("cat dados.txt");

        return 0;
}


