// FCI _ Programming 1 _ 2018 - Assignment 3
// Program Name: Gray Scale Image Processor.cpp
// Last Modification Date: 6/4/2018
// Author1 and ID and Group: ATEF MAGDY         G.5
// Author2 and ID and Group: Abdelrahman Ibrahim G.6
// Author3 and ID and Group: Abdelrahman Mohamed G.6
// Teaching Assistant: ENG.ATAA
// Purpose: Image Processor

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include<vector>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char Merge[SIZE][SIZE];
unsigned char Rot[SIZE][SIZE];
unsigned char enlarge[SIZE][SIZE];
unsigned char shrank[SIZE][SIZE];
unsigned char picture[SIZE][SIZE];

void loadImage();    //0
void SaveImage();    //0
void BlackWite();    //1
void invertImage();      //2
void Merg();        //3
void Flip();         //4
void RotateImage() ;      //5
void Darken_Lighten();  //6
void DetectingEdge();//7
void EnlargeImage();    //8
void Shrink();      //9
void Miror();        //a
void Blur();
void shuffleImage();
void server();

int in , choice;
char f;

int main()
{
    cout << "Ahlan ya user ya habibi." << endl << endl;
    loadImage();
    while(true){
            cout << "\n1- Black & White Filter \n2- Invert Filter \n3- Merge Filter \n4- Flip Image" << endl;
            cout << "5- Darken and Lighten Image \n6- Rotate Image \n7- Detect Image Edges \n8- Enlarge Image" << endl;
            cout << "9- Shrink Image  \n10-Mirror 1/2 Image \n11-Blur image \n12-Shuffle image \n13-Save image \n0- Exit" << endl << endl;
            cout << "Please select a filter to apply or 0 to exit :";
            cin >> choice;
            while(choice>13 || choice<0){
                cout << "Enter a correct number : ";
                cin >> choice;
            }
            if(choice==1) BlackWite();
            else if(choice==2) invertImage();
            else if(choice==3) Merg();
            else if(choice==4) Flip();
            else if(choice==5) Darken_Lighten();
            else if(choice==6) RotateImage();
            else if(choice==7) DetectingEdge();
            else if(choice==8) EnlargeImage();
            else if(choice==9) Shrink();
            else if(choice==10) Miror();
            else if(choice==11) Blur();
            else if(choice==12) shuffleImage();
            else if(choice==13) SaveImage();
            else if(choice==0) break;
    }

    return 0;
}
void loadImage () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
void BlackWite(){
    int total=0 , average;
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                total+=image[i][j];

        }}
    average=total/pow(SIZE,2);
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                if(image[i][j] > average) image[i][j]=255;
                else image[i][j]=0;

        }}
}
void SaveImage() {
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
void invertImage (){
for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
        image[i][j]=255-image[i][j];
    }
}
}
void Merg(){
    unsigned char image2[SIZE][SIZE];
    char name[100];
    cout<<"Enter name of the other image :";
    cin>>name;
    strcat (name, ".bmp");
   readGSBMP(name, image2);

   for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){

        image[i][j]=(image[i][j]+image2[i][j])/2;
    }
   }

}
void Flip(){
    cout << "Flip (h)orizontally or (v)ertically ?";
    cin >> f;
    while(f!='v' && f!='h'){
            cout << "Enter v or h : ";
            cin >> f;
        }
    if(f=='v'){
            unsigned char half[SIZE][SIZE/2+1];
            for(int i=0 ; i<SIZE ; ++i){
                for(int j=0 ; j<SIZE/2+1 ; ++j){
                        half[i][j]=image[i][j];
                        image[i][j]=image[i][255-j];
                }}
            for(int i=0 ; i<SIZE ; ++i){
                for(int j=SIZE/2+2; j<SIZE ; ++j){
                        image[i][j]=half[i][255-j];

        }}}

    else if(f=='h'){
            unsigned char half[SIZE/2+1][SIZE];
            for(int i=0 ; i<SIZE/2+1 ; ++i){
                for(int j=0 ; j<SIZE ; ++j){
                        half[i][j]=image[i][j];
                        image[i][j]=image[255-i][j];
                }}
            for(int i=SIZE/2+2 ; i<SIZE ; ++i){
                for(int j=0 ; j<SIZE ; ++j){
                        image[i][j]=half[255-i][j];

        }}}
}
void RotateImage(){
int x;
int temp [256] [256];
cout<<"what do you want to do now ! "<<endl;
cout<<"press 1 to rotate 90 clockwise"<<endl;
cout<<"press 2 to rotate 180 clockwise "<<endl;
cout<<"press 3 to rotate 270 clockwise "<<endl;
cout<<"So ! what to u chooce ! "<<endl;
cin>>x;
if(x==1){
    for (int i=0 ;i<SIZE ; i++){
        for (int j=0;j<SIZE ; j++){
            temp[i][j]=image[SIZE-j][i];
        }
    }
    for (int i=0 ; i<SIZE ; i++){
        for (int j=0 ; j<SIZE;j++){
            image [i][j]=temp[i][j];
        }
    }
}
if(x==2){
    for (int i=0;i<SIZE ;i++){
            for (int j=0 ;j<SIZE;j++){
                temp[i][j]=image [SIZE-i][SIZE-j];
        }
    }
    for (int i=0;i<SIZE;i++){
            for (int j=0 ;j<SIZE;j++){
                image[i][j]=temp[i][j];
        }
    }
}
if (x==3){
    for (int i=0 ; i<SIZE ; i++){
            for (int j=0 ; j<SIZE ; j++){
                temp[i][j]=image[j][SIZE-i] ;
        }
    }
    for (int i=0;i<SIZE;i++){
            for (int j=0 ;j<SIZE;j++){
            image[i][j]=temp[i][j];
        }
    }
}
}
void Darken_Lighten(){
    int x;
    cout<<"1-Darken the image\n2-Lighten the image "<<endl;
    cin>>x;
    if(x==1){
for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
            image[i][j]-=image[i][j]/2;
}}
    }
