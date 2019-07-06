// FCI _ Programming 1 _ 2018 - Assignment 3
// Program Name: Gray Scale Image Processor.cpp
// Last Modification Date: 6/4/2018
// Author1 and ID and Group: ATEF MAGDY         G.5
// Author2 and ID and Group: Abdelrahman Ibrahim G.6
// Author3 and ID and Group: Abdelrahman Mohamed G.6
// Teaching Assistant: ENG.ATAA
// Purpose: Image Processor
#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE][RGB];
    unsigned char image2[SIZE][SIZE][RGB];

unsigned char flip[SIZE][SIZE][RGB];

void load();
void save();
void invertImage();
void Black_White();
void FlipH();
void FlipV();
void DetectEdges();
void Merge_Colored();
void lighten_Darken_Colored();
void Shrink_Colored();
void EnlargeImage();
void RotateImage();
void server();

int main()
{
    int choice;
    cout << "Ahlan ya user ya habibi." << endl << endl;
    load();
    while(true){
            cout << "\n1- Black & White Filter \n2- Invert Filter \n3- Merge Filter \n4- Flip Image" << endl;
            cout << "5- Darken and Lighten Image \n6- Rotate Image \n7- Detect Image Edges \n8-Enlarge image \n9- Shrink image" << endl;
            cout << "10- Save Image \n0- Exit" << endl << endl;
            cout << "Please select a filter to apply or 0 to exit :";
            cin >> choice;
            while(choice>10 || choice<0){
                cout << "Enter a correct number : ";
                cin >> choice;
            }
            if(choice==1) Black_White();
            else if(choice==2) invertImage();
            else if(choice==3) Merge_Colored();
            else if(choice==4) {int z; cout<<"1-Flip H \n 2-Flip V"<<endl; cin>>z; if(z==1) FlipH(); if(z==2) FlipV();}
            else if(choice==5) RotateImage();
            else if(choice==6) lighten_Darken_Colored();
            else if(choice==7) DetectEdges();
            else if(choice==8) EnlargeImage();
            else if(choice==9) Shrink_Colored();
            else if(choice==10) save();



            else if(choice==0) break;
    }

    return 0;
}


void load(){
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}
void save(){
    char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}
