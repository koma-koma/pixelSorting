#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofLoadImage(pix, "monroe.jpg");
  pix.resize(pix.getWidth(), pix.getHeight());
  img.allocate(pix.getWidth(), pix.getHeight(), OF_IMAGE_COLOR);
  
  next = pix.getWidth()/2;
  
  w = pix.getWidth();
  h = pix.getHeight();
  
//  for (int i = 0; i < pix.size(); i+=3) {
//    int nexti = i+next*3;
//    if (nexti >= pix.size()) { nexti -= pix.size(); }
//    pix[i] = p[s];
//    pix[i+1] = p[nexti+1];
//    pix[i+2] = p[nexti+2];
//  }

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      c.push_back(pix.getColor(x, y));
      
      //cout << (x+y*w) << " " << b[x+y*w] << endl;
    }
  }
  
  i = 0;
  p = pix;
  running = true;
}


//--------------------------------------------------------------
void ofApp::update(){
  //すべて
//  if (i < w*h-1) {
//    int max = b[i];
//    int max_n = i;
//    for (int j = i + 1; j < w*h; j++) {
//      if(b[j] > max) {
//        max = b[j];
//        max_n = j;
//      }
//    }
//    int tmp = b[i];
//    b[i] = b[max_n];
//    b[max_n] = tmp;
//    
//    //cout << i << endl;
//    
//    
//    
//    pix[i*3] = p[max_n*3];
//    pix[i*3+1] = p[max_n*3+1];
//    pix[i*3+2] = p[max_n*3+2];
//    
//    pix[max_n*3] = p[i*3];
//    pix[max_n*3+1] = p[i*3+1];
//    pix[max_n*3+2] = p[i*3+2];
//
  
  // 一行ずつ
    if (i < w-1 && running) {
      for (int y = 0; y < h; y++) {
        int cur_val = c[i + y*w].getHue();
        if (cur_val >= 0) {
          int max = cur_val;
          int max_n = i;
          //        int max = 0;
          //        int max_n = 0;
          for (int j = i + 1; j < w; j++) {
            int val = c[j + y*w].getBrightness();
            if (val >= 0) {
              if (val >= max) {
                max = val;
                max_n = j;
              }
            }
          }
          int tmp = cur_val;
          c[i + y*w] = c[max_n + y*w];
          c[max_n + y*w] = tmp;
          
//          cout << i << endl;
          
          //普通の
          pixelExchange(i + y*w, max_n + y*w);
        }
      }
      i++;
      img.setFromPixels(pix);
    }
  //cout << ofGetFrameRate() << endl;
}

void ofApp::sortLine(int row) {
}


void ofApp::pixelExchange(int cur_num, int change_num) {
  int tmp0 = pix[cur_num*3];
  int tmp1 = pix[cur_num*3+1];
  int tmp2 = pix[cur_num*3+2];
  
  pix[cur_num*3] = pix[change_num*3];
  pix[cur_num*3 + 1] = pix[change_num*3 + 1];
  pix[cur_num*3 + 2] = pix[change_num*3 + 2];
  
  pix[change_num*3] = tmp0;
  pix[change_num*3 + 1] = tmp1;
  pix[change_num*3 + 2] = tmp2;
}

//--------------------------------------------------------------
void ofApp::draw(){
  img.draw(0, 0, pix.getWidth(), pix.getHeight());
  ofImage originalImg;
  originalImg.setFromPixels(p);
  originalImg.draw(pix.getWidth(), 0, p.getWidth(), p.getHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if(key == 's'){
    img.save("sorted.png", OF_IMAGE_QUALITY_BEST);
  }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  }

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  running = !running;

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