else if(x==2){
    for(int i=0; i<SIZE; ++i){
        for(int j=0; j<SIZE; ++j){
        if (image[i][j]+(image[i][j]/2)>255)
            image[i][j]=255;
        else
            image[i][j]+=image[i][j]/2;
    }}

}


}
void DetectingEdge(){
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                if((image[i+1][j]-image[i][j]>=40) || (image[i][j+1]-image[i][j]>=40) || image[i][j]-image[i+1][j]>=40 || image[i][j]-image[i][j+1]>=40) image[i][j]=0;
                else image[i][j]=255;
}}}
void EnlargeImage() {
    int  x, r=0 , c=0;
    cout << "Which quarter you wanna enlarge 1, 2, 3 or 4 ?  " << endl ;
    cout << "1- To enlarge the first quarter "  << endl ;
    cout << "2- To enlarge the second quarter " << endl ;
    cout << "3- To enlarge the third quarter " << endl ;
    cout << "4- To enlarge the forth quarter " << endl ;
    cout << "choose the number you want :\n " << endl ;
    cin >> x;
    if (x== 1 ){
  for (int i = 0; i < SIZE/2; i++) {
    for (int j = 0; j< SIZE/2; j++){
             picture[r][c] = image[i][j] ;
             picture[r+1][c]= image[i][j];
             picture[r][c+1]= image[i][j];
             picture[r+1][c+1]= image[i][j];
             c+=2;
        }
        c=0;
        r+=2;
     }
      server();
}
 if (x== 2 ){
  for (int i = 0; i < SIZE/2; i++) {
    for (int j = 128; j< SIZE; j++){
             picture[r][c] = image[i][j] ;
             picture[r+1][c]= image[i][j];
             picture[r][c+1]= image[i][j];
             picture[r+1][c+1]= image[i][j];
             c+=2;
        }
        c=0;
        r+=2;
     }
      server ();
}
 if (x== 3 ){
  for (int i =128; i < SIZE; i++) {
    for (int j = 0; j< SIZE/2; j++){
             picture[r][c] = image[i][j] ;
             picture[r+1][c]= image[i][j];
             picture[r][c+1]= image[i][j];
             picture[r+1][c+1]= image[i][j];
             c+=2;
        }
        c=0;
        r+=2;
     }
      server ();
}
 if (x== 4 ){
  for (int i = 128; i < SIZE; i++) {
    for (int j = 128; j< SIZE; j++){
             picture[r][c] = image[i][j] ;
             picture[r+1][c]= image[i][j];
             picture[r][c+1]= image[i][j];
             picture[r+1][c+1]= image[i][j];
             c+=2;
        }
        c=0;
        r+=2;
        }
    }
     server ();
}
void Shrink(){
    int x,r=0,c=0;

    cout<<"1-Shrink by 1/2\n2-Shrink by 1/3\n3-Shrink by 1/4"<<endl;
    cin>>x;
    if(x==1){
        for(int i=0; i<128; ++i){
            for(int j=0; j<128; ++j){

picture[i][j]=(image[r][c]+image[r][c+1])/2;
            c+=2;
            }
            c=0;
            r+=2;

        }
        for(int i=0; i<SIZE; ++i){
            for(int j=0; j<SIZE; ++j){
                if(i>128 || j>128)
                    picture[i][j]=255;
                else
                    continue;
            }
        }
server();

    }
if(x==2){

   for(int i=0; i<85; ++i){
    for(int j=0; j<85; ++j){
        picture[i][j]=(image[r][c]+image[r][c+1]+image[r][c+2])/3;
        c+=3;
    }
    c=0;
    r+=3;
   }
   for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
        if(i>85 || j>85)
            picture[i][j]=255;
        else
            continue;
    }
   }
   server();
}
if(x==3){

     for(int i=0; i<64; ++i){
    for(int j=0; j<64; ++j){
        picture[i][j]=(image[r][c]+image[r][c+1]+image[r][c+2]+image[r][c+3])/4;
        c+=4;
    }
    c=0;
    r+=4;
   }
   for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
        if(i>64 || j>64)
            picture[i][j]=255;
        else
            continue;
    }
   }
    server();
}
    }