void Black_White(){
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                if((image[i][j][0]+image[i][j][1]+image[i][j][2])>128*3){
                        image[i][j][0]=255;
                        image[i][j][1]=255;
                        image[i][j][2]=255;
                    }
                else {
                        image[i][j][0]=0;
                        image[i][j][1]=0;
                        image[i][j][2]=0;
                    }
        }}
}
void FlipH(){
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                for(int k=0 ; k<RGB ; ++k){
                flip[255-i][j][k]=image[i][j][k];
        }}}
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                for(int k=0 ; k<RGB ; ++k){
                image[i][j][k]=flip[i][j][k];
        }}}

}
void FlipV(){
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                for(int k=0 ; k<RGB ; ++k){
                flip[i][255-j][k]=image[i][j][k];
        }}}
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                for(int k=0 ; k<RGB ; ++k){
                image[i][j][k]=flip[i][j][k];
        }}}
}
void DetectEdges(){
    Black_White();
    for(int i=0 ; i<SIZE ; ++i){
        for(int j=0 ; j<SIZE ; ++j){
                for(int k=0 ; k<RGB ; ++k){
                    if((image[i][j][k]-image[i][j+1][k])>20 || (image[i][j][k]-image[i][j+1][k])<-20 ||
                        (image[i][j][k]-image[i+1][j][k])>20 || (image[i][j][k]-image[i+1][j][k])<-20)
                        image[i][j][k]=0;
                    else image[i][j][k]=255;
        }}}


}
void Merge_Colored(){
    unsigned imageSave [SIZE][SIZE][RGB];

    char name[100];
    cout<<"Enter name of the other image to merge"<<endl;
    cin>>name;
    strcat (name, ".bmp");
   readRGBBMP(name,image2);

for(int i=0; i<SIZE;++i){
    for(int j=0; j<SIZE; ++j){
        for(int c=0; c<RGB; ++c){

            imageSave[i][j][c]=(image[i][j][c]+image2[i][j][c])/2;
        }
    }
}
   for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
        for(int c=0; c<RGB; ++c){
            image[i][j][c]=imageSave[i][j][c];
        }
    }
   }
}
void lighten_Darken_Colored(){
        int x;

    cout<<"1-Lighten image\n2-Darken image"<<endl;
    cin>>x;
    if(x==1){
for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
        for(int c=0; c<RGB; ++c){
                if((image[i][j][c]+=image[i][j][c])>255)
                    image[i][j][c]=255;
                else image[i][j][c]+=image[i][j][c]/2;

        }
    }
}
    }
    if(x==2){
       for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
        for(int c=0; c<RGB; ++c){
            image[i][j][c]-=image[i][j][c]/2;

        }
    }
}
    }
}
void Shrink_Colored(){
int x,r=0,c=0;


cout<<"1-Shrink by 1/2\n2-Shrink by 1/3\n3-Shrink by 1/4 "<<endl;
cin>>x;

if(x==1){

    for(int i=0; i<128; ++i){
        for(int j=0; j<128; ++j){
            for(int k=0; k<RGB; ++k){
                image2[i][j][k]=(image[r][c][k]+image[r][c+1][k])/2;

            }
            c+=2;
        }
        c=0;
        r+=2;
    }
    for(int i=0; i<SIZE; ++i){
        for(int j=0; j<SIZE; ++j){
            for(int k=0; k<RGB; ++k){
                if(i>128 || j>128)
                    image2[i][j][k]=255;
                else
                    continue;
            }
        }
    }

 server();
}
if(x==2){
     for(int i=0; i<85; ++i){
        for(int j=0; j<85; ++j){
            for(int k=0; k<RGB; ++k){
                image2[i][j][k]=(image[r][c][k]+image[r][c+1][k]+image[r][c+2][k])/3;

            }
            c+=3;
        }
        c=0;
        r+=3;
    }
    for(int i=0; i<SIZE; ++i){
        for(int j=0; j<SIZE; ++j){
            for(int k=0; k<RGB; ++k){
                if(i>85 || j>85)
                    image2[i][j][k]=255;
                else
                    continue;
            }
        }
    }
server();
}
if(x==3){
    for(int i=0; i<64; ++i){
        for(int j=0; j<64; ++j){
            for(int k=0; k<RGB; ++k){
                image2[i][j][k]=(image[r][c][k]+image[r][c+1][k]+image[r][c+2][k]+image[r][c+3][k])/4;

            }
            c+=4;
        }
        c=0;
        r+=4;
    }
    for(int i=0; i<SIZE; ++i){
        for(int j=0; j<SIZE; ++j){
            for(int k=0; k<RGB; ++k){
                if(i>64 || j>64)
                    image2[i][j][k]=255;
                else
                    continue;
            }
        }
    }
server();
}
}

