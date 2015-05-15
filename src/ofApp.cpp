#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
    osc = new Osc(PORT, this);
    sender.setup("127.0.0.1" , 7400);
    app.setup();
    
    
    for(int i=0; i<(NODE_NUM); i++){
        //Setup blinks
        sloBlink blink;
        blink.spd = BLINK_SPD;
        blinks.push_back(blink);
        //Reset nord flags
        app.special_nords[i] = false;
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    osc->update();
    app.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255, 255, 255);

    
    //Draw All Rects
    for(int i =0; i< SQ_COLUMN; i++){
        
        for(int j=0; j< SQ_ROW; j++){
            
            ofNoFill();
            float x = (SQ_SIZE*i);
            float margin_x = (SQ_SIZE*SQ_MARGIN)*i;
            float y = (SQ_SIZE*j);
            float margin_y = (SQ_SIZE*SQ_MARGIN)*j;


            ofSetColor(255);
            int conveted_xy_to_index = (j*SQ_COLUMN)+i;
            
            //if blink all, change color
            if(timer_blink_all>0){
                ofSetColor(255, 0, 0);
            }

            blinks[conveted_xy_to_index].draw(x+margin_x+SC_MARGIN_LEFT, y+margin_y+SC_MARGIN_TOP);

            //Draw Special Nords
            if(timer_blink_all==0){ // disp special node
                if(app.special_nords[conveted_xy_to_index]==true){
                    ofFill();
                    ofSetColor(255.0 , 0.0, 0.0);
                    ofRect(x+margin_x+SC_MARGIN_LEFT, y+margin_y+SC_MARGIN_TOP, SQ_SIZE, SQ_SIZE);
                }
            }
        }
        
    }
    if(timer_blink_all>0)timer_blink_all--;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key=='s'){

        int rnd_index;
        do{
            rnd_index = (int)ofRandom(NODE_NUM);
        }while(rnd_index==app.pre_rnd_index);
        
        if(app.checkSpecial(rnd_index)){

            //If the trg node is special
            blinkAll();
            app.createSpecialNode();
            
        }else{
            
            blinks[rnd_index].bang();
        
        }
        app.pre_rnd_index = rnd_index;
    
        
    }
    if(key=='a'){
        
        app.createSpecialNodes(NUM_SPECICAL_NODE);
        
    }
    
    if(key=='d'){
        
        
        for(int i=0; i<NODE_NUM; i++){
            
            app.special_nords[i]=false;
            
            
        }
        
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

//-------------------------------------------------------------
void ofApp::blinkAll(){
    
    for(int i=0; i<NODE_NUM;i++){
        
        blinks[i].bang();
        
    }
    
    timer_blink_all = BLINK_SPD;
    
}

//-------------------------------------------------------------
void ofApp::setSpecials(specials_t sp){

    app.resetSpecials();
    for(int i=0; i<sp.node_num; i++){
        
        app.special_nords[sp.specials[i]] = true;
        
    }
    
}
