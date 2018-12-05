//Arquivo salvo em tesseract.cpp
// CARREGA IMAGEM E EXPOE NA JANELA
#include <stdio.h>

#include <stddef.h>

#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    String imageName( "foto3.jpg" ); // BUSCAR A IMAGEM
    if( argc > 1)
    {
        imageName = argv[1];
    }
    Mat image;
    image = imread( imageName, IMREAD_GRAYSCALE ); // LER A IMAGEM EM ESCALAS D$
    if( image.empty() )                      // CHECA SE O ARQUIVO É VÁLIDO
    {
        cout <<  "Nao foi possivel abrir ou encontrar o arquivo" << std::endl ;
        return -1;
    }
// Especificar a localização da ROI, assumindo que: 
// x,y = (190,230)   
// largura, altura = (260, 60)
//-------------------------------------------------------------
// roi_1 é o corte do numero de identidade
        cv::Rect roi_1 = cv::Rect(101, 10, 150, 45);
// roi_2 é o corte do nome
        cv::Rect roi_2 = cv::Rect(23, 45, 475, 65);
// roi_3 é o corte dos nomes dos pais do cidadao
        cv::Rect roi_3 = cv::Rect(10, 129, 365, 57);
// roi_4 é o corte da data de nascimento
        cv::Rect roi_4 = cv::Rect(465, 198, 150, 40);
// roi_5 é o corte do CPF
        cv::Rect roi_5 = cv::Rect(3, 325, 201 ,35);

//-----------------------------------------------------------------------------$
// Criar uma nova imagem a partir da ROI setada na imagem original:
        cv::Mat sub_img1 = image(roi_1);
        cv::Mat sub_img2 = image(roi_2);
        cv::Mat sub_img3 = image(roi_3);
        cv::Mat sub_img4 = image(roi_4);
        cv::Mat sub_img5 = image(roi_5);

//mostrar as imagens cortadas na janela 
//      cv::imshow("crop1", sub_img1);
//      cv::imshow("crop2", sub_img2);
//      cv::imshow("crop3", sub_img3);
//      cv::imshow("crop4", sub_img4);
//      cv::imshow("crop5", sub_img5);
//      cv::waitKey(0);
// SALVAR OS CORTES COMO IMAGENS
        cv::imwrite("rg.jpg", sub_img1);
        cv::imwrite("nome.jpg", sub_img2);
        cv::imwrite("pais.jpg", sub_img3);
        cv::imwrite("data_nasc.jpg", sub_img4);
        cv::imwrite("cpf.jpg", sub_img5);
//---------------------------------------------------------------
// APLICANDO O TESSERACT

        system("tesseract rg.jpg rg");
        printf("\n");
        system("cat rg.txt");

        system("tesseract nome.jpg nome");
        printf("\n");
        system("cat nome.txt");

        system("tesseract pais.jpg pais");
        printf("\n");
        system("cat pais.txt");

        system("tesseract data_nasc.jpg data_nasc");
        printf("\n");
        system("cat data_nasc.txt");

        system("tesseract cpf.jpg cpf");
        printf("\n");
        system("cat cpf.txt");

        return 0;
}
//Rect region_of_interest = Rect(x, y, w, h);
//Mat image_roi = image(region_of_interest);