void Miror(){
    char choise;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
    cin >> choise;
    while(choise!='l' && choise!='r' && choise!='u' && choise!='d'){
        cout << "Enter 'l' or 'r' or 'u' or 'd' : ";
        cin >> choise;
    }
    if(choise=='l'){
        for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE/2 ; ++j){
                image[i][255-j]=image[i][j];
            }}}

    else if(choise=='r'){
        for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE/2 ; ++j){
                image[i][j]=image[i][255-j];
            }}}

    else if(choise=='u'){
        for(int i=0 ; i<SIZE/2 ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                image[255-i][j]=image[i][j];
            }}}

    else if(choise=='d'){
        for(int i=0 ; i<SIZE/2 ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                image[i][j]=image[255-i][j];
            }}}
}
 void Blur(){
    for (int n=0;n<5; ++n){
        for(int i=0; i<SIZE; ++i){
            for(int j=0; j<SIZE; ++j){
                if(i==0 && j==0){
                    image[i][j]=(image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1]+image[i][j+2])/9;
}
if(i==0 && j>0 && j<255){
    image[i][j]=(image[i][j]+image[i][j-1]+image[i][j+1]+image[i+1][j-1]+image[i+1][j]+image[i+1][j+1])/9;
}

if(j==0 && i>0 && i<255 ){
    image[i][j]=(image[i][j]+image[i-1][j]+image[i+1][j]+image[i][j+1]+image[i-1][j+1]+image[i+1][j+1])/9;
}


    image[i][j]=(image[i][j]+image[i][j-1]+image[i-1][j-1]+image[i+1][j-1]+image[i+1][j]+image[i-1][j]+image[i][j+1]+image[i-1][j+1]+image[i+1][j+1])/9;


    }
 }
}
 }
 void shuffleImage(){
    int a=0 , b=0 ;
    string order ;
    cout << "Enter the order of the shuffled Quarters that U want ?!!! : ";
    cin >> order ;
    for(int i=0 ; i<4; i++){
        for(int j=0; j<(SIZE/2); j++){
            for(int k=0; k<(SIZE/2); k++){
                if(order[i]== '1'){
                    a=j; b=k;
                }
                else if(order[i]== '2'){
                    a=j; b=(SIZE/2)+k;
                }
                else if(order[i]== '3'){
                    a=(SIZE/2)+j; b=k;
                }
                else if(order[i]== '4'){
                    a=(SIZE/2)+j; b=(SIZE/2)+k;
                }
///--------------------------------------------------------
                if(i==0)       picture[j][k]=image[a][b];
                else if(i==1)  picture[j][(SIZE/2)+k]=image[a][b];
                else if(i==2)  picture[(SIZE/2)+j][k]=image[a][b];
                else if (i==3) picture[(SIZE/2)+j][(SIZE/2)+k]=image[a][b];
            }
        }
    } server ();
}
////////////////////////////////////////////////////////////////////////////////////
void server (){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++){
            image[i][j]=picture[i][j];
}
    }
}