void server (){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++){
            for(int k=0; k<RGB; ++k){
            image[i][j][k]=image2[i][j][k];
}
    }
    }
}
void invertImage (){
for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j){
        for(int c=0; c<RGB; ++c){
        image[i][j][c]=255-image[i][j][c];
}
}
}
}
void RotateImage(){
int x;
unsigned char temp [256] [256][RGB];
cout<<"\nwhat do you want to do now ! \n"<<endl;
cout<<"press 1 to rotate 90 clockwise"<<endl;
cout<<"press 2 to rotate 180 clockwise "<<endl;
cout<<"press 3 to rotate 270 clockwise \n "<<endl;
cout<<"So ! what do u choose to be done ! "<<endl;
cin>>x;
if(x==1){
    for (int i=0 ;i<SIZE ; i++){
        for (int j=0;j<SIZE ; j++){
            for(int c = 0; c <RGB; ++c){
            temp[i][j][c]=image[SIZE-j][i][c];
           }
        }
    }
    for (int i=0 ; i<SIZE ; i++){
        for (int j=0 ; j<SIZE;j++){
            for(int c=0; c<RGB; ++c){
            image[i][j][c]=temp [i][j][c];
           }
        }
    }
}
if(x==2){
for(int i=0 ; i< SIZE ; i++){
        for (int j = 0; j< SIZE; j++) {
                 for ( int c=0 ; c< RGB ; c++){
            temp[i][j][c]=image[SIZE-i][SIZE-j][c];


        }
    }
 }
for(int i=0 ; i< SIZE; i++){
        for (int j = 0; j< SIZE; j++) {
                 for ( int c=0 ; c< RGB ; c++){
           image[i][j][c]=temp[i][j][c];


        }
    }
}
}
if (x==3){
    for (int i=0 ; i<SIZE ; i++){
            for (int j=0 ; j<SIZE ; j++){
                for(int c=0; c<RGB; ++c){
                temp[i][j][c]=image[j][SIZE-i][c] ;
            }
        }
    }
for (int i=0;i<SIZE;i++){
        for (int j=0 ;j<SIZE;j++){
            for(int c=0; c<RGB; ++c){
            image[i][j][c]=temp[i][j][c];
            }
        }
    }
}

}
void EnlargeImage(){
    unsigned char picture [SIZE][SIZE][RGB];
    int  x , r=0 , c=0;
    cout << "Which quarter to enlarge 1, 2, 3 or 4 ?  " << endl ;
    cout << "1- To enlarge the first quarter "  << endl ;
    cout << "2- To enlarge the second quarter " << endl ;
    cout << "3- To enlarge the third quarter " << endl ;
    cout << "4- To enlarge the forth quarter " << endl ;
    cout << "choose the number you want :\n " << endl ;
    cin >> x;
if (x== 1 ){
  for (int i = 0; i < SIZE/2; i++) {
    for (int j = 0; j< SIZE/2; j++){
            for(int k=0; k<RGB; ++k){
             image2[r][c][k] = image[i][j][k] ;
             image2[r+1][c][k]= image[i][j][k];
             image2[r][c+1][k]= image[i][j][k];
             image2[r+1][c+1][k]= image[i][j][k];
        }
             c+=2;
        }
             c=0;
             r+=2;
     }
}
 if (x== 2 ){
  for (int i = 0; i < SIZE/2; i++) {
    for (int j = 128; j< SIZE; j++){
            for(int k=0; k<RGB; ++k){
             image2[r][c][k] = image[i][j][k] ;
             image2[r+1][c][k]= image[i][j][k];
             image2[r][c+1][k]= image[i][j][k];
             image2[r+1][c+1][k]= image[i][j][k];
        }
             c+=2;
        }
             c=0;
             r+=2;
     }
}
 if (x== 3 ){
  for (int i =128; i < SIZE; i++) {
    for (int j = 0; j< SIZE/2; j++){
            for(int k=0; k<RGB; ++k){
             image2[r][c][k] = image[i][j][k] ;
             image2[r+1][c][k]= image[i][j][k];
             image2[r][c+1][k]= image[i][j][k];
             image2[r+1][c+1][k]= image[i][j][k];
        }
             c+=2;
        }
             c=0;
             r+=2;
     }
}
 if (x== 4 ){
  for (int i = 128; i < SIZE; i++) {
    for (int j = 128; j< SIZE; j++){
            for(int k=0; k<RGB; ++k){
             image2[r][c][k] = image[i][j][k] ;
             image2[r+1][c][k]= image[i][j][k];
             image2[r][c+1][k]= image[i][j][k];
             image2[r+1][c+1][k]= image[i][j][k];
        }
             c+=2;
        }
        c=0;
        r+=2;
     }
}
server();
}
